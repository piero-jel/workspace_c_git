/**
* 
* *********************************************************************************//**
* \addtogroup modules "Modulos/Librerias Arduino"
* @{ 
* \copyright  
* 2019, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of modules .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright holder. &copy;
* \file adlx345.cpp
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \brief Descripcion breve.
* \details Descripcion detallada.
* 
*
* \version 01v01d01.
* \date Domingo 25 de Octubre, 2020.
* \pre pre, condiciones que deben cuplirse antes del llamado, example: First
* initialize the system.
* \bug bug, depuracion example: Not all memory is freed when deleting an object 
* of this class.
* \warning mensaje de precaucion, warning.
* \note nota.
* 
* @} doxygen end group definition 
* ********************************************************************************** */
#include "adlx345.h"
  

bool_t adlx345_checkdevices(adlx345_hdl_t * pHdl)
{ 
  ASSERT(pHdl == NULL, return FALSE);
  if(adlx345_read_register(pHdl,adxl345_REG_DEVID) == 0xE5) 
  {    
    return TRUE;
  }  
  /* No adxl345 detected ... return false */
  return FALSE;
}



bool_t adlx345_init(adlx345_hdl_t * pHdl, uint8_t addr,bool_t busInit)
{
  ASSERT(pHdl == NULL, return FALSE);
  /* Almacenamos la direccion en el handler */
  pHdl->addr = addr;
  /* Establceemos el ID, usando la parte baja de la direccion 
   * puede cambiar si el seteo de direcciones es diferente al
   * convencional de 3-bits 0x5 {0~7}
   */
  pHdl->sensor_id |= (addr & 0x0F); 
  /* Inicio el bus i2c */
  if(busInit)
    adlx345_i2c_begin();
  /* Consultamos la disponibilidad del sensor */
  if(!adlx345_checkdevices(pHdl))
  {    
    return FALSE;
  }
  /* Maracmoas que lo inicializo */
  pHdl->sensor_id |= 0x80;
  /* Configuracion por defecto del Sensor 
   */  
  adlx345_write_register(pHdl,adxl345_REG_POWER_CTL,0x08);  
  return TRUE;
}


bool_t adlx345_check_init(adlx345_hdl_t * pHdl,bool_t clean)
{  
  ASSERT(pHdl == NULL, return FALSE);
  bool_t rval = (pHdl->sensor_id & 0x80)? TRUE:FALSE;  
  if(clean)
    pHdl->sensor_id &= 0x7F;    
  return rval;
}

/*
 Register 0x31—DATA_FORMAT 

  FULL_RES Bit :<3>
  When this bit is set to a value of 1, the device is in full resolution
  mode, where the output resolution increases with the g range
  set by the range bits to maintain a 4 mg/LSB scale factor. When
  the FULL_RES bit is set to 0, the device is in 10-bit mode, and
  the range bits determine the maximum g range and scale factor.

 
 */

void adlx345_config(adlx345_hdl_t * pHdl, adlx345_range_t rango, adlx345_datarate_t rate)
{  
  ASSERT(pHdl == NULL, return);
  uint8_t format, lrango;
  lrango = (uint8_t) rango;
#if (__dlx345_version__ == 1)  
  switch(lrango)  
  {
    case adlx345_RANGE_16_G:
      pHdl->range = 512;
      break;
    case adlx345_RANGE_8_G:
      pHdl->range = 1024;
      break;
    case adlx345_RANGE_4_G:
      pHdl->range = 2048;
      break;      
    default:
      lrango = adlx345_RANGE_2_G;
    case adlx345_RANGE_2_G:
      pHdl->range = 4096;
      break;    
  }    

#endif  
  /* Nos quedamos con la parte baga del valor */
  lrango &= 0x0F;
  /* Establecemos el Rango */
  format = adlx345_read_register(pHdl,adxl345_REG_DATA_FORMAT);
  /* Borramos la Parte Baja */
  format &= 0xF0;
  /* Colocamos el rango Nuevo de forma temporal */
  format |= lrango;
  /* Nos aseguramos de mantener Habilito el FULL-RES  */
  format |= 0x08;
  /* Escribimos el format */
  adlx345_write_register(pHdl,adxl345_REG_DATA_FORMAT,format);
  
  if(rate != 0)
    adlx345_write_register(pHdl,adxl345_REG_BW_RATE,rate);
}  



  
  
/**
 * 
 *  
*/
uint8_t adlx345_read_register(adlx345_hdl_t * pHdl, uint8_t reg)
{
  ASSERT(pHdl == NULL, return 0xFF);
  adlx345_i2c_begin_transmission(pHdl->addr);
  adlx345_i2c_writebyte(reg);
  adlx345_i2c_end_transmission();
  adlx345_i2c_request_from(pHdl->addr,1);
  return (adlx345_i2c_readbyte());
}


void adlx345_write_register(adlx345_hdl_t * pHdl, uint8_t reg, uint8_t value)  
{
  ASSERT(pHdl == NULL, return);
  adlx345_i2c_begin_transmission(pHdl->addr);  
  adlx345_i2c_writebyte(reg);
  adlx345_i2c_writebyte(value);
  adlx345_i2c_end_transmission();
}
  

int16_t adlx345_read_i16(adlx345_hdl_t * pHdl, uint8_t reg)
{
  ASSERT(pHdl == NULL, return 0xFFFF);
  adlx345_i2c_begin_transmission(pHdl->addr);
  adlx345_i2c_writebyte(reg);
  adlx345_i2c_end_transmission();
  adlx345_i2c_request_from(pHdl->addr,2);
  return (int16_t) (adlx345_i2c_readbyte() | (adlx345_i2c_readbyte()<<8)); 
}
  

/*
 SELF_TEST bit in the DATA_FORMAT register, Address 0x31
 
 
 
 The part also must be placed into normal power operation by ensuring the LOW_POWER bit in the BW_RATE register is cleared (LOW_POWER bit = 0) for accurate self-test measurements
      # BW_RATE<LOW_POWER> = 0
      
 */
  
/*
    ## D0 | D1  Wakeup    
    ## D2       Sleep    
    ## D3       Measure
    ## D4       AUTO_SLEEP
    ## D5       Link
    ## D6 | D7  not use
    
    adlx345_write_register(pHdl,adxl345_REG_POWER_CTL,0x08); 
 */  

void adlx345_calibrated(adlx345_hdl_t * pHdl)
{
  ASSERT(pHdl == NULL, return);
  
  
}

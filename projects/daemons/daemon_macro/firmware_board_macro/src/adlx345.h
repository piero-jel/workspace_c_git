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
* \file adlx345.h
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


#ifndef __adlx345_h__
#define __adlx345_h__ /**<@brief definimos el header file, para evitar includes recursivos */
/* 
* ***** [ Add header files ] *****
*/
#include <Arduino.h>
#include "stdctype.h"
#include "systick.h"
#include <Wire.h>
/*
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =======================================[begin of project file]=======================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
* 
*/
/*
* 
* ============================[Open, cplusplus]============================
* 
*/
#ifdef __cplusplus
extern "C" {
#endif
  
#define dlx345_i2c_ENABLE           1 /**<@brief Enable '1'/Disable '0' el Bus de I2C. */
  
  
/**
*  
* \def __dlx345_version__
* \brief Etiqueta para establecer la version del modulo.
*   should be:
*     + 0, version base
*     + 1, se agrega la apis para calibrar y se agrega al handler los datos de rango
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */   
#define __dlx345_version__          1
  




/*
 * ------------------------------------------------------------------------------------
 *
 * ++++++++++++++++++++++++++[ Registros del Sensor ]++++++++++++++++++++++++++
 * 
 * Bancos de registros del dispositivo estos ss antienen
 * para los diferentes bus de comunicacion del dispositivo
 *
 ------------------------------------------------------------------------------------ */
  
#define adxl345_REG_DEVID               (0x00) /**<@brief Device ID */
#define adxl345_REG_THRESH_TAP          (0x1D) /**<@brief Tap threshold */
#define adxl345_REG_OFSX                (0x1E) /**<@brief X-axis offset */
#define adxl345_REG_OFSY                (0x1F) /**<@brief Y-axis offset */
#define adxl345_REG_OFSZ                (0x20) /**<@brief Z-axis offset */
#define adxl345_REG_DUR                 (0x21) /**<@brief Tap duration */
#define adxl345_REG_LATENT              (0x22) /**<@brief Tap latency */
#define adxl345_REG_WINDOW              (0x23) /**<@brief Tap window */
#define adxl345_REG_THRESH_ACT          (0x24) /**<@brief Activity threshold */
#define adxl345_REG_THRESH_INACT        (0x25) /**<@brief Inactivity threshold */
#define adxl345_REG_TIME_INACT          (0x26) /**<@brief Inactivity time */
#define adxl345_REG_ACT_INACT_CTL       (0x27) /**<@brief Axis enable control for activity and inactivity detection */
#define adxl345_REG_THRESH_FF           (0x28) /**<@brief Free-fall threshold */
#define adxl345_REG_TIME_FF             (0x29) /**<@brief Free-fall time */
#define adxl345_REG_TAP_AXES            (0x2A) /**<@brief Axis control for single/double tap */
#define adxl345_REG_ACT_TAP_STATUS      (0x2B) /**<@brief Source for single/double tap */
#define adxl345_REG_BW_RATE             (0x2C) /**<@brief Data rate and power mode control */
#define adxl345_REG_POWER_CTL           (0x2D) /**<@brief Power-saving features control */
#define adxl345_REG_INT_ENABLE          (0x2E) /**<@brief Interrupt enable control */
#define adxl345_REG_INT_MAP             (0x2F) /**<@brief Interrupt mapping control */
#define adxl345_REG_INT_SOURCE          (0x30) /**<@brief Source of interrupts */
#define adxl345_REG_DATA_FORMAT         (0x31) /**<@brief Data format control */
#define adxl345_REG_DATAX0              (0x32) /**<@brief X-axis data 0 */
#define adxl345_REG_DATAX1              (0x33) /**<@brief X-axis data 1 */
#define adxl345_REG_DATAY0              (0x34) /**<@brief Y-axis data 0 */
#define adxl345_REG_DATAY1              (0x35) /**<@brief Y-axis data 1 */
#define adxl345_REG_DATAZ0              (0x36) /**<@brief Z-axis data 0 */
#define adxl345_REG_DATAZ1              (0x37) /**<@brief Z-axis data 1 */
#define adxl345_REG_FIFO_CTL            (0x38) /**<@brief FIFO control */
#define adxl345_REG_FIFO_STATUS         (0x39) /**<@brief FIFO status */

/*
 * ------------------------------------------------------------------------------------
 *
 * +++++++++++++++++++++++[ Enumeracion p/Data Rate y  Rango ]+++++++++++++++++++++++
 * 
 * Enumeraciones para configurar y obtener el data rate del sensor y el rango de operacion
 * del mismo.
 *
 ------------------------------------------------------------------------------------ */
/**
* \enum adlx345_datarate_t;
*  \brief Enumeracion para la seleccion del data rate del sensor, los valores posibles son:
*  \li \ref adlx345_DATARATE_3200_HZ
*  \li \ref adlx345_DATARATE_1600_HZ
*  \li \ref adlx345_DATARATE_800_HZ 
*  \li \ref adlx345_DATARATE_400_HZ 
*  \li \ref adlx345_DATARATE_200_HZ 
*  \li \ref adlx345_DATARATE_100_HZ 
*  \li \ref adlx345_DATARATE_50_HZ
*  \li \ref adlx345_DATARATE_25_HZ
*  \li \ref adlx345_DATARATE_12_5_HZ
*  \li \ref adlx345_DATARATE_6_25HZ 
*  \li \ref adlx345_DATARATE_3_13_HZ
*  \li \ref adlx345_DATARATE_1_56_HZ
*  \li \ref adlx345_DATARATE_0_78_HZ
*  \li \ref adlx345_DATARATE_0_39_HZ
*  \li \ref adlx345_DATARATE_0_20_HZ
*  \li \ref adlx345_DATARATE_0_10_HZ
* \version 01v01d01.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum 
{
  adlx345_DATARATE_3200_HZ = 0b1111, /**<@brief 1600Hz Bandwidth   140uA IDD */
  adlx345_DATARATE_1600_HZ = 0b1110, /**<@brief  800Hz Bandwidth    90uA IDD */
  adlx345_DATARATE_800_HZ = 0b1101,  /**<@brief  400Hz Bandwidth   140uA IDD */
  adlx345_DATARATE_400_HZ = 0b1100,  /**<@brief  200Hz Bandwidth   140uA IDD */
  adlx345_DATARATE_200_HZ = 0b1011,  /**<@brief  100Hz Bandwidth   140uA IDD */
  adlx345_DATARATE_100_HZ = 0b1010,  /**<@brief 50Hz Bandwidth   140uA IDD */
  adlx345_DATARATE_50_HZ = 0b1001,   /**<@brief 25Hz Bandwidth    90uA IDD */
  adlx345_DATARATE_25_HZ = 0b1000,   /**<@brief 12.5Hz Bandwidth    60uA IDD */
  adlx345_DATARATE_12_5_HZ = 0b0111, /**<@brief 6.25Hz Bandwidth    50uA IDD */
  adlx345_DATARATE_6_25HZ = 0b0110,  /**<@brief 3.13Hz Bandwidth    45uA IDD */
  adlx345_DATARATE_3_13_HZ = 0b0101, /**<@brief 1.56Hz Bandwidth    40uA IDD */
  adlx345_DATARATE_1_56_HZ = 0b0100, /**<@brief 0.78Hz Bandwidth    34uA IDD */
  adlx345_DATARATE_0_78_HZ = 0b0011, /**<@brief 0.39Hz Bandwidth    23uA IDD */
  adlx345_DATARATE_0_39_HZ = 0b0010, /**<@brief 0.20Hz Bandwidth    23uA IDD */
  adlx345_DATARATE_0_20_HZ = 0b0001, /**<@brief 0.10Hz Bandwidth    23uA IDD */
  adlx345_DATARATE_0_10_HZ =  0b0000 /**<@brief 0.05Hz Bandwidth    23uA IDD (default value) */
} adlx345_datarate_t;

/**
* \enum adlx345_range_t 
* \brief Enumeracion para la seleccion del rango de trabajo del dispoitivo.
* Elementos que componen la enumeracion:
*  \li \ref adlx345_RANGE_16_G 
*  \li \ref adlx345_RANGE_8_G 
*  \li \ref adlx345_RANGE_4_G 
*  \li \ref adlx345_RANGE_2_G 
* \version 01v01d01.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  adlx345_RANGE_16_G = 0x03, /**<@brief rango de trabajo de +/- 16g a 13-bits sensibilidad de 1.953125 mG */
  adlx345_RANGE_8_G = 0x02,  /**<@brief rango de trabajo de +/- 8g a 13-bits sensibilidad de 976.56 uG */
  adlx345_RANGE_4_G = 0x01,  /**<@brief rango de trabajo de +/- 4g a 13-bits sensibilidad de 488.28125 mG */
  adlx345_RANGE_2_G = 0x00  /**<@brief rango de trabajo de +/- 2g (default value) a 13-bits sensibilidad de 244.140625 mG  */
} adlx345_range_t;



 
#if (dlx345_i2c_ENABLE == 1)  
  


/** 
 * Dependencia de las librerias de arduino.
 * Escritura de un byte sobre el bus I2C,
 * deberiamos implementar una libreria para simplificar el uso del bus
 * 
 * busi2c_writebyte(I2Cbus,writeByte)
 * busi2c_readbyte(I2Cbus,dstByte)
 * 
 */

#if ARDUINO >= 100
#define adlx345_i2c_writebyte( Byte )            Wire.write((uint8_t)Byte)
#define adlx345_i2c_readbyte()                   Wire.read()
#else
#define adlx345_i2c_writebyte( Byte )            Wire.send(x)
#define adlx345_i2c_readbyte()                   Wire.receive()
#endif

#define adlx345_i2c_begin()                      Wire.begin()
#define adlx345_i2c_begin_transmission(Address)  Wire.beginTransmission((int)Address)
#define adlx345_i2c_end_transmission()           Wire.endTransmission()
#define adlx345_i2c_request_from(Address,nByte)  Wire.requestFrom((int)Address,(int)nByte)




#define adxl345_DEFAULT_ADDRESS (0x53) /**<@brief I2C ADDRESS/BITS, Assumes ALT address pin low */



/**
* \struct adlx345_i16data_t; 
* \brief Esturcutra de dato para almacenar los valores de la aceleracion 
* en los tres ejes, en formato entero sin signo de 16-bits.
*  \li \ref x;
*  \li \ref y;
*  \li \ref z;
* \version  01v01d01.
* \note nota sobre la estructura.
* \warning Este tipo de estructura no puede ser almacenada 
* en memoria de programa. Por lo que no puede usar el cualificador 'const'.
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  int16_t x; /**<@brief Aceleraccion en el eje x */
  int16_t y; /**<@brief Aceleraccion en el eje y */
  int16_t z; /**<@brief Aceleraccion en el eje z */  
}adlx345_i16data_t;

/**
* \struct adlx345_f32data_t; 
* \brief Esturcutra de dato para manejar los valores de la aceleracion 
* en los tres ejes, en formato numero con coma flotante de 32-bits.
*  \li \ref x;
*  \li \ref y;
*  \li \ref z;
* \version  01v01d01.
* \note nota sobre la estructura.
* \warning Este tipo de estructura no puede ser almacenada 
* en memoria de programa. Por lo que no puede usar el cualificador 'const'.
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  float x; /**<@brief Aceleraccion en el eje x */
  float y; /**<@brief Aceleraccion en el eje y */
  float z; /**<@brief Aceleraccion en el eje z */  
}adlx345_f32data_t;    
  

/**
* \struct adlx345_hdl_t; 
* \brief Estructura de dato que funciona como handler del sensor.
* Elementos de la configuracion:
*  \li \ref addr ;
*  \li \ref sensor_id;
*  \li \ref range;
*  \li \ref rate;
* \version  01v01d01.
* \note nota sobre la estructura.
* \warning Este tipo de estructura no puede ser almacenada 
* en memoria de programa. Por lo que no puede usar el cualificador 'const'.
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  /* 7 - Inicializacion 1-Succes | 0-Failure 
   * 6 - disponible
   * 5 - disponible
   * 4 - disponible
   */
  uint8_t sensor_id;  /**<@brief Id en caso de contener mas de una sensor hasta 16 valores posibles */
  uint8_t addr;       /**<@brief Direccion del sensor dentro del bus de datos */
#if (__dlx345_version__ == 1)  
  uint16_t range;      /**<@brief Para almacenar el rango de operacion */
#endif
}adlx345_hdl_t;




/*******************************************************************************//**
* \fn bool_t adlx345_init(adlx345_hdl_t * pHdl, uint8_t addr,bool_t busInit);
* \brief Funcion que inicializa el hardware necesario para el modulo acelerometro
*  conectado al bus I2C.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \param addr : Direccion dentro del bus I2C.
* \param busInit : Con este le indicamos si debemos o no inicializar el bus,
* se este es FALSE, el bus debe estar inicializado ya.
* \return estado de la inicializacion del modulo.
*      \li TRUE, success
*      \li FALSE, failure
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 24 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
void setup()
{  
  WATCH_DOG_TIMER(DISABLE);
  powersave_init();
  powersave_set(powerflags,powersave_SET);
  blinkyled_init(&cfgLed1);  
#ifndef ESP8266  
  while (!Serial); 
#endif  
  Serial.begin(115200);
  Serial.println("Consola configurada a 115200bps");  
  
  while(!accelerometer_init())
  {
    Serial.println("No se Detecto el Sensor ADXL345 ... Check las conexiones!");
    // esperamos un segundo
    systick_pause_ms(1000);
  }    
    
  blinkyled_set(2);
  WATCH_DOG_TIMER(ENABLE,8s);
}
</PRE>
*************************************************************************************/
bool_t adlx345_init(adlx345_hdl_t * pHdl, uint8_t addr,bool_t busInit);


/*******************************************************************************//**
* \fn bool_t adlx345_checkdevices(adlx345_hdl_t * pHdl);
* \brief Funcion para chequear si el dispoitivo esta online, dentro del bus i2c.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return estado del check
*      \li TRUE, success
*      \li FALSE, no se encuentra disponible.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 24 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
void setup()
{  
  WATCH_DOG_TIMER(DISABLE);
  powersave_init();
  powersave_set(powerflags,powersave_SET);
  blinkyled_init(&cfgLed1);  
#ifndef ESP8266  
  while (!Serial); 
#endif  
  Serial.begin(115200);
  Serial.println("Consola configurada a 115200bps");
  while(!accelerometer_init())
  {
    Serial.println("No se Detecto el Sensor ADXL345 ... Check las conexiones!");
    // esperamos un segundo
    systick_pause_ms(1000);
  }    
  blinkyled_set(2);
  WATCH_DOG_TIMER(ENABLE,8s);
}
</PRE>
*************************************************************************************/
bool_t adlx345_checkdevices(adlx345_hdl_t * pHdl);

/*******************************************************************************//** 
* \fn void adlx345_config(adlx345_hdl_t * pHdl, adlx345_range_t rango, adlx345_datarate_t rate);
* \brief Funcion para establecer el rango y el data rate del sensor.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \param rango : rango de trabajo al cual se quiere setear el dispositivo (\ref adlx345_range_t).
* \param rate : Data rate que se quiere establecer para el dispositivo (\ref adlx345_datarate_t).
* \return nothing
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/  
void adlx345_config(adlx345_hdl_t * pHdl, adlx345_range_t rango, adlx345_datarate_t rate);

/*******************************************************************************//** 
* \fn uint8_t adlx345_read_register(adlx345_hdl_t * pHdl, uint8_t reg);
* \brief Funcion para leer un registro interno de 8-bits, del acelerometro.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \param reg : Registro que se requiere leer, listado de Registros:
* \li \ref adxl345_REG_DEVID               
* \li \ref adxl345_REG_THRESH_TAP          
* \li \ref adxl345_REG_OFSX                
* \li \ref adxl345_REG_OFSY                
* \li \ref adxl345_REG_OFSZ                
* \li \ref adxl345_REG_DUR                 
* \li \ref adxl345_REG_LATENT              
* \li \ref adxl345_REG_WINDOW              
* \li \ref adxl345_REG_THRESH_ACT          
* \li \ref adxl345_REG_THRESH_INACT        
* \li \ref adxl345_REG_TIME_INACT          
* \li \ref adxl345_REG_ACT_INACT_CTL       
* \li \ref adxl345_REG_THRESH_FF           
* \li \ref adxl345_REG_TIME_FF             
* \li \ref adxl345_REG_TAP_AXES            
* \li \ref adxl345_REG_ACT_TAP_STATUS      
* \li \ref adxl345_REG_BW_RATE             
* \li \ref adxl345_REG_POWER_CTL           
* \li \ref adxl345_REG_INT_ENABLE          
* \li \ref adxl345_REG_INT_MAP             
* \li \ref adxl345_REG_INT_SOURCE          
* \li \ref adxl345_REG_DATA_FORMAT         
* \li \ref adxl345_REG_DATAX0              
* \li \ref adxl345_REG_DATAX1              
* \li \ref adxl345_REG_DATAY0              
* \li \ref adxl345_REG_DATAY1              
* \li \ref adxl345_REG_DATAZ0              
* \li \ref adxl345_REG_DATAZ1              
* \li \ref adxl345_REG_FIFO_CTL            
 * \li \ref adxl345_REG_FIFO_STATUS         
* \return Valor que contiene el registro del acelerometro. Formato \ref uint8_t.
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/  
uint8_t adlx345_read_register(adlx345_hdl_t * pHdl, uint8_t reg);


/*******************************************************************************//** 
* \fn void adlx345_write_register(adlx345_hdl_t * pHdl, uint8_t reg, uint8_t value);
* \brief Funcion para escribir en un registro interno, de 8-bits, del acelerometro.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \param reg : Registro que se requiere escribir, listado de Registros:
* \li \ref adxl345_REG_DEVID               
* \li \ref adxl345_REG_THRESH_TAP          
* \li \ref adxl345_REG_OFSX                
* \li \ref adxl345_REG_OFSY                
* \li \ref adxl345_REG_OFSZ                
* \li \ref adxl345_REG_DUR                 
* \li \ref adxl345_REG_LATENT              
* \li \ref adxl345_REG_WINDOW              
* \li \ref adxl345_REG_THRESH_ACT          
* \li \ref adxl345_REG_THRESH_INACT        
* \li \ref adxl345_REG_TIME_INACT          
* \li \ref adxl345_REG_ACT_INACT_CTL       
* \li \ref adxl345_REG_THRESH_FF           
* \li \ref adxl345_REG_TIME_FF             
* \li \ref adxl345_REG_TAP_AXES            
* \li \ref adxl345_REG_ACT_TAP_STATUS      
* \li \ref adxl345_REG_BW_RATE             
* \li \ref adxl345_REG_POWER_CTL           
* \li \ref adxl345_REG_INT_ENABLE          
* \li \ref adxl345_REG_INT_MAP             
* \li \ref adxl345_REG_INT_SOURCE          
* \li \ref adxl345_REG_DATA_FORMAT         
* \li \ref adxl345_REG_DATAX0              
* \li \ref adxl345_REG_DATAX1              
* \li \ref adxl345_REG_DATAY0              
* \li \ref adxl345_REG_DATAY1              
* \li \ref adxl345_REG_DATAZ0              
* \li \ref adxl345_REG_DATAZ1              
* \li \ref adxl345_REG_FIFO_CTL            
* \li \ref adxl345_REG_FIFO_STATUS         
* \param value : valor que se desea escribir, sobre el registro interno del acelerometro.
* 
* \return nothing
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/  
void adlx345_write_register(adlx345_hdl_t * pHdl, uint8_t reg, uint8_t value);


/*******************************************************************************//** 
* \fn int16_t adlx345_read_i16(adlx345_hdl_t * pHdl, uint8_t reg);
* \brief Funcion para leer un registro interno de 16-bits (dos registros de 8-bits
* consecutivos, iniciando por la direccion pasada), del acelerometro.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \param reg : Registro que se requiere leer, listado de Registros:
* \li \ref adxl345_REG_DEVID               
* \li \ref adxl345_REG_THRESH_TAP          
* \li \ref adxl345_REG_OFSX                
* \li \ref adxl345_REG_OFSY                
* \li \ref adxl345_REG_OFSZ                
* \li \ref adxl345_REG_DUR                 
* \li \ref adxl345_REG_LATENT              
* \li \ref adxl345_REG_WINDOW              
* \li \ref adxl345_REG_THRESH_ACT          
* \li \ref adxl345_REG_THRESH_INACT        
* \li \ref adxl345_REG_TIME_INACT          
* \li \ref adxl345_REG_ACT_INACT_CTL       
* \li \ref adxl345_REG_THRESH_FF           
* \li \ref adxl345_REG_TIME_FF             
* \li \ref adxl345_REG_TAP_AXES            
* \li \ref adxl345_REG_ACT_TAP_STATUS      
* \li \ref adxl345_REG_BW_RATE             
* \li \ref adxl345_REG_POWER_CTL           
* \li \ref adxl345_REG_INT_ENABLE          
* \li \ref adxl345_REG_INT_MAP             
* \li \ref adxl345_REG_INT_SOURCE          
* \li \ref adxl345_REG_DATA_FORMAT         
* \li \ref adxl345_REG_DATAX0              
* \li \ref adxl345_REG_DATAX1              
* \li \ref adxl345_REG_DATAY0              
* \li \ref adxl345_REG_DATAY1              
* \li \ref adxl345_REG_DATAZ0              
* \li \ref adxl345_REG_DATAZ1              
* \li \ref adxl345_REG_FIFO_CTL            
* \li \ref adxl345_REG_FIFO_STATUS         
* \return Valor que contiene el registro del acelerometro formato \ref uint16_t.
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/ 
int16_t adlx345_read_i16(adlx345_hdl_t * pHdl, uint8_t reg);


#define adlx345_MG2G_MULTIPLIER (0.004)       /**<@brief 4mg per lsb */
#define SENSORS_GRAVITY_EARTH (9.80665F)      /**<@brief Earth's gravity in m/s^2 */
#define adlx345_FLOAT32_ESCALAR (0.0392266F)  /**<@brief Factor para obtener la aceleraccion en m/s^2 */


/*******************************************************************************//**
* \def adlx345_getXi16(pHdl)
* \brief Macro funcion para Obtener la aceleraccion en el eje \b x, en formato entero 
* y en unidades de [G/256LSB].
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return aceleracion en el eje \b x en unidades [G/256LSB] y formato entero de 16-Bits.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_getXi16(pHdl)    adlx345_read_i16(pHdl, adxl345_REG_DATAX0) 

/*******************************************************************************//**
* \def adlx345_getYi16(pHdl)
* \brief Macro funcion para Obtener la aceleraccion en el eje \b y, en formato entero 
* y en unidades de [G/256LSB].
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return aceleracion en el eje \b y en unidades [G/256LSB] y formato entero de 16-Bits.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_getYi16(pHdl)    adlx345_read_i16(pHdl, adxl345_REG_DATAY0) 

/*******************************************************************************//**
* \def adlx345_getZi16(pHdl)
* \brief Macro funcion para Obtener la aceleraccion en el eje \b z, en formato entero 
* y en unidades de [G/256LSB].
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return aceleracion en el eje \b z en unidades [G/256LSB] y formato entero de 16-Bits.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_getZi16(pHdl)    adlx345_read_i16(pHdl, adxl345_REG_DATAZ0)



/*******************************************************************************//**
* \def adlx345_getoffsetX(pHdl);
* \brief Funcion para obtener el offset de aceleraccion del eje \b x. 
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return offset de la aceleracion en el eje \b x .
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_getoffsetX(pHdl)    adlx345_read_register(pHdl, adxl345_REG_OFSX) 

/*******************************************************************************//**
* \def adlx345_getoffsetY(pHdl);
* \brief Funcion para obtener el offset de aceleraccion del eje \b x. 
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return offset de la aceleracion en el eje \b y .
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_getoffsetY(pHdl)    adlx345_read_register(pHdl, adxl345_REG_OFSY) 


/*******************************************************************************//**
* \def adlx345_getoffsetZ(pHdl);
* \brief Funcion para obtener el offset de aceleraccion del eje \b x. 
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return offset de la aceleracion en el eje \b z .
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_getoffsetZ(pHdl)    adlx345_read_register(pHdl, adxl345_REG_OFSZ)


/*******************************************************************************//**
* \def adlx345_setoffsetX(pHdl,Value)
* \brief Macro funcion para establecer el Offset sobre el eje \b x.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \param Value : Valor de Offset que se desea establecer para el eje correspondiente.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_setoffsetX(pHdl,Value)    adlx345_write_register(pHdl, adxl345_REG_OFSX,Value) 

/*******************************************************************************//**
* \def adlx345_setoffsetY(pHdl,Value)
* \brief Macro funcion para establecer el Offset sobre el eje \b y.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \param Value : Valor de Offset que se desea establecer para el eje correspondiente.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
#define adlx345_setoffsetY(pHdl,Value)    adlx345_write_register(pHdl, adxl345_REG_OFSY,Value) 

/*******************************************************************************//**
* \def adlx345_setoffsetZ(pHdl,Value)
* \brief Macro funcion para establecer el Offset sobre el eje \b z.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \param Value : Valor de Offset que se desea establecer para el eje correspondiente.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
#define adlx345_setoffsetZ(pHdl,Value)    adlx345_write_register(pHdl, adxl345_REG_OFSZ,Value)


/*******************************************************************************//**
* \def adlx345_getXf32(pHdl)
* \brief Macro funcion para Obtener la aceleraccion en el eje \b x, en formato con 
* punto flotante y en unidades de [m/s^2].
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return aceleracion en el eje \b x en unidades [m/s^2] y formato punto flotante.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_getXf32(pHdl)    (adlx345_read_i16(pHdl, adxl345_REG_DATAX0)*adlx345_FLOAT32_ESCALAR)

/*******************************************************************************//**
* \def adlx345_getYf32(pHdl)
* \brief Macro funcion para Obtener la aceleraccion en el eje \b y, en formato con 
* punto flotante y en unidades de [m/s^2].
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return aceleracion en el eje \b y en unidades [m/s^2] y formato punto flotante.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_getYf32(pHdl)    (adlx345_read_i16(pHdl, adxl345_REG_DATAY0)*adlx345_FLOAT32_ESCALAR)

/*******************************************************************************//**
* \def adlx345_getZf32(pHdl)
* \brief Macro funcion para Obtener la aceleraccion en el eje \b z, en formato con 
* punto flotante y en unidades de [m/s^2].
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return aceleracion en el eje \b z en unidades [m/s^2] y formato punto flotante.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_getZf32(pHdl)    (adlx345_read_i16(pHdl, adxl345_REG_DATAZ0)*adlx345_FLOAT32_ESCALAR)


/*******************************************************************************//**
* \def adlx345_get_id(pHdl)
* \brief Macro funcion para obtener el ID del sensor.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return ID del sensor, desde su registro interno .
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_get_id(pHdl)     adlx345_read_register(pHdl,adxl345_REG_DEVID)

/*******************************************************************************//**
* \def adlx345_get_range(pHdl)
* \brief Macro funcion para obtener el rango establecido actualemente en sensor.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return Rango actual, con el cual esta operando el sensor.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_get_range(pHdl)  (adlx345_read_register(pHdl,adxl345_REG_DATA_FORMAT) & 0x03)

/*******************************************************************************//**
* \def adlx345_get_rate(pHdl)
* \brief Macro funcion para obtener el data rate establecido actualemente en sensor.
* \param pHdl : Puntero al Handler correspondiente al acelerometro.
* \return data rate actual, con el cual esta operando el sensor (comunicacion con el master del bus).
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/
#define adlx345_get_rate(pHdl)   (adlx345_read_register(pHdl,adxl345_REG_BW_RATE) & 0x0F)


/* Si en algun momento lo pudo inicializar al sensor */
bool_t adlx345_check_init(adlx345_hdl_t * pHdl,bool_t clean);

#if (dlx345_VERSION == 1)



#endif /* #if (dlx345_VERSION == 1) */







#else /* #if (dlx345_i2c_ENABLE == 1)   */

#warning "APIs no definidas a un para el bus de datos SPI "
#endif /* #if (dlx345_i2c_ENABLE == 1)   */
/*
 * FIXME pasar la calibracion como una funcion que depende de systick, para las demoras.
 * 
 */


/*
* ============================[close, cplusplus]============================
*/
#ifdef __cplusplus
}
#endif
/*==============================[end of file]==============================*/
/*
* 
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* ========================================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #ifndef __adlx345_h__ */

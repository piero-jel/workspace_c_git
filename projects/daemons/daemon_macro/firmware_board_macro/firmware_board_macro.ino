 #define __main_project__
 /*******************************[ Source file example_01.pro ]*************************************//**
 * \addtogroup firmware_board_macro_02
 * @{
 * @copyright 
 * ${date}, Luccioni Jesús Emanuel. \n
 * All rights reserved.\n
 * This file is part of port module.\n
 * Redistribution is not allowed on binary and source forms, with or without 
 * modification.\n
 * Use is permitted with prior authorization by the copyright holder.\n
 * \file firmware_board_macro_02.ino
 * \brief Ejemplo de como realizar el Blink de un LED, con el uso de las primitivas de
 * Arduino.
 * \version 01v01d01
 * \date dom 30 de junio 2019  
 * \note none
 * \author JEL, Jesus Emanuel Luccioni
 * \li <b> piero.jel@gmail.com <\b>
 * @} doxygen end group definition
 *************************************************************************************/
/*
 *
 **********************************************************************************************
 *
 * ==========================[ BEGIN, Add header file ]==========================
 *
 * ******************************************************************************************** */

/**/

#include "src/stdctype.h"
#include "src/systick.h"
/*=====[ Header para el acelerometro ADXL345 ]=====*/
#include "src/adlx345.h"

#include <math.h>

#include "src/powersave.h"

#include "src/stdc.h"

#define project_version     0
#include "firmware_board_macro.h"

/*
 * **********************************************************************************************
 *
 * ==========================[ END, Add header file ]==========================
 *
 * ******************************************************************************************** */



#define BOARD_NAME_ID     "TempBoard"




/*
 * ******************************************************************************//**
 * \fn void setup(void);
 * \breif funcion que es invocada para realizar la configuracion 
 * pre incio del sistema.
 * **********************************************************************************/
void setup()
{
//   uint8_t retry;
  WATCH_DOG_TIMER(DISABLE);
  /* Inicializamos el modulo p/sleep() */
  powersave_init();
  /* Cargasmo los Flags con los perifericos que ahorraran eneriga */
  powersave_set(powerflags,powersave_SET);
  serial_flg = 0;
  /* Configuramos el tty */
  while(!Serial);    
  Serial.begin(115200);
  Serial.setTimeout(TERMINAL_TIME_OUT);  
  /* Para este hardware la palca se presenta de esta forma,
   * ya que al abrir el puerto de comunicacion desde el lado 
   * de la PC inicia el hardware. 
   * Por lo que en este punto debemos enviar el nombre.
   * Para otros debemos esperar la trama de query */  
  chip_ADC(INIT);
  accelerometer_init();
#if 0  
  acc_msg = "No se Detecto el Sensor ADXL345 ... verificar conexiones!";
  retry = 0;
  while(!accelerometer_init() && retry++ < 10 )
  {
//     msg_index = FLAG_MSG_ADXL345_COM_ERROR;
//     Serial.println("No se Detecto el Sensor ADXL345 ... verificar conexiones!");
    systick_pause_ms(1000);    
  }/*
  if(retry != 10)
    acc_msg = "Sensor ADXL345 conectado";*/
#endif    
  /* establecemos el wdt, contemplando el boot time */
  WATCH_DOG_TIMER(ENABLE,8s);
}

/*
 * ******************************************************************************//**
 * \fn void loop(void);
 * \brief funcion que es invocada dentro de un loop infinito, en la cual se deben 
 * actualizar todas las FSM (Finite State Machine, maquina de estados finita) que 
 * componen al Sistema. 
 * **********************************************************************************/
void loop()
{    
  adc_update();
  accelerometer_update();
  update_rxserial();
  update_txserial(0);
  
  

  
  
  
  
  WATCH_DOG_TIMER(RESET);
  
  /* Si utilizamos la terminal
   * debemos asegurarnos de termiar todo 
   * el envio de datos antes de entrar en sleep() 
   * se recomienda usar el Serial.flush(); siempre que envie
   * datos.
   */
  powersave_sleepwfi();
}

/*
 * >> update_rxserial() : Si recibimos algo lo analizamos para setear flags globales y en caso de 
 *    ser necesario enviamos el ID.
 * 
 * >> update_txserial(uint8_t arg) :  se encarga de actualizar el envio de datos en funcion de los 
 *    flags globales y los tiempos. Este es el callback llamado por el modulo "switch" con el flag 1, 
 *    mediante el cual indica que se debe actualizar de forma inmediata.
 *    Si arg = 0, debe verificar los flags (armado de la trama) y el timeout.
 * 
 * 
 * podemos agregar los target:
 *    + id
 *    + stop
 *    + reset
 */
void update_rxserial(void)
{
  uint8_t i;
  char buff[32];
  /* esperamos por la consulta del id, */      
  i = Serial.readBytes(buff,sizeof(buff));
  if(i == 0) return;
  if(!stdc_strcmp("id",buff,sizeof(buff)))
    return;
  Serial.println(BOARD_NAME_ID);  
  serial_flg |= SERIAL_TXENABLE;
  Serial.flush();  
}


/** 
 * Actualizacion del envio de datos por puerto serie 
 */
void update_txserial(uint8_t arg)
{
  static tick_t acu = 0;
  if(!(serial_flg & SERIAL_TXENABLE))
    return;
  
  if(arg & SERIAL_UPDATE_FORCED )
  {
    SendData();
    systick_Init(acu,ms);
    return;
  }
    
  /* Debemos considerar que nos pida el id en algun momento indeterminado */
  if(systick_TimeOut_ms(&acu,1000,TRUE))
    return;
  SendData();  
}

void SendData(void)
{
  uint8_t i;
  String tmp = "";   
  i = 0;
  Serial.print("<T:");
  while(i < chip_ADC_Nro_CHANNELS)
  {     
    tmp = " " + String(i) + "- " + String(adc_readval[i]) + " ";
    Serial.print(tmp);
    i++;
  }    
  tmp = " ,Ai: x- " + String(acc_x) + " y- " + String(acc_y) + " z- " + String(acc_z) + " ";
  Serial.print(tmp);
  tmp = " ,Af: x- " + String(accf_x,2) + " y- " + String(accf_y,2) + " z- " + String(accf_z,2) + " "/*+ ">"*/;
  Serial.print(tmp);
  acc_msg += ">";
  Serial.println(acc_msg);  
  Serial.flush();
}


void adc_update(void)
{
  static uint8_t item = 0;  
  static uint32_t readval;  
  static tick_t acums;
  uint8_t i;
  uint32_t tmp;
  /* Ingresamos cada 20[mS] */
  if( systick_TimeOut_ms(&acums,chip_ADC(UPDATE_TIME),TRUE)) return;
  /* Seleccionamos el canal del mux */
  mux_set(item);
  
  /* Iniciamos la conversion */
  i = 8;
  readval = 0;  
  while(i)
  {
    readval += analogRead(chip_ADC_PIN) ;
    i--;
  }
  adc_readval[item] = adc_procces_data(readval);
  item++;
  if(item == chip_ADC_Nro_CHANNELS) item = 0;
}


float adc_procces_data(uint32_t samples)
{
  float rval;
  float tmp2,Rm;  
  tmp2 = (float) ((chip_ADC_RESOLUCION/(float) samples) -1) ;
  /* */
  rval = log(tmp2);
  //tmp2 = rval * TH + BETHA;
  tmp2 = TERMISTOR_BETHA - rval * TERMISTOR_TH ;
  rval = TERMISTOR_THxBETHA/tmp2;

  return rval - 273.15;
}

void mux_init(void)
{
  uint8_t i = 0;
  while(i < sizeof(mux_pins))
  {
    pinMode(mux_pins[i],OUTPUT);
    i++;
  }
}

void mux_set(uint8_t channel)
{
  uint8_t i;
  /*-- deshabiltmas el mux */
  digitalWrite(mux_PIN_nE,HIGH);
  i = 0;  
  while(i<4)
  {
    if(channel & (0x01<<i))
      digitalWrite(mux_pins[i],HIGH);    
    else
      digitalWrite(mux_pins[i],LOW);  
    i++;    
  }
  digitalWrite(mux_PIN_nE,LOW);
}


bool_t accelerometer_init(void)
{
  static bool_t calibracion = FALSE;
  
  if(!adlx345_init(&acc,0x53,TRUE))
  {
    if(adlx345_check_init(&acc,FALSE))
      acc_msg = "Se Perdio la comunicacion con el Accelerometro ...";
//       Serial.println("Se Perdio la comunicacion con el Accelerometro ..."); 
    else
      acc_msg = "No se Pudo establecer comunicacion con el Accelerometro ...";
//       Serial.println("No se Pudo establecer comunicacion con el Accelerometro ...");   
    
//     Serial.flush();
    return FALSE;
  }
  acc_msg = "Sensor ADXL345 conectado";
  //adlx345_config(&acc,adlx345_RANGE_16_G,adlx345_DATARATE_50_HZ);  
  adlx345_config(&acc,adlx345_RANGE_16_G,adlx345_DATARATE_100_HZ);  
  if(!calibracion)
  {
    accelerometer_calibrated();
    calibracion = TRUE;
  }    
  return TRUE;  
}


void accelerometer_update(void)
{
  static uint8_t st,i;
  static tick_t acums, times;
     
  switch(st)
  {
    default:
      st = 0;
    case 0:      
      if(adlx345_checkdevices(&acc))
      {        
        st = 2;
        return;
      }      
      times = 1000;
      break;
   
    case 1:
      if( systick_TimeOut_ms(&acums,times,TRUE)) return;
      accelerometer_init();
             
      st = 0;
      return;
      
    case 2:
      i = 0;
      times = 10;  
      break;
      
    case 3:
      if( systick_TimeOut_ms(&acums,times,TRUE)) return;
      /* Escala de G/256LSB, lo dividimos por 256 y obtenemos la aceleracion */
      acc_x = adlx345_getXi16(&acc); 
      acc_y = adlx345_getYi16(&acc);
      acc_z = adlx345_getZi16(&acc);
      /* Escala en m/s²*/
      accf_x = adlx345_getXf32(&acc);
      accf_y = adlx345_getYf32(&acc);
      accf_z = adlx345_getZf32(&acc);
      st = 0;
      return;       
  }  
  st++;
}



void accelerometer_calibrated(void)
{
/* en la posicion de reposo de inicio debemos 
 *  tomar 10 mediciones con un perido de 10 ms
 *  promediar y obtenemos los 
 *    X_0g
 *    Y_0g
 *    Z+1g
 * FIXME: debemos considerar almacenar en memoria EEPROM los valores
 * Desde donde lo toma el acelerometro al iniciar.
 * 
*/  
  int8_t X_0g,Y_0g,Z_0g,Zp1g;
  float tmp;
  int8_t i;
  String strTmp;
  X_0g = 0;
  Y_0g = 0;
  Zp1g = 0;
  i = 0;
  while(i < 10)
  {
    X_0g += adlx345_getXi16(&acc);
    Y_0g += adlx345_getYi16(&acc);
    Zp1g += adlx345_getZi16(&acc);
    i++;
    systick_pause_ms(1);
  }  
  //
  X_0g = X_0g / -10;
  
  Y_0g = Y_0g / -10;
    
  Zp1g = Zp1g / -10;
    
  tmp = ( accelerometer_SENSIBILIDAD * 15.6F ) / 1000.0F ;
  Z_0g = ((int8_t) tmp) - Zp1g ;
  
  /*
  adlx345_setoffsetX(&acc,X_0g);
  adlx345_setoffsetY(&acc,Y_0g);
  adlx345_setoffsetZ(&acc,Z_0g); */
  
  
#if (DEBUG_ON == 1  )
  strTmp = "<Ai: x- " + String(adlx345_getoffsetX(&acc)) + " y- " +\
           String(adlx345_getoffsetY(&acc)) + " z- " + String(adlx345_getoffsetZ(&acc)) + " ";
            
  Serial.print(strTmp);
  strTmp = " ,Af: x- " + String(X_0g) + " y- " + String(Y_0g) + " z- " + String(Z_0g) + ">";
  
  Serial.println(strTmp);
  Serial.flush();
#endif /*#if (DEBUG_ON == 1  )*/
}

/*
 * ====================================================================================================================
 */

/*
 * **********************************************************************************************
 *
 * ==========================[ begin, local Function declaration ]==========================
 *
 * **********************************************************************************************
 */




/*
 *
 * **********************************************************************************************
 *
 * ==========================[ End, local Function Definition ]==========================
 *
 * ******************************************************************************************** */

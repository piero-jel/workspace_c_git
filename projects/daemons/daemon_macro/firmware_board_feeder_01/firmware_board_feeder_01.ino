 #define __main_project__
 /*******************************[ Source file example_01.pro ]*************************************//**
 * \addtogroup firmware_feeder_macro_02
 * @{
 * @copyright 
 * ${date}, Luccioni Jesús Emanuel. \n
 * All rights reserved.\n
 * This file is part of port module.\n
 * Redistribution is not allowed on binary and source forms, with or without 
 * modification.\n
 * Use is permitted with prior authorization by the copyright holder.\n
 * \file firmware_feeder_macro_02.ino
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
#include "./src/stdctype.h"
#include "./src/systick.h"
#include "./src/switch.h"




#include "./src/powersave.h"

#include "./src/stdc.h"

#define project_version     0
#include "firmware_board_feeder.h"

/*
 * **********************************************************************************************
 *
 * ==========================[ END, Add header file ]==========================
 *
 * ******************************************************************************************** */
switch_hdl_sT hdlSw1;
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
  /* Incializamos los SW */  
  switch_minit(hdlSw1,pin_SW0,sw_on,NULL);  



  
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
  update_rxserial();
  update_txserial(0);
  
  /* Update el SW */
  switch_update(&hdlSw1);
  
  
  
  
  WATCH_DOG_TIMER(RESET);  
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
  if(!stdc_strcmp(QUERY_ID,buff,sizeof(buff)))
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
  if(systick_TimeOut_ms(&acu,TIME_UPDATE,TRUE))
    return;
  SendData();  
}

/** 
 */
void sw_on(void * arg)
{
  /* se Acciono el SW, no hacemos uso del argumento */
  notifySW = "on";
  update_txserial(SERIAL_UPDATE_FORCED);
  notifySW = "off";
}



void SendData(void)
{
  uint8_t i;
  String tmp = "";   
  i = 0;
  Serial.print("<SW0:");
  tmp = " " + notifySW + " " + ">";
  Serial.println(tmp);
  /*tmp += ">";
  Serial.println(tmp);  */
  Serial.flush();
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

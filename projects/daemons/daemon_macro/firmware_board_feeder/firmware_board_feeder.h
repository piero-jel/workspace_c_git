 /**********************************************************************************//**
 * \addtogroup firmware_feeder_macro_02
 * @{ 
 * \copyright  
 * 2019, Luccioni Jesús Emanuel \n
 * All rights reserved.\n 
 * This file is part of feeder_macro.h .\n
 * Redistribution is not allowed on binary and source forms, with or without \n
 * modification. Use is permitted with prior authorization by the copyright 
 * holder. &copy;
 * \file feeder_macro.h
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
 * \brief 
 * \version 01v01d01.
 * \date Martes 18 de Junio, 2019.
 * \pre pre, debemos contener dentro de la carpeta "libraries" del ide Arduino
 * la carpeta que acompaña a este proyecto, llamda modules.
 * Basicamente debemos copiar la carpeta "modules" y pegarla en :
    \li Linux /home/${USER}/${ARDUINO-VERSION}/libraries/
    \li Windows C:\\"Program Files (x86)\"\Arduino\libraries
 * \bug Por ahora no presenta bug dentro del Hambito de Prueva. Para el mismo se utilizo
 * la version "arduino-1.8.13" del Ide de Arduino. Disponible en la pagina
 * <a href="https://www.arduino.cc/en/Main/Software">Arduino Ide Download</a>
 * \warning mensaje de precaucion, warning.
 * \note nota.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * @} doxygen end group definition 
 * ********************************************************************************** */
 
#ifndef __feeder_macro_h__
#define __feeder_macro_h__

/*
 * ============================[Open, cplusplus]============================
 */
#ifdef __cplusplus
extern "C" {
#endif 

#include <Arduino.h>

#define DEBUG_ON  1

/*
 *
 **********************************************************************************************
 *
 * ==========================[ BEGIN, typedef for project ]==========================
 *
 * ******************************************************************************************** */





/*
 * **********************************************************************************************
 *
 * ==========================[ END, typedef for project ]==========================
 *
 * ******************************************************************************************** */
 
 
 
 /*
 *
 **********************************************************************************************
 *
 * ==========================[ BEGIN, Labels for project config ]==========================
 *
 * ******************************************************************************************** */
#define BOARD_NAME_ID           "FeederBoard"
#define QUERY_ID               "id"
#define TIME_UPDATE             1000 /* mili segundos */

#define TERMINAL_TIME_OUT       5 /* esperasmo por 5ms*/
#define pin_SW0                 7
#define SERIAL_TXENABLE         0x01
#define SERIAL_UPDATE_FORCED    0x02
/*
 * **********************************************************************************************
 *
 * ==========================[ END, Labels for project config ]==========================
 *
 * ******************************************************************************************** */ 
 /*
 *
 **********************************************************************************************
 *
 * ==========================[ BEGIN, variables      ]==========================
 *
 * ******************************************************************************************** */
 
/**
* \var powerflags;
* \brief Variable global que usamos para establecer los flags de reducion de consumo de energia. 
* <b> El unico periferico que no es puesto dentro del savepower es el TIMER 0 </b>
* \version 01v01d00
* \note  Del Modulo de ahorro de energia dejamos afuera los modulos:
 *  TIMER0 : El systick del sistema
 *  USART0 : Terminal por la cual esperamos peticion desde el host
* \warning mensaje de "warning".
* \date Martes 18 de Junio, 2019.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
const powersave_flag_t powerflags = powersave_ADC | /*powersave_USART0 |*/ powersave_SPI | powersave_TIMER1 | powersave_TIMER2 | powersave_I2C;

String notifySW = "off";
uint8_t serial_flg = 0;
/*
 * **********************************************************************************************
 *
 * ==========================[ END  , variables      ]==========================
 *
 * ******************************************************************************************** */ 
/*
 *
 **********************************************************************************************
 *
 * ==========================[ BEGIN, Macro Function ]==========================
 *
 * ******************************************************************************************** */


/*
 * **********************************************************************************************
 *
 * ==========================[ END, Macro Function ]==========================
 *
 * ******************************************************************************************** */
 
 


/*
 *
 * *********************************************************************************************
 *
 * ==========================[ BEGIN, Function declaration ]==========================
 *
 * ******************************************************************************************** */
void sw_on(void * arg);
void update_rxserial(void);
void update_txserial(uint8_t arg);
void SendData(void);
/*
 *
 **********************************************************************************************
 *
 * ==========================[ END, Function declaration ]==========================
 *
 * ******************************************************************************************** */

/*
 * ============================[close, cplusplus]============================
 */
#ifdef __cplusplus
}
#endif
/*==================[end of file]============================================*/
#endif /* #ifndef __main_h__ */

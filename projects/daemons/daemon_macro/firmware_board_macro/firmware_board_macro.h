 /**********************************************************************************//**
 * \addtogroup firmware_board_macro_02
 * @{ 
 * \copyright  
 * 2019, Luccioni Jesús Emanuel \n
 * All rights reserved.\n 
 * This file is part of example_02.h .\n
 * Redistribution is not allowed on binary and source forms, with or without \n
 * modification. Use is permitted with prior authorization by the copyright 
 * holder. &copy;
 * \file example_02.h
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
 * \brief 
 * \details 

 * \version 01v01d01.
 * \date domingo 18 de Octubre, 2020.
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
 
#ifndef __example_02_h__
#define __example_02_h__

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
 * ==========================[ Begin, typedef for project ]==========================
 *
 * ******************************************************************************************** */





/*
 * **********************************************************************************************
 *
 * ==========================[ End, typedef for project ]==========================
 *
 * ******************************************************************************************** */
 
 
 
 /*
 *
 **********************************************************************************************
 *
 * ==========================[ Begin, Labels for project config ]==========================
 *
 * ******************************************************************************************** */







/*
 * **********************************************************************************************
 *
 * ==========================[ End, Labels for project config ]==========================
 *
 * ******************************************************************************************** */
 
 /*
 *
 **********************************************************************************************
 *
 * ==========================[ Begin, Add Macro Labels ]==========================
 *
 * ******************************************************************************************** */

 /*
 * ------------------------------------------------------------------------------------
 *
 * ++++++++++++++++++++++++++[ Adc mutiplexor y termistor ]++++++++++++++++++++++++++
 *
 ------------------------------------------------------------------------------------ */
#define chip_ADC_RESOLUCION          8192.00//1024
#define TERMISTOR_RH            100000.00 /* Resistencia a 298,15 K */
#define TERMISTOR_BETHA         3950.00
#define TERMISTOR_TH            298.15
#define TERMISTOR_THxBETHA      1177692.5

#define chip_ADC_UPDATE_TIME()  20  /* */
#define chip_ADC_RESOLUTION()   1024 /* 10-Bits */
#define chip_ADC_Vref()         5000 /* 10-Bits */
#define chip_ADC_INIT()\
{\
  mux_init();\
  analogReference(DEFAULT);\
} 

/* =====[ Configuracion del ADC ]===== */
#define chip_ADC(Action, ...) chip_ADC_##Action(__VA_ARGS__)

#define chip_ADC_PIN           A0
#define chip_ADC_Nro_CHANNELS  16
//uint16_t adc_readval[ACD_Nro_CHANNELS] = {0};
float adc_readval[chip_ADC_Nro_CHANNELS] = {0};

/* =====[ Configuracion de pines del Mux ]===== */
#define mux_PIN_S0    5
#define mux_PIN_S1    6
#define mux_PIN_S2    8
#define mux_PIN_S3    7
#define mux_PIN_nE    9

const uint8_t mux_pins[] = {mux_PIN_S0,mux_PIN_S1,mux_PIN_S2,mux_PIN_S3,mux_PIN_nE};

void adc_update(void);
#define VERSION_adc_procces_data    2
float adc_procces_data(uint32_t samples);
void mux_init(void);
void mux_set(uint8_t channel);



 /*
 * ------------------------------------------------------------------------------------
 *
 * ++++++++++++++++++++++++++[ Acelerometro ]++++++++++++++++++++++++++
 *
 ------------------------------------------------------------------------------------ */
#define accelerometer_RANGO         32 /* +-16g */
#define accelerometer_LSB           8192 /* 2 ^13  */
#define accelerometer_SENSIBILIDAD  256 /* Sensibilidad = 1/Resolucion = 8192 [LSB] / 32 [g] = 256 [LSB/g]  */
#define accelerometer_count 


adlx345_hdl_t acc = {0};
int16_t acc_x = 0,acc_y = 0,acc_z = 0;
float accf_x = 0,accf_y = 0,accf_z = 0;
String acc_msg;

bool_t accelerometer_init(void);
void accelerometer_update(void);
void accelerometer_calibrated(void);





// #define TERMINAL_TIME_OUT 5 /* esperasmo por 5ms*/
#define SERIAL_TXENABLE         0x01
#define SERIAL_UPDATE_FORCED    0x02
uint8_t serial_flg = 0;
void update_rxserial(void);
void update_txserial(uint8_t arg);

void SendData(void);

 /*
 * ------------------------------------------------------------------------------------
 *
 * ++++++++++++++++++++++++++[ Consola Serial ]++++++++++++++++++++++++++
 *
 ------------------------------------------------------------------------------------ */








/*
 * **********************************************************************************************
 *
 * ==========================[ End, Add Macro Labels ]==========================
 *
 * ******************************************************************************************** */
 
/*
 *
 **********************************************************************************************
 *
 * ==========================[ Begin, Macro Function ]==========================
 *
 * ******************************************************************************************** */




/*
 * **********************************************************************************************
 *
 * ==========================[ End, Macro Function ]==========================
 *
 * ******************************************************************************************** */
 
 

/**
* \var powerflags;
* \brief Variable global que usamos para establecer los flags de reducion de consumo de energia. 
* <b> El unico periferico que no es puesto dentro del savepower es el TIMER 0 </b>
* \version 01v01d00
* \note nota.
* \warning mensaje de "warning".
* \date day dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */

/* 
 * Del Modulo de ahorro de energia dejamos afuera los modulos:
 *  TIMER0 : El systick del sistema
 *  USART0 : Terminal por la cual esperamos peticion desde el host
 */
  const powersave_flag_t powerflags = powersave_ADC | /*powersave_USART0 |*/ powersave_SPI | powersave_TIMER1 | powersave_TIMER2 | powersave_I2C;
  
#define TARGET_UPDATE "status\r"  
#define TERMINAL_TIME_OUT 5 /* esperasmo por 5ms*/
  
uint8_t msg_index = 0;  
const char *msg[] = 
{
  /* 00   0x10 */  "ADXL345 comunicacion Ok"
  /* 01   0x20 */ ,"No se Detecto el Sensor ADXL345 ... verificar conexiones!"
  /* 02   0x40 */ ,"No se detecto Termistor"
};

#define ADXL345_RETRY_CHECK         10
#define MSG_FLAG_ADXL345_COM_OK     0x10
#define MSG_FLAG_ADXL345_COM_ERROR  0x20
#define MSG_FLAG_TERMISTOR_OP       0x40
#define MSG_FLAG_MASK               0x70
#define MSG_FLAG_nMASK              0x8F





 
 
 
/*
 *
 * *********************************************************************************************
 *
 * ==========================[ begin, Function declaration ]==========================
 *
 * ******************************************************************************************** */
 














/*
 *
 **********************************************************************************************
 *
 * ==========================[ End, Function declaration ]==========================
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

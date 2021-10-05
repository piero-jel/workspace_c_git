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
* \file powersave.h
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


#ifndef __powersave_h__
#define __powersave_h__ /**<@brief definimos el header file, para evitar includes recursivos */
/* 
* ***** [ Add header files ] *****
*/
#include <Arduino.h>
#include "stdctype.h"
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

  
 /*
  * Board con uC AVR :
  *   >> ARDUINO_AVR_MICRO
  *   >> ARDUINO_AVR_NANO
  *   >> ARDUINO_AVR_MEGA
  * 
  * FIXME Board con uC CortexM, aun no cargado
  *   >> ARDUINO_ARCH_SAM   
  */ 

/**
 * \def powersave_ADC 
 * \brief Labels o Flags para agragar, quitar el modulo ADC de la funciones de reduccion de energia.
 * \version 01v01d00. 
 * \date lunes 15 de Febrero, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
/**
 * \def powersave_USART0 
 * \brief Labels o Flags para agragar, quitar el modulo USART0 de la funciones de reduccion de energia.
 * \version 01v01d00. 
 * \date lunes 15 de Febrero, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
/**
 * \def powersave_SPI 
 * \brief Labels o Flags para agragar, quitar el modulo SPI de la funciones de reduccion de energia.
 * \version 01v01d00. 
 * \date lunes 15 de Febrero, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
/**
 * \def powersave_I2C 
 * \brief Labels o Flags para agragar, quitar el modulo I2C de la funciones de reduccion de energia.
 * \version 01v01d00. 
 * \date lunes 15 de Febrero, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */

/**
 * \def powersave_TWI 
 * \brief Labels o Flags para agragar, quitar el modulo I2C de la funciones de reduccion de energia.
 * \version 01v01d00. 
 * \date lunes 15 de Febrero, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
/**
 * \def powersave_TIMER0 
 * \brief Labels o Flags para agragar, quitar el modulo TIMERn de la funciones de reduccion de energia.
 * \version 01v01d00. 
 * \date lunes 15 de Febrero, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
/**
 * \def powersave_TIMER1
 * \brief Labels o Flags para agragar, quitar el modulo TIMERn de la funciones de reduccion de energia.
 * \version 01v01d00. 
 * \date lunes 15 de Febrero, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
/**
 * \def powersave_TIMER2
 * \brief Labels o Flags para agragar, quitar el modulo TIMERn de la funciones de reduccion de energia.
 * \version 01v01d00. 
 * \date lunes 15 de Febrero, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
/**
 * \def powersave_CLEAN
 * \brief Labels o Flags para limpiar el registro de modulos adjuntados a la reduccion de consumo de energia.
 * \version 01v01d00. 
 * \date lunes 15 de Febrero, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */

  /**
  * \var powersave_flag_t;
  * \brief redefinicion del tipo de dato para retener los flags de ahoro de energia, que 
  * perifericos son los que formaran parte del grupo de power save. 
  * \version 01v01d01.
  * \note nota.
  * \warning mensaje de "warning".
  * \date \date Domingo 24 de Octubre, 2020.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */ 


#if (defined(ARDUINO_ARCH_AVR))
#include <avr/sleep.h>
#include <avr/power.h>

  #if (defined(ARDUINO_AVR_NANO))
    /* Listado de perifericos del atmega328P los cuales se pueden Up/Down
     * PRR – Power Reduction Register
     *      
     *    PRTWI PRTIM2 PRTIM0 – PRTIM1 PRSPI PRUSART0 PRADC   
     */
    #define powersave_ADC           0x01
    #define powersave_USART0        0x02
    #define powersave_SPI           0x04
    #define powersave_TIMER1        0x08
    #define powersave_TIMER0        0x20
    #define powersave_TIMER2        0x40
    #define powersave_TWI           0x80
    // TODO: para compatibilidad con otros micros controladores
    #define powersave_I2C           0x80 
    /* TODO FLAG para limpiar el registro local */
    #define powersave_CLEAN         0x00

    
    /*
    * \var powersave_flag_t;
    * \brief redefiniicion del tipo de dato para retener los flags de power 
    * \version AAvBBdCC.
    * \note nota.
    * \warning mensaje de "warning".
    * \date day dayOfMonth de month, years.
    * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
    * \par meil
    * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */    
    typedef uint8_t powersave_flag_t ;    
    
    

  #elif (defined(ARDUINO_AVR_MICRO))
    /* Listado de perifericos del atmega2560 los cuales se pueden Up/Down
     * PRR0 – Power Reduction Register
     *  PRTWI - PRTIM0 – PRTIM1 PRSPI - PRADC  */
    #define powersave_ADC           0x0001
    #define powersave_SPI           0x0004
    #define powersave_TIMER1        0x0008
    #define powersave_TIMER0        0x0020    
    #define powersave_TWI           0x0080
    // TODO: para compatibilidad con otros micros controladores
    #define powersave_I2C           0x0080
    /* TODO: La reduccion para el TIMER2 y USART0 no esta disponible p/este micro 
     * Para evitar errores de compilacion lo establecemso con el valor 0x0000
     * el cual no realiza camios.
     */
    #define powersave_TIMER2        0x0000
    #define powersave_USART0        0x0000
    /* Listado de perifericos del atmega2560 los cuales se pueden Up/Down
     * PRR1 – Power Reduction Register
     *  PRUSB – PRTIM5 PRTIM4 PRTIM3 - - PRUSART1  */
    #define powersave_USART1        0x0100
    #define powersave_TIMER3        0x0800
    #define powersave_TIMER4        0x1000
    #define powersave_PRUSB         0x8000
    /* TODO FLAG para limpiar el registro local */
    #define powersave_CLEAN         0x0000

    
    /*
    * \var powersave_flag_t;
    * \brief redefiniicion del tipo de dato para retener los flags de power 
    * \version AAvBBdCC.
    * \note nota.
    * \warning mensaje de "warning".
    * \date day dayOfMonth de month, years.
    * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
    * \par meil
    * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */    
    typedef uint16_t powersave_flag_t ;     
    
    
  #elif (defined(ARDUINO_AVR_MEGA2560))
    /* Listado de perifericos del atmega2560 los cuales se pueden Up/Down
     * PRR0 – Power Reduction Register
     *  PRTWI PRTIM2 PRTIM0 – PRTIM1 PRSPI PRUSART0 PRADC
     *  TIMER0 {Timer/counter 8-Bis | pwm }
     *  TIMER1 {Timer/counter 16-Bis | pwm }
     *  TIMER2 {Timer/counter 8-Bis | pwm | Asynchronous Operation }
     *  SPI 
     *  USART0
     *  TWI -> I2C 
     *  AC     Analog Comparator
     *  ADC      */
    #define powersave_ADC           0x0001
    #define powersave_USART0        0x0002
    #define powersave_SPI           0x0004
    #define powersave_TIMER1        0x0008
    #define powersave_TIMER0        0x0020
    #define powersave_TIMER2        0x0040
    #define powersave_TWI           0x0080
    // TODO: para compatibilidad con otros micros controladores
    #define powersave_I2C           0x0080
        /* Listado de perifericos del atmega2560 los cuales se pueden Up/Down
     * PRR1 – Power Reduction Register
     *  – – PRTIM5 PRTIM4 PRTIM3 PRUSART3 PRUSART2 PRUSART1
     *  TIMER0 {Timer/counter 8-Bis | pwm }
     *  TIMER1 {Timer/counter 16-Bis | pwm }
     *  TIMER2 {Timer/counter 8-Bis | pwm | Asynchronous Operation }
     *  SPI 
     *  USART0
     *  TWI -> I2C 
     *  AC     Analog Comparator
     *  ADC      */
    #define powersave_USART1        0x0100
    #define powersave_USART2        0x0200
    #define powersave_USART3        0x0400
    #define powersave_TIMER3        0x0800
    #define powersave_TIMER4        0x1000
    #define powersave_TIMER5        0x2000
    /* TODO FLAG para limpiar el registro local */
    #define powersave_CLEAN         0x0000
    

    
    /*
    * \var powersave_flag_t;
    * \brief redefiniicion del tipo de dato para retener los flags de power 
    * \version AAvBBdCC.
    * \note nota.
    * \warning mensaje de "warning".
    * \date day dayOfMonth de month, years.
    * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
    * \par meil
    * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */ 
    typedef uint16_t powersave_flag_t ;    

  #endif /**/


#else /* #if (defined(ARDUINO_ARCH_AVR)) */
    
  #warning "Otro micro, debemos verificar las condiciones de energia power save "    

#endif/* #if (defined(ARDUINO_ARCH_AVR)) */
  
/**
* \enum powersave_action_t
* \brief Enumeracion para establecer la accion a realizar con los flags pasado a
* funciones como parte del listado de argumentos.
* Elementos que componen la enumeracion:
*  \li \ref powersave_ENABLE
*  \li \ref powersave_DISABLE
*  \li \ref powersave_SET
* \version 01v01d01.
* \warning mensaje de "warning".
* \date Domingo 24 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  powersave_ENABLE = 0,   /**<@brief Etiqueta para \b habilitar el o los modulos especificados en el flags. */
  powersave_DISABLE,      /**<@brief Labels Para \b deshabilitar el o los modulos, en el flags. */
  powersave_SET           /**<@brief Etiqueta para \b Establecer los flags con los modulos pasados, para la reduccion de energia.*/
} powersave_action_t;


  
/*******************************************************************************//**
* \fn void powersave_init(void);
* \brief Funcion que inicializa el modulo de ahorro de eneriga del micro controlador
* este inicia la variable local.
* \return nothing.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 24 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
  const powersave_flag_t powerflags = powersave_ADC | powersave_USART0 | powersave_SPI | powersave_TIMER1 | powersave_TIMER2;
  void setup()
  {
    WATCH_DOG_TIMER(DISABLE);
    powersave_init();
    powersave_set(powerflags);
    blinkyled_init();
    blinkyled_set(2);
    WATCH_DOG_TIMER(ENABLE,8s);
  }
  //... more code
</PRE>
*************************************************************************************/
void powersave_init( void );


/**
* 
* ******************************************************************************* 
* \fn void powersave_set(powersave_flag_t flg,powersave_action_t action);
* \brief descripcion breve sobre la funcion, fn_name().  
* \param flg : Flags que contine los Modulos que formaran parte de la reduccion
* de energia durante un sleep (estos no podran despertar el core en el 
* proceso de sleep). \n
*   should be:
*     \li \ref powersave_USART0
*     \li \ref powersave_ADC           
*     \li \ref powersave_SPI
*     \li \ref powersave_TIMER1
*     \li \ref powersave_TIMER0
*     \li \ref powersave_TIMER2
*     \li \ref powersave_I2C           
*     \li \ref powersave_CLEAN         
* \param action : Accion a realizar con los flags pasado en el arguemtno \b flg.
*   should be:
*     \li \ref powersave_ENABLE
*     \li \ref powersave_DISABLE
*     \li \ref powersave_SET
* 
* \return nothing
* \version 01v01d01.
* \note note.
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
  //... more code here
  blinkyled_set(2);
  WATCH_DOG_TIMER(ENABLE,2s);
}
void loop()
{  
  blinkyled_update();  
  // ...
  // more code ...
  WATCH_DOG_TIMER(RESET);   
  powersave_sleepwfi();
}
</PRE>  
*********************************************************************************/  
void powersave_set(powersave_flag_t flg,powersave_action_t action);


/*******************************************************************************//**
* \fn void powersave_sleepwfi(void);
* \brief Funcion que inicia el modo sleep a la espera de una interupcion, la cual
* debe provenir de un modulo que no este adjuntado a la reducion de consumo de energia. 
* \return nothing.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 24 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
  const powersave_flag_t powerflags = powersave_I2C | powersave_ADC | powersave_USART0 | powersave_SPI | powersave_TIMER1 | powersave_TIMER2;  
  void setup()
  {
    WATCH_DOG_TIMER(DISABLE);
    powersave_init();
    powersave_set(powerflags);
    // ... more code ...
    WATCH_DOG_TIMER(ENABLE,8s);
  }
  void loop()
  {     
    blinkyled_update();
    //... more code    
    WATCH_DOG_TIMER(RESET); 
    powersave_sleepwfi();
  }
  
</PRE>
*************************************************************************************/
void powersave_sleepwfi(void);




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
#endif /* #ifndef __powersave_h__ */

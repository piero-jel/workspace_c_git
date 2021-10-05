/**
* 
* *********************************************************************************//**
* \addtogroup modules "Modulos/Librerias Arduino" 
* @{ 
* \copyright  
* 2019, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of typedef.h .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright holder. &copy;
* \file stdctype.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \version 01v01d01.
* \date Domingo 18 de Octubre, 2020.
* \pre pre, condiciones que deben cuplirse antes del llamado, example: First
* initialize the system.
* \bug bug, depuracion example: Not all memory is freed when deleting an object 
* of this class.
* \warning mensaje de precaucion, warning.
* \note nota.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* @} doxygen end group definition 
* ********************************************************************************** */
#ifndef __stdctype_h__
#define __stdctype_h__ /**<@brief definimos el header file, para evitar includes recursivos */

/* header que contine las redefiniciones de
 * variables primitivas
 */
#include <stdint.h>

// TODO enable assert
#define ASSERT_ENABLE             1   /**<@brief */
#define PROJECT_USE_FuseConfig    0   /**<@brief */
#define JTAG_ENABLE               0   /**<@brief */
#define WDT_ENABLE                1   /**<@brief */



/**
* \typedef uint_t;
* \brief Redefinimos el tipo de dato entero sin signo por defecto 
* de 4-Bytes 32-Bits.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef uint32_t uint_t;

/**
* \enum bool_t
* \brief Redefinicion del tipo de dato booleano.
*  \li \ref FALSE.
*  \li \ref TRUE.
* \version 01v01d01.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
    FALSE = 0,      /**<@brief Enumeracion para establecer la condicion logica flase o '0' */
    TRUE = ~FALSE   /**<@brief Enumeracion para establecer la condicion logica true o distinto de '0' */
}bool_t;

/**
* \enum action_t
* \brief Redefinicion del tipo de dato "accion", cuando se requiere 
* demandar una accion logica a ejecutar.
*  \li \ref DISABLE.
*  \li \ref ENABLE.
* \version 01v01d01.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum{
    DISABLE = 0x00, /**<@brief Enumeracion para establecer que se deshabilite un parametro */
    ENABLE = 0x80   /**<@brief Enumeracion para establecer que se habilite un parametro */
} action_t;

#define __ENABLE__  0x80 /**<@brief Etiqueta/Label para establecer que se habilite una 
seccion o una funcionaolidad mediante CPP preprocesamiento del compilador */
#define __DISABLE__ 0x00 /**<@brief Etiqueta/Label para establecer que se deshabilite una 
seccion o una funcionaolidad mediante CPP preprocesamiento del compilador */



#if (defined(ARDUINO_ARCH_AVR))

#include <avr/sleep.h>
#include <avr/wdt.h>

/*
 ******************************************************************//**
 * @brief sleep, pone en modo bajo consumo al micro controlador
 * a la espera de una interupcion.
 * @param   action 
 * @return  nothing
 ********************************************************************/
#define SLEEP() \
{\
  sleep_enable();\
  sleep_cpu();\
  sleep_disable();\
}

  #if (PROJECT_USE_FuseConfig == 1 && WDT_ENABLE==1 )
    #define CONFIG_FUSE() \
      __fuse_t __fuse __attribute__((section (".fuse"))) = \
      { .low = LFUSE_DEFAULT, .high = LFUSE_DEFAULT & FUSE_WDTON, .extended = EFUSE_DEFAULT }

  #elif (PROJECT_USE_FuseConfig == 1 && JTAG_ENABLE==1 )
    #define CONFIG_FUSE() \
      __fuse_t __fuse __attribute__((section (".fuse"))) = \
      { .low = LFUSE_DEFAULT, \
        .high = (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_EESAVE & FUSE_SPIEN & FUSE_JTAGEN & FUSE_OCDEN), \
        .extended = EFUSE_DEFAULT }

  #elif (PROJECT_USE_FuseConfig == 1)
    #define CONFIG_FUSE() \
      __fuse_t __fuse __attribute__((section (".fuse"))) = \
      { .low = LFUSE_DEFAULT, .high = LFUSE_DEFAULT, .extended = EFUSE_DEFAULT }  
    
  #else /* #if (PROJECT_USE_FuseConfig == 1 && WDT_ENABLE==1 ) */
      
    #define CONFIG_FUSE()
    
  #endif /* #if (PROJECT_USE_FuseConfig == 1 && WDT_ENABLE==1 ) */

  #if (WDT_ENABLE==1)
    #define WATCH_DOG_TIMER_15ms      WDTO_15MS   /**<@brief */
    #define WATCH_DOG_TIMER_30ms      WDTO_30MS   /**<@brief */
    #define WATCH_DOG_TIMER_60ms      WDTO_60MS   /**<@brief */
    #define WATCH_DOG_TIMER_120ms     WDTO_120MS  /**<@brief */
    #define WATCH_DOG_TIMER_250ms     WDTO_250MS  /**<@brief */
    #define WATCH_DOG_TIMER_500ms     WDTO_500MS  /**<@brief */
    #define WATCH_DOG_TIMER_1s        WDTO_1S     /**<@brief */
    #define WATCH_DOG_TIMER_2s        WDTO_2S     /**<@brief */
    #define WATCH_DOG_TIMER_4s        WDTO_4S     /**<@brief */
    #define WATCH_DOG_TIMER_8s        WDTO_8S     /**<@brief */
      
    #define WATCH_DOG_TIMER_ENABLE(Time)    wdt_enable(WATCH_DOG_TIMER_##Time)
    #define WATCH_DOG_TIMER_DISABLE()       wdt_disable()
    #define WATCH_DOG_TIMER_RESET()         wdt_reset()
  
  #else /* #if (WDT_ENABLE==1) */

    #define WATCH_DOG_TIMER_ENABLE(Time)    // nothing
    #define WATCH_DOG_TIMER_DISABLE()       // nothing
    #define WATCH_DOG_TIMER_RESET()         // nothing
  #endif /* #if (WDT_ENABLE==1) */

#else /* #if(defined(ARDUINO_ARCH_AVR)) */

  #define WATCH_DOG_TIMER_ENABLE(Time)    // nothing
  #define WATCH_DOG_TIMER_DISABLE()       // nothing
  #define WATCH_DOG_TIMER_RESET()         // nothing
    
#endif /* #if(defined(ARDUINO_ARCH_AVR)) */







/**
 * ****************************************************************//**
 * \def WATCH_DOG_TIMER(lit ,...) 
 * \brief watch dog timer macro Function
 * \param   action
 *  \li ENABLE, habilitamos el wdt y establecemos el periodo de trabajo
 *    + 15ms | 30ms | 60ms | 120ms
 *    + 250ms | 500ms | 1s | 2s | 4s | 8s
 *  \li DISABLE, deshabilita el wdt.
 *  \li RESET, reinicia el timer del wdt.
 * \return nothing
  <pre>
  // config, main init
  WATCH_DOG_TIMER(DISABLE);
    
  // end config , enbale wdt 
  WATCH_DOG_TIMER(ENABLE,8s);
  
  // loop while(1)
  ... more code
  
  WATCH_DOG_TIMER(RESET)
  </pre>
 ********************************************************************/
#define WATCH_DOG_TIMER(lit ,...)  WATCH_DOG_TIMER_##lit(__VA_ARGS__)


/**
 * ****************************************************************//**
 * \def ASSERT(Cond,Token) 
 * \brief Macro funcion para chequear arguementos pasados a la funcion * 
 * \param Cond
 *  Condicional, este es quien determina si se ejecuta el token o no.
 * \param Token Token que se ejecutara si el assert es valido.
 * \return nothing
<pre>
  int8_t fn_example(char *pbuff, size_t len)
  {
    ASSERT(pbuff == NULL, return -1)
    // ... more code here
  }
</pre>
 ********************************************************************/
#if (ASSERT_ENABLE == 1)
#define ASSERT(Cond,Token) \
{\
  if(Cond) \
  {\
    Token;\
  }\
}  
#else
#define ASSERT(Cond,Token)
#endif







#endif /* __stdctype_h__ */

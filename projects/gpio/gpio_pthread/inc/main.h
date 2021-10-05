/** ***********************************************************************************//**
 * \addtogroup template 
 * @{
 * \copyright  
 * 2021, Luccioni Jesús Emanuel \n
 * All rights reserved.\n 
 * This file is part of template .\n
 * Redistribution is not allowed on binary and source forms, with or without \n
 * modification. Use is permitted with prior authorization by the copyright 
 * holder. &copy;
 * \file main.h
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
 * \brief Descripcion breve.
 * \details Descripcion detallada.
 *
 * \version 01v01d01.
 * \date Domingo 17 de Enero, 2021.
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
/*
 * -- Definimos el Nombre del modulo
*/
#ifndef __main_h__
#define __main_h__
/*
 * ===========================[ BEGIN include header file ]===========================
 */

/** @example : #include <nmbHeaderFile.h> */

/*
 * ===========================[ END include header file   ]===========================
 * */


/*
 * ==========================[ BEGIN Main APIs Declaration ]==========================
 */
/**
* ******************************************************************************** 
* \fn int main(int argc, char **argv);
* \brief Funcion Principal
* \param argc : cantidad de Argumentos pasados al invocar la app.
* \param argv : puntero a puntero que contiene el listado de arguementos.
* \return status de la ejecucion de la app.
*      \li 0, success
*      \li 1, failure
* \version numero de version a la cual corresponde.
* \note nota.
* \warning mensaje de "warning". 
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
*********************************************************************************/
int main(int argc, char **argv);

/*
 * ==========================[ END   Main APIs Declaration ]==========================
 */


 #if (version_QueryNumber(__main_version__,01v00d00))
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d00 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d00
*/

/*
 * ========================[ BEGIN redefinition of variables ]========================
 */
/**
* \struct blinky_led_t; 
* \brief estructura para el manejo del blink sobre un led.
* Elementos que componen la union:
*  \li \ref gpion
*  \li \ref i
*  \li \ref gpion
*  \li \ref blinky_led_t_item2;
* \version    numero de version a la cual corresponde.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  uint8_t gpion;/**<@brief Numero de GPIO */  
  uint8_t i; /**<@brief Numero de interraccion actual */
  uint16_t time_on; /**<@brief tiempo que aparece encendido */
  uint16_t time_off; /**<@brief tiempo que permace apagado */ 
  
}blinky_led_t;
/*
 * ========================[ END   redefinition of variables ]======================== 
 */

/*
 * ========================[ BEGIN declaration of variables  ]========================
 */

/*
 * ========================[ END   declaration of variables  ]======================== 
 */
/*
 * ==========================[ BEGIN Function declaration  ]==========================
 */

void blinky_led(void * arg);
void thread_main(void * arg);
/*
 * ==========================[ END   Function declaration  ]==========================
 */
/*
 * ==========================[ BEGIN macros definitions    ]==========================
 */

/*
 * ==========================[ END   macros definitions    ]==========================
 */

/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d00 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d01))
/**
* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d01 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d01
*/
/*
 * ========================[ BEGIN redefinition of variables ]========================
 */
/**
* \struct blinky_led_t; 
* \brief estructura para el manejo del blink sobre un led.
* Elementos que componen la union:
*  \li \ref gpion
*  \li \ref i
*  \li \ref gpion
*  \li \ref blinky_led_t_item2;
* \version    numero de version a la cual corresponde.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  uint8_t gpion;/**<@brief Numero de GPIO */  
  uint8_t i; /**<@brief Numero de interraccion actual */
  uint16_t time_on; /**<@brief tiempo que aparece encendido */
  uint16_t time_off; /**<@brief tiempo que permace apagado */ 
  
}blinky_led_t;
/*
 * ========================[ END   redefinition of variables ]======================== 
 */

/*
 * ========================[ BEGIN declaration of variables  ]========================
 */

/*
 * ========================[ END   declaration of variables  ]======================== 
 */
/*
 * ==========================[ BEGIN Function declaration  ]==========================
 */
void blinky_led(void * arg);
void thread_main(void * arg);
/*
 * ==========================[ END   Function declaration  ]==========================
 */
/*
 * ==========================[ BEGIN macros definitions    ]==========================
 */

/*
 * ==========================[ END   macros definitions    ]==========================
 */

/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d01 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d02))
/**
* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d02 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d02
*/
/*
 * ========================[ BEGIN redefinition of variables ]========================
 */
/**
* \struct blinky_led_t; 
* \brief estructura para el manejo del blink sobre un led.
* Elementos que componen la union:
*  \li \ref gpion
*  \li \ref i
*  \li \ref gpion
*  \li \ref blinky_led_t_item2;
* \version    numero de version a la cual corresponde.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  uint8_t gpion;/**<@brief Numero de GPIO */  
  uint8_t i; /**<@brief Numero de interraccion actual */
  uint16_t time_on; /**<@brief tiempo que aparece encendido */
  uint16_t time_off; /**<@brief tiempo que permace apagado */ 
  
}blinky_led_t;
typedef struct
{
  uint8_t gpion;/**<@brief Numero de GPIO */  
  uint8_t st; /**<@brief Numero de interraccion actual */
  uint16_t debounce_time; /**<@brief tiempo que aparece encendido */  
  void (*callback) (void*);
}switch_hdl_t;
/*
 * ========================[ END   redefinition of variables ]======================== 
 */

/*
 * ========================[ BEGIN declaration of variables  ]========================
 */

/*
 * ========================[ END   declaration of variables  ]======================== 
 */
/*
 * ==========================[ BEGIN Function declaration  ]==========================
 */
void blinky_led(void * arg);
void thread_main(void * arg);
void fncallback_sw(void *arg);
void switch_update(void * arg);
static void signal_capture(int signal);
/*
 * ==========================[ END   Function declaration  ]==========================
 */
/*
 * ==========================[ BEGIN macros definitions    ]==========================
 */

/*
 * ==========================[ END   macros definitions    ]==========================
 */
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d02 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d03))
/**
* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d03 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d03
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d03 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d04))
/**
* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d04 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d04
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d04 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d05))
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d05 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d05
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d05 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d06))
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d06 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d06
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d06 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d07))
/**
* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d07 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d07
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d07 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d08))
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d08 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d08
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d08 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d09))
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d09 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d09
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d09 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/

#endif /* #if(version_QueryNumber(__main_version__,01v00d00)) */
/* **********************************************************************************************
 *
 * ===========================[ END Global Macros functions ]==================================
 *
 **********************************************************************************************
 * 
 */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef __main_h__ */

#ifndef prpi_gpio_projectEnable
#define prpi_gpio_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup prpi 
* @{ borrarme, solo para mantener la identacion -> }@
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of prpi .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file prpi_gpio.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v01d01.
* \date Jueves 25 de Marzo, 2021.
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


#ifndef __prpi_gpio_h__
#define __prpi_gpio_h__ /**<@brief Definimos el Nombre del modulo */


#if (prpi_gpio_projectEnable == 1)

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 
 * ============================[begin of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/*
 * ============================[Open, cplusplus]============================ 
 */
#ifdef __cplusplus
extern "C" {
#endif

/* 
  * ======================[ BEGIN include header file ]=================================
  */
#include <stdio.h>
#include <stdc.h>

/* 
  * ======================[ END   include header file ]=================================
  */

/* 
  * ======================[ BEGIN labels enable/disable ]===============================
  */
#define prpi_gpio_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define prpi_gpio_USE_GlobalTypedef   0 /**<@brief enable/disable the use Global Typedef */
#define prpi_gpio_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define prpi_gpio_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define prpi_gpio_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
  * \def __prpi_gpio_version__ definimos la version actual del proyecto.
  * version 01v00d00 -> test 
  * version 01v00d01 -> test 
  * version 01v00d02 -> test
  * version 01v00d03 -> test
  * version 01v00d04 -> test
  * version 01v00d05 -> test
  *
  * */
#ifndef __prpi_gpio_version__
#define __prpi_gpio_version__        version_SetNumber(01v00d00)
#endif

/* 
  * ======================[ END   labels enable/disable ]===============================
  */
#if (version_QueryNumber(__prpi_gpio_version__,01v00d00))
/* 
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ BEGIN __prpi_gpio_version__    01v00d00 ]───────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */
/* 
  * ======================[ BEGIN Global Macros/labels definition ]=================
  */
#if (prpi_gpio_USE_GlobalMacro == 1)
#define prpi_PINCONFIG_DEFAULT  0x00 /**<@brief configuracion por defecto despues de un reset. Por lo general y para reducir el consumo de energia esta es una configuracion como entrada. */
#define prpi_PINCONFIG_INPUT    0x00 /**<@brief Para configurar el GPIO como Entrada. */
#define prpi_PINCONFIG_OUTPUT   0x01 /**<@brief Para configurar el GPIO como Salida. */
#define prpi_PINCONFIG_FUNC5    0x02 /**<@brief Para Asignarle al GPIO la Funcion numero 5.*/
#define prpi_PINCONFIG_FUNC4    0x03 /**<@brief Para Asignarle al GPIO la Funcion numero 4.*/
#define prpi_PINCONFIG_FUNC3    0x07 /**<@brief Para Asignarle al GPIO la Funcion numero 3.*/
#define prpi_PINCONFIG_FUNC2    0x06 /**<@brief Para Asignarle al GPIO la Funcion numero 2.*/
#define prpi_PINCONFIG_FUNC1    0x05 /**<@brief Para Asignarle al GPIO la Funcion numero 1.*/
#define prpi_PINCONFIG_FUNC0    0x04 /**<@brief Para Asignarle al GPIO la Funcion numero 0.*/


#endif /* #if(prpi_gpio_USE_GlobalMacro == 1) */
/* 
  * ======================[ END   Global Macros/labels definition ]=================
  */


/* 
  * ======================[ BEGIN Global typedef      ]=============================
  */
#if (prpi_gpio_USE_GlobalTypedef == 1)
/**
  * \typedef prpi_gpio_tvar_ex_vT;
  * \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
  * \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
  * \version 01v01d01.
  * \note nota.
  * \warning mensaje de "warning". 
  * \date Jueves 25 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int prpi_gpio_tvar_ex_vT;


/**
  * \typedef prpi_gpio_pfun_ex_fT;
  * \details Descripcion detallada sobre la redefinicion de puntero a funcion.
  * \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
  * Prototipo de la funcion, al acual debe apuntar:
  *  + void * function ( void * arg )
  * \version 01v01d01.
  * \note nota.
  * \warning mensaje de "warning". 
  * \date Jueves 25 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*prpi_gpio_pfun_ex_fT) (void *); 


/**
  * \struct prpi_gpio_struct_ex_sT;
  * \brief Descripcion breve sobre el tipo de estructura.
  * Elementos que componen a la Estructura de datos:
  *  \li \ref vtchar;
  *  \li \ref vtint;
  *  \li \ref vtdouble;
  * \version 01v01d01.
  * \note nota sobre la estructura.
  * \warning mensaje de "warning". 
  * \date Jueves 25 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} prpi_gpio_struct_ex_sT ; 

/**
  * \union prpi_gpio_union_ex_uT;
  * \brief Descripcion breve sobre el tipo de union.
  * Elementos que componen la union:
  *   \li \ref item1 
  *   \li \ref item2 
  * \version 01v01d01.
  * \warning mensaje de "warning". 
  * \date Jueves 25 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} prpi_gpio_union_ex_uT;


/**
  * \enum prpi_gpio_enum_eT;
  * \details Descripcion detallada sobre la redefinicion de enumeracio.
  * \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
  * Elementos que componen la enumeracion:
  *  \li \ref prpi_gpio_eITEM0 . 
  *  \li \ref prpi_gpio_eITEM1 .
  *  \li \ref prpi_gpio_eITEM2 .
  * \version 01v01d01.
  * \warning mensaje de "warning".
  * \date Jueves 25 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  prpi_gpio_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'prpi_gpio_eITEM0' de Enumeracion */
  prpi_gpio_eITEM1,     /**<@brief descripcion breve de la etiqueta 'prpi_gpio_eITEM1' de Enumeracion */
  prpi_gpio_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'prpi_gpio_eITEM2' de Enumeracion */
} prpi_gpio_enum_eT;

#endif /* #if(prpi_gpio_USE_GlobalTypedef == 1) */
/* 
  * ======================[ END   Global typedef      ]=============================
  */
/* 
  * ======================[ BEGIN local declaration   ]=============================
  */
#ifdef __prpi_gpio_c__


#endif /* #ifdef __prpi_gpio_c__ */
/* 
  * ======================[ END   local declaration   ]=============================
  */
/* 
  * ======================[ BEGIN Global declaration  ]=============================
  */
#if (prpi_gpio_USE_GlobalData==1)
extern unsigned int prpi_gpio_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (prpi_gpio_USE_GlobalData==1) */
/* 
  * ======================[ END   Global declaration  ]=============================
  */
/* 
  * ======================[ BEGIN Global functions declaration ]====================
  */
#if (prpi_gpio_USE_GlobalFunctions == 1)
/** 
* 
* ******************************************************************************* 
* \fn bool_t prpi_gpio_init(int *errnotify);
* \brief Funcion para inicializar el periferico GPIO de la RPI
* \param errnotify : Puntero/referencia donde se colocara el valor de error, 
* en caso de que el mismo surga.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure
* 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Jueves 25 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
*********************************************************************************/
bool_t prpi_gpio_init(int *errnotify);
/** 
* 
* ******************************************************************************* 
* \fn bool_t prpi_gpio_deinit(int *errnotify);
* \brief Funcion liberar los recursos relaconados al GPIO
* \param errnotify : Puntero/referencia donde se colocara el valor de error, 
* en caso de que el mismo surga.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure
* 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Jueves 25 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
*********************************************************************************/
bool_t prpi_gpio_deinit(int *errnotify);
/** 
* 
* ******************************************************************************* 
* \fn void prpi_gpio_config(uint8_t gpion, uint8_t fn);
* \brief Funcion para configurar el pin de GPIO, mediante esta asignamos la 
* funcion indibidual para cada GPIO.
* \param gpion : Numero de GPIO.
* \param fn : funcion que se desea asignarle al pin/GPIO su valor puede ser:
*      \li \ref prpi_PINCONFIG_DEFAULT
*      \li \ref prpi_PINCONFIG_INPUT
*      \li \ref prpi_PINCONFIG_OUTPUT
*      \li \ref prpi_PINCONFIG_FUNC0
*      \li \ref prpi_PINCONFIG_FUNC1
*      \li \ref prpi_PINCONFIG_FUNC2
*      \li \ref prpi_PINCONFIG_FUNC3
*      \li \ref prpi_PINCONFIG_FUNC4
*      \li \ref prpi_PINCONFIG_FUNC5
* 
* \return nothing.
*      \li TRUE, success
*      \li FALSE, failure
* 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Jueves 25 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
*********************************************************************************/
void prpi_gpio_config(uint8_t gpion, uint8_t fn);
/** 
* 
* ******************************************************************************* 
* \fn void prpi_gpio_write(uint8_t gpion, bool_t state);
* \brief Funcion para escribir un '0' o un '1' sobre un GPIO determinado
* \param gpion : Numero de GPIO
* \param state : Estado que deseamos escribir
*   \li TRUE : escrbiremos un '1'.
*   \li FALSE : escrbiremos un '0'.
* \return nothing
* 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Jueves 25 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
*********************************************************************************/
void prpi_gpio_write(uint8_t gpion, bool_t state);
/** 
* 
* ******************************************************************************* 
* \fn bool_t prpi_gpio_read(uint8_t gpion);
* \brief Funcion para leer el estado actual de un GPIO determinado
* \param gpion : Numero de GPIO
* \return estado actual del GPIO
*   \li TRUE : estado actual HIGH.
*   \li FALSE : estado actual LOW.
* 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Jueves 25 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
*********************************************************************************/
bool_t prpi_gpio_read(uint8_t gpion);




#endif /* #if (prpi_gpio_USE_GlobalFunctions == 1) */
/* 
  * ======================[ END   Global functions declaration ]====================
  */

/* 
  * ======================[ BEGIN Global Macros functions ]=========================
  */
#if ( prpi_gpio_USE_GlobalMacroApis == 1 )
/**
  * 
  * ********************************************************************************
  * \def prpi_gpio_macro_ex(Arg1,Arg2)
  * \details Descripcion detallada sobre la macro funcion \ref prpi_gpio_macro_ex().
  * \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
  * \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
  *
  * \brief Descripcion breve sobre la macro funcion \ref prpi_gpio_macro_ex().
  * \param Arg1 : Argumento uno, de la macro funcion.
  * \param Arg2 : Argumento dos, de la macro funcion.
  * \return nothinig
  * \version 01v01d01.
  * \note nota.
  * \warning mensaje de "warning".
  * \date Jueves 25 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
  * \par example :
  * <PRE>
  * 
  * </PRE> 
  *********************************************************************************/ 
#define prpi_gpio_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( prpi_gpio_USE_GlobalMacroApis == 1 ) */
/* 
  * ======================[ END   Global Macros functions ]=========================
  */



/*
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ END   __prpi_gpio_version__    01v00d00 ]───────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  *
  */
#elif (version_QueryNumber(__prpi_gpio_version__,01v00d01))
/* 
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ BEGIN __prpi_gpio_version__    01v00d01 ]───────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */



/*
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ END   __prpi_gpio_version__    01v00d01 ]───────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */
#endif



/*
  * ============================[close, cplusplus]============================
  */
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/*==============================[end of file]==============================*/
#endif /* #ifndef __prpi_gpio_h__ */
/*
 * 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =============================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(prpi_gpio_projectEnable == 1) */

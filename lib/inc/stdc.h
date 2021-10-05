#ifndef stdc_projectEnable
#define stdc_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup stdc 
* @{ borrarme, solo para mantener la identacion -> }@
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of stdc .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file stdc.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v00d00.
* \date Miercoles 28 de Abril, 2021.
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

#ifndef __stdc_h__
#define __stdc_h__ /**<@brief Definimos el Nombre del modulo */


#if (stdc_projectEnable == 1)

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 
 * ============================[begin of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/*
 * ============================[Open, cplusplus]============================ 
 */
#ifdef __cplusplus
extern "C" 
{
#endif

/* 
  * ======================[ BEGIN include header file ]=================================
  */
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdint.h>
#include <ctype.h>

/*loacl header files */
#include <version.h>
#include <stdctype.h>
#include <stdcstr.h>
#include <stdcprint.h>
#include <stdctimer.h>
#include <stdcfile.h>
/* en etapa de test 01d00v00*/
#include <stdcmenu.h>
#include <timestamp.h>

/*fuera del estandar*/
#include <logger.h>

// #include <serialterminal.h>
#include "serialterminal.h"






/* 
  * ======================[ END   include header file ]=================================
  */

/* 
  * ======================[ BEGIN labels enable/disable ]===============================
  */
#define stdc_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define stdc_USE_GlobalTypedef   0 /**<@brief enable/disable the use Global Typedef */
#define stdc_USE_GlobalMacroApis 1 /**<@brief enable/disable the use Gobal macros functions */

/**
  * \def __stdc_version__ definimos la version actual del proyecto.
  * version 01v00d00 -> test 
  * version 01v00d01 -> test 
  * version 01v00d02 -> test
  * version 01v00d03 -> test
  * version 01v00d04 -> test
  * version 01v00d05 -> test
  *
  * */
#ifndef __stdc_version__
#define __stdc_version__        version_SetNumber(01v00d00)
#endif

/* 
  * ======================[ END   labels enable/disable ]===============================
  */
#if (version_QueryNumber(__stdc_version__,01v00d00))
/* 
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ────────────────────────[ BEGIN __stdc_version__    01v00d00 ]─────────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */
/* 
  * ======================[ BEGIN Global Macros/labels definition ]=================
  */
#if (stdc_USE_GlobalMacro == 1)


#endif /* #if(stdc_USE_GlobalMacro == 1) */
/* 
  * ======================[ END   Global Macros/labels definition ]=================
  */
/* 
  * ======================[ BEGIN Global typedef      ]=============================
  */
#if (stdc_USE_GlobalTypedef == 1)

/**
  * \typedef stdc_tvar_ex_vT;
  * \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
  * \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
  * \version 01v00d00.
  * \note nota.
  * \warning mensaje de "warning". 
  * \date Miercoles 28 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int stdc_tvar_ex_vT;


/**
  * \typedef stdc_pfun_ex_fT;
  * \details Descripcion detallada sobre la redefinicion de puntero a funcion.
  * \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
  * Prototipo de la funcion, al acual debe apuntar:
  *  + void * function ( void * arg )
  * \version 01v00d00.
  * \note nota.
  * \warning mensaje de "warning". 
  * \date Miercoles 28 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*stdc_pfun_ex_fT) (void *); 


/**
  * \struct stdc_struct_ex_sT;
  * \brief Descripcion breve sobre el tipo de estructura.
  * Elementos que componen a la Estructura de datos:
  *  \li \ref vtchar;
  *  \li \ref vtint;
  *  \li \ref vtdouble;
  * \version 01v00d00.
  * \note nota sobre la estructura.
  * \warning mensaje de "warning". 
  * \date Miercoles 28 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} stdc_struct_ex_sT ; 

/**
  * \union stdc_union_ex_uT;
  * \brief Descripcion breve sobre el tipo de union.
  * Elementos que componen la union:
  *   \li \ref item1 
  *   \li \ref item2 
  * \version 01v00d00.
  * \warning mensaje de "warning". 
  * \date Miercoles 28 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} stdc_union_ex_uT;


/**
  * \enum stdc_enum_eT;
  * \details Descripcion detallada sobre la redefinicion de enumeracio.
  * \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
  * Elementos que componen la enumeracion:
  *  \li \ref stdc_eITEM0 . 
  *  \li \ref stdc_eITEM1 .
  *  \li \ref stdc_eITEM2 .
  * \version 01v00d00.
  * \warning mensaje de "warning".
  * \date Miercoles 28 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  stdc_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'stdc_eITEM0' de Enumeracion */
  stdc_eITEM1,     /**<@brief descripcion breve de la etiqueta 'stdc_eITEM1' de Enumeracion */
  stdc_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'stdc_eITEM2' de Enumeracion */
} stdc_enum_eT;

#endif /* #if(stdc_USE_GlobalTypedef == 1) */
/* 
  * ======================[ END   Global typedef      ]=============================
  */


/* 
  * ======================[ BEGIN Global Macros functions ]=========================
  */
#if ( stdc_USE_GlobalMacroApis == 1 )
    
    
    
#endif /* #if ( stdc_USE_GlobalMacroApis == 1 ) */
/* 
  * ======================[ END   Global Macros functions ]=========================
  */
/*
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ────────────────────────[ END   __stdc_version__    01v00d00 ]─────────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  *
  */
#elif (version_QueryNumber(__stdc_version__,01v00d01))
/* 
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ────────────────────────[ BEGIN __stdc_version__    01v00d01 ]─────────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */



/*
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ────────────────────────[ END   __stdc_version__    01v00d01 ]─────────────────────── │
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
#endif /* #ifndef __stdc_h__ */
/*
 * 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =============================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(stdc_projectEnable == 1) */

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

/* Definimos los label para habilitar el uso de GNU para todos los header files */
#if !defined(__USE_GNU)
  #define __USE_GNU    
#endif

#if !defined(_GNU_SOURCE)
  #define _GNU_SOURCE
#endif

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
/* FIXME news modules, componentes de stdc_ */
#include <stdc_print.h>
#include <stdc_str.h>

#include <stdctimer.h>
#include <stdcfile.h>
/* en etapa de test 01d00v00*/
#include <stdcmenu.h>
#include <timestamp.h>
#include <stdcutils.h>
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

/* ======================[ END   labels enable/disable ]=============================== */
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
/* ======================[ BEGIN Global Macros/labels definition ]================= */
#if (stdc_USE_GlobalMacro == 1)


#endif /* #if(stdc_USE_GlobalMacro == 1) */
/* 
  * ======================[ END   Global Macros/labels definition ]=================
  */
/* ======================[ BEGIN Global typedef      ]============================= */
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
/* ======================[ END   Global typedef      ]============================= */


/* ======================[ BEGIN Global Macros functions ]========================= */
#if ( stdc_USE_GlobalMacroApis == 1 )
/**
 * \def ARRAY_SIZE(Arr)
 * \brief Macro funcion para obtener el numero de item de un array,
 * no el numero de bytes.
 * \param Arr   : Array sobre el cual se desea obtener el numero de Items.
 * \return El numero de item de un array de elementos. */
#define ARRAY_SIZE(Arr)     (sizeof(Arr)/sizeof(Arr[0]))     

/** 
 * \def ARRAY_PRINT(Buff,Fmt)
 * \brief Macro funcion para imprimir un array de valores primitivos.
 * \param Buff    Buffer de valores del tipo primitivo.
 * \param Fmt     Formato, se debe corresponde al tipo de datos del array. 
 * \return nothing 
 */
#define ARRAY_PRINT(Buff,Fmt) \
{\
  size_t i ;\
  for(i=0;i<ARRAY_SIZE(Buff);i++)\
    printf("\t"Fmt"\n",Buff[i]);\
}



/**
 * 
*/
#define RETURN_STATE_NONE(rValue,pState,rState) \
{\
  if(pState != NULL) \
    *pState = rState; \
  return rValue;\
}  

#define RETURN_STATE_SUCCESS(Value,pState) \
{\
  if(pState != NULL) \
    *pState = TRUE; \
  return Value; \
}

#define RETURN_STATE_FAILURE(Value,pState) \
{\
  if(pState != NULL) \
    *pState = FALSE; \
  return Value;\
}

#define RETURN_STATE_TRUE(pState) \
{\
  if(pState != NULL) \
    *pState = TRUE; \
  return TRUE;\
}
#define RETURN_STATE_FALSE(pState) \
{\
  if(pState != NULL) \
    *pState = FALSE; \
  return FALSE;\
}

#define RETURN_STATE_NULL(pState,rState) \
{\
  if(pState != NULL) \
    *pState = rState; \
  return NULL;\
} 

/** 
* \def RETURN_STATE(Type,...)
* \brief Macro funcion para retornar un State desde una funcion y marcar un flag si este es
* valido (distinto de NULL).
* \param Type : Tipo de salida, esta puede ser:
    \param[in] SUCCESS : RETURN_STATE(SUCCESS,rValue,pState) => pState = TRUE, return rValue;
    \param[in] FAILURE : RETURN_STATE(FAILURE,rValue,pState) => pState = FALSE, return rValue;
    \param[in] NONE    : RETURN_STATE(NONE,rValue,pState,rState) => pState = rState, return rValue;
    \param[in] TRUE    : RETURN_STATE(TRUE,pState) => pState = TRUE, return TRUE;
    \param[in] FALSE   : RETURN_STATE(FALSE,pState) => pState = FALSE, return FALSE; 
    \param[in] NULL    : RETURN_STATE(NULL,pState,rState) => pState = rState, return NULL;
* \param ... : Listado de Argumentos, String con formato seguido de cada argumento .
* \return rValue
* \version AAvBBdCC.
* \note nota.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>


</PRE> 
*/
#define RETURN_STATE(Type,...) \
  RETURN_STATE_##Type(__VA_ARGS__)
  
    
#endif /* #if ( stdc_USE_GlobalMacroApis == 1 ) */
/* ======================[ END   Global Macros functions ]========================= */
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

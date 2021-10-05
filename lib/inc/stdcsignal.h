#ifndef stdcsignal_projectEnable
#define stdcsignal_projectEnable 1 /**<@brief enable/disable the project */
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
* \file stdcsignal.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v00d00.
* \date Lunes 26 de Abril, 2021.
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

#ifndef __stdcsignal_h__
#define __stdcsignal_h__ /**<@brief Definimos el Nombre del modulo */


#if (stdcsignal_projectEnable == 1)

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
#include <stdctype.h>

/* 
  * ======================[ END   include header file ]=================================
  */

/* 
  * ======================[ BEGIN labels enable/disable ]===============================
  */
#define stdcsignal_USE_GlobalMacro     0 /**<@brief enable/disable the use Global Macros/Labels */
#define stdcsignal_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define stdcsignal_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define stdcsignal_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define stdcsignal_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
  * \def __stdcsignal_version__ definimos la version actual del proyecto.
  * version 01v00d00 -> test 
  * version 01v00d01 -> test 
  * version 01v00d02 -> test
  * version 01v00d03 -> test
  * version 01v00d04 -> test
  * version 01v00d05 -> test
  *
  * */
#ifndef __stdcsignal_version__
#define __stdcsignal_version__        version_SetNumber(01v00d00)
#endif

/* 
  * ======================[ END   labels enable/disable ]===============================
  */
#if (version_QueryNumber(__stdcsignal_version__,01v00d00))
/* 
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ BEGIN __stdcsignal_version__    01v00d00 ]──────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */
/* 
  * ======================[ BEGIN Global Macros/labels definition ]=================
  */
#if (stdcsignal_USE_GlobalMacro == 1)



#endif /* #if(stdcsignal_USE_GlobalMacro == 1) */
/* 
  * ======================[ END   Global Macros/labels definition ]=================
  */
/* 
  * ======================[ BEGIN Global typedef      ]=============================
  */
#if (stdcsignal_USE_GlobalTypedef == 1)

/**
* \typedef stdcsignal_pfun_ex_fT;
* \details Descripcion detallada sobre la redefinicion de puntero a funcion.
* \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
* Prototipo de la funcion, al acual debe apuntar:
*  + void * function ( void * arg )
* \version 01v00d00.
* \note nota.
* \warning mensaje de "warning". 
* \date Lunes 26 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void (*stdcsignal_callback_t) (int); 


#if 0
/**
  * \typedef stdcsignal_tvar_ex_vT;
  * \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
  * \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
  * \version 01v00d00.
  * \note nota.
  * \warning mensaje de "warning". 
  * \date Lunes 26 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int stdcsignal_tvar_ex_vT;

/**
  * \struct stdcsignal_struct_ex_sT;
  * \brief Descripcion breve sobre el tipo de estructura.
  * Elementos que componen a la Estructura de datos:
  *  \li \ref vtchar;
  *  \li \ref vtint;
  *  \li \ref vtdouble;
  * \version 01v00d00.
  * \note nota sobre la estructura.
  * \warning mensaje de "warning". 
  * \date Lunes 26 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} stdcsignal_struct_ex_sT ; 

/**
  * \union stdcsignal_union_ex_uT;
  * \brief Descripcion breve sobre el tipo de union.
  * Elementos que componen la union:
  *   \li \ref item1 
  *   \li \ref item2 
  * \version 01v00d00.
  * \warning mensaje de "warning". 
  * \date Lunes 26 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} stdcsignal_union_ex_uT;


/**
  * \enum stdcsignal_enum_eT;
  * \details Descripcion detallada sobre la redefinicion de enumeracio.
  * \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
  * Elementos que componen la enumeracion:
  *  \li \ref stdcsignal_eITEM0 . 
  *  \li \ref stdcsignal_eITEM1 .
  *  \li \ref stdcsignal_eITEM2 .
  * \version 01v00d00.
  * \warning mensaje de "warning".
  * \date Lunes 26 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  stdcsignal_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'stdcsignal_eITEM0' de Enumeracion */
  stdcsignal_eITEM1,     /**<@brief descripcion breve de la etiqueta 'stdcsignal_eITEM1' de Enumeracion */
  stdcsignal_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'stdcsignal_eITEM2' de Enumeracion */
} stdcsignal_enum_eT;
#endif


#endif /* #if(stdcsignal_USE_GlobalTypedef == 1) */
/* 
  * ======================[ END   Global typedef      ]=============================
  */
/* 
  * ======================[ BEGIN Global declaration  ]=============================
  */
#if (stdcsignal_USE_GlobalData==1)
extern unsigned int stdcsignal_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (stdcsignal_USE_GlobalData==1) */
/* 
  * ======================[ END   Global declaration  ]=============================
  */ 
/* 
  * ======================[ BEGIN Global functions declaration ]====================
  */
#if (stdcsignal_USE_GlobalFunctions == 1)
/** 
  * 
  * ******************************************************************************* 
  * \fn int stdcsignal_test_01(unsigned int a,const char* name);
  * \details Descripcion detallada sobre la funcion \ref stdcsignal_test_01().
  * \brief descripcion breve sobre la funcion, \ref stdcsignal_test_01().
  * \param a : Puntero al array.
  * \param name : longitud del array.
  * \return status de la opreacion.
  *      \li 0, success
  *      \li 1, failure
  * \version 01v00d00.
  * \note notq.
  * \warning mensaje de "warning". 
  * \date Lunes 26 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
  * \par example :
  * <PRE>
  * 
  * </PRE>  
  *********************************************************************************/
int stdcsignal_sethandler( stdcsignal_callback_t hanlder );

/**
  * 
  * ******************************************************************************* 
  * \fn int stdcsignal_test_02(unsigned int a,const char* name);
  * \details Descripcion detallada sobre la funcion \ref stdcsignal_test_02().
  * \brief descripcion breve sobre la funcion, \ref stdcsignal_test_02().
  * \param a : Puntero al array.
  * \param name : longitud del array.
  * \return status de la opreacion.
  *      \li 0, success
  *      \li 1, failure
  * \version 01v00d00.
  * \note notq.
  * \warning mensaje de "warning". 
  * \date Lunes 26 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
  * \par example :
  * <PRE>
  * 
  * </PRE>  
  *********************************************************************************/
/*int stdcsignal_test_02(unsigned int a,const char* name);*/

#endif /* #if (stdcsignal_USE_GlobalFunctions == 1) */
/* 
  * ======================[ END   Global functions declaration ]====================
  */
/* 
  * ======================[ BEGIN Global Macros functions ]=========================
  */
#if ( stdcsignal_USE_GlobalMacroApis == 1 )
/**
  * 
  * ********************************************************************************
  * \def stdcsignal_macro_ex(Arg1,Arg2)
  * \details Descripcion detallada sobre la macro funcion \ref stdcsignal_macro_ex().
  * \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
  * \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
  *
  * \brief Descripcion breve sobre la macro funcion \ref stdcsignal_macro_ex().
  * \param Arg1 : Argumento uno, de la macro funcion.
  * \param Arg2 : Argumento dos, de la macro funcion.
  * \return nothinig
  * \version 01v00d00.
  * \note nota.
  * \warning mensaje de "warning".
  * \date Lunes 26 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
  * \par example :
  * <PRE>
  * 
  * </PRE> 
  *********************************************************************************/ 
#define stdcsignal_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( stdcsignal_USE_GlobalMacroApis == 1 ) */
/* 
  * ======================[ END   Global Macros functions ]=========================
  */
/*
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ END   __stdcsignal_version__    01v00d00 ]──────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  *
  */
#elif (version_QueryNumber(__stdcsignal_version__,01v00d01))
/* 
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ BEGIN __stdcsignal_version__    01v00d01 ]──────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */



/*
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ END   __stdcsignal_version__    01v00d01 ]──────────────────── │
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
#endif /* #ifndef __stdcsignal_h__ */
/*
 * 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =============================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(stdcsignal_projectEnable == 1) */

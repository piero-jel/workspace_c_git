#ifndef stdc_str_projectEnable
#define stdc_str_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup stdc_str 
* @{ borrarme, solo para mantener la identacion -> }@
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of stdc_str .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file stdc_str.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v00d01.
* \date Lunes 01 de Noviembre, 2021.
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

#ifndef __stdc_str_h__
#define __stdc_str_h__ /**<@brief Definimos el Nombre del modulo */


#if (stdc_str_projectEnable == 1)

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 
 * ============================[begin of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* ============================[BEGIN Open,  cplusplus ]============================  */
#ifdef __cplusplus
extern "C" 
{ /* } */
#endif
/* ============================[END   Open,  cplusplus ]============================  */

/* ======================[ BEGIN include header file ]================================= */
#include <stdio.h>
#include <stdc.h>

/* ======================[ END   include header file ]================================= */

/* ======================[ BEGIN labels enable/disable ]=============================== */
#define stdc_str_USE_GlobalMacro     0 /**<@brief enable/disable the use Global Macros/Labels */
#define stdc_str_USE_GlobalTypedef   0 /**<@brief enable/disable the use Global Typedef */
#define stdc_str_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define stdc_str_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define stdc_str_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
 * \def __stdc_str_version__ definimos la version actual del proyecto.
 * version 01v00d00 -> test 
 * version 01v00d01 -> test 
 * version 01v00d02 -> test
 * version 01v00d03 -> test
 * version 01v00d04 -> test
 * version 01v00d05 -> test
 *
 * */
#ifndef __stdc_str_version__
#define __stdc_str_version__        version_SetNumber(01v00d00)
#endif

/* ======================[ END   labels enable/disable ]=============================== */
#if (version_QueryNumber(__stdc_str_version__,01v00d00))
/* 
 * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 * │                                                                                       │  
 * │                                                                                       │  
 * │ ─────────────────────[ BEGIN __stdc_str_version__    01v00d00 ]────────────────────── │
 * │                                                                                       │
 * │                                                                                       │             
 * └───────────────────────────────────────────────────────────────────────────────────────┘
 */
/* ======================[ BEGIN Global Macros/labels definition ]================= */
#if (stdc_str_USE_GlobalMacro == 1)



#endif /* #if(stdc_str_USE_GlobalMacro == 1) */
/* ======================[ END   Global Macros/labels definition ]================= */

/* ======================[ BEGIN Global typedef      ]============================= */
#if (stdc_str_USE_GlobalTypedef == 1)

/**
 * \typedef stdc_str_tvar_ex_vT;
 * \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
 * \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
 * \version 01v00d01.
 * \note nota.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int stdc_str_tvar_ex_vT;


/**
 * \typedef stdc_str_pfun_ex_fT;
 * \details Descripcion detallada sobre la redefinicion de puntero a funcion.
 * \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
 * Prototipo de la funcion, al acual debe apuntar:
 *  + void * function ( void * arg )
 * \version 01v00d01.
 * \note nota.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*stdc_str_pfun_ex_fT) (void *); 


/**
 * \struct stdc_str_struct_ex_sT;
 * \brief Descripcion breve sobre el tipo de estructura.
 * Elementos que componen a la Estructura de datos:
 *  \li \ref vtchar;
 *  \li \ref vtint;
 *  \li \ref vtdouble;
 * \version 01v00d01.
 * \note nota sobre la estructura.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} stdc_str_struct_ex_sT ; 

/**
 * \union stdc_str_union_ex_uT;
 * \brief Descripcion breve sobre el tipo de union.
 * Elementos que componen la union:
 *   \li \ref item1 
 *   \li \ref item2 
 * \version 01v00d01.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} stdc_str_union_ex_uT;


/**
 * \enum stdc_str_enum_eT;
 * \details Descripcion detallada sobre la redefinicion de enumeracio.
 * \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
 * Elementos que componen la enumeracion:
 *  \li \ref stdc_str_eITEM0 . 
 *  \li \ref stdc_str_eITEM1 .
 *  \li \ref stdc_str_eITEM2 .
 * \version 01v00d01.
 * \warning mensaje de "warning".
 * \date Lunes 01 de Noviembre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  stdc_str_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'stdc_str_eITEM0' de Enumeracion */
  stdc_str_eITEM1,     /**<@brief descripcion breve de la etiqueta 'stdc_str_eITEM1' de Enumeracion */
  stdc_str_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'stdc_str_eITEM2' de Enumeracion */
} stdc_str_enum_eT;

#endif /* #if(stdc_str_USE_GlobalTypedef == 1) */
/* ======================[ END   Global typedef      ]============================= */

/* =====================[ BEGIN Global variable declaration  ]===================== */
#if (stdc_str_USE_GlobalData==1)
extern unsigned int stdc_str_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (stdc_str_USE_GlobalData==1) */
/* =====================[ END   Global variable declaration  ]===================== */ 

/* =====================[ BEGIN Global functions declaration ]===================== */
#if (stdc_str_USE_GlobalFunctions == 1)

/**
 * \fn char * stdc_strtok(char * str,const char* delim, char **remainder )
 * \brief funcion para obtener un token delimitado por el string \b delim.
 * 
 * \param str     : string donde se buscara el token, este es modificado
 * \param delim   : string delimitador
 * \param remainder : puntero donde se alamcenara el remainder
 * \return 
 *  + success retorna el token, es el string formado desde \b str hasta la primer 
 * aparicion de \b delim, si se epsecifica \b remiander este se actaliza con el 
 * string remanente.
 *  + NULL si ningun caracter de \b delim se localizo dentro de \b str, en este
 * caso no se modifica \b remainder ni \b str
 * \version 01v01d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 12 de Abril, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>

 </PRE> 
 */
char * stdc_strtok(char * str,const char* delim, char **remainder );


/**
 * \fn char * stdc_strremchar(char * str,const char c);
 * \brief funcion que remueve char desde el inicio del del string
 * \param str : Puntero al array String
 * \param c   : Caracter que se desea omitir.
 * \return el str con los caracteres removidos desde el inicio.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 12 de Abril, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>

 </PRE> 
 */
char * stdc_strremchar(char * str,const char c);

/**
 * \fn char * stdc_strremchar(char * str,const char c);
 * \brief funcion que remueve char desde el inicio del del string
 * \param str : Puntero al array String
 * \param rem : Listado de caracteres, formando un string, que deben ser ignorados
 * desde el inicio del string \b str.
 * \return el str con los caracteres removidos desde el inicio.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 12 de Abril, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>

 </PRE> 
 */
char * stdc_strremove(char * str,const char *rem);



#endif /* #if (stdc_str_USE_GlobalFunctions == 1) */

/* =====================[ END   Global functions declaration ]===================== */

/* ======================[ BEGIN Global Macros functions ]========================= */
#if ( stdc_str_USE_GlobalMacroApis == 1 )
/**
 * 
 * ********************************************************************************
 * \def stdc_str_macro_ex(Arg1,Arg2)
 * \details Descripcion detallada sobre la macro funcion \ref stdc_str_macro_ex().
 * \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
 * \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
 *
 * \brief Descripcion breve sobre la macro funcion \ref stdc_str_macro_ex().
 * \param Arg1 : Argumento uno, de la macro funcion.
 * \param Arg2 : Argumento dos, de la macro funcion.
 * \return nothinig
 * \version 01v00d01.
 * \note nota.
 * \warning mensaje de "warning".
 * \date Lunes 01 de Noviembre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 * <PRE>
 * 
 * </PRE> 
 *********************************************************************************/ 
#define stdc_str_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( stdc_str_USE_GlobalMacroApis == 1 ) */
/* ======================[ END   Global Macros functions ]========================= */
/*
 * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 * │                                                                                       │  
 * │                                                                                       │  
 * │ ─────────────────────[ END   __stdc_str_version__    01v00d00 ]────────────────────── │
 * │                                                                                       │
 * │                                                                                       │             
 * └───────────────────────────────────────────────────────────────────────────────────────┘
 *
 */
#elif (version_QueryNumber(__stdc_str_version__,01v00d01))
/* 
 * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 * │                                                                                       │  
 * │                                                                                       │  
 * │ ─────────────────────[ BEGIN __stdc_str_version__    01v00d01 ]────────────────────── │
 * │                                                                                       │
 * │                                                                                       │             
 * └───────────────────────────────────────────────────────────────────────────────────────┘
 */



/*
 * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 * │                                                                                       │  
 * │                                                                                       │  
 * │ ─────────────────────[ END   __stdc_str_version__    01v00d01 ]────────────────────── │
 * │                                                                                       │
 * │                                                                                       │             
 * └───────────────────────────────────────────────────────────────────────────────────────┘
 */
#endif



/* ============================[BEGIN close, cplusplus ]============================ */
#ifdef __cplusplus
}
#endif
/* ============================[END   close, cplusplus ]============================ */
/** @} doxygen end group definition */
/*==============================[end of file]==============================*/
#endif /* #ifndef __stdc_str_h__ */
/*
 * 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =============================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(stdc_str_projectEnable == 1) */

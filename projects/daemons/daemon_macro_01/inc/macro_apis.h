#ifndef macro_apis_projectEnable
#define macro_apis_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup daemon_macro 
* @{
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of daemon_macro .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file macro_apis.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v01d01.
* \date Lunes 08 de Marzo, 2021.
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


#ifndef __macro_apis_h__
#define __macro_apis_h__ /**<@brief Definimos el Nombre del modulo */


#if (macro_apis_projectEnable == 1)

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
#include <stdctype.h>

/* 
* ======================[ END   include header file ]=================================
*/

/* 
* ======================[ BEGIN labels enable/disable ]===============================
*/
#define macro_apis_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define macro_apis_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define macro_apis_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define macro_apis_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define macro_apis_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
* \def __macro_apis_version__ definimos la version actual del proyecto.
* version 01v00d00 -> test 
* version 01v00d01 -> test 
* version 01v00d02 -> test
* version 01v00d03 -> test
* version 01v00d04 -> test
* version 01v00d05 -> test
*
* */
#ifndef __macro_apis_version__
#define __macro_apis_version__        version_SetNumber(01v00d00)
#endif

/* 
* ======================[ END   labels enable/disable ]===============================
*/


#if (version_QueryNumber(__macro_apis_version__,01v00d00))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ BEGIN __macro_apis_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
/* 
* ======================[ BEGIN Global Macros/labels definition ]=================
*/
#if (macro_apis_USE_GlobalMacro == 1)

// #define macro_VARENVIROMENT_FOLDER  "HOME"
// #define macro_LOG_FOLDER  "/home/pi/"
#define macro_LOG_FOLDER  "/home/jel"
#define macro_NAME_LOG_TEMPBOARD    "log_tempboard"
#define macro_NAME_LOG_FEEDERBOARD  "log_feederboard"

#endif /* #if(macro_apis_USE_GlobalMacro == 1) */
/* 
* ======================[ END   Global Macros/labels definition ]=================
*/


/* 
* ======================[ BEGIN Global typedef      ]=============================
*/
#if (macro_apis_USE_GlobalTypedef == 1)


/**
* \typedef macro_apis_pfun_ex_fT;
* \details Descripcion detallada sobre la redefinicion de puntero a funcion.
* \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
* Prototipo de la funcion, al acual debe apuntar:
*  + void * function ( void * arg )
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef bool_t (*macro_pfun_init_t) (void*,int*); 
typedef bool_t (*macro_pfun_deinit_t) (int*); 
typedef bool_t (*macro_pfun_processdata_t) (void*,int*); 
typedef bool_t (*macro_pfun_notify_t) (void*,int*); 


typedef struct
{
  macro_pfun_init_t fn_init ;           /**<@brief puntero a la funcion para inicializar */
  macro_pfun_deinit_t fn_deinit ;       /**<@brief puntero para la funcion de inicializar*/
  macro_pfun_processdata_t fn_processdata; /**<@brief puntero a la fucnion que procesa los datos */
  macro_pfun_notify_t fn_notify; /**<@brief puntero a funcion Notificacion de eventos  */  
} macro_hdl_apis_t ; 


#if 0
/**
* \typedef macro_apis_tvar_ex_vT;
* \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
* \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int macro_apis_tvar_ex_vT;

/**
* \struct macro_apis_struct_ex_sT;
* \brief Descripcion breve sobre el tipo de estructura.
* Elementos que componen a la Estructura de datos:
*  \li \ref vtchar;
*  \li \ref vtint;
*  \li \ref vtdouble;
* \version 01v01d01.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} macro_apis_struct_ex_sT ; 

/**
* \union macro_apis_union_ex_uT;
* \brief Descripcion breve sobre el tipo de union.
* Elementos que componen la union:
*   \li \ref item1 
*   \li \ref item2 
* \version 01v01d01.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} macro_apis_union_ex_uT;


/**
* \enum macro_apis_enum_eT;
* \details Descripcion detallada sobre la redefinicion de enumeracio.
* \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
* Elementos que componen la enumeracion:
*  \li \ref macro_apis_eITEM0 . 
*  \li \ref macro_apis_eITEM1 .
*  \li \ref macro_apis_eITEM2 .
* \version 01v01d01.
* \warning mensaje de "warning".
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  macro_apis_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'macro_apis_eITEM0' de Enumeracion */
  macro_apis_eITEM1,     /**<@brief descripcion breve de la etiqueta 'macro_apis_eITEM1' de Enumeracion */
  macro_apis_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'macro_apis_eITEM2' de Enumeracion */
} macro_apis_enum_eT;
#endif 

#endif /* #if(macro_apis_USE_GlobalTypedef == 1) */
/* 
* ======================[ END   Global typedef      ]=============================
*/

/* 
* ======================[ BEGIN local declaration   ]=============================
*/
#ifdef __macro_apis_c__


#endif /* #ifdef __macro_apis_c__ */
/* 
* ======================[ END   local declaration   ]=============================
*/


/* 
* ======================[ BEGIN Global declaration  ]=============================
*/
#if (macro_apis_USE_GlobalData==1)
extern unsigned int macro_apis_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (macro_apis_USE_GlobalData==1) */
/* 
* ======================[ END   Global declaration  ]=============================
*/

/* 
* ======================[ BEGIN Global functions declaration ]====================
*/
#if (macro_apis_USE_GlobalFunctions == 1)
/** 
* 
* ******************************************************************************* 
* \fn int macro_apis_test_01(unsigned int a,const char* name);
* \details Descripcion detallada sobre la funcion \ref macro_apis_test_01().
* \brief descripcion breve sobre la funcion, \ref macro_apis_test_01().
* \param a : Puntero al array.
* \param name : longitud del array.
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
/* -- Para la Temperature Board (Termistores, Acelerometro) */
bool_t macro_TempBoard_Init(void * arg,int *errmsg);
bool_t macro_TempBoard_Deinit(int *errmsg);
bool_t macro_TempBoard_ProcessData(void * arg,int *errmsg);
bool_t macro_TempBoard_Notify(void * arg,int *errmsg);

/* -- Para la Feeder Board (RFID, GLCD, Fin de filamento) */
bool_t macro_FeederBoard_Init(void * arg,int *errmsg);
bool_t macro_FeederBoard_Deinit(int *errmsg);
bool_t macro_FeederBoard_ProcessData(void * arg,int *errmsg);
bool_t macro_FeederBoard_Notify(void * arg,int *errmsg);

/* -- para la placa dos */
bool_t macro_OtherBoard_Init(void * arg,int *errmsg);
bool_t macro_OtherBoard_ProcessData(void * arg,int *errmsg);
bool_t macro_OtherBoard_Notify(void * arg,int *errmsg);





/**
* 
* ******************************************************************************* 
* \fn int macro_apis_test_02(unsigned int a,const char* name);
* \details Descripcion detallada sobre la funcion \ref macro_apis_test_02().
* \brief descripcion breve sobre la funcion, \ref macro_apis_test_02().
* \param a : Puntero al array.
* \param name : longitud del array.
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
// int macro_apis_test_02(unsigned int a,const char* name);

#endif /* #if (macro_apis_USE_GlobalFunctions == 1) */
/* 
* ======================[ END   Global functions declaration ]====================
*/

/* 
* ======================[ BEGIN Global Macros functions ]=========================
*/
#if ( macro_apis_USE_GlobalMacroApis == 1 )
/**
* 
* ********************************************************************************
* \def macro_apis_macro_ex(Arg1,Arg2)
* \details Descripcion detallada sobre la macro funcion \ref macro_apis_macro_ex().
* \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
* \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
*
* \brief Descripcion breve sobre la macro funcion \ref macro_apis_macro_ex().
* \param Arg1 : Argumento uno, de la macro funcion.
* \param Arg2 : Argumento dos, de la macro funcion.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/ 
#define macro_apis_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( macro_apis_USE_GlobalMacroApis == 1 ) */
/* 
* ======================[ END   Global Macros functions ]=========================
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ END   __macro_apis_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (version_QueryNumber(__macro_apis_version__,01v00d01))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ BEGIN __macro_apis_version__    01v00d01 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ END   __macro_apis_version__    01v00d01 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#endif



/*
*============================[close, cplusplus]============================
*/
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/*==============================[end of file]==============================*/
#endif /* #ifndef __macro_apis_h__ */
/*
*
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =============================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(macro_apis_projectEnable == 1) */

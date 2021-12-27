#ifndef stdctimer_projectEnable
#define stdctimer_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup miscellaneous 
* @{ borrarme, solo para mantener la identacion -> }@
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of miscellaneous .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file stdctimer.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v01d01.
* \date Miercoles 24 de Marzo, 2021.
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


#ifndef __stdctimer_h__
#define __stdctimer_h__ /**<@brief Definimos el Nombre del modulo */


#if (stdctimer_projectEnable == 1)

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
#include <stdc_print.h>

/* 
  * ======================[ END   include header file ]=================================
  */

/* 
  * ======================[ BEGIN labels enable/disable ]===============================
  */
#define stdctimer_USE_GlobalMacro     0 /**<@brief enable/disable the use Global Macros/Labels */
#define stdctimer_USE_GlobalTypedef   0 /**<@brief enable/disable the use Global Typedef */
#define stdctimer_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define stdctimer_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define stdctimer_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
  * \def __stdctimer_version__ definimos la version actual del proyecto.
  * version 01v00d00 -> test 
  * version 01v00d01 -> test 
  * version 01v00d02 -> test
  * version 01v00d03 -> test
  * version 01v00d04 -> test
  * version 01v00d05 -> test
  *
  * */
#ifndef __stdctimer_version__
#define __stdctimer_version__        version_SetNumber(01v00d00)
#endif

/* 
  * ======================[ END   labels enable/disable ]===============================
  */


#if (version_QueryNumber(__stdctimer_version__,01v00d00))
/* 
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ BEGIN __stdctimer_version__    01v00d00 ]───────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */
/* 
  * ======================[ BEGIN Global Macros/labels definition ]=================
  */
#if (stdctimer_USE_GlobalMacro == 1)



#endif /* #if(stdctimer_USE_GlobalMacro == 1) */
/* 
  * ======================[ END   Global Macros/labels definition ]=================
  */


/* 
  * ======================[ BEGIN Global typedef      ]=============================
  */
#if (stdctimer_USE_GlobalTypedef == 1)

/**
  * \typedef stdctimer_tvar_ex_vT;
  * \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
  * \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
  * \version 01v01d01.
  * \note nota.
  * \warning mensaje de "warning". 
  * \date Miercoles 24 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int stdctimer_tvar_ex_vT;


/**
  * \typedef stdctimer_pfun_ex_fT;
  * \details Descripcion detallada sobre la redefinicion de puntero a funcion.
  * \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
  * Prototipo de la funcion, al acual debe apuntar:
  *  + void * function ( void * arg )
  * \version 01v01d01.
  * \note nota.
  * \warning mensaje de "warning". 
  * \date Miercoles 24 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*stdctimer_pfun_ex_fT) (void *); 


/**
  * \struct stdctimer_struct_ex_sT;
  * \brief Descripcion breve sobre el tipo de estructura.
  * Elementos que componen a la Estructura de datos:
  *  \li \ref vtchar;
  *  \li \ref vtint;
  *  \li \ref vtdouble;
  * \version 01v01d01.
  * \note nota sobre la estructura.
  * \warning mensaje de "warning". 
  * \date Miercoles 24 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} stdctimer_struct_ex_sT ; 

/**
  * \union stdctimer_union_ex_uT;
  * \brief Descripcion breve sobre el tipo de union.
  * Elementos que componen la union:
  *   \li \ref item1 
  *   \li \ref item2 
  * \version 01v01d01.
  * \warning mensaje de "warning". 
  * \date Miercoles 24 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} stdctimer_union_ex_uT;


/**
  * \enum stdctimer_enum_eT;
  * \details Descripcion detallada sobre la redefinicion de enumeracio.
  * \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
  * Elementos que componen la enumeracion:
  *  \li \ref stdctimer_eITEM0 . 
  *  \li \ref stdctimer_eITEM1 .
  *  \li \ref stdctimer_eITEM2 .
  * \version 01v01d01.
  * \warning mensaje de "warning".
  * \date Miercoles 24 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  stdctimer_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'stdctimer_eITEM0' de Enumeracion */
  stdctimer_eITEM1,     /**<@brief descripcion breve de la etiqueta 'stdctimer_eITEM1' de Enumeracion */
  stdctimer_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'stdctimer_eITEM2' de Enumeracion */
} stdctimer_enum_eT;

#endif /* #if(stdctimer_USE_GlobalTypedef == 1) */
/* 
  * ======================[ END   Global typedef      ]=============================
  */

/* 
  * ======================[ BEGIN local declaration   ]=============================
  */
#ifdef __stdctimer_c__


#endif /* #ifdef __stdctimer_c__ */
/* 
  * ======================[ END   local declaration   ]=============================
  */


/* 
  * ======================[ BEGIN Global declaration  ]=============================
  */
#if (stdctimer_USE_GlobalData==1)
extern unsigned int stdctimer_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (stdctimer_USE_GlobalData==1) */
/* 
  * ======================[ END   Global declaration  ]=============================
  */

/* 
  * ======================[ BEGIN Global functions declaration ]====================
  */
#if (stdctimer_USE_GlobalFunctions == 1)
/** 
  * 
  * ******************************************************************************* 
  * \fn int stdctimer_test_01(unsigned int a,const char* name);
  * \details Descripcion detallada sobre la funcion \ref stdctimer_test_01().
  * \brief descripcion breve sobre la funcion, \ref stdctimer_test_01().
  * \param a : Puntero al array.
  * \param name : longitud del array.
  * \return status de la opreacion.
  *      \li 0, success
  *      \li 1, failure
  * \version 01v01d01.
  * \note notq.
  * \warning mensaje de "warning". 
  * \date Miercoles 24 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
  * \par example :
  * <PRE>
  * 
  * </PRE>  
  *********************************************************************************/
bool_t stdctimer_msleep(uint32_t msec, int *errnotify);


#define stdctimer_SLEEP_SEG   0x01    /**<@brief  */
#define stdctimer_SLEEP_ms    0x02    /**<@brief  */
#define stdctimer_SLEEP_us    0x03    /**<@brief  */
#define stdctimer_SLEEP_ns    0x04    /**<@brief  */
/********************************************************************
 * @brief funcion que realiza un sleep usando la configuracion de timespec
 * con alta resoluccion.
 * @param time      : Tiempo
 * @param type      : Tipo de base de tiempo 
 *      \li stdctimer_SLEEP_SEG
 *      \li stdctimer_SLEEP_ms
 *      \li stdctimer_SLEEP_us
 *      \li stdctimer_SLEEP_ns
 *  'segundos'puntero al buffer del string
 * @param errnotify :
 * @return valor del tipo int
 *********************************************************************/
bool_t stdctimer_sleepspec(uint32_t time, uint8_t type,int *errnotify);


#define stdctimer_sleep(Msec, Errnotify)\
    stdctimer_sleepspec(Msec,stdctimer_SLEEP_SEG,Errnotify)

#define stdctimer_mssleep(Msec, Errnotify)\
    stdctimer_sleepspec(Msec,stdctimer_SLEEP_ms,Errnotify)

#define stdctimer_ussleep(Msec, Errnotify)\
    stdctimer_sleepspec(Msec,stdctimer_SLEEP_us,Errnotify)

#define stdctimer_nssleep(Msec, Errnotify)\
    stdctimer_sleepspec(Msec,stdctimer_SLEEP_ns,Errnotify)
/**
  * 
  * ******************************************************************************* 
  * \fn int stdctimer_test_02(unsigned int a,const char* name);
  * \details Descripcion detallada sobre la funcion \ref stdctimer_test_02().
  * \brief descripcion breve sobre la funcion, \ref stdctimer_test_02().
  * \param a : Puntero al array.
  * \param name : longitud del array.
  * \return status de la opreacion.
  *      \li 0, success
  *      \li 1, failure
  * \version 01v01d01.
  * \note notq.
  * \warning mensaje de "warning". 
  * \date Miercoles 24 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
  * \par example :
  * <PRE>
  * 
  * </PRE>  
  *********************************************************************************/
// int stdctimer_test_02(unsigned int a,const char* name);

#endif /* #if (stdctimer_USE_GlobalFunctions == 1) */
/* 
  * ======================[ END   Global functions declaration ]====================
  */

/* 
  * ======================[ BEGIN Global Macros functions ]=========================
  */
#if ( stdctimer_USE_GlobalMacroApis == 1 )
/**
  * 
  * ********************************************************************************
  * \def stdctimer_macro_ex(Arg1,Arg2)
  * \details Descripcion detallada sobre la macro funcion \ref stdctimer_macro_ex().
  * \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
  * \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
  *
  * \brief Descripcion breve sobre la macro funcion \ref stdctimer_macro_ex().
  * \param Arg1 : Argumento uno, de la macro funcion.
  * \param Arg2 : Argumento dos, de la macro funcion.
  * \return nothinig
  * \version 01v01d01.
  * \note nota.
  * \warning mensaje de "warning".
  * \date Miercoles 24 de Marzo, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
  * \par example :
  * <PRE>
  * 
  * </PRE> 
  *********************************************************************************/ 
#define stdctimer_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( stdctimer_USE_GlobalMacroApis == 1 ) */
/* 
  * ======================[ END   Global Macros functions ]=========================
  */



/*
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ END   __stdctimer_version__    01v00d00 ]───────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  *
  */
#elif (version_QueryNumber(__stdctimer_version__,01v00d01))
/* 
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ BEGIN __stdctimer_version__    01v00d01 ]───────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */



/*
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ─────────────────────[ END   __stdctimer_version__    01v00d01 ]───────────────────── │
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
#endif /* #ifndef __stdctimer_h__ */
/*
 * 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =============================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(stdctimer_projectEnable == 1) */

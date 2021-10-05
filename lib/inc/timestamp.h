#ifndef timestamp_projectEnable
#define timestamp_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup miscellaneus 
* @{ borrarme, solo para mantener la identacion -> }@
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of miscellaneus .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file timestamp.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v01d00.
* \date Jueves 04 de Marzo, 2021.
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


#ifndef __timestamp_h__
#define __timestamp_h__ /**<@brief Definimos el Nombre del modulo */


#if (timestamp_projectEnable == 1)

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
#include <version.h>

/* 
* ======================[ END   include header file ]=================================
*/

/* 
* ======================[ BEGIN labels enable/disable ]===============================
*/
#define timestamp_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define timestamp_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define timestamp_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define timestamp_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define timestamp_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
* \def __timestamp_version__ definimos la version actual del proyecto.
* version 01v00d00 -> test 
* version 01v00d01 -> test 
* version 01v00d02 -> test
* version 01v00d03 -> test
* version 01v00d04 -> test
* version 01v00d05 -> test
*
* */
#ifndef __timestamp_version__
#define __timestamp_version__        version_SetNumber(01v00d00)
#endif

/* 
* ======================[ END   labels enable/disable ]===============================
*/


#if (version_QueryNumber(__timestamp_version__,01v00d00))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ─────────────────────[ BEGIN __timestamp_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
/* 
* ======================[ BEGIN Global Macros/labels definition ]=================
*/
#if (timestamp_USE_GlobalMacro == 1)

#define timestamp_FMT_DDMMYYYY                   0x00 /* Dia Mes Año */
#define timestamp_FMT_DDYYYYMM                   0x01 /* Dia Año Mes */
#define timestamp_FMT_MMDDYYYY                   0x02 /* Mes Dia Año */
#define timestamp_FMT_MMYYYYDD                   0x03 /* Mes Año Dia */
#define timestamp_FMT_YYYYMMDD                   0x04 /* Año Mes Dia */
#define timestamp_FMT_YYYYDDMM                   0x05 /* Año Dia Mes */

#define timestamp_FMT_DDMMYY                     0x10 /* Dia Mes Año */
#define timestamp_FMT_DDYYMM                     0x11 /* Dia Año Mes */
#define timestamp_FMT_MMDDYY                     0x12 /* Mes Dia Año */
#define timestamp_FMT_MMYYDD                     0x13 /* Mes Año Dia */
#define timestamp_FMT_YYMMDD                     0x14 /* Año Mes Dia */
#define timestamp_FMT_YYDDMM                     0x15 /* Año Dia Mes */


#define timestamp_FMT_HHMMSS                     0x0C /* Hora Minutos Segundos, este formato excluye la fecha */






#endif /* #if(timestamp_USE_GlobalMacro == 1) */
/* 
* ======================[ END   Global Macros/labels definition ]=================
*/


/* 
* ======================[ BEGIN Global typedef      ]=============================
*/
#if (timestamp_USE_GlobalTypedef == 1)


typedef struct
{
  uint8_t hh;       /**<@brief Variable que almacena los Horas */
  uint8_t mm;       /**<@brief Variable que almacena los Minutos */
  uint8_t ss;       /**<@brief Variable que almacena los Segundos */
}timestamp_time_t; 

typedef struct
{
  uint16_t year;    /**<@brief Argumento para almacenar el Año */
  uint8_t month;    /**<@brief Item que almacena el numero que representa el mes */
  uint8_t day;      /**<@brief Item que almacena el numero que representa el dia */  
}timestamp_date_t; 


/**
* \struct timestamp_t;
* \brief Estructura para almacenar la hora y la fecha.
*  \li \ref year;
*  \li \ref month;
*  \li \ref day;
*  \li \ref hh;
*  \li \ref mm;
*  \li \ref ss;
* \version 01v01d00.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Jueves 04 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  uint16_t year;    /**<@brief Argumento para almacenar el Año */
  uint8_t month;    /**<@brief Item que almacena el numero que representa el mes */
  uint8_t day;      /**<@brief Item que almacena el numero que representa el dia */
  uint8_t hh;       /**<@brief Variable que almacena los Horas */
  uint8_t mm;       /**<@brief Variable que almacena los Minutos */
  uint8_t ss;       /**<@brief Variable que almacena los Segundos */
}timestamp_t;  


#if 0
/**
* \typedef timestamp_tvar_ex_vT;
* \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
* \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
* \version 01v01d00.
* \note nota.
* \warning mensaje de "warning". 
* \date Jueves 04 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int timestamp_tvar_ex_vT;


/**
* \typedef timestamp_pfun_ex_fT;
* \details Descripcion detallada sobre la redefinicion de puntero a funcion.
* \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
* Prototipo de la funcion, al acual debe apuntar:
*  + void * function ( void * arg )
* \version 01v01d00.
* \note nota.
* \warning mensaje de "warning". 
* \date Jueves 04 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*timestamp_pfun_ex_fT) (void *); 
/**
* \union timestamp_union_ex_uT;
* \brief Descripcion breve sobre el tipo de union.
* Elementos que componen la union:
*   \li \ref item1 
*   \li \ref item2 
* \version 01v01d00.
* \warning mensaje de "warning". 
* \date Jueves 04 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} timestamp_union_ex_uT;


/**
* \enum timestamp_enum_eT;
* \details Descripcion detallada sobre la redefinicion de enumeracio.
* \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
* Elementos que componen la enumeracion:
*  \li \ref timestamp_eITEM0 . 
*  \li \ref timestamp_eITEM1 .
*  \li \ref timestamp_eITEM2 .
* \version 01v01d00.
* \warning mensaje de "warning".
* \date Jueves 04 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  timestamp_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'timestamp_eITEM0' de Enumeracion */
  timestamp_eITEM1,     /**<@brief descripcion breve de la etiqueta 'timestamp_eITEM1' de Enumeracion */
  timestamp_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'timestamp_eITEM2' de Enumeracion */
} timestamp_enum_eT;
#endif

#endif /* #if(timestamp_USE_GlobalTypedef == 1) */
/* 
* ======================[ END   Global typedef      ]=============================
*/

/* 
* ======================[ BEGIN local declaration   ]=============================
*/
#ifdef __timestamp_c__


#endif /* #ifdef __timestamp_c__ */
/* 
* ======================[ END   local declaration   ]=============================
*/


/* 
* ======================[ BEGIN Global declaration  ]=============================
*/
#if (timestamp_USE_GlobalData==1)
extern unsigned int timestamp_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (timestamp_USE_GlobalData==1) */
/* 
* ======================[ END   Global declaration  ]=============================
*/

/* 
* ======================[ BEGIN Global functions declaration ]====================
*/
#if (timestamp_USE_GlobalFunctions == 1)
/** 
* 
* ******************************************************************************* 
* \fn int timestamp_test_01(unsigned int a,const char* name);
* \details Descripcion detallada sobre la funcion \ref timestamp_test_01().
* \brief descripcion breve sobre la funcion, \ref timestamp_test_01().
* \param a : Puntero al array.
* \param name : longitud del array.
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v01d00.
* \note notq.
* \warning mensaje de "warning". 
* \date Jueves 04 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
bool_t timestamp_FillStruct(timestamp_t *pt);

/**
* 
* ******************************************************************************* 
* \fn int timestamp_test_02(unsigned int a,const char* name);
* \details Descripcion detallada sobre la funcion \ref timestamp_test_02().
* \brief descripcion breve sobre la funcion, \ref timestamp_test_02().
* \param a : Puntero al array.
* \param name : longitud del array.
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v01d00.
* \note notq.
* \warning mensaje de "warning". 
* \date Jueves 04 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
bool_t timestamp_FillBuff( char * buff,size_t lbuff,const char * sep \
                           /* "/:" "-:" "::" "--" datetime*/,uint8_t fmt);



#endif /* #if (timestamp_USE_GlobalFunctions == 1) */
/* 
* ======================[ END   Global functions declaration ]====================
*/

/* 
* ======================[ BEGIN Global Macros functions ]=========================
*/
#if ( timestamp_USE_GlobalMacroApis == 1 )
/**
* 
* ********************************************************************************
* \def timestamp_macro_ex(Arg1,Arg2)
* \details Descripcion detallada sobre la macro funcion \ref timestamp_macro_ex().
* \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
* \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
*
* \brief Descripcion breve sobre la macro funcion \ref timestamp_macro_ex().
* \param Arg1 : Argumento uno, de la macro funcion.
* \param Arg2 : Argumento dos, de la macro funcion.
* \return nothinig
* \version 01v01d00.
* \note nota.
* \warning mensaje de "warning".
* \date Jueves 04 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/ 
#define timestamp_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( timestamp_USE_GlobalMacroApis == 1 ) */
/* 
* ======================[ END   Global Macros functions ]=========================
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ──────────────────────[ END   __timestamp_version__    01v00d00 ]────────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (version_QueryNumber(__timestamp_version__,01v00d01))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ─────────────────────[ BEGIN __timestamp_version__    01v00d01 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ─────────────────────[ END   __timestamp_version__    01v00d01 ]───────────────────── │
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
#endif /* #ifndef __timestamp_h__ */
/*
*
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =============================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(timestamp_projectEnable == 1) */

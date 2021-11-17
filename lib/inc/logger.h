#ifndef logger_projectEnable
#define logger_projectEnable 1 /**<@brief enable/disable the project */
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
* \file logger.h
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


#ifndef __logger_h__
#define __logger_h__ /**<@brief Definimos el Nombre del modulo */


#if ((logger_projectEnable == 1) && defined(SO_LINUX))

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
#include <stdctype.h>
#include <stdc_print.h>

/* 
* ======================[ END   include header file ]=================================
*/

/* 
* ======================[ BEGIN labels enable/disable ]===============================
*/
#define logger_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define logger_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define logger_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define logger_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define logger_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
* \def __logger_version__ definimos la version actual del proyecto.
* version 01v00d00 -> test 
* version 01v00d01 -> test 
* version 01v00d02 -> test
* version 01v00d03 -> test
* version 01v00d04 -> test
* version 01v00d05 -> test
*
* */
#ifndef __logger_version__
#define __logger_version__        version_SetNumber(01v00d00)
#endif

/* 
* ======================[ END   labels enable/disable ]===============================
*/


#if (version_QueryNumber(__logger_version__,01v00d00))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────────[ BEGIN __logger_version__    01v00d00 ]────────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
/* 
* ======================[ BEGIN Global Macros/labels definition ]=================
*/
#if (logger_USE_GlobalMacro == 1)

#define logger_WARNING    0x04 /**<@brief */
#define logger_ERROR      0x02 /**<@brief */
#define logger_OK         0x03 /**<@brief */
#define logger_INFO       0x05 /**<@brief */

#define logger_CURRENT    0x00 /**<@brief */


#define logger_TRUNCATED  0x10 /**<@brief */
#define logger_APPEND     0x20 /**<@brief */

#define logger_SN_TIMESTAMP   0x80 /**<@brief cuando deseamos loggear mensaje sin timestamp  */


#endif /* #if(logger_USE_GlobalMacro == 1) */
/* 
* ======================[ END   Global Macros/labels definition ]=================
*/


/* 
* ======================[ BEGIN Global typedef      ]=============================
*/
#if (logger_USE_GlobalTypedef == 1)


/**
* \struct logger_struct_ex_sT;
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
  char * path ; /**<@brief ruta del Archivo, es la unica variable que perdura dourante 
                           todo el proceso del logger . */
  char * mode ; /**<@brief Modo de apertura,  */  
  FILE * file ; /**<@brief Archivo de logger */
  uint8_t timestamp_fmt;
  char timestamp_sep[4];
} logger_hdl_t ; 


#if 0
/**
* \typedef logger_tvar_ex_vT;
* \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
* \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int logger_tvar_ex_vT;


/**
* \typedef logger_pfun_ex_fT;
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
typedef void * (*logger_pfun_ex_fT) (void *); 




/**
* \union logger_union_ex_uT;
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
} logger_union_ex_uT;


/**
* \enum logger_enum_eT;
* \details Descripcion detallada sobre la redefinicion de enumeracio.
* \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
* Elementos que componen la enumeracion:
*  \li \ref logger_eITEM0 . 
*  \li \ref logger_eITEM1 .
*  \li \ref logger_eITEM2 .
* \version 01v01d01.
* \warning mensaje de "warning".
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  logger_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'logger_eITEM0' de Enumeracion */
  logger_eITEM1,     /**<@brief descripcion breve de la etiqueta 'logger_eITEM1' de Enumeracion */
  logger_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'logger_eITEM2' de Enumeracion */
} logger_enum_eT;

#endif

#endif /* #if(logger_USE_GlobalTypedef == 1) */
/* 
* ======================[ END   Global typedef      ]=============================
*/

/* 
* ======================[ BEGIN local declaration   ]=============================
*/
#ifdef __logger_c__


#endif /* #ifdef __logger_c__ */
/* 
* ======================[ END   local declaration   ]=============================
*/


/* 
* ======================[ BEGIN Global declaration  ]=============================
*/
#if (logger_USE_GlobalData==1)
extern unsigned int logger_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (logger_USE_GlobalData==1) */
/* 
* ======================[ END   Global declaration  ]=============================
*/

/* 
* ======================[ BEGIN Global functions declaration ]====================
*/
#if (logger_USE_GlobalFunctions == 1)
/** 
* 
* ******************************************************************************* 
* \fn bool_t logger_init(logger_hdl_t *phdl,size_t len,...);
* \brief descripcion breve sobre la funcion, \ref logger_test_01().
* \param phdl : Puntero al Handler o vector de Handler.
* \param len : cantidad de handler
* \param ... : por cada Hanlder debemos pasar los item String {path,mode}
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
// bool_t logger_init(logger_hdl_t *phdl,size_t len,.../*const char *path, const char * mode*/);
bool_t logger_init(int *errnum,logger_hdl_t *phdl,size_t len,.../*const char *path, const char * mode*/);
/**
* 
* ******************************************************************************* 
* \fn bool_t logger_printf(uint32_t nlogg, uint8_t logtype, const char *fmt, ... );
* \brief 
* \param nlogg : numero/id del Log dentro del array con el cual se inicializo la APIs.
* \param logtype : tipo de log
*   \li logger_OK
*   \li logger_ERROR
*   \li logger_WARNING
*   \li logger_INFO
* \param fmt string con el formato.
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
bool_t logger_printf(int *errnum,uint32_t nlogg, uint8_t logtype, const char *fmt, ... );
/**
* 
* ******************************************************************************* 
* \fn bool_t logger_debug( int *errnum,uint32_t nlogg, uint8_t logtype, const char *namefile,const char *namefn ,uint32_t nline, const char *fmt, ... );
* \brief Funcion para imprimir en un log/archivo logger informacion correspondiente 
* a un evento. En este logger se adjunta informacion de Archivo,Funcion y linea 
* desde donde se logea el evento, con la finalidad de depurar el codigo.
* \param errnum : puntero a un entero para almacenar el error en caso que ocurra.
* Podemos pasar NULL en caso de no necesitar el mismo.
* \param nlogg : Numero que representa el contexto del logger, este depende de la 
* creacion, cuantos archivos tendremos para logger.
* \param logtype : tipo de log, este puede ser 
*   \li logger_OK
*   \li logger_ERROR
*   \li logger_WARNING
*   \li logger_INFO
* \param namefile : Nombre del Archivo, podemos usar la macro __FILE__
* \param namefn : Nombre de la funcion, podemos usar __FUNCTION__
* \param nline : Numero de linea,  __LINE__
* \param fmt : String con formato
* \param ... : demas argumentos especificados por el string fmt.
* \return status de la opreacion.
*      \li TURE, success
*      \li FALSE, failure si pasamso el puntero en errnum almacenamos en el 
* error ocurrido.
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
bool_t logger_debug( int *errnum,uint32_t nlogg, uint8_t logtype \
                   , const char *namefile,const char *namefn ,uint32_t nline, const char *fmt, ... );

/********************************************************************************//**
* \def logger_mdebug(nlogg, logtype, ... )
* \brief Macro function para imprimir informacion utili para depuracion
* de codigo. Es idem a \ref logger_debug() excepto que se carga de forma 
* automatica las macros de FILE, LINE, FUCNTION. Este no considera el 
* puntero a la variable donde podemos salvar un error ocurrido.
* \param nlogg : numero/id del Log dentro del array con el cual se inicializo la APIs.
* \param logtype : tipo de log
*   \li logger_OK
*   \li logger_ERROR
*   \li logger_WARNING
*   \li logger_INFO
* \param ... listado de demas parametros.
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
#define logger_mdebug(nlogg, logtype, ... ) \
    logger_debug(NULL,nlogg, logtype,__FILE__,__FUNCTION__,__LINE__, __VA_ARGS__)
  
/********************************************************************************//**
* \def logger_macro_ex(Arg1,Arg2)
* \brief idem a logger_printf() pero en esta no pasamos el puntero a error.
* \param nlogg : numero/id del Log dentro del array con el cual se inicializo la APIs.
* \param logtype : tipo de log
*   \li logger_OK
*   \li logger_ERROR
*   \li logger_WARNING
*   \li logger_INFO
* \param ... listado de demas parametros.
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
#define logger_mprintf(nlogg, logtype, ... ) \
    logger_printf(NULL,nlogg, logtype, __VA_ARGS__)   


 
/********************************************************************************//**
* \def LOGGER_INFO_DEBUG(nlogg, logtype, ... )
* \brief imprime informacion para debiug, dentro del logger file establecido,
* si esta hbilitado el DEBUG_ENABLE muestra toda la informacion pertinente
* como FILE, FUNCTION, LINE y el mensaje con formato.
* De lo contrario solo muestra la informacion del mensaje con formato.
* \param nlogg : numero/id del Log dentro del array con el cual se inicializo la APIs.
* \param logtype : tipo de log
*   \li logger_OK
*   \li logger_ERROR
*   \li logger_WARNING
*   \li logger_INFO
* \param ... listado de demas parametros.
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
/********************************************************************************//**
* \def LOGGER_ONLY_DEBUG(nlogg, logtype, ... )
* \brief imprime informacion para debiug, dentro del logger file establecido,
* solamente si esta habilitado el DEBUG_ENABLE. De lo contrario no tiene importancia
* es descartado el llamado a esta macro.
* \param nlogg : numero/id del Log dentro del array con el cual se inicializo la APIs.
* \param logtype : tipo de log
*   \li logger_OK
*   \li logger_ERROR
*   \li logger_WARNING
*   \li logger_INFO
* \param ... listado de demas parametros.
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
#if (defined(DEBUG_ENABLE))
  #define LOGGER_INFO_DEBUG(nlogg, logtype, ... ) \
    logger_debug(NULL,nlogg, logtype,__FILE__,__FUNCTION__,__LINE__, __VA_ARGS__)
    
  #define LOGGER_ONLY_DEBUG(nlogg, logtype, ... ) \
    logger_debug(NULL,nlogg, logtype,__FILE__,__FUNCTION__,__LINE__, __VA_ARGS__)
  
#else /* #if (defined(DEBUG_ENABLE)) */
  #define LOGGER_INFO_DEBUG(nlogg, logtype, ... ) \
    logger_printf(NULL,nlogg, logtype, __VA_ARGS__)
    
  #define LOGGER_ONLY_DEBUG(nlogg, logtype, ... )
    
#endif /* #if (defined(DEBUG_ENABLE)) */
    

    

    
 

    

/*bool_t logger_dateprintf(uint8_t logtype, const char *fmt, ... );*/

void logger_deinit(void);
#endif /* #if (logger_USE_GlobalFunctions == 1) */
/* 
* ======================[ END   Global functions declaration ]====================
*/

/* 
* ======================[ BEGIN Global Macros functions ]=========================
*/
#if ( logger_USE_GlobalMacroApis == 1 )
/**
* 
* ********************************************************************************
* \def logger_macro_ex(Arg1,Arg2)
* \details Descripcion detallada sobre la macro funcion \ref logger_macro_ex().
* \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
* \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
*
* \brief Descripcion breve sobre la macro funcion \ref logger_macro_ex().
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
#define logger_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( logger_USE_GlobalMacroApis == 1 ) */
/* 
* ======================[ END   Global Macros functions ]=========================
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────────[ END   __logger_version__    01v00d00 ]────────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (version_QueryNumber(__logger_version__,01v00d01))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────────[ BEGIN __logger_version__    01v00d01 ]────────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/

/* 
* ======================[ BEGIN Global Macros/labels definition ]=================
*/
#if (logger_USE_GlobalMacro == 1)

#define logger_WARNING    0x04 /**<@brief */
#define logger_ERROR      0x02 /**<@brief */
#define logger_OK         0x03 /**<@brief */
#define logger_INFO       0x05 /**<@brief */

#define logger_CURRENT    0x00 /**<@brief */


#define logger_TRUNCATED  0x10 /**<@brief */
#define logger_APPEND     0x20 /**<@brief */


#endif /* #if(logger_USE_GlobalMacro == 1) */
/* 
* ======================[ END   Global Macros/labels definition ]=================
*/


/* 
* ======================[ BEGIN Global typedef      ]=============================
*/
#if (logger_USE_GlobalTypedef == 1)


/**
* \struct logger_struct_ex_sT;
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
  char * path ; /**<@brief descripcion del item vtchar */
  char * mode ; /**<@brief descripcion del item vtint */  
  FILE * file ; /**<@brief */
} logger_hdl_t ; 


#if 0
/**
* \typedef logger_tvar_ex_vT;
* \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
* \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int logger_tvar_ex_vT;


/**
* \typedef logger_pfun_ex_fT;
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
typedef void * (*logger_pfun_ex_fT) (void *); 




/**
* \union logger_union_ex_uT;
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
} logger_union_ex_uT;


/**
* \enum logger_enum_eT;
* \details Descripcion detallada sobre la redefinicion de enumeracio.
* \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
* Elementos que componen la enumeracion:
*  \li \ref logger_eITEM0 . 
*  \li \ref logger_eITEM1 .
*  \li \ref logger_eITEM2 .
* \version 01v01d01.
* \warning mensaje de "warning".
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  logger_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'logger_eITEM0' de Enumeracion */
  logger_eITEM1,     /**<@brief descripcion breve de la etiqueta 'logger_eITEM1' de Enumeracion */
  logger_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'logger_eITEM2' de Enumeracion */
} logger_enum_eT;

#endif

#endif /* #if(logger_USE_GlobalTypedef == 1) */
/* 
* ======================[ END   Global typedef      ]=============================
*/

/* 
* ======================[ BEGIN local declaration   ]=============================
*/
#ifdef __logger_c__


#endif /* #ifdef __logger_c__ */
/* 
* ======================[ END   local declaration   ]=============================
*/


/* 
* ======================[ BEGIN Global declaration  ]=============================
*/
#if (logger_USE_GlobalData==1)
extern unsigned int logger_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (logger_USE_GlobalData==1) */
/* 
* ======================[ END   Global declaration  ]=============================
*/

/* 
* ======================[ BEGIN Global functions declaration ]====================
*/
#if (logger_USE_GlobalFunctions == 1)
/** 
* 
* ******************************************************************************* 
* \fn int logger_test_01(unsigned int a,const char* name);
* \details Descripcion detallada sobre la funcion \ref logger_test_01().
* \brief descripcion breve sobre la funcion, \ref logger_test_01().
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
bool_t logger_init(logger_hdl_t *phdl,const char *path, const char * mode);
/**
* 
* ******************************************************************************* 
* \fn int logger_test_02(unsigned int a,const char* name);
* \details Descripcion detallada sobre la funcion \ref logger_test_02().
* \brief descripcion breve sobre la funcion, \ref logger_test_02().
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
bool_t logger_printf(logger_hdl_t *phdl, uint8_t logtype, const char *fmt, ... );


bool_t logger_dateprintf(logger_hdl_t *phdl, uint8_t logtype, const char *fmt, ... );

#endif /* #if (logger_USE_GlobalFunctions == 1) */
/* 
* ======================[ END   Global functions declaration ]====================
*/

/* 
* ======================[ BEGIN Global Macros functions ]=========================
*/
#if ( logger_USE_GlobalMacroApis == 1 )
/**
* 
* ********************************************************************************
* \def logger_macro_ex(Arg1,Arg2)
* \details Descripcion detallada sobre la macro funcion \ref logger_macro_ex().
* \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
* \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
*
* \brief Descripcion breve sobre la macro funcion \ref logger_macro_ex().
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
#define logger_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( logger_USE_GlobalMacroApis == 1 ) */
/* 
* ======================[ END   Global Macros functions ]=========================
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────────[ END   __logger_version__    01v00d01 ]────────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__logger_version__,01v00d02))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────────[ BEGIN __logger_version__    01v00d02 ]────────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────────[ END   __logger_version__    01v00d02  ]────────────────────── │
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
#endif /* #ifndef __logger_h__ */
/*
*
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =============================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(logger_projectEnable == 1) */

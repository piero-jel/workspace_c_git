#ifndef serialterminal_projectEnable
#define serialterminal_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup modules 
* @{ 
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of modules .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file serialterminal.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v01d01.
* \date Martes 02 de Marzo, 2021.
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


#ifndef __serialterminal_h__
#define __serialterminal_h__ /**<@brief Definimos el Nombre del modulo */


#if (serialterminal_projectEnable == 1 && defined(SO_LINUX))

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
#include <stdio.h>    /* Libreria estandar de entrada salida */
#include <termios.h>  /* Contains POSIX terminal control definitions */
#include <version.h>
#include <assert.h>
#include <stdctype.h> /* Redefinicion de variables primitivas */
#include <stdc_print.h>

/* 
* ======================[ END   include header file ]=================================
*/

/* 
* ======================[ BEGIN labels enable/disable ]===============================
*/
#define serialterminal_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define serialterminal_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define serialterminal_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define serialterminal_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define serialterminal_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
* \def __serialterminal_version__ definimos la version actual del proyecto.
* version 01v00d00 -> test 
* version 01v00d01 -> test 
* version 01v00d02 -> test
* version 01v00d03 -> test
* version 01v00d04 -> test
* version 01v00d05 -> test
*
* */
#ifndef __serialterminal_version__
#define __serialterminal_version__        version_SetNumber(01v00d00)
#endif

/* 
* ======================[ END   labels enable/disable ]===============================
*/


#if (version_QueryNumber(__serialterminal_version__,01v00d00))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN __serialterminal_version__    01v00d00 ]────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
/* 
* ======================[ BEGIN Global Macros/labels definition ]=================
*/
#if (serialterminal_USE_GlobalMacro == 1)

#define serialterminal_NAME_PORT_LENG   64 /**<@brief definimos la longitud del buffer que contendra el 
nombre del puerto de la terminal seria a abrir */

#define serialterminal_SYSTEM_PATH  "/dev/"
#endif /* #if(serialterminal_USE_GlobalMacro == 1) */
/* 
* ======================[ END   Global Macros/labels definition ]=================
*/


/* 
* ======================[ BEGIN Global typedef      ]=============================
*/
#if (serialterminal_USE_GlobalTypedef == 1)

#if 0
/**
* \typedef serialterminal_tvar_ex_vT;
* \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
* \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Martes 02 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int serialterminal_tvar_ex_vT;


/**
* \typedef serialterminal_pfun_ex_fT;
* \details Descripcion detallada sobre la redefinicion de puntero a funcion.
* \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
* Prototipo de la funcion, al acual debe apuntar:
*  + void * function ( void * arg )
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Martes 02 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*serialterminal_pfun_ex_fT) (void *); 


/**
* \union serialterminal_union_ex_uT;
* \brief Descripcion breve sobre el tipo de union.
* Elementos que componen la union:
*   \li \ref item1 
*   \li \ref item2 
* \version 01v01d01.
* \warning mensaje de "warning". 
* \date Martes 02 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} serialterminal_union_ex_uT;


/**
* \enum serialterminal_enum_eT;
* \details Descripcion detallada sobre la redefinicion de enumeracio.
* \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
* Elementos que componen la enumeracion:
*  \li \ref serialterminal_eITEM0 . 
*  \li \ref serialterminal_eITEM1 .
*  \li \ref serialterminal_eITEM2 .
* \version 01v01d01.
* \warning mensaje de "warning".
* \date Martes 02 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  serialterminal_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'serialterminal_eITEM0' de Enumeracion */
  serialterminal_eITEM1,     /**<@brief descripcion breve de la etiqueta 'serialterminal_eITEM1' de Enumeracion */
  serialterminal_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'serialterminal_eITEM2' de Enumeracion */
} serialterminal_enum_eT;
#endif



/**
* \struct serialterminal_struct_ex_sT;
* \brief Descripcion breve sobre el tipo de estructura.
* Elementos que componen a la Estructura de datos:
*  \li \ref vtchar;
*  \li \ref vtint;
*  \li \ref vtdouble;
* \version 01v01d01.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Martes 02 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{ 
  struct termios opt;      /**<@brief estrucutura de configuracion de la terminal */
  struct termios optsave; /**<@brief Puntero a estrucutura de configuracion para salvar la configuracion que es reservada  */
  bool_t autosave; /**<@brief Habilitamos/deshabilitamos el auto save/restore de la configuracion actual */
  int fd; /**<@brief descriptor de archivo que le corresponde */
  char name[serialterminal_NAME_PORT_LENG]; /**<@brief nombre de la terminal*/
  int BaudRate;
  int Frame;
  int CtrlFlow;  
} serialterminal_hdl_t ; 

typedef struct
{   
  uint32_t BaudRate;
  int Frame;
  int CtrlFlow;  
} serialterminal_cfg_t ; 


#endif /* #if(serialterminal_USE_GlobalTypedef == 1) */
/* 
* ======================[ END   Global typedef      ]=============================
*/

/* 
* ======================[ BEGIN local declaration   ]=============================
*/
#ifdef __serialterminal_c__


#endif /* #ifdef __serialterminal_c__ */
/* 
* ======================[ END   local declaration   ]=============================
*/


/* 
* ======================[ BEGIN Global declaration  ]=============================
*/
#if (serialterminal_USE_GlobalData==1)
extern unsigned int serialterminal_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (serialterminal_USE_GlobalData==1) */
/* 
* ======================[ END   Global declaration  ]=============================
*/

/* 
* ======================[ BEGIN Global functions declaration ]====================
*/
#if (serialterminal_USE_GlobalFunctions == 1)
/** 
* 
* ******************************************************************************* 
* \fn bool_t serialterminal_OpenPort( serialterminal_hdl_t *phdl, const char* port, bool_t autosave,int *errnum)
* \brief Funcion para abrir una termianl serie.
* \param phdl : Handler para manejar la terminal serie.
* \param port : nombre del Pueto
*   \li ttys0 ...
*   \li ttyACM1
*   \li ttyUSB0
* \param autosave Habilitamos deshabilitamos el auto save, en caso de 
* querer restaurar la configuracion anterior.  
* \param errnum Puntero donde se alamacenara el numero de error en caso de 
* falla en algunas de las operaciones, en caso de no necesitar el mismo 
* pasamos NULL.
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v01d01.
* \note note.
* \warning mensaje de "warning". 
* \date Martes 02 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
bool_t serialterminal_OpenPort( serialterminal_hdl_t *phdl, const char* port\
                              , bool_t autosave,int *errnum);
/** 
* 
* ******************************************************************************* 
* \fn int serialterminal_test_01(unsigned int a,const char* name);
* \details Descripcion detallada sobre la funcion \ref serialterminal_test_01().
* \brief descripcion breve sobre la funcion, \ref serialterminal_test_01().
* \param a : Puntero al array.
* \param name : longitud del array.
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Martes 02 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
bool_t serialterminal_ClosePort(serialterminal_hdl_t *phdl, bool_t autorestore,int *errnum);



/**
* 
* ******************************************************************************* 
* \fn int serialterminal_test_02(unsigned int a,const char* name);
* \details Descripcion detallada sobre la funcion \ref serialterminal_test_02().
* \brief descripcion breve sobre la funcion, \ref serialterminal_test_02().
* \param a : Puntero al array.
* \param name : longitud del array.
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Martes 02 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/

bool_t serialterminal_SetConfig( serialterminal_hdl_t *phdl, uint32_t baudrate \
                               , const char * Frame,int *errnum );


size_t serialterminal_Receive( serialterminal_hdl_t * phdl, void *pbuff \
                             , size_t lbuff, const char charEndRcv );

size_t serialterminal_Transmit( serialterminal_hdl_t * phdl,void *pbuff\
  ,size_t lbuff, const char charEndTrx );


int serialterminal_CheckBaudrate(uint32_t baudrate);

#endif /* #if (serialterminal_USE_GlobalFunctions == 1) */
/* 
* ======================[ END   Global functions declaration ]====================
*/

/* 
* ======================[ BEGIN Global Macros functions ]=========================
*/
#if ( serialterminal_USE_GlobalMacroApis == 1 )
/**
* 
* ********************************************************************************
* \def serialterminal_macro_ex(Arg1,Arg2)
* \details Descripcion detallada sobre la macro funcion \ref serialterminal_macro_ex().
* \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
* \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
*
* \brief Descripcion breve sobre la macro funcion \ref serialterminal_macro_ex().
* \param Arg1 : Argumento uno, de la macro funcion.
* \param Arg2 : Argumento dos, de la macro funcion.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Martes 02 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/ 
#define serialterminal_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( serialterminal_USE_GlobalMacroApis == 1 ) */
/* 
* ======================[ END   Global Macros functions ]=========================
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   __serialterminal_version__    01v00d00 ]────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (version_QueryNumber(__serialterminal_version__,01v00d01))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN __serialterminal_version__    01v00d01 ]────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   __serialterminal_version__    01v00d01 ]────────────────── │
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
#endif /* #ifndef __serialterminal_h__ */
/*
*
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =============================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(serialterminal_projectEnable == 1) */

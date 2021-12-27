#ifndef stdcmenu_projectEnable
#define stdcmenu_projectEnable 1 /**<@brief enable/disable the project */
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
* \file stdcmenu.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v00d01.
* \date Jueves 13 de Mayo, 2021.
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

#ifndef __stdcmenu_h__
#define __stdcmenu_h__ /**<@brief Definimos el Nombre del modulo */


#if (stdcmenu_projectEnable == 1)

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
#include <string.h>
#include <stdlib.h>


/* 
* ======================[ END   include header file ]=================================
*/

/* 
* ======================[ BEGIN labels enable/disable ]===============================
*/
#define stdcmenu_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define stdcmenu_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define stdcmenu_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define stdcmenu_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define stdcmenu_USE_GlobalMacroApis 1 /**<@brief enable/disable the use Gobal macros functions */

/**
* \def __stdcmenu_version__ definimos la version actual del proyecto.
* version 01v00d00 -> test 
* version 01v00d01 -> test 
* version 01v00d02 -> test
* version 01v00d03 -> test
* version 01v00d04 -> test
* version 01v00d05 -> test
*
* */
#ifndef __stdcmenu_version__
#define __stdcmenu_version__        version_SetNumber(01v00d00)
#endif

/* 
* ======================[ END   labels enable/disable ]===============================
*/
#if (version_QueryNumber(__stdcmenu_version__,01v00d00))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ──────────────────────[ BEGIN __stdcmenu_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
/* ======================[ BEGIN Global Macros/labels definition ]================= */
#if (stdcmenu_USE_GlobalMacro == 1)

#define stdcmenu_FLAGS_OPGETED      0x01  /**<@brief */
#define stdcmenu_FLAGS_OPRESMEM     0x02  /**<@brief */

#define stdcmenu_PRINT_OPTS         0x0001  /**<@brief options short */
#define stdcmenu_PRINT_OPTL         0x0002  /**<@brief options long */
#define stdcmenu_PRINT_OPT          0x0003  /**<@brief options */
#define stdcmenu_PRINT_FMT          0x0004  /**<@brief format */
#define stdcmenu_PRINT_ARGC         0x0008  /**<@brief argument count */
#define stdcmenu_PRINT_HELP         0x0010  /**<@brief msg help */
#define stdcmenu_PRINT_ID           0x0020  /**<@brief unique identificador number */
#define stdcmenu_PRINT_FLAGS        0x0040  /**<@brief flags */

#endif /* #if(stdcmenu_USE_GlobalMacro == 1) */
/* ======================[ END   Global Macros/labels definition ]================= */
/* ======================[ BEGIN Global typedef      ]============================= */
#if (stdcmenu_USE_GlobalTypedef == 1)

/**
* \typedef stdcmenu_uopnum_t;
* \brief Redefinicion de tipo de variable para almacenar el numero de 
* operandos por argumentos del tipo sin signo.
* \version 01v00d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Jueves 13 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef uint8_t stdcmenu_uopnum_t;

/**
* \typedef stdcmenu_opnum_t;
* \brief Redefinicion de tipo de variable para almacenar el numero de 
* operandos por argumentos del tipo con signo, para notificacion de error 
* en caso de ser necesarios.
* \version 01v00d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Jueves 13 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef uint8_t stdcmenu_opnum_t;

/**
* \struct stdcmenu_getopt_t;
* \brief Esctructura de datos para representar un menu o array de opciones.
*  \li \ref opt_short
*  \li \ref opt_long
*  \li \ref fmt
*  \li \ref help
*  \li \ref id
*  \li \ref flags
*  \li \ref argv
*  \li \ref argc
*  \li \ref callback
*  \li \ref rval_callback
* \version 01v00d00.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct __stdcmenu_getopt_t
{
  char *opt_short ; /**<@brief Opcion Corta, guion medio y una sola letra */
  char *opt_long  ; /**<@brief Opcion Larga, dos guiones mediso y 
    palabras sin espacios */  
  char *fmt;        /**<@brief String con formato, para especificar los 
    argumentos esperados, hasta cuatro */  
  char *help; /**<@brief Mensaje breve de ayuda */
    
  uint32_t id; /**<@brief Numero de identificacion para el item, es colocado por el usuario */
  uint8_t flags; /**<@brief Flags Internos relacionado a item */
  char **argv; /**<@brief array de operandos por argumentos ingresado */
  stdcmenu_uopnum_t argc; /**<@brief numero de operandos por argumentos ingresados*/
  /** FIXME: deberiamos pasarle el puntero y el index, de esta forma pasamos al callback
   * el menu completo y el index al cual corresponde el callback, con la finalidad de sacar
   * mas info. Para ello debemos acompañar con mas APIs para obtener info desde el interior
   * del callback  */
  void (*callback) (struct __stdcmenu_getopt_t*); /**<@brief funcion de callback
  la cual se invocara cuando se terminen de identificar los operanodos */
  void **rval_callback; /**<@brief Variable donde deseamos guardar el resultado 
  a retornar por el callback */
}stdcmenu_getopt_t ; 


#if 0
/**
* \typedef stdcmenu_tvar_ex_vT;
* \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
* \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
* \version 01v00d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Jueves 13 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int stdcmenu_tvar_ex_vT;


/**
* \typedef stdcmenu_pfun_ex_fT;
* \details Descripcion detallada sobre la redefinicion de puntero a funcion.
* \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
* Prototipo de la funcion, al acual debe apuntar:
*  + void * function ( void * arg )
* \version 01v00d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Jueves 13 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*stdcmenu_pfun_ex_fT) (void *); 


/**
* \struct stdcmenu_struct_ex_sT;
* \brief Descripcion breve sobre el tipo de estructura.
* Elementos que componen a la Estructura de datos:
*  \li \ref vtchar;
*  \li \ref vtint;
*  \li \ref vtdouble;
* \version 01v00d01.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Jueves 13 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} stdcmenu_struct_ex_sT ; 

/**
* \union stdcmenu_union_ex_uT;
* \brief Descripcion breve sobre el tipo de union.
* Elementos que componen la union:
*   \li \ref item1 
*   \li \ref item2 
* \version 01v00d01.
* \warning mensaje de "warning". 
* \date Jueves 13 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} stdcmenu_union_ex_uT;


/**
* \enum stdcmenu_enum_eT;
* \details Descripcion detallada sobre la redefinicion de enumeracio.
* \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
* Elementos que componen la enumeracion:
*  \li \ref stdcmenu_eITEM0 . 
*  \li \ref stdcmenu_eITEM1 .
*  \li \ref stdcmenu_eITEM2 .
* \version 01v00d01.
* \warning mensaje de "warning".
* \date Jueves 13 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  stdcmenu_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'stdcmenu_eITEM0' de Enumeracion */
  stdcmenu_eITEM1,     /**<@brief descripcion breve de la etiqueta 'stdcmenu_eITEM1' de Enumeracion */
  stdcmenu_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'stdcmenu_eITEM2' de Enumeracion */
} stdcmenu_enum_eT;
#endif

#endif /* #if(stdcmenu_USE_GlobalTypedef == 1) */
/* ======================[ END   Global typedef      ]============================= */
/* =====================[ BEGIN Global variable declaration  ]===================== */
#if (stdcmenu_USE_GlobalData==1)
extern unsigned int stdcmenu_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (stdcmenu_USE_GlobalData==1) */
/* =====================[ END   Global variable declaration  ]===================== */ 
/* =====================[ BEGIN Global functions declaration ]===================== */
#if (stdcmenu_USE_GlobalFunctions == 1)

/**
* ****************************************************************************** 
* \fn bool_t stdcmenu_FillMenuOpts(uint32_t numarg, char **arrarg ,stdcmenu_getopt_t *menuopt, uint32_t valini);
* \brief Funcion para obtener solo operandos desde un array de argumentos,
*  como el pasado por comnsola al llamar una aplicacion.
* \param numarg : Numero de argumentos dentro del estring de argumentos.
* \param arrarg : Array de argumentos en formato string cada uno.
* \param menuopt : Array del tipo \ref stdcmenu_getopt_t, con el contexto 
* para cada posible arguemento arrivado.
* \param valini : Valor de inicio del array de argumentos, en caso de que se
* requieran descartar valores iniciales del \b arrarg .
* \return status de la opreacion.
*      \li TRUE, success
*      \li FASLE, failure
* \version 01v00d00.
* \note notq.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
bool_t stdcmenu_FillMenuOpts(uint32_t numarg, char **arrarg \
  ,stdcmenu_getopt_t *menuopt, uint32_t valini);

/** 
* ****************************************************************************
* \fn void stdcmenu_FreeMenuOpts(stdcmenu_getopt_t *menuopt);
* \brief Funcion para liberar la memoria dinamica usada a la hora de llanar
* un array del tipo \ref stdcmenu_getopt_t.
* \param menu : Puntero al array del tipo \ref stdcmenu_getopt_t.
* \return nothing
* \version 01v00d00.
* \note notq.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
void stdcmenu_FreeMenuOpts(stdcmenu_getopt_t *menuopt);

/**
* ****************************************************************************** 
* \fn void stdcmenu_Print(stdcmenu_getopt_t *menu, FILE *stream,uint8_t flags);
* \brief Funcion para imprimir el contenido de una estructura del tipo 
* \ref stdcmenu_getopt_t , con el formato de una meno de opeciones.
* \param menu : Puntero al array del tipo \ref stdcmenu_getopt_t, el cual
* representa el menu de opciones.
* \param stream : Stream o medio de impresion este puede ser cualquiera de los
* estandar o un archivo abierto.
*   \li stdout
*   \li stderr
* \param flags : Con este indicamos los datos que deseamos imprimir, su valor 
* puede ser:
*   \li \ref stdcmenu_PRINT_OPTS
*   \li \ref stdcmenu_PRINT_FMT
*   \li \ref stdcmenu_PRINT_ARGC
*   \li \ref stdcmenu_PRINT_HELP
*   \li \ref stdcmenu_PRINT_ID
*   \li \ref stdcmenu_PRINT_FLAGS
* \return nothing
* \version 01v00d00.
* \note notq.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
bool_t stdcmenu_Print(stdcmenu_getopt_t *menu, FILE *stream,uint8_t flags);


/**
* ****************************************************************************** 
* \fn void stdcmenu_PrintHelp(stdcmenu_getopt_t *menu,FILE *stream);
* \brief Funcion para imprimir un mensaje de ayuda en funcion de 
* los parametros inicializados en un array del tipo \ref stdcmenu_getopt_t .
*
* \param menu : Puntero al array del tipo \ref stdcmenu_getopt_t.
* \param stream : Stream o medio de impresion este puede ser cualquiera de los
* estandar o un archivo abierto.
*   \li stdout
*   \li stderr
* \return nothing
* \version 01v00d00.
* \note notq.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
void stdcmenu_PrintHelp(stdcmenu_getopt_t *menu,FILE *stream);

/**
* ****************************************************************************** 
* \fn void stdcmenu_GetOperandByOptions(const char *Options, stdcmenu_getopt_t *menuopt,stdcmenu_uopnum_t optnum,void *operand );
* \brief Funcion para obtener un operando, desde un item del array de menu (previamente 
* llenado), mediante una opcion (String que representa la opcion corta o larga del
* item dentro del menu). 
* \param Options : Opcion, String que debe coincidir con la opcion corta o larga
* dentro del menu, previamente definido.
* 
* \param menuopt : Puntero al array del tipo \ref stdcmenu_getopt_t.
* \param optnum : Numero de Operando correspondiente a la opcion.
* \param operand : Puntero del tipo void donde se almacenara por copia el 
* valor obtenido desde el fill del menu.
* \return nothing
* \version 01v00d00.
* \note La copia en caso de string se realiza mediante dump() del string original.
* Por lo que el argumento \b operand debe ser liberado luego de su uso o previo
* a una nueva asignacion de puntero de memoria.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
void stdcmenu_GetOperandByOptions(const char *Options, stdcmenu_getopt_t *menuopt\
  , stdcmenu_uopnum_t optnum,void *operand );

/**
* ****************************************************************************** 
* \fn void stdcmenu_GetOperandByOptions(const char *Options, stdcmenu_getopt_t *menuopt,stdcmenu_uopnum_t optnum,void *operand );
* \brief Funcion para obtener un operando, desde un item del array de menu (previamente 
* llenado), mediante un index (que representa la poscion del item dentro del array). 
* \param index : Index, el cual debe ser menor al numero de Itmes del array de menu.
* \param menuopt : Puntero al array del tipo \ref stdcmenu_getopt_t.
* \param optnum : Numero de Operando correspondiente a la opcion.
* \param operand : Puntero del tipo void donde se almacenara por copia el 
* valor obtenido desde el fill del menu.
* \return nothing
* \version 01v00d00.
* \note La copia en caso de string se realiza mediante dump() del string original.
* Por lo que el argumento \b operand debe ser liberado luego de su uso o previo
* a una nueva asignacion de puntero de memoria.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
void stdcmenu_GetOperandByIndex(uint32_t index, stdcmenu_getopt_t *menuopt\
  , stdcmenu_uopnum_t optnum, void *operand );

/**
* ****************************************************************************** 
* \fn void stdcmenu_GetOperand(stdcmenu_getopt_t *pitem, stdcmenu_uopnum_t optnum ,void *operand );
* \brief Funcion para obtener un operando, desde un item del tipo 
* \ref stdcmenu_getopt_t . Este es desde el item, no desde un array, utili para 
* utilizar dentro del callback, para obtener los operandos.
* \param pitem : Puntero al item dentro de un array del tipo \ref stdcmenu_getopt_t.
* \param optnum : Numero de Operando correspondiente a la opcion.
* \param operand : Puntero del tipo void donde se almacenara por copia el 
* valor obtenido desde el fill del menu.
* \return nothing
* \version 01v00d00.
* \note La copia en caso de string se realiza mediante dump() del string original.
* Por lo que el argumento \b operand debe ser liberado luego de su uso o previo
* a una nueva asignacion de puntero de memoria.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
void callback_rating(stdcmenu_getopt_t *arg)
{
  // por cuestiones de seguridad, no es necesario por como se relaiza el llamado
  // pero para descartar errores
  if(arg == NULL)
    return;
  // para este item en el meno tenemos la fila dentro del menu:
  // float ratingprom;
  //..
  // ("-R", "--rating","%f%f%f",NULL,callback_rating,(void**) &ratingprom)
  // Por lo que esperamos tres operandos del tipo float.
  //...
  // definimos variables para obtener los operandos
  float t1,t2,t3;
  // definimos la variable para almacenar el valor que deseamso retornar
  float tmed;
  // Obtenemos cada operando 
  stdcmenu_GetOperand(arg,1,&t1);
  stdcmenu_GetOperand(arg,2,&t2);
  stdcmenu_GetOperand(arg,3,&t3);
  // realizamos la operacion deseada
  tmed = (t1 + t2 + t3)/3;
  // En caso de ser necesario almacenamos el valor en la variable 
  // asociada al callback,  
  *(arg->rval_callback) = *((void**) &tmed);  
}
</PRE>  
*********************************************************************************/
void stdcmenu_GetOperand(stdcmenu_getopt_t *pitem, stdcmenu_uopnum_t optnum \
  ,void *operand );

/**
* ****************************************************************************** 
* \fn stdcmenu_opnum_t stdcmenu_StatusOperand(stdcmenu_getopt_t *pitem);
* \brief Funcion para obtener el estado de los operandos esperados para un argumento
* dado dentro del item perteneciente a un array del tipo menu (\ref stdcmenu_getopt_t).
* \param pitem : Puntero al item dentro de un array del tipo \ref stdcmenu_getopt_t.
* \return 
*   \li 0, en caso de no tener ingresos de operando para el agumetno.
*   \li !=0 , el valor de operandos ingresados para el argumetno.
* \version 01v00d00.
* \note La copia en caso de string se realiza mediante dump() del string original.
* Por lo que el argumento \b operand debe ser liberado luego de su uso o previo
* a una nueva asignacion de puntero de memoria.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
stdcmenu_opnum_t stdcmenu_StatusOperand(stdcmenu_getopt_t *pitem);

/**
* ****************************************************************************** 
* \fn stdcmenu_opnum_t stdcmenu_StatusOperandByIndex(uint32_t index,stdcmenu_getopt_t *menuopt);
* \brief Funcion para obtener el estado de los operandos esperados para un argumento
* dado dentro del item perteneciente a un array del tipo menu (\ref stdcmenu_getopt_t).
* \param index : index del item dentro del array.
* \param menuopt : Menu de opciones o array del tipo \ref stdcmenu_getopt_t.
* \return 
*   \li 0, en caso de no tener ingresos de operando para el agumetno.
*   \li !=0 , el valor de operandos ingresados para el argumetno.
* \version 01v00d00.
* \note La copia en caso de string se realiza mediante dump() del string original.
* Por lo que el argumento \b operand debe ser liberado luego de su uso o previo
* a una nueva asignacion de puntero de memoria.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
stdcmenu_opnum_t stdcmenu_StatusOperandByIndex(uint32_t index \
  , stdcmenu_getopt_t *menuopt);

/**
* ****************************************************************************** 
* \fn stdcmenu_opnum_t stdcmenu_StatusOperandByOptions(const char *Options,stdcmenu_getopt_t *menuopt);
* \brief Funcion para obtener el estado de los operandos esperados para un argumento
* dado dentro del item perteneciente a un array del tipo menu (\ref stdcmenu_getopt_t).
* \param Options : String que representa la opcion, este puede ser la opcion corta
* (\b opt_short) o la opcion larga (\b opt_long ).
* \param menuopt : Menu de opciones o array del tipo \ref stdcmenu_getopt_t.
* \return 
*   \li 0, en caso de no tener ingresos de operando para el agumetno.
*   \li !=0 , el valor de operandos ingresados para el argumetno.
* \version 01v00d00.
* \note La copia en caso de string se realiza mediante dump() del string original.
* Por lo que el argumento \b operand debe ser liberado luego de su uso o previo
* a una nueva asignacion de puntero de memoria.
* \warning mensaje de "warning". 
* \date Viernes 30 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
stdcmenu_opnum_t stdcmenu_StatusOperandByOptions(const char *Options \
  , stdcmenu_getopt_t *menuopt);

#endif /* #if (stdcmenu_USE_GlobalFunctions == 1) */
/* =====================[ END   Global functions declaration ]===================== */
/* ======================[ BEGIN Global Macros functions ]========================= */
#if ( stdcmenu_USE_GlobalMacroApis == 1 )


/**
* *******************************************************************************
* \def stdcmenu_DPERROR(...)
* \brief Macro funcion para imprimir un mensaje de error solo si DEBUG_ENABLE esta 
* habilitado. Podemos redefinir esta funcion a un log de eventos en caso de ser 
* necesario, por ejemplo:
<PRE>
FIXME : no esta definida aun.
#define stdcmenu_DPERROR(...) \
    logger_error(NULL,0, noerr, __FILE__,__FUNCTION__,__LINE__, __VA_ARGS__)
</PRE>
* \param ... : Listado de Argumentos, String fmt y demas argumentos, Idem a printf();
* \return nothinig
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
 * *********************************************************************************/
#define stdcmenu_DPERROR(Nerr,Exit, ...)  DEBUG_PERROR(Nerr,Exit,__VA_ARGS__)

/********************************************************************************//**
* \def stdcmenu_DPRINTF(...)
* \brief Macro funcion para imprimir un mensaje solo si DEBUG_ENABLE esta habilitado.
* Podemos redefinir esta funcion a un log de eventos en caso de ser necesario, 
* por ejemplo:
<PRE>
#define stdcmenu_DPRINTF(...) \
    logger_debug(NULL,0, logger_INFO, __FILE__,__FUNCTION__,__LINE__, __VA_ARGS__)
    // O podemos cambiar el formato o color del mensaje cambiando a la siguente linea 
#define stdcmenu_DPRINTF(...) \    
    logger_debug(NULL,0, logger_OK, __FILE__,__FUNCTION__,__LINE__, __VA_ARGS__)
</PRE>
* \param ... : Listado de Argumentos, String fmt y demas argumentos, Idem a printf();
* \return nothinig
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
 * *********************************************************************************/
#if 0
#define stdcmenu_DPRINTF(...) DEBUG_PRINTF(__VA_ARGS__) 
#else
#define stdcmenu_DPRINTF(...) CPRINTF(BLUE, __VA_ARGS__)
#endif

/********************************************************************************//**
* \def stdcmenu_PRINTF(...)
* \brief Macro funcion para imprimir un mensaje, Podemos redefinir esta funcion a un 
* log de eventos en caso de ser necesario.
* \param ... : Listado de Argumentos, String fmt y demas argumentos, Idem a printf();
* \return nothinig
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
 * *********************************************************************************/
#define stdcmenu_PRINTF(...) CPRINTF(BLUE, __VA_ARGS__)

/********************************************************************************//**
* \def stdcmenu_MENUEND_stdcmenu_getopt_t(pMenu,Index)
* \brief Macro funcion de hook para \ref stdcmenu_MENUEND().
* \param pMenu : Puntero al menu, estructura del tipo \ref stdcmenu_getopt_t.
* \param Index : Index del item dentro del array, el cual deseamos encuestar.
* \return nothinig
* \version AAvBBdCC.
* \note nota.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> 
* *********************************************************************************/  
#define stdcmenu_MENUEND_stdcmenu_getopt_t(pMenu,Index) \
  ((pMenu[Index].opt_short == NULL) && (pMenu[Index].opt_long == NULL))
  
/********************************************************************************//**
* \def stdcmenu_MENUEND(Type,pMenu,Index)
* \brief Macro funcion para detectar el final de un array del tipo menu.
* \param Type : Con este arg establecemos el tipo de array, este puede ser:
*   \li stdcmenu_getopt_t
*   \li ...
* \param pMenu : Puntero al menu, estructura del tipo \ref stdcmenu_getopt_t.
* \param Index : Index del item dentro del array, el cual deseamos encuestar.
* \return bool
*   \li 0, no se localizo el final del array 
*   \li 1, Se loclaizo el fin del array
* \version AAvBBdCC.
* \note nota.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
while(!stdcmenu_MENUEND(stdcmenu_getopt_t,menuopt,i))
{
  // acces item in array -> menuopt[i]
  //... more code here
  // incrementamos el index
  i++;
}
</PRE> 
 * *********************************************************************************/  
#define stdcmenu_MENUEND(Type,pMenu,Index) \
  stdcmenu_MENUEND_##Type(pMenu,Index)
  

/**
 * \def stdcmenu_getopt_END Etiqueta para marcar el fin de un array 
 * de item del tipo \b stdcmenu_getopt_t.
 */
#define stdcmenu_getopt_END   {.opt_short = NULL, .opt_long = NULL}

/**
 * \def stdcmenu_FillRow(OptShort,OptLong,Fmt,Help,Callback,Rval)
 * \brief macro para llenar una fila en la declaracion/defnicion
 * de un array del tipo \ref stdcmenu_getopt_t.
 * \param OptShort : String que representa la opcion corta.
 * \param OptLong : String que representa la opcion larga.
 * \param Fmt : String con formato, mediante este especificamos
 * la cantidad de operandos y el tipo de cada uno. Usando la 
 * misma sintaxis que printf(). Ej "%d%s%s" , en orden especificamos
 * tres operando ; entero, string y string.
 * \param Help : String con el mensaje de ayuda, para el caso de 
 * necesitar imprimir un mensaje de ayuida respecto del uso del contexto.
 * \param Callback : callback, funcion del tipo \b "void fn (stdcmenu_getopt_t*arg)"
 * \param Rval : Puntero del tipo void** donde almacenaremos el resultado 
 * del callback.
 * \return la sintaxis para llenar la fila del array.      */
#define stdcmenu_FillRow(OptShort,OptLong,Fmt,Help,Callback,Rval) \
  { .opt_short = OptShort, .opt_long = OptLong, .fmt = Fmt\
    , .help = Help, .callback = Callback, .rval_callback = Rval }  

/**
 * \def stdcmenu_FillRowId(OptShort,OptLong,Fmt,Help,Callback,Rval,Id)
 * \brief macro para llenar una fila en la declaracion/definicion
 * de un array del tipo \ref stdcmenu_getopt_t.
 * \param OptShort : String que representa la opcion corta.
 * \param OptLong : String que representa la opcion larga.
 * \param Fmt : String con formato, mediante este especificamos
 * la cantidad de operandos y el tipo de cada uno. Usando la 
 * misma sintaxis que printf(). Ej "%d%s%s" , en orden especificamos
 * tres operando ; entero, string y string.
 * \param Help : String con el mensaje de ayuda, para el caso de 
 * necesitar imprimir un mensaje de ayuida respecto del uso del contexto.
 * \param Callback : callback, funcion del tipo \b "void fn (stdcmenu_getopt_t*arg)"
 * \param Rval : Puntero del tipo void** donde almacenaremos el resultado 
 * del callback.
 * \param Id : Numero ID, identificador unico del Item dentro del ARRAY
 * el cual es util para usar con un Switch dentro de un callback.
 * \return la sintaxis para llenar la fila del array.      */    
#define stdcmenu_FillRowId(OptShort,OptLong,Fmt,Help,Callback,Rval,Id) \
  { .opt_short = OptShort, .opt_long = OptLong, .fmt = Fmt\
    , .help = Help, .callback = Callback, .rval_callback = Rval, .id = Id}  

    
/********************************************************************************//**
* \def stdcmenu_SaveRvalInCallback(pItem,Rval)
* \brief Macro funcion para almacenar el resutlado de una operacion realizada dentro
* de un callback, dentro de un item del menu, en la variable pertinente.
* 
* \param pItem : Puntero al item, el cual es cargado por la API al terminar de cargar
* los operanods disponibles y antes de llamar al callback, de dnode esta es invocada. 
* \param Rval : Variable definida dentro del callback donde se almaceno el resutlado 
* de la operacion.
* 
* \return nothinig
* \version AAvBBdCC.
* \note nota.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
void callback_count(stdcmenu_getopt_t *arg)
{
  if(arg == NULL || arg->rval_callback == NULL)
    return;
  // definimos las variables donde almacenaremos los valores a operar
  uint32_t cmin,cmed,cmax,rval;
  // extraemos una copia de cada operando del item ->
  // "--count","%u%u%u",NULL,callback_count,(void**) &count_promed  
  //
  stdcmenu_GetOperand(arg,1,&cmin);
  stdcmenu_GetOperand(arg,2,&cmed);
  stdcmenu_GetOperand(arg,3,&cmax);
  // realizmaos el calculo pertinente    
  rval = (cmin+cmed+cmax)>>1;  
  // salvamos el resultado en la variable del callback
  stdcmenu_SaveRvalInCallback(arg,rval);
}
</PRE> 
 * *********************************************************************************/    
#define stdcmenu_SaveRvalInCallback(pItem,Rval)\
  *(pItem->rval_callback) = *((void**) &Rval)

  
/********************************************************************************//**
* \def stdcmenu_GetRvalInCallback(pItem,Type)
* \brief Macro funcion para obtner el puntero a la variable de callback, la cual
* podemos utilizar para devolver un resultado desde un callback.
* 
* \param pItem : Puntero al item, el cual es cargado por la API al terminar de cargar
* los operanods disponibles y antes de llamar al callback, de dnode esta es invocada. 
* \param Type : Tipo de varibale donde referenciaremos la variable de retorno del 
* callback.
* 
* \return nothinig
* \version AAvBBdCC.
* \note nota.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
//
static argument_list_t arg_list;
memset(&arg_list,0,sizeof(argument_list_t));
// fill menu
stdcmenu_getopt_t menu[] = {
    stdcmenu_FillRowId("-d","--devices","%s",MSG_HELP_DEVICES\
    ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_INDEX_DEVICE)
  ,stdcmenu_FillRowId("-p", "--port","%s",MSG_HELP_PORT\
    ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_INDEX_PORT)
  ,stdcmenu_FillRowId("-b", "--baudrate","%u",MSG_HELP_BAUDRATE\
    ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_INDEX_BAUDRATE)    
  ,stdcmenu_FillRowId("-l","--logger_path","%s",MSG_HELP_LOGGERPATH\
    ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_LOGGER_PATH)
  ,stdcmenu_getopt_END //
  }; 
//  
// llenamos el menu
if(stdcmenu_FillMenuOpts(argc,argv,menu,1) == FALSE)
{
  PERROR(EINVAL,FAILURE,"\tLos parametros pasados son Incorrectos.\n");
  stdcmenu_PrintHelp(menu,stdout);  
  exit(EXIT_SUCCESS);  
}
// 
// more code  
void argument_FillList(stdcmenu_getopt_t *arg)
{
  stdcmenu_AssertCallback(Rval,arg);
  argument_list_t *list = stdcmenu_GetRvalInCallback(arg, argument_list_t* );
  // analizamos la precedencia del callback 
  switch(arg->id)
  {
    default:
      break;
    case menu_INDEX_DEVICE:
      stdcmenu_GetOperand(arg,1,&list->device);
      break;
      
    case menu_INDEX_PORT:      
      stdcmenu_GetOperand(arg,1,&list->port);
      break;
      
    case menu_LOGGER_PATH:
      stdcmenu_GetOperand(arg,1,&list->logger_path);
      break;      
  }    
}
</PRE> 
 * *********************************************************************************/  
#define stdcmenu_GetRvalInCallback(pItem,Type) (Type) (pItem->rval_callback)

  
/********************************************************************************//**
* \def stdcmenu_AssertCallback_Item(pItem)
* \brief Macro funcion de hook para \ref stdcmenu_AssertCallback().
* \param pItem : Puntero al Item, el cual recibe el callback como arguemtno.
* \return nothinig
* \version AAvBBdCC.
* \note nota.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> 
* *********************************************************************************/ 
#define stdcmenu_AssertCallback_Item(pItem) \
  if(pItem == NULL) return

/********************************************************************************//**
* \def stdcmenu_AssertCallback_Rval(pItem)
* \brief Macro funcion de hook para \ref stdcmenu_AssertCallback().
* \param pItem : Puntero al Item, el cual recibe el callback como arguemtno.
* \return nothinig
* \version AAvBBdCC.
* \note nota.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> 
* *********************************************************************************/     
#define stdcmenu_AssertCallback_Rval(pItem) \
  if(pItem == NULL || pItem->rval_callback == NULL) return

/********************************************************************************//**
* \def stdcmenu_AssertCallback(Type,pItem)
* \brief Macro funcion para realizar el asser el chequeo de los argumentos 
* a la hora de ingresar en el callback. 
* \param Type : Tipo de assert, este depende de la funcionalidad del callback, puede 
* ser :
*   \li Item : en este caso solo chequea el item, este no asegura el contexto si
*       se desea almacenar algun tipo de valor en la variable asociada al callback.
*   \li Rval : Este realiza todos los chequeos para asegurar el llamado y almacenar
*       valores sobre la variable asociada al callback.
*
* \param pItem : Puntero al Item, el cual recibe el callback como arguemtno.
* \return nothinig
* \version AAvBBdCC.
* \note nota.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
void callback_count(stdcmenu_getopt_t *arg)
{
  stdcmenu_AssertCallback(Rval,arg);    
  // definimos las variables donde almacenaremos los valores a operar
  uint32_t cmin,cmed,cmax,rval;
  // extraemos una copia de cada operando del item ->
  // "--count","%u%u%u",NULL,callback_count,(void**) &count_promed  
  //
  stdcmenu_GetOperand(arg,1,&cmin);
  stdcmenu_GetOperand(arg,2,&cmed);
  stdcmenu_GetOperand(arg,3,&cmax);
  // realizmaos el calculo pertinente    
  rval = (cmin+cmed+cmax)>>1;  
  // salvamos el resultado en la variable del callback
  stdcmenu_SaveRvalInCallback(arg,rval);
}
</PRE> 
 * *********************************************************************************/ 
#define stdcmenu_AssertCallback(Type,pItem) \
  stdcmenu_AssertCallback_##Type(pItem)

/*FIXME debemos eliminar de los call el llamado a esta, ya deja de ser de solo debug */  
#define stdcmenu_PrintStruct_getopt(Menu,Stream,Flags) \
  stdcmenu_Print(Menu,Stream,Flags)
  
#endif /* #if ( stdcmenu_USE_GlobalMacroApis == 1 ) */
/* 
* ======================[ END   Global Macros functions ]=========================
*/
/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ──────────────────────[ END   __stdcmenu_version__    01v00d00 ]────────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (version_QueryNumber(__stdcmenu_version__,01v00d01))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ──────────────────────[ BEGIN __stdcmenu_version__    01v00d01 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ──────────────────────[ END   __stdcmenu_version__    01v00d01 ]───────────────────── │
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
#endif /* #ifndef __stdcmenu_h__ */
/*
*
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =============================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(stdcmenu_projectEnable == 1) */

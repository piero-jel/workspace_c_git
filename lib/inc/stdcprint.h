#ifndef stdcprint_projectEnable
#define stdcprint_projectEnable 1 /**<@brief enable/disable the project */
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
* \file stdcprint.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v00d00.
* \date Martes 04 de Mayo, 2021.
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

#ifndef __stdcprint_h__
#define __stdcprint_h__ /**<@brief Definimos el Nombre del modulo */


#if (stdcprint_projectEnable == 1)

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
#include <version.h>
#include <stdctype.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <error.h>
#include <errno.h>

/* 
* ======================[ END   include header file ]=================================
*/

/* 
* ======================[ BEGIN labels enable/disable ]===============================
*/
#define stdcprint_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define stdcprint_USE_GlobalTypedef   0 /**<@brief enable/disable the use Global Typedef */
#define stdcprint_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define stdcprint_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define stdcprint_USE_GlobalMacroApis 1 /**<@brief enable/disable the use Gobal macros functions */

/**
* \def __stdcprint_version__ definimos la version actual del proyecto.
* version 01v00d00 -> test 
* version 01v00d01 -> test 
* version 01v00d02 -> test
* version 01v00d03 -> test
* version 01v00d04 -> test
* version 01v00d05 -> test
*
* */
#ifndef __stdcprint_version__
#define __stdcprint_version__        version_SetNumber(01v00d00)
#endif

/* 
* ======================[ END   labels enable/disable ]===============================
*/
#if (version_QueryNumber(__stdcprint_version__,01v00d00))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ─────────────────────[ BEGIN __stdcprint_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
/* 
* ======================[ BEGIN Global Macros/labels definition ]=================
*/
#if (stdcprint_USE_GlobalMacro == 1)
/*
* Tamaños de Memorias, tamaño por debajo de 1K Bytes:
*    32  64    128   256   512
*    XS  S     M     L     XL
*/
#define BUFFER_LEN_XS       32
#define BUFFER_LEN_S        64
#define BUFFER_LEN_M        128
#define BUFFER_LEN_L        256
#define BUFFER_LEN_XL       512
#define BUFFER_LEN_1K       1024
#define BUFFER_LEN_2K       2048
#define BUFFER_LEN_4K       4096


#define FONT_COLOR_BLACK            "\e[0;30m"
#define FONT_COLOR_RED              "\e[0;31m"
#define FONT_COLOR_GREEN            "\e[0;32m"
#define FONT_COLOR_YELLOW           "\e[0;33m"
#define FONT_COLOR_BLUE             "\e[0;34m"
#define FONT_COLOR_MAGENTA          "\033[0;35m"
#define FONT_COLOR_CYAN             "\e[0;36m"
#define FONT_COLOR_WHITE            "\e[0;37m"
#define FONT_COLOR_RESET            "\e[0m"
/**/
#define BACKGROUND_COLOR_BLACK      "\e[0;48;5;21m"
#define BACKGROUND_COLOR_RED        "\e[0;48;5;31m"
#define BACKGROUND_COLOR_GREEN      "\e[0;48;5;41m"
#define BACKGROUND_COLOR_YELLOW     "\e[0;48;5;51m"
#define BACKGROUND_COLOR_BLUE       "\e[0;48;5;61m"
#define BACKGROUND_COLOR_MAGENTA    "\e[0;48;5;71m"
#define BACKGROUND_COLOR_CYAN       "\e[0;48;5;81m"
#define BACKGROUND_COLOR_WHITE      "\e[0;48;5;91m"
#define BACKGROUND_COLOR_RESET      "\e[0;48;2;0;0;0m"

#define PRINTF_COLOR_RESET          "\033[0m"


#define STDC_ERR  stdout
#define STDC_DEBUG  stdout
#define STDC_ERR_LEN_BUFF   256
#define STDC_DEBUG_LEN_BUFF   256  

#endif /* #if(stdcprint_USE_GlobalMacro == 1) */
/* 
* ======================[ END   Global Macros/labels definition ]=================
*/
/* 
* ======================[ BEGIN Global typedef      ]=============================
*/
#if (stdcprint_USE_GlobalTypedef == 1)

/**
* \typedef stdcprint_tvar_ex_vT;
* \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
* \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
* \version 01v00d00.
* \note nota.
* \warning mensaje de "warning". 
* \date Martes 04 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int stdcprint_tvar_ex_vT;


/**
* \typedef stdcprint_pfun_ex_fT;
* \details Descripcion detallada sobre la redefinicion de puntero a funcion.
* \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
* Prototipo de la funcion, al acual debe apuntar:
*  + void * function ( void * arg )
* \version 01v00d00.
* \note nota.
* \warning mensaje de "warning". 
* \date Martes 04 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*stdcprint_pfun_ex_fT) (void *); 


/**
* \struct stdcprint_struct_ex_sT;
* \brief Descripcion breve sobre el tipo de estructura.
* Elementos que componen a la Estructura de datos:
*  \li \ref vtchar;
*  \li \ref vtint;
*  \li \ref vtdouble;
* \version 01v00d00.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Martes 04 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} stdcprint_struct_ex_sT ; 

/**
* \union stdcprint_union_ex_uT;
* \brief Descripcion breve sobre el tipo de union.
* Elementos que componen la union:
*   \li \ref item1 
*   \li \ref item2 
* \version 01v00d00.
* \warning mensaje de "warning". 
* \date Martes 04 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} stdcprint_union_ex_uT;


/**
* \enum stdcprint_enum_eT;
* \details Descripcion detallada sobre la redefinicion de enumeracio.
* \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
* Elementos que componen la enumeracion:
*  \li \ref stdcprint_eITEM0 . 
*  \li \ref stdcprint_eITEM1 .
*  \li \ref stdcprint_eITEM2 .
* \version 01v00d00.
* \warning mensaje de "warning".
* \date Martes 04 de Mayo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  stdcprint_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'stdcprint_eITEM0' de Enumeracion */
  stdcprint_eITEM1,     /**<@brief descripcion breve de la etiqueta 'stdcprint_eITEM1' de Enumeracion */
  stdcprint_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'stdcprint_eITEM2' de Enumeracion */
} stdcprint_enum_eT;

#endif /* #if(stdcprint_USE_GlobalTypedef == 1) */
/* 
* ======================[ END   Global typedef      ]=============================
*/
/* 
* =====================[ BEGIN Global variable declaration  ]=====================
*/
#if (stdcprint_USE_GlobalData==1)
extern unsigned int stdcprint_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (stdcprint_USE_GlobalData==1) */
/* 
* =====================[ END   Global variable declaration  ]=====================
*/ 
/* 
* =====================[ BEGIN Global functions declaration ]=====================
*/
#if (stdcprint_USE_GlobalFunctions == 1)
/** 
* 
* ******************************************************************************* 
* \fn int stdc_perror(int errnum,const char *file, const char *funct, size_t line, const char *fmt, ...);
* \brief funcion para imprimir un mensaje de error que acompaña al error estandar
* junto con el Nombre del archivo, nombre de la funcion y Numero de linea donde 
* se reporta el mismo.
*  breve sobre la funcion, \ref stdc_test_01().
* \param errnum : Numeroo de error este puede ser errno.
* \param file : Nombre del Archivo, este puede ser la macro \b __FILE__.
* \param funct : Nombre de la fucion, este puede ser la macro \b __FUNCTION__.
* \param line : Numero de linea donde se reporta el error, \b __LINE__.
* \param fmt : string con formato identico al usada en \b printf()
* \param ... : demas arguementos, dependiendo del contenido \ref fmt.
* \return
*      \li 0, success
*      \li 1, failure
* \version 01v00d00.
* \note notq.
* \warning mensaje de "warning". 
* \date Miercoles 28 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
*********************************************************************************/
int stdc_perror(int errnum,const char *file, const char *funct\
  , size_t line, const char *fmt, ...);

/**
* 
* ******************************************************************************* 
* \fn int stdc_debug(int color,const char *file, const char *funct size_t line, const char *fmt, ...);
* \brief Funcion para imprimir un mensaje con finalidad de depuracion de codigo
* , dicho mensaje estara acompañado de datos relacionado a la ubicacin de donde 
* se llama a la funcion.
* \param color : Color que se desea utilizar para el string del mensaje.
* \param file : Nombre del Archivo, este puede ser la macro \b __FILE__.
* \param funct : Nombre de la fucion, este puede ser la macro \b __FUNCTION__.
* \param line : Numero de linea donde se reporta el error, \b __LINE__.
* \param fmt : string con formato identico al usada en \b printf()
* \param ... : demas arguementos, dependiendo del contenido \ref fmt.
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v00d00.
* \note notq.
* \warning mensaje de "warning". 
* \date Miercoles 28 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
*********************************************************************************/
int stdc_debug(int color,const char *file, const char *funct\
, size_t line, const char *fmt, ...);



#endif /* #if (stdcprint_USE_GlobalFunctions == 1) */
/* 
* =====================[ END   Global functions declaration ]=====================
*/
/* 
* ======================[ BEGIN Global Macros functions ]=========================
*/
#if ( stdcprint_USE_GlobalMacroApis == 1 )



/*
 * Macro funcion para obtener el numero de item de un array,
 * no el numero de bytes.
 */
#define ARRAY_SIZE(Arr)     (sizeof(Arr)/sizeof(Arr[0])) 

/*
 * set font color, inserta los caracteres para establecer el color 
 * de la lentra.
 */
#define SET_COLOR_FONT(Color)       FONT_COLOR_##Color
/*
 * set background color, inserta los caracteres para establecer el color 
 * de fondo para la lentra.
 */
#define SET_COLOR_BACK(Color)       BACKGROUND_COLOR_##Color

/********************************************************************//**
 * \def SET_COLOR(Type,Color);
 * \brief macro para establecer el color de Font y background de la
 * salida por consola.
 * \details descripcion detallada.
 * \param Type : Tipo de color  a establecer, este puede ser
 * 		\li BACK : para establecer el color de background.
 * 		\li FONT : para establecer el color de font.
 * \param Color : Argumento dos.
 * \return  Nothing
 * \note nota sobre la macro funcion.
 * \warning mensaje de precaucion.
 * \par example :
 <PRE>
  printf(SET_COLOR(FONT,RED)"\t El Numero aleatorio de %u\n"SET_COLOR(FONT,RESET),get_random(5));
  printf(SET_COLOR(FONT,GREEN)"\t El Numero aleatorio de %u\n"SET_COLOR(FONT,RESET),get_random(5));
  printf(SET_COLOR(FONT,YELLOW)"\t El Numero aleatorio de %u\n"SET_COLOR(FONT,RESET),get_random(5));
  printf(SET_COLOR(FONT,BLUE)"\t El Numero aleatorio de %u\n"SET_COLOR(FONT,RESET),get_random(5));
  printf(SET_COLOR(FONT,MAGENTA)"\t El Numero aleatorio de %u\n"SET_COLOR(FONT,RESET),get_random(5));
  printf(SET_COLOR(FONT,CYAN)"\t El Numero aleatorio de %u\n"SET_COLOR(FONT,RESET),get_random(5));
  printf(SET_COLOR(FONT,WHITE)"\t El Numero aleatorio de %u\n"SET_COLOR(FONT,RESET),get_random(5));
  printf(SET_COLOR(FONT,BLACK)"\t El Numero aleatorio de %u\n"SET_COLOR(FONT,RESET),get_random(5));
  //
  printf(SET_COLOR(BACK,RED)"\t El Numero aleatorio de %u\n"SET_COLOR(BACK,RESET),get_random(5));
  printf(SET_COLOR(BACK,GREEN)"\t El Numero aleatorio de %u\n"SET_COLOR(BACK,RESET),get_random(5));
  printf(SET_COLOR(BACK,YELLOW)"\t El Numero aleatorio de %u\n"SET_COLOR(BACK,RESET),get_random(5));
  printf(SET_COLOR(BACK,BLUE)"\t El Numero aleatorio de %u\n"SET_COLOR(BACK,RESET),get_random(5));
  printf(SET_COLOR(BACK,MAGENTA)"\t El Numero aleatorio de %u\n"SET_COLOR(BACK,RESET),get_random(5));
  printf(SET_COLOR(BACK,CYAN)"\t El Numero aleatorio de %u\n"SET_COLOR(BACK,RESET),get_random(5));
  printf(SET_COLOR(BACK,WHITE)"\t El Numero aleatorio de %u\n"SET_COLOR(BACK,RESET),get_random(5));
  printf(SET_COLOR(BACK,BLACK)"\t El Numero aleatorio de %u\n"SET_COLOR(BACK,RESET),get_random(5)); </PRE>
 *
 *********************************************************************/
#define SET_COLOR(Type,Color) SET_COLOR_##Type(Color)


#define PRINTF_FONT_COLOR(Color,Fmt, ...) \
    printf(SET_COLOR(FONT,Color) Fmt SET_COLOR(FONT,RESET),__VA_ARGS__)
    
#define PRINTF_BACK_COLOR(Color,Fmt, ...) \
    printf(SET_COLOR(BACK,Color) Fmt SET_COLOR(BACK,RESET),__VA_ARGS__)


/* print error */    
#define PERROR_EXIT_SUCCESS(Nerr,...) \
{\
  stdc_perror(Nerr,__FILE__,__FUNCTION__,__LINE__, __VA_ARGS__);\
  exit(EXIT_SUCCESS);\
}

#define PERROR_EXIT_FAILURE(Nerr,...) \
{\
  stdc_perror(Nerr,__FILE__,__FUNCTION__,__LINE__, __VA_ARGS__);\
  exit(EXIT_FAILURE);\
}

/*
int stdc_perror(int errnum,const char *file, const char *funct\
  , size_t line, const char *fmt, ...); */
#define PERROR_EXIT_NONE(Nerr,...) stdc_perror(Nerr,__FILE__,__FUNCTION__,__LINE__, __VA_ARGS__)


/**
* 
* ********************************************************************************
* \def PERROR(Nerr,Exit, ...)
* \brief Macro funcion para impriir un mensaje de erro sobre stdout con color rojo
* \param Nerr : numero de error, este puede ser directamente "errno"
* \param Exit : Tipo de salida
*   + NONE, no sale
*   + FAILURE, finaliza la ejecucion notificando error al sistema.
*   + SUCCESS, finaliza la ejecucion sin notificar el error al sistema.
* \param ... demas argumentos 
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
if(errnum != 0)
  NPERROR(errnum, NONE, "Error, al Intentar Bloquear/Tomar el Mutex\n");  
return NULL;
</PRE> 
*********************************************************************************/   
#define PERROR(Nerr,Exit, ...) PERROR_EXIT_##Exit(Nerr,__VA_ARGS__)


#if (defined(DEBUG_ENABLE))

#define DEBUG_PERROR_EXIT_NONE(Nerr,...) stdc_perror(Nerr,__FILE__,__FUNCTION__,__LINE__, __VA_ARGS__)
#define DEBUG_PERROR_EXIT_FAILURE(Nerr,...) \
{\
  stdc_perror(Nerr,__FILE__,__FUNCTION__,__LINE__, __VA_ARGS__);\
  exit(EXIT_FAILURE);\
}
#define DEBUG_PERROR_EXIT_SUCCESS(Nerr,...) \
{\
  stdc_perror(Nerr,__FILE__,__FUNCTION__,__LINE__, __VA_ARGS__);\
  exit(EXIT_SUCCESS);\
}


#endif /* #if (defined(DEBUG_ENABLE)) */

/**
 * * ********************************************************************************
* \def DEBUG_PERROR(Nerr,Exit, ...)
* \brief Macro funcion para impriir un mensaje de erro sobre stdout con color rojo
* \param Nerr : numero de error, este puede ser directamente "errno"
* \param Exit : Tipo de salida
*   + NONE, no sale
*   + FAILURE, finaliza la ejecucion notificando error al sistema.
*   + SUCCESS, finaliza la ejecucion sin notificar el error al sistema.
* \param ... demas argumentos 
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
if(errnum != 0)
  NPERROR(errnum, NONE, "Error, al Intentar Bloquear/Tomar el Mutex\n");  
return NULL;
</PRE> 
 * *********************************************************************************/
/**
 * 
 * * ********************************************************************************
* \def DEBUG_PRINTF(...)
* \brief Macro funcion para impriir un mensaje solo si DEBUG_ENABLE esta habilitado.
* \param ... : Listado de Argumentos, String con formato seguido de cada argumento .
* Idem a printf();
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
if(errnum != 0)
  NPERROR(errnum, NONE, "Error, al Intentar Bloquear/Tomar el Mutex\n");  
return NULL;
</PRE> 
 * *********************************************************************************/
#if (defined(DEBUG_ENABLE))
#define DEBUG_PERROR(Nerr,Exit, ...)  DEBUG_PERROR_EXIT_##Exit(Nerr,__VA_ARGS__)
#define DEBUG_PRINTF(...) stdc_debug(0,__FILE__,__FUNCTION__,__LINE__, __VA_ARGS__)
#else /* #if (defined(DEBUG_ENABLE)) */
#define DEBUG_PERROR(Nerr,Exit, ...)
#define DEBUG_PRINTF(...)
#endif /* #if (defined(DEBUG_ENABLE)) */
    
#define ERROR_SAVE(pErrnot) \
{\
  int Save;\
  Save = errno;\
  if(pErrnot != NULL) \
    *pErrnot = Save; \
}    
    
    
    
#define FPERROR(File,Fmt, ...) \
    fprintf(File,SET_COLOR(FONT,RED) Fmt SET_COLOR(FONT,RESET),__VA_ARGS__)

/**
 * \def CFPRINTF(Color,File,Fmt, ...)
 * \brief Color File Print : imprime un texto con color en un archivo especificado por su Stream
 * \param Color   : Color deseado para el texto, este puede ser
 *  + GREEN | RED | BLUE | YELLOW
 * \param Fmt     : Stroing con formato.
 * \param arg...  : Demas Argumentos correspondiente al string cpn formato \ref Fmt. * 
 * \return nothing
 * \pre example
 <PRE>
  CFPRINTF(BLUE,stdout,"Hola %d", argn);
 </PRE>
 */    
#define CFPRINTF(Color,File,Fmt, arg...) \
    fprintf(File,SET_COLOR(FONT,Color) Fmt SET_COLOR(FONT,RESET),##arg)

/**
 * \def CPRINTF(Color,Fmt, arg...)
 * \brief Funcion para imprimir un mensaje por stdout con conlor
 * \param Color   : Color deseado para el texto, este puede ser
 *  + GREEN | RED | BLUE | YELLOW
 * \param Fmt     : Stroing con formato.
 * \param arg...  : Demas Argumentos correspondiente al string cpn formato \ref Fmt.
 * \return nothing
*/
#define CPRINTF(Color,Fmt, arg...) \
    printf(SET_COLOR(FONT,Color) Fmt SET_COLOR(FONT,RESET), ##arg)

    


#endif /* #if ( stdcprint_USE_GlobalMacroApis == 1 ) */
/* 
* ======================[ END   Global Macros functions ]=========================
*/
/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ─────────────────────[ END   __stdcprint_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (version_QueryNumber(__stdcprint_version__,01v00d01))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ─────────────────────[ BEGIN __stdcprint_version__    01v00d01 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ─────────────────────[ END   __stdcprint_version__    01v00d01 ]───────────────────── │
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
#endif /* #ifndef __stdcprint_h__ */
/*
*
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =============================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(stdcprint_projectEnable == 1) */

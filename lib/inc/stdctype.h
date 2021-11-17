#define stdctype_projectEnable 1 /**<@brief enable/disable the project in case of versioned */
/** ***********************************************************************************//**
* \addtogroup base 
* @{ 
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of base .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file stdctype.c
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v01d01.
* \date Lunes 18 de Junio, 2020.
* \pre pre, condiciones que deben cuplirse antes del llamado, example: First
* initialize the system.
* \bug bug, depuracion example: Not all memory is freed when deleting an object 
* of this class.
* \warning mensaje de precaucion, warning.
* \note nota.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* @} doxygen end group definition 
* ********************************************************************************** 
*/ 
#ifndef __stdctype_h__
#define __stdctype_h__ /**<@brief Definimos el Nombre del modulo*/

#if (stdctype_projectEnable == 1)
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =======================================[begin of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*
 *============================[Open, cplusplus]============================
 */
#ifdef __cplusplus
extern "C" {
#endif
/* 
 * *********************************************************************************************
 *
 * =================================[ Begin include header file ]================================
 *
 * ******************************************************************************************** 
 * TODO: include header file sector, "only in case especific" 
 */
/** example : #include <nmbHeaderFile.h> */
#include <stdio.h>
#include <stdctype.h>
#include <stdc_print.h>
#include <stdarg.h>
/*
 * *********************************************************************************************
 *
 * ==================================[ End include header file ]=================================
 *
 * *********************************************************************************************
 */

/* **********************************************************************************************
 *
 * ==========================[ Begin labels enable/disable functions ]===========================
 *
 * ******************************************************************************************** 
 * TODO: labels enable/disable functions
 */
#define stdctype_USE_GlobalMacro      1  /**<@brief enable/disable the use Global Macros/Labels */
#define stdctype_USE_GlobalTypedef    1 /**<@brief enable/disable the use Global Typedef */
#define stdctype_USE_GlobalData       0 /**<@brief enable/disable the use Global Data */
#define stdctype_USE_GlobalFunctions  1 /**<@brief enable/disable the use Gobal functions */
#define stdctype_USE_GlobalMacroApis  1 /**<@brief enable/disable the use Gobal macros functions */





/* **********************************************************************************************
 *
 * ==========================[ End labels enable/disable functions ]===========================
 *
 * ******************************************************************************************** **/
/* 
 *  
 * *********************************************************************************************
 *
 * ==========================[ Begin Global Macros/labels definition]===========================
 *
 * ******************************************************************************************** **/
#if (stdctype_USE_GlobalMacro==1)
/*
 * TODO : Macros/labels definition
 */

#ifdef __GNUC__
/* This macro stops 'gcc -Wall' complaining that "control reaches
end of non-void function" if we use the following functions to
terminate main() or some other non-void function. */
#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif


#if 1
  #define Newline 		"\n"
  #define HorizontalTab	"\t"
  #define VerticalTab	 	"\v"
  #define CarriReturn		"\r"
  #define FormFeed		"\f"
  #define ESC				"\e"
  #define BlackSpace		"\b"
  #define AudibleAlert	"\a"

#else

  #define Newline 		'\n'
  #define HorizontalTab	'\t'
  #define VerticalTab	 	'\v'
  #define CarriReturn		'\r'
  #define FormFeed		'\f'
  #define ESC				'\e'
  #define BlackSpace		'\b'
  #define AudibleAlert	'\a'

#endif

/**<@brief etiqueta para indicar el fin de linea -> cpp 'std::cout<<endl'  */

/**/
#endif /* #if(stdctype_USE_GlobalMacro==1) */
/* **********************************************************************************************
 *
 * ==========================[ End Macros/labels Globals ]===========================
 *
 * ******************************************************************************************** **/
/*
 * 
 * *********************************************************************************************
 *
 * ====================================[BEGIN Global stdctype]====================================
 *
 * ******************************************************************************************** */
#if (stdctype_USE_GlobalTypedef==1)
/*
 * TODO: Global stdctype
*/


/**
 * \def __UINT_T__
 * \brief label para evitar redefinicion
 * */
/**
 * \def __INT_T__
 * \brief label para evitar redefinicion
 * */

/**
 * \def __INT8_T__
 * \brief label para evitar redefinicion
 * */
/**
 * \def __INT16_T__
 * \brief label para evitar redefinicion
 * */
/**
 * \def __INT32_T__
 * \brief label para evitar redefinicion
 * */
/**
 * \def __INT64_T__
 * \brief label para evitar redefinicion
 * */
/**
 * \def __UINT8_T__
 * \brief label para evitar redefinicion
 * */
/**
 * \def __UINT16_T__
 * \brief label para evitar redefinicion
 * */
/**
 * \def __UINT32_T__
 * \brief label para evitar redefinicion
 * */
/**
 * \def __UINT64_T__
 * \brief label para evitar redefinicion
 * */
/**
* \stdctype uint_t;
* \brief redefinicion del tipo de dato primitivo, cuyo tamaño se corresponde
* con el del procesador (para lograr mayor eficiencia ) */

/**
* \stdctype uint8_t;
* \brief redefinicion del tipo de dato primitivo, unsigned int 8-Bits */
/**
* \stdctype uint16_t;
* \brief redefinicion del tipo de dato primitivo, unsigned int 16-Bits */
/**
* \stdctype uint32_t;
* \brief redefinicion del tipo de dato primitivo, unsigned int 32-Bits */
/**
* \stdctype uint64_t;
* \brief redefinicion del tipo de dato primitivo, unsigned int 64-Bits */
/**
* \stdctype int8_t;
* \brief redefinicion del tipo de dato primitivo, signed int 8-Bits */
/**
* \stdctype int16_t;
* \brief redefinicion del tipo de dato primitivo, signed int 16-Bits */
/**
* \stdctype int32_t;
* \brief redefinicion del tipo de dato primitivo, signed int 32-Bits */
/**
* \stdctype int64_t;
* \brief redefinicion del tipo de dato primitivo, signed int 64-Bits */



#if 0
#if defined(__M16__)
/*-- redefinicion de datos primitvos arquitectura de 16-Bits
 * ┌─────────────────┬──────┬───────┬─────┬──────┬───────────┬───────┬────────┬─────────────┐
 * │  Data model     │ char │ short │ int │ long │ long long │ float │ double │ long double │
 * ├─────────────────┼──────┼───────┼─────┼──────┼───────────┼───────┼────────┼─────────────┤
 * │  IP16L32 (near) │   8  │  16   │  32 │  32  │ --------- │ ----- │ ------ │ ----------- │
 * ├─────────────────┼──────┼───────┼─────┼──────┼───────────┼───────┼────────┼─────────────┤
 * │  I16LP32 (far)  │   8  │  16   │  32 │  32  │ --------- │ ----- │ ------ │ ----------- │
 * ├─────────────────┼──────┼───────┼─────┼──────┼───────────┼───────┼────────┼─────────────┤
 * │  -m32           │   8  │  16   │  32 │  32  │    64     │   32  │   64   │     96      │
 * ├─────────────────┼──────┼───────┼─────┼──────┼───────────┼───────┼────────┼─────────────┤
 * │  -m64           │   8  │  16   │  32 │  64  │    64     │   32  │   64   │    128      │
 * └─────────────────┴──────┴───────┴─────┴──────┴───────────┴───────┴────────┴─────────────┘
 * */
#ifndef __UINT8_T__
#define __UINT8_T__
typedef unsigned char uint8_t ;
#endif
#ifndef __INT8_T__
#define __INT8_T__
typedef signed char int8_t ;
#endif
#ifndef __UINT16_T__
#define __UINT16_T__
typedef unsigned short uint16_t ;
#endif
#ifndef __INT16_T__
#define __INT16_T__
typedef signed short int16_t ;
#endif
#ifndef __UINT32_T__
#define __UINT32_T__
typedef unsigned int uint32_t ;
#endif
#ifndef __INT32_T__
#define __INT32_T__
typedef signed int int32_t ;
#endif
/**/
#elif defined(__M32__) /* #if defined(__M16__) */
/*-- redefinicion de datos primitvos arquitectura de 16-Bits
 * ┌─────────────────┬──────┬───────┬─────┬──────┬───────────┬───────┬────────┬─────────────┐
 * │  Data model     │ char │ short │ int │ long │ long long │ float │ double │ long double │
 * ├─────────────────┼──────┼───────┼─────┼──────┼───────────┼───────┼────────┼─────────────┤
 * ├─────────────────┼──────┼───────┼─────┼──────┼───────────┼───────┼────────┼─────────────┤
 * │  -m32 [Bits]    │   8  │  16   │  32 │  32  │    64     │   32  │   64   │     96      │
 * ├─────────────────┼──────┼───────┼─────┼──────┼───────────┼───────┼────────┼─────────────┤
 * │  -m32 [Bytes]   │  01  │  02   │  04 │  04  │    08     │   04  │   08   │     12      │
 * └─────────────────┴──────┴───────┴─────┴──────┴───────────┴───────┴────────┴─────────────┘
 * */
#ifndef __UINT8_T__
#define __UINT8_T__
typedef unsigned char uint8_t ;
#endif
#ifndef __INT8_T__
#define __INT8_T__
typedef signed char int8_t ;
#endif
#ifndef __UINT16_T__
#define __UINT16_T__
typedef unsigned short uint16_t;
#endif
#ifndef __INT16_T__
#define __INT16_T__
typedef signed short int16_t ;
#endif
#ifndef __UINT32_T__
#define __UINT32_T__
typedef unsigned int uint32_t ;
#endif
#ifndef __INT32_T__
#define __INT32_T__
typedef signed int int32_t ;
#endif
#ifndef __UINT64_T__
#define __UINT64_T__
typedef unsigned long long uint64_t ;
#endif
#ifndef __INT64_T__
#define __INT64_T__
typedef signed long long int64_t ;
#endif
/**/
#ifndef __NLINE_T__
#define __NLINE_T__
typedef unsigned int nline_t ;
#endif


#elif defined(__M64__) /* #if defined(__M16__) */
/*-- redefinicion de datos primitvos arquitectura de 16-Bits
 * ┌─────────────────┬──────┬───────┬─────┬──────┬───────────┬───────┬────────┬─────────────┐
 * │  Data model     │ char │ short │ int │ long │ long long │ float │ double │ long double │
 * ├─────────────────┼──────┼───────┼─────┼──────┼───────────┼───────┼────────┼─────────────┤
 * ├─────────────────┼──────┼───────┼─────┼──────┼───────────┼───────┼────────┼─────────────┤
 * │  -m64 [Bits]    │   8  │  16   │  32 │  64  │    64     │   32  │   64   │    128      │
 * ├─────────────────┼──────┼───────┼─────┼──────┼───────────┼───────┼────────┼─────────────┤
 * │  -m64 [Bytes]   │  01  │  02   │  04 │  08  │    08     │   04  │   08   │    016      │
 * └─────────────────┴──────┴───────┴─────┴──────┴───────────┴───────┴────────┴─────────────┘
 * */
#ifndef __UINT_T__
#define __UINT_T__	32
typedef unsigned int uint_t ;
#endif
#ifndef __INT_T__
#define __INT_T__	32
typedef signed int int_t ;
#endif

#ifndef __UINT8_T__
#define __UINT8_T__
typedef unsigned char uint8_t ;
#endif
#ifndef __INT8_T__
#define __INT8_T__
typedef signed char int8_t ;
#endif
#ifndef __UINT16_T__
#define __UINT16_T__
typedef unsigned short uint16_t ;
#endif
#ifndef __INT16_T__
#define __INT16_T__
typedef signed short int16_t ;
#endif
#ifndef __UINT32_T__
#define __UINT32_T__
typedef unsigned int uint32_t ;
#endif
#ifndef __INT32_T__
#define __INT32_T__
typedef signed int int32_t ;
#endif
#define __UINT64_T__
#ifndef __UINT64_T__
#define __UINT64_T__
typedef unsigned long long uint64_t ;
#endif
#ifndef __INT64_T__
#define __INT64_T__
/*stdctype signed long long int64_t ;*/
#endif
/**/
#ifndef __NLINE_T__
#define __NLINE_T__
typedef unsigned int nline_t ;
#endif
/* */
#else

#warning "Arquitectura del procesador no definida"

#endif
#endif

/* stdctype unsigned long long uint64_t ;*/ /**<@brief unsigned integer 64-Bits  */
#ifndef NULL
#define NULL ((void*) 0)
#endif




/** @brief Enumeracion del tipo Bool  */
#if (!(defined(FALSE) || defined(TRUE)))
typedef enum
{
	FALSE=0, /**<@brief Falso, Cero */
	TRUE = ~FALSE,/**<@brief Verdadero, Distinto de Cero*/
}bool_t;
#else 
typedef gboolean bool_t;
#endif


/** @brief Flag Status and Interrupt Flag Status type definition  */
typedef enum {RESET = 0, SET = !RESET} flagStatus_t, intStatus_t;

/** @brief Flag Status and Interrupt Flag Status type definition  */
typedef enum {LOW = 0, HIGH = !LOW} setState_t,getState_t, activity_t;

typedef enum {OFF = 0, ON = !OFF} state_t ;

/** @brief Functional State Definition */
typedef enum {DISABLE = 0, ENABLE = !DISABLE} functionalState_t,status_t;

/** @brief Enumeracion del tipo status  */
typedef enum {ERROR = 0, SUCCESS = !ERROR} errStatus_t;


/* FIXME podemos agragarles utilidades
 * para verificar el espacio restante del buffer.
 */
#if 0 /* FIXME debemos eliminar este */
typedef struct 
{
  char *buff; /**<@brief Puntero al buffer */
  size_t len; /**<@brief Longitud del buffer */  
}buffer_t;

#define BUFFER_INIT(Str,Buff)\
  Str.buff = Buff, Str.len = sizeof(Buff)
#endif  
  

#define CAST_VOID_UINT2PVOID(i)  (void*)(uintptr_t)(i)
#define CAST_VOID_PVOID2UINT(p)  (unsigned int)(uintptr_t)(p)
#define CAST_VOID_INT2PVOID(i)   (void*)(intptr_t)(i)
#define CAST_VOID_PVOID2INT(p)   (signed int)(intptr_t)(p)
  
#define CAST_VOID_PVOID2F32(p)   (*((float*) p))
  
#define CAST_VOID_UINT2PPVOID(p)    (void**) &p
#define CAST_VOID_INT2PPVOID(p)     (void**) &p
#define CAST_VOID_FLOAT2PPVOID(p)   (void**) &p
#define CAST_VOID_DOUBLE2PPVOID(p)  (void**) &p  
#define CAST_VOID_PCHAR2PPVOID(p)   (void**) &p
#define CAST_VOID_PPCHAR2PPVOID(p)  (void**) &p
#define CAST_VOID_STRUCT2PPVOID(p)  (void**) &p
#define CAST_VOID_PSTRUCT2PPVOID(p) (void**) &p
/**
* 
* ********************************************************************************
* \def CAST_VOID(Type,Op)
* \brief Macro funcion para realizar el casting de puntero a void a contenedores
* del tipo entero con y sin signo { uint16_t|int16_t|uint32_t|int32_t }
* \param Type : Tipo de casting
*   \li UINT2PVOID
*   \li PVOID2UINT
*   \li INT2PVOID
*   \li PVOID2INT
* 
*   \li PVOID2F32   float
*   \li PVOID2F64   double
*   \li PVOID2FMAX  long double
* 
*   \li UINT2PPVOID   -> CAST_VOID(UINT2PPVOID,varname)
*   \li INT2PPVOID    -> CAST_VOID(INT2PPVOID,varname)
*   \li FLOAT2PPVOID  -> CAST_VOID(FLOAT2PPVOID,varname)
*   \li DOUBLE2PPVOID -> CAST_VOID(DOUBLE2PPVOID,varname)
*   \li PCHAR2PPVOID  -> CAST_VOID(PCHAR2PPVOID,varname)
*   \li PPCHAR2PPVOID -> CAST_VOID(PPCHAR2PPVOID,varname)
*   \li PPCHAR2PPVOID -> CAST_VOID(STRUCT2PPVOID,varname)
*   \li PPCHAR2PPVOID -> CAST_VOID(PSTRUCT2PPVOID,varname)
* 
* \param Op : Operando sobre el cual se realiza el casting, este puede ser un
* litera, una variable o puntero.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
void * fn_example(void * loops)
{
  int loc, j;
  uint32_t max = CAST_VOID(PVOID2UINT,loops);
  //... more code
}
//...
uint32_t j = 1024*5/4;
fn_example(CAST_VOID(UINT2PVOID,j));
//...
fn_example(CAST_VOID(UINT2PVOID,(1024*5/4)));
</PRE> 
*********************************************************************************/ 
#define CAST_VOID(Type,Op) CAST_VOID_##Type(Op)  

#endif /*#if(stdctype_USE_GlobalTypedef==1)*/
/* **********************************************************************************************
 *
 * ====================================[END Global stdctype]====================================
 *
 * ******************************************************************************************** 
 */
#ifdef __stdctype_c__
/*
 * *********************************************************************************************
 *
 * ==================================[ BEGIN local declaration ]=================================
 *
 ********************************************************************************************** */
/*
 * 
 * ---------------------------------------------------------------------------------
 *
 * ==================[BEGIN Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------*/
#if (stdctype_USE_GlobalData==1)
/*
 * TODO : Global data declaration
*/
unsigned int globalExample; /**<@brief variable global example, brief of data */


#endif//#if(stdctype_USE_GlobalTypedef==1)
/* ---------------------------------------------------------------------------------
 *
 * ==================[END Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------*/
/* 
 * 
 * *********************************************************************************************
 *
 * ==================================[ END local declaration ]=================================
 *
 ********************************************************************************************** 
 */
#else /* ifdef __stdctype_c__*/
/*
 * 
 * *********************************************************************************************
 *
 * ==============================[ BEGIN Only externa declaration ]=============================
 *
 ********************************************************************************************** */
/* SECTOR excluido de -> stdctype.c, utlizar con cuidado */
/*
 * TODO : Only external declaration
*/
/* ---------------------------------------------------------------------------------
 *
 * ==================[BEGIN Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------*/
#if (stdctype_USE_GlobalData==1)
/*
 * TODO : Global data declaration
*/
extern unsigned int globalExample; /**<@brief variable global example, brief of data */

#endif /* #if(stdctype_USE_GlobalTypedef==1) */
/* ---------------------------------------------------------------------------------
 *
 * ==================[END Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------*/

/* 
 * *********************************************************************************************
 *
 * ==============================[ END Only externa declaration ]=============================
 *
 ********************************************************************************************** 
 * 
 */
 #endif /* ifdef __stdctype_c__ */
/* 
 * 
 * *********************************************************************************************
 *
 * ==================================[ BEGIN Global declaration ]=================================
 *
 ********************************************************************************************** */
/*
 * ---------------------------------------------------------------------------------
 *
 * ==================[BEGIN Global functions declaration]=========================
 *
 * --------------------------------------------------------------------------------*/
#if (stdctype_USE_GlobalFunctions==1)
/*
 * TODO : Global functions declaration
*/
#if 0
/*******************************************************************//**
* @brief	API Global, descripion de @ref stdctype_nmbAPI_1()
* en caso de necesitar referencia a otra funcion dentro del mismo
* archivo -> @ref {file_base}_nombreAPI_2()
* @b WordInBold
* <b> text in format bold </b>
* @a WordInSpecialFont
* <a> text in special font </a>
* @param arg : argument description
* should be :
* 		+ ...
* 		+ ....
* @return value description
* @note
* @par example :
<pre>
a = stdctype_nombreAPI_1(Arg);
</pre>
*********************************************************************/
int stdctype_nombreAPI_1(unsigned int arg);
#endif

#if 0
/*******************************************************************//**
* @brief	API Global, descripion de 'stdctype_nmbFunc'
* @param arg : argument description
* should be :
* 		+ ...
* 		+ ....
* @return value description
* @note
* @par example :
<pre>
a = stdctype_nombreAPI_2(Arg);
</pre>
*********************************************************************/
static inline bool_t stdctype_CheckPathFile(const char *pathFile)
{
  struct stat buffer;
  return (stat(pathFile, &buffer) == 0)? TRUE: FALSE;  
}
#endif


/*
*
* ****************************************************************************//**
* \fn void stdctype_StdinGetline(const char * format, ...)
* \brief Funcion para obtener una linea desde la consola o desde stdin
* \param format: string con formato.
* \param ... : listado de argumento que se corresponde string con formato
* \return nothing
*********************************************************************************/
static inline void stdctype_StdinGetLine(const char * format, ...)
{
  va_list arp;
  va_start(arp, format);
  fflush(stdin);
  fflush(stdout);
  vscanf(format,arp);
  getchar();
  va_end(arp);
}

#endif /*#if(stdctype_USE_GlobalFunctions==1) */
/* ---------------------------------------------------------------------------------
 *
 * ==================[End Global functions declaration]=========================
 *
 * --------------------------------------------------------------------------------*/
/*
 * *********************************************************************************************
 *
 * ===========================[ Begin Global Macros functions ]==================================
 *
 ********************************************************************************************** */
#if (stdctype_USE_GlobalMacroApis==1)
#define ASSERT_ENABLE_EXITS   1 /* Enable '1'/Disable '0' la terminacion del programa si asser check es success */

#if (!defined(ASSERT) && defined(SO_LINUX))
extern int errno;
#define ASSERT(Expresion,File,Line) \
{\
  if(Expresion) \
    error_at_line ( ASSERT_ENABLE_EXITS, errno,File,Line,\
    FONT_COLOR_RED"Error reportado por ASSERT con la expresion: "#Expresion\
    FONT_COLOR_RESET);\
}

#endif 
/*
 * ******************************************************************//**
 * \def stdctype_nASSERT(Expresion)
 * \brief Es el simil del assert() negando el arguemtno.
 * Si la expresion es true, reporta el error con mensaje y finaliza la 
 * ejecucion del programa.
 * \param Expresion : Expresion que se analiza. 
 * \return nothing 
 *********************************************************************/
#define stdctype_nASSERT(Expresion) ASSERT((Expresion),__FILE__,__LINE__)

#endif /* #if(stdctype_USE_GlobalMacroApis==1) */
/* **********************************************************************************************
 *
 * ===========================[ END Global Macros functions ]==================================
 *
 ********************************************************************************************** */
/* 
 * 
 * *********************************************************************************************
 *
 * ==================================[ END GLOBAL declaration ]=================================
 *
 ********************************************************************************************** */



/*
 *============================[close, cplusplus]============================
 */

#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/*==============================[end of file]==============================*/
#endif /* #ifndef __stdctype_h__ */

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * ========================================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /*#if(stdctype_projectEnable == 1) */

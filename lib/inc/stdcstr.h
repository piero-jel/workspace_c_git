#ifndef stdcstr_projectEnable
#define stdcstr_projectEnable 1 /**<@brief enable/disable the project */
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
* \file stdcstr.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v01d01.
* \date Lunes 12 de Abril, 2021.
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


#ifndef __stdcstr_h__
#define __stdcstr_h__ /**<@brief Definimos el Nombre del modulo */


#if (stdcstr_projectEnable == 1)

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
#include <stdcprint.h>
#include <stdint.h>
#include <ctype.h>
#include <error.h>
#include <errno.h>
#include <version.h>
/* 
  * ======================[ END   include header file ]=================================
  */

/* 
  * ======================[ BEGIN labels enable/disable ]===============================
  */
#define stdcstr_USE_GlobalMacro     0 /**<@brief enable/disable the use Global Macros/Labels */
#define stdcstr_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define stdcstr_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define stdcstr_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define stdcstr_USE_GlobalMacroApis 1 /**<@brief enable/disable the use Gobal macros functions */

/**
  * \def __stdcstr_version__ definimos la version actual del proyecto.
  * version 01v00d00 -> test 
  * version 01v00d01 -> test 
  * version 01v00d02 -> test
  * version 01v00d03 -> test
  * version 01v00d04 -> test
  * version 01v00d05 -> test
  *
  * */
#ifndef __stdcstr_version__
#define __stdcstr_version__        version_SetNumber(01v00d01)
#endif

/* 
  * ======================[ END   labels enable/disable ]===============================
  */


#if (version_QueryNumber(__stdcstr_version__,01v00d00) \
  || version_QueryNumber(__stdcstr_version__,01v00d01) )
/* 
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ──────────────────────[ BEGIN __stdcstr_version__    01v00d00 ]────────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */
/* 
  * ======================[ BEGIN Global Macros/labels definition ]=================
  */
#if (stdcstr_USE_GlobalMacro == 1)



#endif /* #if(stdcstr_USE_GlobalMacro == 1) */
/* 
  * ======================[ END   Global Macros/labels definition ]=================
  */


/* 
  * ======================[ BEGIN Global typedef      ]=============================
  */
#if (stdcstr_USE_GlobalTypedef == 1)


#define stdcstr_MANTISSA_LEN          128
// #define stdcstr_rnumber_              0x01
#define stdcstr_rnumber_IS_ZERO       0x01
#define stdcstr_rnumber_IS_REAL       0x02 /* si localizo un punto, es Numero real */
#define stdcstr_rnumber_IS_INTEGER    0x04 /* si localizo un punto, es Numero real */
#define stdcstr_rnumber_REP_EXP       0x08
#define stdcstr_rnumber_WITH_REMAIND  0x10
#define stdcstr_rnumber_OVERFLOAD     0x80

/* para establecer el tipo de enteros con y sin signo */
#define stdcstr_NUMTYPE_INT8          0x00  /**<@brief */
#define stdcstr_NUMTYPE_UINT8         0x80  /**<@brief */
#define stdcstr_NUMTYPE_INT16         0x01  /**<@brief */
#define stdcstr_NUMTYPE_UINT16        0x81  /**<@brief */
#define stdcstr_NUMTYPE_INT32         0x02  /**<@brief */
#define stdcstr_NUMTYPE_UINT32        0x82  /**<@brief */
#define stdcstr_NUMTYPE_INT64         0x03  /**<@brief */
#define stdcstr_NUMTYPE_UINT64        0x84  /**<@brief */
/**/
#define stdcstr_NUMTYPE_FLOAT32       0x10  /**<@brief */
#define stdcstr_NUMTYPE_FLOAT64       0x20  /**<@brief */
#define stdcstr_NUMTYPE_FLOATMAX      0x30  /**<@brief */



/**
  * \struct stdcstr_struct_ex_sT;
  * \brief Descripcion breve sobre el tipo de estructura.
  * Elementos que componen a la Estructura de datos:
  *  \li \ref vtchar;
  *  \li \ref vtint;
  *  \li \ref vtdouble;
  * \version 01v01d01.
  * \note nota sobre la estructura.
  * \warning mensaje de "warning". 
  * \date Lunes 12 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> 
  * 
  * RealNumber = (sign ? −1 : 1) ·( 2 ^ exp )· Mant
  */
#if (version_QueryNumber(__stdcstr_version__,01v00d00))
typedef struct
{
  /**<@brief descripcion del item vtchar */
  char mantissa[stdcstr_MANTISSA_LEN];  
  int32_t exponent;
  /* para almacenar los flags de conversion */
  uint8_t flags;
} stdcstr_rnumber_t ;
#elif (version_QueryNumber(__stdcstr_version__,01v00d01))
typedef struct
{
  /**<@brief descripcion del item vtchar */
  char mantissa[stdcstr_MANTISSA_LEN];  
  int32_t exponent;
  int8_t sign;
  /* para almacenar los flags de conversion */
  uint8_t flags;
} stdcstr_rnumber_t ;
#endif



#if 0
/**
  * \typedef stdcstr_tvar_ex_vT;
  * \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
  * \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
  * \version 01v01d01.
  * \note nota.
  * \warning mensaje de "warning". 
  * \date Lunes 12 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int stdcstr_tvar_ex_vT;


/**
  * \typedef stdcstr_pfun_ex_fT;
  * \details Descripcion detallada sobre la redefinicion de puntero a funcion.
  * \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
  * Prototipo de la funcion, al acual debe apuntar:
  *  + void * function ( void * arg )
  * \version 01v01d01.
  * \note nota.
  * \warning mensaje de "warning". 
  * \date Lunes 12 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*stdcstr_pfun_ex_fT) (void *); 


/**
  * \struct stdcstr_struct_ex_sT;
  * \brief Descripcion breve sobre el tipo de estructura.
  * Elementos que componen a la Estructura de datos:
  *  \li \ref vtchar;
  *  \li \ref vtint;
  *  \li \ref vtdouble;
  * \version 01v01d01.
  * \note nota sobre la estructura.
  * \warning mensaje de "warning". 
  * \date Lunes 12 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} stdcstr_struct_ex_sT ; 

/**
  * \union stdcstr_union_ex_uT;
  * \brief Descripcion breve sobre el tipo de union.
  * Elementos que componen la union:
  *   \li \ref item1 
  *   \li \ref item2 
  * \version 01v01d01.
  * \warning mensaje de "warning". 
  * \date Lunes 12 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} stdcstr_union_ex_uT;


/**
  * \enum stdcstr_enum_eT;
  * \details Descripcion detallada sobre la redefinicion de enumeracio.
  * \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
  * Elementos que componen la enumeracion:
  *  \li \ref stdcstr_eITEM0 . 
  *  \li \ref stdcstr_eITEM1 .
  *  \li \ref stdcstr_eITEM2 .
  * \version 01v01d01.
  * \warning mensaje de "warning".
  * \date Lunes 12 de Abril, 2021.
  * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
  * \par meil
  * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  stdcstr_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'stdcstr_eITEM0' de Enumeracion */
  stdcstr_eITEM1,     /**<@brief descripcion breve de la etiqueta 'stdcstr_eITEM1' de Enumeracion */
  stdcstr_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'stdcstr_eITEM2' de Enumeracion */
} stdcstr_enum_eT;
#endif


#endif /* #if(stdcstr_USE_GlobalTypedef == 1) */
/* 
  * ======================[ END   Global typedef      ]=============================
  */

/* 
  * ==================[ BEGIN Global variable declaration  ]=========================
  */
#if (stdcstr_USE_GlobalData==1)
extern unsigned int stdcstr_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (stdcstr_USE_GlobalData==1) */
/* 
  * ==================[ END   Global variable declaration  ]=========================
  */
/* 
  * ======================[ BEGIN Global functions declaration ]====================
  */
#if (stdcstr_USE_GlobalFunctions == 1)
/*******************************************************************************//** 
* \fn char * stdcstr_breaktoken(const char *pstr,const char *token,char **premaind);
* \brief Funcion para Obtener el string remanente en funcion de un token. Esta busca
* el token en el string, almacena el remanente en \b "premaind" y retorna un puntero 
* al inicio donde se localizo el token.
* \param pstr : String donde se requeire localizar el token.
* \param token : String que se desea localizar.
* \param premaind : Puntero a puntero donde se almacenara donde finaliza el token 
* demtro del string.
* \return Retorna la direccion donde inicia el token dentro del strong \ref pstr.
* En caso de no localizar el token retonra NULL.
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
  char *str = "str = {text}+{token}+{text}";
  char *token = "token";
  char *prem;
  char *premToken;  
  // llamamos a la funcion
  premToken = stdcstr_breaktoken(str,token,&prem);  
  // impimimos el rsultado.
  printf("premToken = stdcstr_breaktoken(str,token,&prem);\n");  
  printf("\tstr: \"%s\" \n",str);  
  printf("\ttoken: \"%s\" \n",token);
  printf("\tprem: \"%s\" \n",prem);
  printf("\tpremToken: \"%s\" \n",premToken);  
// Slaida por consola
premToken = stdcstr_breaktoken(str,token,&prem);
	str: "str = {text}+{token}+{text}" 
	token: "token" 
	prem: "}+{text}" 
	premToken: "token}+{text}" 
</PRE>  
*********************************************************************************/
char * stdcstr_breaktoken(const char *pstr,const char *token,char **premaind);

/*******************************************************************************//**
* \fn bool_t stdcstr_find(const char *pstr,const char *token);
* \brief Funcion para localizar un token dentro de un string.
* \param pstr : String donde se requeire localizar el token.
* \param token : String que se desea localizar.
* \return Retorna
*   \li TRUE se localizo el token dentro del string.
*   \li FALSE no se localizo el token.
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
  // definimos el token 
  char *token = "token";
  // definimos un array de sring
  char *astr[] ={
     "str = {text}+{token}+{text}"
    ,"token}+{text}str = {text}+{"
    ,"}+{text}str = {text}+{token"
    ,"toke tok to t toke"
    ,"toke tok to t token"
    ,NULL
  };
  // recorremos el array de string para el test
  size_t i = 0;
  while(astr[i] != NULL)
  {
    if(stdcstr_find(astr[i],token))
      printf("\ttoken: \"%s\" localizado dentro de str: \"%s\" \n",token,astr[i]);    
    else
      printf("\ttoken: \"%s\" NO LOCALIZADO dentro de str: \"%s\" \n",token,astr[i]);     
    i++;
  }
// salida por consola:
	token: "token" localizado dentro de str: "str = {text}+{token}+{text}" 
	token: "token" localizado dentro de str: "token}+{text}str = {text}+{" 
	token: "token" localizado dentro de str: "}+{text}str = {text}+{token" 
	token: "token" NO LOCALIZADO dentro de str: "toke tok to t toke" 
	token: "token" localizado dentro de str: "toke tok to t token"   
</PRE>  
*********************************************************************************/
bool_t stdcstr_find(const char *pstr,const char *token);

/*******************************************************************************//** 
* \fn bool_t stdcstr_isNumber(const char *pstr);
* \brief Funcion para verificar si un string representa un numero. Esta considera
* si el numero es entero o real con coma o punto.
* \param pstr : String
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
 
</PRE>  
*********************************************************************************/
bool_t stdcstr_isNumber(const char *pstr);

/*******************************************************************************//** 
* \fn bool_t stdcstr_containsNumbers(const char *pstr, char **pnum);
* \brief Funcion para verificar si un string contiene caracteres numericos.
* \param pstr : String
* \param pnum : puntero donde almacenara la ubicacion del primer caractere
* numerico encontrado. Si este es NULL, no itenta actualizar.
* \return status de la opreacion.
*      \li TRUE, se localizo un caracter numerico.
*      \li FALSE, no se localizo ningun caracter numerico en el string.
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
 
</PRE>  
*********************************************************************************/
bool_t stdcstr_containsNumbers(const char *pstr,char** pnum, stdcstr_rnumber_t *prnum);

/*******************************************************************************//** 
* \fn bool_t stdcstr_getInteger32(const char *pstr,void *pval, bool_t force, bool_t unsig);
* \brief funcion para obtener un integer con o  sin signo de hasta 32-bits.
* \param pstr : Strig desde el cual se requiere obtener le 
* \param pval : Puntero a la variable donde se desea almacenar el entero.
* \param force : Con este establecemos si deseamso forzar la busqueda
* en caso de que el string no solo poseea caracteres numericos.
*  \li TRUE se habilita a extraer la primer cifra numerica desde un string 
*   alfanumerico y retrona TRUE si es valido.
*  \li FALSE se deshabilita y en caso de que el string no represente un numero
*  esta funcion retorna FALSE.
* \param unsig : con este flags especificamos si el entero buscado es del tipo
*  signed (\b FALSE) o del tipo unsigned (\b TRUE).
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
  *********************************************************************************/
// bool_t stdcstr_getInteger32(const char *pstr,void *pval, bool_t force, bool_t unsig);

/*******************************************************************************//** 
* \fn bool_t stdcstr_getInteger(const char *pstr,void *pval, bool_t force, uint8_t type);
* \brief funcion para obtener un integer con o  sin signo de hasta 32-bits.
* \param pstr : Strig desde el cual se requiere obtener le 
* \param pval : Puntero a la variable donde se desea almacenar el entero.
* \param force : Con este establecemos si deseamos forzar la busqueda
* en caso de que el string no solo poseea caracteres numericos.
*  \li TRUE se habilita a extraer la primer cifra numerica desde un string 
*   alfanumerico y retrona TRUE si es valido.
*  \li FALSE se deshabilita y en caso de que el string no represente unicamente
* un numero esta funcion retorna FALSE.
* \param type : con este argumento especificamos el tipo de numero entero que
* deseamos extraer. Este puede ser:
*   \li stdcstr_NUMTYPE_INT8    ó   stdcstr_NUMTYPE_UINT8
*   \li stdcstr_NUMTYPE_INT16   ó   stdcstr_NUMTYPE_UINT16
*   \li stdcstr_NUMTYPE_INT32   ó   stdcstr_NUMTYPE_UINT32
*   \li stdcstr_NUMTYPE_INT64   ó   stdcstr_NUMTYPE_UINT64
* 
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
  *********************************************************************************/
bool_t stdcstr_getInteger(const char *pstr,void *pval, bool_t force, uint8_t type);


#if 0
/*******************************************************************************//** 
* \fn bool_t stdcstr_getint32(const char *pstr,int32_t *pval, bool_t force);
* \brief funcion para obtener un valor entero con signo de hasta 32-bits, desde
* un string.
* \param pstr : Strig desde el cual se requiere obtener el numero.
* \param pval : puntero donde almacenaremos el valor entero obtenido.
* \param force : Mediante este indicamos con \ref TRUE si forzamos la 
* escritura del valor, si el string contiene numeros y caracteres 
* alfanumericos. De lo contrario colocamos este arguemtnos el \b FALSE.
* Independientemente del valor de este argumento y si sucede este 
* caso retornara \b FALSE.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
  *********************************************************************************/
bool_t stdcstr_getint32(const char *pstr,int32_t *pval, bool_t force);

/*******************************************************************************//** 
* \fn bool_t stdcstr_getuint32(const char *pstr,uint32_t *pval, bool_t force);
* \brief funcion para obtener un valor entero sin signo de hasta 32-bits, desde
* un string.
* \param pstr : Strig desde el cual se requiere obtener el numero.
* \param pval : puntero donde almacenaremos el valor entero obtenido.
* \param force : Mediante este indicamos con \ref TRUE si forzamos la 
* escritura del valor, si el string contiene numeros y caracteres 
* alfanumericos. De lo contrario colocamos este arguemtnos el \b FALSE.
* Independientemente del valor de este argumento y si sucede este 
* caso retornara \b FALSE.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
  *********************************************************************************/
bool_t stdcstr_getuint32(const char *pstr,uint32_t *pval, bool_t force);

#endif




#endif /* #if (stdcstr_USE_GlobalFunctions == 1) */
/* 
  * ======================[ END   Global functions declaration ]====================
  */

/* 
  * ======================[ BEGIN Global Macros functions ]=========================
  */
#if ( stdcstr_USE_GlobalMacroApis == 1 )
/********************************************************************************//**
* \def stdcstr_DPERROR(...)
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
#define stdcstr_DPERROR(Nerr,Exit, ...)  DEBUG_PERROR(Nerr,Exit,__VA_ARGS__)

/********************************************************************************//**
* \def stdcstr_DPRINTF(...)
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
#define stdcstr_DPRINTF(...) DEBUG_PRINTF(__VA_ARGS__) 
#else
#define stdcstr_DPRINTF(...) CPRINTF(BLUE, __VA_ARGS__)
#endif

/********************************************************************************//**
* \def stdcstr_PRINTF(...)
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
#define stdcstr_PRINTF(...) CPRINTF(BLUE, __VA_ARGS__)


/********************************************************************************//**
* \def stdcstr_rnumberIsInteger(pRnum)
* \brief Macro funcion para imprimir un mensaje, Podemos redefinir esta funcion a un 
* log de eventos en caso de ser necesario.
* \param pRnum : Puntero a la estructura numero real \ref stdcstr_rnumber_t.
* \return 
*   \li 0, No es del tipo integer entero
*   \li 1, Si es entero 
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
#define stdcstr_rnumberIsInteger(pRnum)\
  ((pRnum)->flags & stdcstr_rnumber_IS_INTEGER) 
  
#define stdcstr_rnumberWithRemainder(pRnum)\
  ((pRnum)->flags & stdcstr_rnumber_WITH_REMAIND)   
  
  
/*******************************************************************************//** 
* \def stdcstr_getint16(pStr,pVal, Force);
* \brief funcion para obtener un valor entero con signo de hasta 16-bits, desde
* un string.
* \param pstr : Strig desde el cual se requiere obtener el numero.
* \param pval : puntero donde almacenaremos el valor entero obtenido.
* \param force : Mediante este indicamos con \ref TRUE si forzamos la 
* escritura del valor, si el string contiene numeros y caracteres 
* alfanumericos. De lo contrario colocamos este arguemtnos el \b FALSE.
* Independientemente del valor de este argumento y si sucede este 
* caso retornara \b FALSE.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
  *********************************************************************************/  
#define stdcstr_getint16(pStr,pVal, Force) \
  stdcstr_getInteger(pStr,pVal,Force,stdcstr_NUMTYPE_INT16)
  
/*******************************************************************************//** 
* \def stdcstr_getuint16(pStr,pVal, Force);
* \brief funcion para obtener un valor entero sin signo de hasta 16-bits, desde
* un string.
* \param pstr : Strig desde el cual se requiere obtener el numero.
* \param pval : puntero donde almacenaremos el valor entero obtenido.
* \param force : Mediante este indicamos con \ref TRUE si forzamos la 
* escritura del valor, si el string contiene numeros y caracteres 
* alfanumericos. De lo contrario colocamos este arguemtnos el \b FALSE.
* Independientemente del valor de este argumento y si sucede este 
* caso retornara \b FALSE.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
  *********************************************************************************/   
#define stdcstr_getuint16(pStr,pVal, Force) \
  stdcstr_getInteger(pStr,pVal,Force,stdcstr_NUMTYPE_UINT16)  
  
/*******************************************************************************//** 
* \def stdcstr_getint32(pStr,pVal, Force);
* \brief funcion para obtener un valor entero con signo de hasta 32-bits, desde
* un string.
* \param pstr : Strig desde el cual se requiere obtener el numero.
* \param pval : puntero donde almacenaremos el valor entero obtenido.
* \param force : Mediante este indicamos con \ref TRUE si forzamos la 
* escritura del valor, si el string contiene numeros y caracteres 
* alfanumericos. De lo contrario colocamos este arguemtnos el \b FALSE.
* Independientemente del valor de este argumento y si sucede este 
* caso retornara \b FALSE.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
  *********************************************************************************/  
#define stdcstr_getint32(pStr,pVal, Force) \
  stdcstr_getInteger(pStr,pVal,Force,stdcstr_NUMTYPE_INT32)
  
/*******************************************************************************//** 
* \def stdcstr_getuint32(pStr,pVal, Force);
* \brief funcion para obtener un valor entero sin signo de hasta 32-bits, desde
* un string.
* \param pstr : Strig desde el cual se requiere obtener el numero.
* \param pval : puntero donde almacenaremos el valor entero obtenido.
* \param force : Mediante este indicamos con \ref TRUE si forzamos la 
* escritura del valor, si el string contiene numeros y caracteres 
* alfanumericos. De lo contrario colocamos este arguemtnos el \b FALSE.
* Independientemente del valor de este argumento y si sucede este 
* caso retornara \b FALSE.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
  *********************************************************************************/   
#define stdcstr_getuint32(pStr,pVal, Force) \
  stdcstr_getInteger(pStr,pVal,Force,stdcstr_NUMTYPE_UINT32)    
  
  
/*******************************************************************************//** 
* \def stdcstr_getint64(pStr,pVal, Force);
* \brief funcion para obtener un valor entero con signo de hasta 64-bits, desde
* un string.
* \param pstr : Strig desde el cual se requiere obtener el numero.
* \param pval : puntero donde almacenaremos el valor entero obtenido.
* \param force : Mediante este indicamos con \ref TRUE si forzamos la 
* escritura del valor, si el string contiene numeros y caracteres 
* alfanumericos. De lo contrario colocamos este arguemtnos el \b FALSE.
* Independientemente del valor de este argumento y si sucede este 
* caso retornara \b FALSE.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
  *********************************************************************************/  
#define stdcstr_getint64(pStr,pVal, Force) \
  stdcstr_getInteger(pStr,pVal,Force,stdcstr_NUMTYPE_INT64)
  
/*******************************************************************************//** 
* \def stdcstr_getuint64(pStr,pVal, Force);
* \brief funcion para obtener un valor entero sin signo de hasta 64-bits, desde
* un string.
* \param pstr : Strig desde el cual se requiere obtener el numero.
* \param pval : puntero donde almacenaremos el valor entero obtenido.
* \param force : Mediante este indicamos con \ref TRUE si forzamos la 
* escritura del valor, si el string contiene numeros y caracteres 
* alfanumericos. De lo contrario colocamos este arguemtnos el \b FALSE.
* Independientemente del valor de este argumento y si sucede este 
* caso retornara \b FALSE.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure 
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Lunes 12 de Abril, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
* <PRE>
* 
* </PRE>  
  *********************************************************************************/   
#define stdcstr_getuint64(pStr,pVal, Force) \
  stdcstr_getInteger(pStr,pVal,Force,stdcstr_NUMTYPE_UINT64)  
  
  
#endif /* #if ( stdcstr_USE_GlobalMacroApis == 1 ) */
/* 
  * ======================[ END   Global Macros functions ]=========================
  */



/*
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ──────────────────────[ END   __stdcstr_version__    01v00d00 ]────────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  *
  */
#elif (version_QueryNumber(__stdcstr_version__,01v00d02) )
/* 
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ──────────────────────[ BEGIN __stdcstr_version__    01v00d01 ]────────────────────── │
  * │                                                                                       │
  * │                                                                                       │             
  * └───────────────────────────────────────────────────────────────────────────────────────┘
  */



/*
  * ┌───────────────────────────────────────────────────────────────────────────────────────┐           
  * │                                                                                       │  
  * │                                                                                       │  
  * │ ──────────────────────[ END   __stdcstr_version__    01v00d01 ]────────────────────── │
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
#endif /* #ifndef __stdcstr_h__ */
/*
 * 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =============================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(stdcstr_projectEnable == 1) */

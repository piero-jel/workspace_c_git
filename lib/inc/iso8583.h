#ifndef iso8583_projectEnable
#define iso8583_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup iso8583 
* @{ borrarme, solo para mantener la identacion -> }@
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of iso8583 .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file iso8583.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v01d00.
* \date Martes 05 de Octubre, 2021.
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
#ifndef __iso8583_h__
#define __iso8583_h__ /**<@brief Definimos el Nombre del modulo */


#if (iso8583_projectEnable == 1)

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


/* 
 * ======================[ END   include header file ]=================================
 */

/* 
 * ======================[ BEGIN labels enable/disable ]===============================
 */
#define iso8583_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define iso8583_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define iso8583_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define iso8583_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define iso8583_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
 * \def __iso8583_version__ definimos la version actual del proyecto.
 * version 01v00d00 -> test 
 * version 01v00d01 -> test 
 * version 01v00d02 -> test
 * version 01v00d03 -> test
 * version 01v00d04 -> test
 * version 01v00d05 -> test
 *
 * */
#ifndef __iso8583_version__
#define __iso8583_version__        version_SetNumber(01v00d00)
#endif

/* 
 * ======================[ END   labels enable/disable ]===============================
 */
#if (version_QueryNumber(__iso8583_version__,01v00d00))
/* 
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ──────────────────────[ BEGIN __iso8583_version__    01v00d00 ]────────────────────── │
 │                                                                                       │
 │                                                                                       │             
 └───────────────────────────────────────────────────────────────────────────────────────┘
 */
/* 
 * ======================[ BEGIN Global Macros/labels definition ]=================
 */
#if (iso8583_USE_GlobalMacro == 1)


#define iso8583_TFIELD_b       0   /**<@brief Información binaria */
#define iso8583_TFIELD_a       1   /**<@brief Alfanumérico, incluyendo los espacios */
#define iso8583_TFIELD_n       2   /**<@brief Solo valores numéricos */
#define iso8583_TFIELD_s       3   /**<@brief Solo caracteres especiales */
#define iso8583_TFIELD_an      4   /**<@brief Alfanumérico */
#define iso8583_TFIELD_as      5   /**<@brief Solo caracteres alfanuméricos y especiales */
#define iso8583_TFIELD_ns      6   /**<@brief Solo caracteres numéricos y especiales */
#define iso8583_TFIELD_ans     7   /**<@brief Caracteres Alfabéticos, numéricos y especiales */
#define iso8583_TFIELD_z       8   /**<@brief Tracks 2 y 3 code set como se define en la ISO 4909 y en ISO 7813 */



#define iso8583_ERR_FMT_LEN       0x8000   /* error en el formato de la longitud */
#define iso8583_ERR_OVR_LEN       0x4000   /* la longitud establecida supera la maxima */
#define iso8583_ERR_RES_MEM       0x2000   /* Error al intentar reservar memoria p/un nuevo item */

#define iso8583_ERR_MASK          (iso8583_ERR_FMT_LEN|iso8583_ERR_OVR_LEN|iso8583_ERR_RES_MEM) /*0xF000*/   /* Mascara para obtener el error */



#define iso8583_LBL_WRN_NOT_LEN   "Warning, faltan Caracteres p/Obtener la longitud del Campo."
#define iso8583_LBL_WRN_NOT_FIELD "Warning, faltan Caracteres p/Obtener el Campo Completo."
#define iso8583_LBL_WRN_END_STR   "Warning Default Llegamos al final, falta Caracetres p/completar el campo."  

#define iso8583_WRN_NOT_LEN       0x0080   /* Warning No se pudo obtener la longitud del campo actual por que se termino la cadena de caracteres */ 
#define iso8583_WRN_NOT_FIELD     0x0040   /* Warning No se pudo obtener el campo actual por que se termino la cadena de caracteres */  
#define iso8583_WRN_MASK          (iso8583_WRN_NOT_LEN|iso8583_WRN_NOT_FIELD)  /* Mascara para obtener el warning */

#define iso8583_LBL_EMPTY_FIELD  "empty"
#define iso8583_LBL_ERR_FMT_LEN  "Error en el Formato de la Longitud del campo."
#define iso8583_LBL_ERR_OVR_LEN  "Error longitud arrivada superior a la maxima para el campo."


#define iso8583_BIT_MAP_LENG      8  /**<@brief Longitud en bytes de cada Bit Map */
#define iso8583_BIT_MAP_NUMB      2  /**<@brief Numero de Bip Map soportados */


#define iso8583_FLGPRINT_TBL      0x01  /**<@brief Falg para habilitar el formato tabla en la impresion por stream del mensaje expandido */
#define iso8583_FLGPRINT_COLOR    0x02  /**<@brief Falg para habilitar el uso de color en la impresion por stream del mensaje expandido  */
#endif /* #if(iso8583_USE_GlobalMacro == 1) */
/* 
 * ======================[ END   Global Macros/labels definition ]=================
 */
/* 
 * ======================[ BEGIN Global typedef      ]=============================
 */
#if (iso8583_USE_GlobalTypedef == 1)

/**
 * \typedef iso8583_tvar_ex_vT;
 * \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
 * \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
 * \version 01v01d00.
 * \note nota.
 * \warning mensaje de "warning". 
 * \date Martes 05 de Octubre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int iso8583_tvar_ex_vT;


/**
 * \typedef iso8583_pfun_ex_fT;
 * \details Descripcion detallada sobre la redefinicion de puntero a funcion.
 * \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
 * Prototipo de la funcion, al acual debe apuntar:
 *  + void * function ( void * arg )
 * \version 01v01d00.
 * \note nota.
 * \warning mensaje de "warning". 
 * \date Martes 05 de Octubre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*iso8583_pfun_ex_fT) (void *); 


/**
 * \struct iso8583_struct_ex_sT;
 * \brief Descripcion breve sobre el tipo de estructura.
 * Elementos que componen a la Estructura de datos:
 *  \li \ref vtchar;
 *  \li \ref vtint;
 *  \li \ref vtdouble;
 * \version 01v01d00.
 * \note nota sobre la estructura.
 * \warning mensaje de "warning". 
 * \date Martes 05 de Octubre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} iso8583_struct_ex_sT ; 



/** 
 * \struct iso8583_field_sT;
 * \brief Estructura de datos para almacenar un campo del mensaje 
 * que cumple con el estandar ISO-8583.
 *  - \ref pos    'uint8_t  ; '
 *  - \ref type   'uint8_t  ; '
 *  - \ref len    'uint32_t ; ' 
 *  - \ref field; 'char*    ; '
 *  - \ref brief; 'char*    ; '
 * \note note:
 * \warning warning:
 * \date Friday 17 de September, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>

</PRE>
*/
typedef struct __iso8583_field_sT
{
  uint8_t pos;      /**<@brief posicion del campo dentro del mensaje */
  uint8_t type;     /**<@brief Tipo de campo */
  uint32_t len;     /**<@brief Longitud del campo, en caso de necesitar verificacion del mismo */  
  char *field;      /**<@brief Campo en formato ASCII, en meoria dinamica HEAP */
  char *brief;      /**<@brief Mensaje descriptivo del campo */
  /* campos de debug */
  uint32_t remainder; /* para impactar el numero de caracteres remanente, */ 
  
}iso8583_field_sT;

/** 
 * \struct iso8583_sT;
 * \brief Estructura de datos para almacenar un mensaje que cumple con el estandar ISO-8583.
 *  - \ref MTID[8]  'char MTID[8]; '
 *  - \ref bitMap   'uint8_t bitMap[][];'
 *  - \ref nfields  'uint32_t nfields;' 
 *  - \ref fields;  'void** fields;'
 *  - \ref fields;  'uint8_t* listField;'
 * 
 * \note note:
 * \warning warning:
 * \date Friday 17 de September, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>

</PRE>
*/
typedef struct __iso8583_sT
{
  char MTID[8];           /**<@brief Indicador de tipo de mensaje */
  /** No vale la pena hacerlo dinamico a este campo ya que la longitud 
   *  es fija y la cantidad hasta el momento es de uno o dos, no mas.
   *  Aplicariamos una logica complicada para poder liberar 8-bytes.
  */
  uint8_t bitMap[iso8583_BIT_MAP_NUMB][iso8583_BIT_MAP_LENG];  /**<@brief Bit map, mapa de bit, cada uno de 8 Bytes/64-Bits */
  uint32_t nfields;            /**<@brief Cantidad de campos de Datos */
  iso8583_field_sT** fields;   /**<@brief Campos de Datos */
  uint8_t* listField;          /**<@brief Listado ordenado de campos disponibles */ 
  /** FIXME p/parsing util para caundo la informacion a parsear esta contenida en un buffer */
  uint16_t status;       /**<@brief estado del parsing, si este es 0 parsin completado de 
    lo contrario salva el estado en el que el parsing quedo por falta de caracteres */  
  uint8_t lastfield;    /**<@brief indice, dentro de la lista de campos, del ultimo campo parseado */
}iso8583_sT;

/** 
 * \struct iso8583_tblfield_sT;
 * \brief Estructura de datos que representa el campo/item de la tabla Estandar 
 * de mensajes con formato ISO-8583.
 *  - \ref type  'uint8_t '
 *  - \ref ndig  'uint8_t '
 *  - \ref lmax  'uint16_t' 
 *  - \ref brief 'char *'
 * \note note:
 * \warning warning:
 * \date Friday 17 de September, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>

</PRE>
*/
typedef struct __iso8583_tblfield_sT
{  
  uint8_t type  ;   /**<@brief Tipo de campo */
  uint8_t ndig  ;   /**<@brief Numero de caracteres a sacar en caso de longitud variable,
                               si es 0 la longitud es fija y establecida en \b lmax */
  uint16_t lmax ;   /**<@brief Longitud Maxima o de caracteres a sacar */  
  char *brief;      /**<@brief Descripcion breve del item */
  /* FIXME podemos agregar un campo mas con la descripcion del campo */
}iso8583_tblfield_sT;


#endif /* #if(iso8583_USE_GlobalTypedef == 1) */
/* 
 * ======================[ END   Global typedef      ]=============================
 */
/* 
 * =====================[ BEGIN Global variable declaration  ]=====================
 */
#if (iso8583_USE_GlobalData==1)



#endif /* #if (iso8583_USE_GlobalData==1) */
/* 
 * =====================[ END   Global variable declaration  ]=====================
 */ 
/* 
 * =====================[ BEGIN Global functions declaration ]=====================
 */
#if (iso8583_USE_GlobalFunctions == 1)

/** 
 * 
 * ******************************************************************************* 
 * \fn iso8583_sT * iso8583_ParseFromStr(const char *str, uint8_t *flag)
 * \brief Funcion para crear una estructura del tipo \b iso8583_sT tomando un mensaje en format string 
 * EBCDIC (exceptuando los bit map)
 * \param str   : Cadena de caracteres formato String EBCDI
 * \param flag  : Puntero a flags de estado del parsing, si retorna NULL este debe ser descartado.
 *  En caso de retornar un valor diferente de NULL debe mirar este para verificar si el parsing
 *  se completo de forma sastifactoria.
 * \return 
 *  \li Success puntero de la estructura alocada dinamicamente y si se paso un flags en este coloca '0'
 *  \li Failure NULL en caso de no poder iniciar el parsing, si pudo iniciar y se paso un flags coloca en 
 *  este un valor distinto de cero.
 * 
 * Campos de datos, void** 
 *  1° - Con la cantidad de campos habiltiados, reservamos memoria para cada uno armando 
 *       la matriz.
 *  2° - Luego reservamso por cada campo en funcion de su longitud constante/variable. 
 * \version 01v01d00.
 * \note notq.
 * \warning mensaje de "warning". 
 * \date Martes 05 de Octubre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>
 
 </PRE>  
 *********************************************************************************/
iso8583_sT * iso8583_ParseFromStr(const char *str, uint8_t *flag);


/** 
 * 
 * ******************************************************************************* 
 * \fn void iso8583_free(iso8583_sT * psT);
 * \brief funcion para liberar una estructura \ref iso8583_sT alocada
 *  dinamicamente cuando se realiza el parsing.
 * \param psT : Puntero a la estructura \ref iso8583_sT alocada dinamicamente
 * a liberar.
 * \return Nothing
 * \version 01v01d00.
 * \note notq.
 * \warning mensaje de "warning". 
 * \date Martes 05 de Octubre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>
 
 </PRE>  
 *********************************************************************************/
void iso8583_free(iso8583_sT * psT);

/** 
 * 
 * ******************************************************************************* 
 * \fn void iso8583_print(FILE *stream,iso8583_sT * msg);
 * \brief funcion para imprimir sobre un stream un mensaje en formato ISO-8583 
 * \param msg     : Puntero a la estructura \ref iso8583_sT alocada dinamicamente
 * a liberar.
 * \param stream  : Stream, este puede ser un archivo abierto. Este puede ser los 
 * stream estandar como \b stdout, \b stderr .
 * \param flag    : Flag/Bendera para indicar el formato de impresion podemos usar 
 * lso siguentes labels para especificar:
 *  \li 0                         sin formato especifico --raw -r
 *  \li iso8583_FLGPRINT_COLOR    Salida con color, para uso en consola
 *  \li iso8583_FLGPRINT_TBL      Formato con tabla
 *  \li (iso8583_FLGPRINT_TBL|iso8583_FLGPRINT_COLOR) Habilitamso los dos anteriores
 *  
 * \return Nothing
 * \version 01v01d00.
 * \note notq.
 * \warning mensaje de "warning". 
 * \date Martes 05 de Octubre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>
 
 </PRE>  
 *********************************************************************************/
void iso8583_print(FILE *stream,iso8583_sT * msg, uint8_t flag);


/** 
 * 
 * ******************************************************************************* 
 * \fn uint8_t iso8583_GetNumberFieldInBitMap(iso8583_sT *pmsg ,uint8_t *errflag)
 * \brief Funcion para obtener el numero de campos en un mensaje ISO8583 a partir de sus bitmap
 * \param pmsg  : Puntero a la estructura del tipo \b iso8583_sT donde se alamcenara el contexto
 * \param pflag : Puntero a la variable donde deseamos almacenar los flags, es opcional (no en uso aun)
 * \return Numero de campos en la lista.
 * \version 01v01d00.
 * \note notq.
 * \warning mensaje de "warning". 
 * \date Martes 05 de Octubre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>
 
 </PRE>  
 
 *********************************************************************************/
uint8_t iso8583_GetNumberFieldInBitMap(iso8583_sT *pmsg ,uint8_t *pflag);



/** 
 * 
 * ******************************************************************************* 
 * \fn char* iso8583_GetFrameFromStr(const char *str,uint8_t *flags);
 * \brief funcion para obtener el frame (Cadena en formato ASCII) de un mensaje ISO8583
 * desde una cadena de caracteres con formato EBCDIC ( | LEN | MTID | BIT MAP | ... MSG  | ). 
 * \param str   : Cadena de caracteres que representa el mensaje ISO8583, con el caracter de terminacion '\0'.
 * \param flags : Puntero al flags en caso de necesitar una notificacion de error.
 * \return
 *  \li Success Puntero al frame armado, debe ser liberado luego de su uso.
 *  \li Failure NULL 
 * \version 01v01d00.
 * \note notq.
 * \warning mensaje de "warning". 
 * \date Martes 05 de Octubre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>
 
 </PRE>  
 *********************************************************************************/
char* iso8583_GetFrameFromStr(const char *str,uint8_t *flags);


#endif /* #if (iso8583_USE_GlobalFunctions == 1) */
/* 
 * =====================[ END   Global functions declaration ]=====================
 */
/* 
 * ======================[ BEGIN Global Macros functions ]=========================
 */
#if ( iso8583_USE_GlobalMacroApis == 1 )
/**
 * 
 * ********************************************************************************
 * \def iso8583_macro_ex(Arg1,Arg2)
 * \details Descripcion detallada sobre la macro funcion \ref iso8583_macro_ex().
 * \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
 * \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
 *
 * \brief Descripcion breve sobre la macro funcion \ref iso8583_macro_ex().
 * \param Arg1 : Argumento uno, de la macro funcion.
 * \param Arg2 : Argumento dos, de la macro funcion.
 * \return nothinig
 * \version 01v01d00.
 * \note nota.
 * \warning mensaje de "warning".
 * \date Martes 05 de Octubre, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 < PRE>                                       *
 
 </PRE> 
 *********************************************************************************/ 
#define iso8583_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( iso8583_USE_GlobalMacroApis == 1 ) */
/* 
 * ======================[ END   Global Macros functions ]=========================
 */
/*
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ──────────────────────[ END   __iso8583_version__    01v00d00 ]────────────────────── │
 │                                                                                       │
 │                                                                                       │             
 └───────────────────────────────────────────────────────────────────────────────────────┘
 *
 */
#elif (version_QueryNumber(__iso8583_version__,01v00d01))
/* 
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ──────────────────────[ BEGIN __iso8583_version__    01v00d01 ]────────────────────── │
 │                                                                                       │
 │                                                                                       │             
 └───────────────────────────────────────────────────────────────────────────────────────┘
 */



/*
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ──────────────────────[ END   __iso8583_version__    01v00d01 ]────────────────────── │
 │                                                                                       │
 │                                                                                       │             
 └───────────────────────────────────────────────────────────────────────────────────────┘
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
#endif /* #ifndef __iso8583_h__ */
/*
 * 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =============================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(iso8583_projectEnable == 1) */

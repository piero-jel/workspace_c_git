#ifndef stdcutils_projectEnable
#define stdcutils_projectEnable 1 /**<@brief enable/disable the project */
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
* \file stdcutils.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v00d00.
* \date Sabado 17 de Julio, 2021.
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
#ifndef __stdcutils_h__
#define __stdcutils_h__ /**<@brief Definimos el Nombre del modulo */


#if (stdcutils_projectEnable == 1)

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
{ /* } */
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
#define stdcutils_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define stdcutils_USE_GlobalTypedef   0 /**<@brief enable/disable the use Global Typedef */
#define stdcutils_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define stdcutils_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define stdcutils_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
 * \def __stdcutils_version__ definimos la version actual del proyecto.
 * version 01v00d00 -> test 
 * version 01v00d01 -> test 
 * version 01v00d02 -> test
 * version 01v00d03 -> test
 * version 01v00d04 -> test
 * version 01v00d05 -> test
 *
 * */
#ifndef __stdcutils_version__
#define __stdcutils_version__        version_SetNumber(01v00d00)
#endif

/* 
 * ======================[ END   labels enable/disable ]===============================
 */
#if (version_QueryNumber(__stdcutils_version__,01v00d00))
/* 
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ─────────────────────[ BEGIN __stdcutils_version__    01v00d00 ]───────────────────── │
 │                                                                                       │
 │                                                                                       │             
 └───────────────────────────────────────────────────────────────────────────────────────┘
 */
/* ======================[ BEGIN Global Macros/labels definition ]================= */
#if (stdcutils_USE_GlobalMacro == 1)
#define stdc_INTEGER    0x00
#define stdc_FLOAT_32   0x01
#define stdc_FLOAT_64   0x02


#endif /* #if(stdcutils_USE_GlobalMacro == 1) */
/* ======================[ END   Global Macros/labels definition ]================= */

/* ======================[ BEGIN Global typedef      ]============================= */
#if (stdcutils_USE_GlobalTypedef == 1)

/**
 * \typedef stdcutils_tvar_ex_vT;
 * \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
 * \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
 * \version 01v00d00.
 * \note nota.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int stdcutils_tvar_ex_vT;


/**
 * \typedef stdcutils_pfun_ex_fT;
 * \details Descripcion detallada sobre la redefinicion de puntero a funcion.
 * \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
 * Prototipo de la funcion, al acual debe apuntar:
 *  + void * function ( void * arg )
 * \version 01v00d00.
 * \note nota.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*stdcutils_pfun_ex_fT) (void *); 


/**
 * \struct stdcutils_struct_ex_sT;
 * \brief Descripcion breve sobre el tipo de estructura.
 * Elementos que componen a la Estructura de datos:
 *  \li \ref vtchar;
 *  \li \ref vtint;
 *  \li \ref vtdouble;
 * \version 01v00d00.
 * \note nota sobre la estructura.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} stdcutils_struct_ex_sT ; 

/**
 * \union stdcutils_union_ex_uT;
 * \brief Descripcion breve sobre el tipo de union.
 * Elementos que componen la union:
 *   \li \ref item1 
 *   \li \ref item2 
 * \version 01v00d00.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} stdcutils_union_ex_uT;


/**
 * \enum stdcutils_enum_eT;
 * \details Descripcion detallada sobre la redefinicion de enumeracio.
 * \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
 * Elementos que componen la enumeracion:
 *  \li \ref stdcutils_eITEM0 . 
 *  \li \ref stdcutils_eITEM1 .
 *  \li \ref stdcutils_eITEM2 .
 * \version 01v00d00.
 * \warning mensaje de "warning".
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  stdcutils_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'stdcutils_eITEM0' de Enumeracion */
  stdcutils_eITEM1,     /**<@brief descripcion breve de la etiqueta 'stdcutils_eITEM1' de Enumeracion */
  stdcutils_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'stdcutils_eITEM2' de Enumeracion */
} stdcutils_enum_eT;

#endif /* #if(stdcutils_USE_GlobalTypedef == 1) */
/* ======================[ END   Global typedef      ]============================= */
/* =====================[ BEGIN Global variable declaration  ]===================== */
#if (stdcutils_USE_GlobalData==1)
extern unsigned int stdcutils_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (stdcutils_USE_GlobalData==1) */
/* =====================[ END   Global variable declaration  ]===================== */ 
/* =====================[ BEGIN Global functions declaration ]===================== */
#if (stdcutils_USE_GlobalFunctions == 1)
/** 
 * 
 * ******************************************************************************* 
 * \fn bool_t stdc_number2bytes(int32_t num, char *byte1,char *byte0); 
 * \brief Funcion para convertir un numero de 16-Bits (unsigned) en dos bytes 
 * con peso, decodificacion de decimal a base 256
 * num => byte1 * 250^1 + byte0 * 256 ^ 0 
 * \param num : Numero que se desea convertir o descomponer en dos byte.
 * \param byte1 : Puntero a donde colocar el byte mas significativo peso '1'.
 * \param byte0 : Puntero a donde colocar el byte menos significativo peso '0'.
 * \return status de la opreacion.
 *      \li TRUE, success.
 *      \li FALSE, failure.
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example
  <PRE>
  
  </PRE>  
 *********************************************************************************/
bool_t stdc_number2bytes(int32_t num, char *byte1,char *byte0);

/**
 * 
 * ******************************************************************************* 
 * \fn bool_t stdc_bytes2number(char *byte1,char *byte0,int32_t *num);
 * \brief Funcion para convertir o reconstruir un numero de 16-Bits (unsigned) 
 * tomando dos bytes de la forma num = byte1 * 250^1 + byte0 * 256 ^ 0 ; 
 * \param byte1 : Puntero a donde colocar el byte mas significativo peso '1'.
 * \param byte0 : ¡untero a donde colocar el byte menos significativo peso '0'.
 * \param num   : Puntero donde se almacenara el resutlado de la operacion.
 * \return status de la opreacion.
 *      \li TRUE, success.
 *      \li FALSE, failure.
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 < PRE>
 
 </PRE>  
 *********************************************************************************/
bool_t stdc_bytes2number(char *byte1,char *byte0,int32_t *num);

/**
 * 
 * ******************************************************************************* 
 * \fn bool_t stdc_number2bytes_i64(int64_t num, char *bytebuff, uint32_t lenbuff);
 * \brief Funcion para convertir un numero del tipo int64 en una secuencia de bytes
 * del tipo  num = b[0] * 256^3 + b[1] * 256^2 + b[2] * 256^1 + b[3] * 256^0
 * \param num : Numero que se descomponera en bytes por peso en base 256.
 * \param bytebuff : Puntero al buffer donde se almacenar el resultado, en orden 
 * especificado '0' cero el de mayor peso.
 * \param lenbuff   : Longitud del buffer, este debe ser de almenos 4-Bytes.
 * \return status de la opreacion.
 *      \li TRUE, success.
 *      \li FALSE, failure.
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 < PRE>
 
 </PRE>  
 *********************************************************************************/
bool_t stdc_number2bytes_i64(int64_t num, char *bytebuff, uint32_t lenbuff);

/**
 * 
 * ******************************************************************************* 
 * \fn bool_t stdc_bytes2number_i64(char *bytebuff, uint32_t lenbuff,int64_t *num);
 * \brief Funcion para convertir o reconstruir un numero de 64-Bits (32-Bits unsigned) 
 * descompuesto en byte de base 256: 
 * num = b[0] * 256^3 + b[1] * 256^2 + b[2] * 256^1 + b[3] * 256^0
 * \param bytebuff : Puntero al buffer donde se encuentra la secuencia de bytes
 * en el orden especificado, el de mayor peso en la posicion '0'.
 * \param lenbuff : Longitud del buffer, debe ser de almenso 4-bytes.
 * \param num   : Puntero donde se almacenara el resultado de la operacion.
 * \return status de la opreacion.
 *      \li TRUE, success.
 *      \li FALSE, failure.
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 < PRE>
 
 </PRE>  
 *********************************************************************************/
bool_t stdc_bytes2number_i64(char *bytebuff, uint32_t lenbuff,int64_t *num);


/**
 * 
 * ******************************************************************************* 
 * \fn bool_t stdc_strhex2uint32(const char *str, uint32_t len, uint32_t *num);
 * \brief Funcion para convertir, una cadena string str con digitos hexadecimales, 
 * en un nuemero entero de 32-bit sin signo, hasta 8 caracteres maximo.
 *  rval = str[0] * 16^(N) + str[1] * 16^(N-1) + str[1] * 16^(N-2) +...+ str[7] * 16^(N-N); 
 *  Con N <==>  0 < N < 9
 * \param str    : String que continene la cadena de caracteres hexadecimales.
 * \param len    : Cantidad de caracteres a tomar de la cadena. Si este es '0' 
 * ( \b len = 0 ) intenta tomar la cadena completa, siempre y cuando la longitud 
 * de la misma sea menor a \b '9', de lo contrario solo tomara los primeros 
 * \b '8' caracteres.
 * Si la longitud pasada es mayor a \b '0' y no menor a  \b '9' tomara los 
 * primeros \b '8' caracteres si la cadena tiene una longitud igual o mayor a este 
 * valor. De lo contrario tomara la cadena completa (cuya longitud sera menor a \b '9' )
 *  
 * \param num    : Puntero donde se almacenara el resutlado de la operacion.
 * \return status de la opreacion.
 *      \li TRUE, success. el contenido de \b num es actualizado con el resultado de la operacion.
 *      \li FALSE, failure, el contenido de \b num no es actualizado.
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 < PRE>
  uint32_t i = 0;
  char * strHexnum = "0163";
  if(stdc_strhex2uint32(strHexnum,4,&i))
  {
    CPRINTF(GREEN,"\t Conversion %s = %06u \n", strHexnum,i);
  }
  else
  {
    CPRINTF(RED,"\t Fallo la conversion con %s\n", strHexnum);
  }
 </PRE>  
 // bool_t stdc_strhex2uint32(char *str, uint32_t *plen,uint32_t *num);
 *********************************************************************************/
bool_t stdc_strhex2uint32(const char *str, uint32_t len, uint32_t *num);


/**
 *
 * ******************************************************************************* 
 * \fn bool_t hexascii2hexa4(const char *porg,char *pbdst,uint32_t plbdst)
 * \brief Codificaca una cadena de digitos hexadecimal en ASCII a hexadecimal de 4 bit
 * reduciendo el tamaño de la misma a la mitad.
 * \param porg    Puntero a la cadena Origen 'digitos hexadecimal codificados en ASCII'.
 * \param lorg    Longitud de la cadena a convertir, si este valor lo pasamos
 * con '0' convierte la totalidad de la cadena.
 * \param pbdst   Puntero al Buffer Destion.
 * \param plbdst  Puntero a la variable que contiene la longitud del buffer destino y
 * donde colocaremos la nueva longitud de la cadena resultante 'sin formato string - sin '\0''
 * \return estado de la conversion
 *  \li TRUE  : success
 *  \li FALSE : failure
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>
  char raw[] = "F0F1F0F07ABE64C128E0D218F1F6F5F2F1F0F6F7F9F9F9F9F9F9F9F0F4F4F0F0";
  char res[1024] = {0};  
  //....
  len = sizeof(res);
  stdc_hexascii2hex(raw,sizeof(raw),res, &len);
    [print]  'res = ����z�d�(����������������������'  
 </PRE>
 *********************************************************************************/
bool_t stdc_hexascii2hex(const char *porg,uint32_t lorg,char *pbdst,uint32_t *plbdst);


/**
 * 
 * ******************************************************************************* 
 * \fn bool_t hex2hexascii(char *porg, uint32_t lorg, char *pbdst,uint32_t lbdst)
 * \brief codificaca/expansion de un buffer de digitos hexadecimal 4-bits a 
 * hexadecimal ASCII de 8 bit. Expandiendo el tamaño del resultante al doble.
 * \param porg    Puntero a la cadena Origen 'hexa 4-Bits (dos por Byte)'
 * \param lorg    Longitud de la cadena Origen, la cantidad de bytes.
 * \param pbdst   Puntero al Buffer Destion.
 * \param plbdst  Puntero donde pasamos la Longitud del buffer destino y en el cual
 * actualizamos con la longitud del resultado.
 * estedebera ser el doble de \ref lorg
 * \return estado de la conversion. 
 *  \li TRUE  : success
 *  \li FALSE : failure, EINVAL
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> 
* \par example :
 <PRE>
  char raw[] = "F0F1F0F07ABE64C128E0D218F1F6F5F2F1F0F6F7F9F9F9F9F9F9F9F0F4F4F0F0";
  char res[1024] = {0};  
  //....
  len = sizeof(res);
  stdc_hexascii2hex(raw,res, &len);
    [print]  'res = ����z�d�(����������������������'
  
  char buff[1024] = {0};
  uint32_t lbuff = sizeof(buff);
  stdc_hex2hexascii(res,len, buff,&lbuff);
    [print]  'buff = F0F1F0F07ABE64C128E0D218F1F6F5F2F1F0F6F7F9F9F9F9F9F9F9F0F4F4F0F0'
 </PRE>* 
 *********************************************************************************/
bool_t stdc_hex2hexascii(char *porg, uint32_t lorg, char *pbdst,uint32_t *plbdst);


/**
 * 
 * ******************************************************************************* 
 * \fn bool_t stdc_genrandom(void* buff, size_t len );
 * \brief Funcion para generar un arry de memoria con numeros aleatorios. 
 * \param buff    Puntero al Buffer de memoria, en el cual se almacenara los
 * numeros aleatorios generados.
 * \param len     Numeros de bytes del buffer.
 * \return estado de la Generacion.
 *  \li TRUE  : success
 *  \li FALSE : failure, EINVAL
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
 <PRE>

 </PRE>
 *********************************************************************************/
#define stdc_genrandom(Buff, Len)\
  stdc_genrandom_type(Buff,Len,stdc_INTEGER)
  
// bool_t stdc_genrandom(void* buff, size_t len );


/**
 * 
 * ******************************************************************************* 
 * \fn bool_t stdc_swap(void *a, void*b, void* tmp, size_t len);
 * \brief Funcion para generar un arry de memoria con numeros aleatorios. 
 * \param a     : Puntero al item a
 * \param b     : Puntero al item b 
 * \param tmp   : Puntero a la variable temporal.
 * \param len   : tamaño en bytes de los item, todos deben ser mismo tamaño. 
 * \return estado de la Generacion.
 *  \li TRUE  : success
 *  \li FALSE : failure, EINVAL
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
 <PRE>

 </PRE>
 *********************************************************************************/
bool_t stdc_swap(void *a, void*b, void* tmp, size_t len);

/**
 * 
 * ******************************************************************************* 
 * \fn bool_t stdc_genrandom_type(void* buff, size_t len , uint8_t type)
 * \brief Funcion para generar un arry de memoria con numeros aleatorios. 
 * \param buff    Puntero al Buffer de memoria, en el cual se almacenara los
 * numeros aleatorios generados.
 * \param len     Numeros de bytes del buffer.
 * \param type    Tipo de buffer a generar
 *  \li \ref stdc_INTEGER_32
 *  \li \ref stdc_FLOAT_32
 *  \li \ref stdc_FLOAT_64
 * \return estado de la Generacion.
 *  \li TRUE  : success
 *  \li FALSE : failure, EINVAL 
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
 <PRE>

 </PRE>
 *********************************************************************************/
bool_t stdc_genrandom_type(void* buff, size_t len , uint8_t type);

/**
 * 
 * ******************************************************************************* 
 * \fn size_t stdc_sort_insert(void *arr, size_t nitme, size_t sitem, bool_t (*fn_cmp) (void*,void*));
 * \brief Metodo de ordenamiento "sort" insercion. 
 * \param arr    : Array de elementos a ordenar.
 * \param nitme  : Numero de item/elementos del Array.
 * \param sitem  : Tamaño de cada Item/Elementos.
 * \param fn_cmp : Puntero a Funcion que realiza la comparacion, esta debe ser
 * del tipo 'bool_t fn_cmp(void* a,void* b);'
 *  
 * \return el numero de interacciones/saltos para realizar el ordenamiento.
 *  \li -1  : En caso de falla
 *  \li > 0 : Numero de interacciones.
 * \version 01v00d00.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
 <PRE>
bool_t cmp_f32(void *a,void * b)
{
  float *aa = (float*) a;
  float *bb = (float*) b;
  return isgreater(*aa,*bb)? TRUE:FALSE;
}
float fbuff[16];
stdc_genrandom_type(fbuff,sizeof(fbuff),stdc_FLOAT_32);
puts("\t Buffer con numeros aleatorios FLOAT generados:\n");
PRINT_ARRAY(fbuff,"%10.6f");
interator = stdc_sortInsert(fbuff,ARRAY_SIZE(fbuff),sizeof(float),cmp_f32);
printf("\n\t Buffer Ordenado, N° Loops = %d. \n",interator);
PRINT_ARRAY(fbuff,"%10.6f");
 </PRE>
 *********************************************************************************/
size_t stdc_sortInsert(void *arr, uint32_t nitem, uint32_t sitem, bool_t (*fn_cmp) (void*,void*));





/**
 * 
 ***********************************************************************************************  
 * \fn uint32_t stdc_EBCDIC2ASCII(const char* ebcdic, char* buff, uint32_t lbuff );
 * \brief funcion para realizar la conversion de una cadena en formato EBCDIC en ASCII.
 * \param ebcdic : cadena string que contiene la informacion en formato EBCDIC
 * \param buff   : Buffer donde se colocara el resultado, cadena en formato ASCII con caracter de terminacion '\0'
 * \param lbuff  : Longitud del buffer
 * \return numero de byte insertados en el buffer, este no contempla el caracter de terminacion '\0'.
 * Este represetna la mitad de caracteres sacadas de la cadena.
 * \note note:
 * \warning warning:
 * \date Wednesday 08 de September, 2021.
 * \file main
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>
</PRE>
* **********************************************************************************************/
uint32_t stdc_EBCDIC2ASCII(const char* ebcdic, char* buff, uint32_t lbuff );
/**
 * 
 * **********************************************************************************************  
 * \fn uint32_t stdc_ASCII2EBCDIC(const char* ascii, char* buff, uint32_t lbuff );
 * \brief funcion para realizar la conversion de una cadena en formato ASCII a EBCDIC (IBM).
 * \param ascii  : cadena string que contiene la informacion en formato ASCII
 * \param buff   : Buffer donde se colocara el resultado, cadena en formato EBCDIC con caracter de terminacion '\0'
 * \param lbuff  : Longitud del buffer \ref buff.
 * \return
 *  \li Success: numero de byte insertados en el buffer, este no contempla el caracter de terminacion '\0'.
 *  \li Failure: Cero '0'
 * \note note:
 * \warning warning:
 * \date Wednesday 08 de September, 2021.
 * \file main
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>
</PRE>
* **********************************************************************************************/
uint32_t stdc_ASCII2EBCDIC(const char* ascii, char* buff, uint32_t lbuff );


/**
 * 
 ***********************************************************************************************  
 * \fn uint8_t stdc_str2Hex4Bit(char digit);
 * \param digit : Digito en fromato ASCII {0~9}-{a~f}{A~F} 
 * \return 
 *  \li success Numero de entero de 8 byte con valores que representa el digito Hex de 4-Bits 0x0 ~ 0xF 
 *  \li failure retorna -16, 0xF0 ya que -1 = 0xFF por lo que se puede confundir con 15 = 0xF si el 
 *  resultado es utilizado como mascara
 *  int8_t val = -16;
 *  CFPRINTF(RED,stdout,"\tValor %d = 0x%X St = %u\n",val,val,(val & 0x8)?1:0);
 * \note note:
 * \warning warning:
 * \date Wednesday 08 de September, 2021.
 * \file main
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>
</PRE>
* **********************************************************************************************/
int8_t stdc_str2Hex4Bit(char digit);
// uint8_t stdc_str2Hex4Bit(char digit);
/**
 * 
 ***********************************************************************************************  
 * \fn int32_t stdc_strtargetInList (const char * target, const char **list);
 * \param target : argument 1
 * \param arg_2 : argument 2
 * \return type return value
 *    \li 0, success
 *    \li 1, failure
 * \note note:
 * \warning warning:
 * \date Wednesday 08 de September, 2021.
 * \file main
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>
</PRE>
* **********************************************************************************************/
int32_t stdc_strtargetInList (const char * target, const char **list);

/**
 * 
 ********************************************************************************************** 
 * \fn int32_t stdc_targetInList (const void * target, uint32_t len, const void** list, uint32_t nitem);
 * \param target : argument 1
 * \param arg_2 : argument 2
 * \return type return value
 *    \li 0, success
 *    \li 1, failure
 * \note note:
 * \warning warning:
 * \date Wednesday 08 de September, 2021.
 * \file main
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>
</PRE>
* **********************************************************************************************/
int32_t stdc_targetInList (const void * target, uint32_t len, const void** list, uint32_t nitem);


/**
 * 
 ***********************************************************************************************  
 * \fn bool_t stdc_EBCDIC2uint32(const char* ebcdic, uint32_t *pnum );
 * \brief funcion para convertir una cadena EBCDIC a numero entero de hasta 32Bits.
 * \param ebcdic : cadena string que contiene la informacion en formato EBCDIC
 * \param pnum   : Puntero donde se almacenara el numero. 
 * \param len    : Longitud de la cadena que se desea convertir, en caso de pasarle '0'
 * intentara convertir la cadena completa cPuntero donde se almacenara el numero. 
 * \return estado de la conversion
 *  \li Success \b TRUE
 *  \li Failute \b FALSE
 * \note note:
 * \warning warning:
 * \date Wednesday 08 de September, 2021.
 * \file main
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>
</PRE>
* **********************************************************************************************/
bool_t stdc_EBCDIC2uint32(const char* ebcdic, uint32_t len, uint32_t *pnum );


#endif /* #if (stdcutils_USE_GlobalFunctions == 1) */
/* =====================[ END   Global functions declaration ]===================== */
/* ======================[ BEGIN Global Macros functions ]========================= */
#if ( stdcutils_USE_GlobalMacroApis == 1 )
/**
 * 
 * ********************************************************************************
 * \def stdcutils_macro_ex(Arg1,Arg2)
 * \details Descripcion detallada sobre la macro funcion \ref stdcutils_macro_ex().
 * \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
 * \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
 *
 * \brief Descripcion breve sobre la macro funcion \ref stdcutils_macro_ex().
 * \param Arg1 : Argumento uno, de la macro funcion.
 * \param Arg2 : Argumento dos, de la macro funcion.
 * \return nothinig
 * \version 01v00d00.
 * \note nota.
 * \warning mensaje de "warning".
 * \date Sabado 17 de Julio, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 < PRE>                                       *
 
 </PRE> 
 *********************************************************************************/ 
#define stdcutils_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( stdcutils_USE_GlobalMacroApis == 1 ) */
/* ======================[ END   Global Macros functions ]========================= */
/*
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ─────────────────────[ END   __stdcutils_version__    01v00d00 ]───────────────────── │
 │                                                                                       │
 │                                                                                       │             
 └───────────────────────────────────────────────────────────────────────────────────────┘
 *
 */
#elif (version_QueryNumber(__stdcutils_version__,01v00d01))
/* 
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ─────────────────────[ BEGIN __stdcutils_version__    01v00d01 ]───────────────────── │
 │                                                                                       │
 │                                                                                       │             
 └───────────────────────────────────────────────────────────────────────────────────────┘
 */



/*
 ┌ ───────────────────────────────────────────*────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ─────────────────────[ END   __stdcutils_version__    01v00d01 ]───────────────────── │
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
#endif /* #ifndef __stdcutils_h__ */
/*
 * 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =============================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(stdcutils_projectEnable == 1) */

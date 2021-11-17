/** ***********************************************************************************//**
 * \addtogroup template 
 * @{
 * \copyright  
 * 2021, Luccioni Jesús Emanuel \n
 * All rights reserved.\n 
 * This file is part of template .\n
 * Redistribution is not allowed on binary and source forms, with or without \n
 * modification. Use is permitted with prior authorization by the copyright 
 * holder. &copy;
 * \file main.h
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
 * \brief Descripcion breve.
 * \details Descripcion detallada.
 *
 * \version 01v01d01.
 * \date Domingo 17 de Enero, 2021.
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
/*
 * -- Definimos el Nombre del modulo
*/
#ifndef __main_h__
#define __main_h__
/*
 * ===========================[ BEGIN include header file ]===========================
 */

#include <linkedlist.h>
#include <stdc_print.h>
#include <stdc.h>
/*
 * ===========================[ END include header file   ]===========================
 * */


/*
 * ==========================[ BEGIN Main APIs Declaration ]==========================
 */

/**
* ******************************************************************************** 
* \fn int main(int argc, char **argv);
* \brief Funcion Principal
* \param argc : cantidad de Argumentos pasados al invocar la app.
* \param argv : puntero a puntero que contiene el listado de arguementos.
* \return status de la ejecucion de la app.
*      \li 0, success
*      \li 1, failure
* \version numero de version a la cual corresponde.
* \note nota.
* \warning mensaje de "warning". 
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
*********************************************************************************/
int main(int argc, char **argv);



/**
 * \fn
 * \brief
 * \param
 * \return 
 * funcion callback que usa linkedlist para imprimir datos del tipo int
 * 
 */
static inline int fn_printint( void *pdato, char *buff,unsigned int lbuff)
{
  if(buff == NULL || lbuff == 0)
    return EINVAL;
  int dato;
  if(pdato != NULL)
    dato = *((int*) pdato);
  else
    dato = 0;
  snprintf(buff,lbuff,"%d",dato);
  return 0;
}

/**
 * \fn
 * \brief
 * \param
 * \return 
 * funcion callback que usa linkedlist para imprimir datos del tipo array de caracteres 'string'
 * 
 */
static inline int fn_printstr( void *pdato, char *buff,unsigned int lbuff)
{
  if(buff == NULL || lbuff == 0)
    return EINVAL;
  char *dato;
  if(pdato != NULL)
    dato = (char*) pdato;
  else
    dato = NULL;
  snprintf(buff,lbuff,"%s", (dato == NULL)? "null":dato);
  return 0;
}

/**
 * \fn
 * \brief
 * \param
 * \return 
 * funcion callback que usa linkedlist para comparar tipos de datos array de caracteres 'string'
 * 
 */
static inline int fn_cmpstr(void *data1,void *data2)
{
  char *str1 = (char*) data1;
  char *str2 = (char*) data2;
  int a,b;
  while(*str1 != '\0' && *str2 != '\0')
  {
    a = toupper(*str1);
    b = toupper(*str2);
    if(a == b)
    {
      str1++;
      str2++;
      continue;
    }
    return (a-b);
  }
  return 0;
}

/**
 * \fn
 * \brief
 * \param
 * \return 
 * funcion callback que usa linkedlist para comparar tipos de datos int 
 * 
 */
static inline int fn_cmpint(void *data1,void *data2)
{
  int val1 = *((int*) data1);
  int val2 = *((int*) data2);
  if(val1 == val2)
    return 0;
  return (val1 > val2)? 1:-1;
}



/**
 * \fn
 * \brief
 * \param
 * \return 
 * funcion callback que usa linkedlist para comparar tipos de datos int 
 * 
 */
static inline int fn_getsizestr(void* data, size_t *nbyte, size_t *nitem)
{
  if( data == NULL || nbyte == NULL || nitem == NULL)
    return EINVAL;

  char *str = (char*) data;
  *nbyte = strlen(str);
  *nitem = 1;
  return 0;
}


/**
 * \fn
 * \brief
 * \param
 * \return 
 * retorna un duplicado del str en lower case, en memoria dinamica Heap
 * FIXME: no implementada
 */
char* stdc_strtolower(const char *str);

/**
 * \fn
 * \brief
 * \param
 * \return  
 * retorna un duplicado de str, en memoria dinamica Heap
*/
char* stdc_strdup(const char *str);

/**
 * \fn
 * \brief
 * \param
 * \return 
 * retorna un duplicado de data, en memoria dinamica Heap
*/
/** 
 * \fn int stdc_gswap(void **d1, void** d2);
 * \brief "generic swap, receive pointer to pointers", este realiza
 * el intercambio de dato generico "punteros void".
 * \param d1  : puntero a puntero del dato 1
 * \param d2  : puntero a puntero del dato 2
 * \return Estado de la operacion
 *  + 0 : success
 *  + != 0 failure, valor positivo que representa el errno.
 * \version 01v00d01.
 * \note notq.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>
 
 </PRE> 
*/
int* stdc_intdup(int data, int *errnum);





/*
 * ==========================[ END   Main APIs Declaration ]==========================
 */


/*
 * ==========================[ BEGIN Main macros APIs     ]==========================
 */



/*
 * ==========================[ END   Main macros APIs     ]==========================
 */



/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef __main_h__ */

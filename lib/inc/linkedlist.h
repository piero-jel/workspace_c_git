#ifndef linkedlist_projectEnable
#define linkedlist_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup linkedlist 
* @{ borrarme, solo para mantener la identacion -> }@
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of linkedlist .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file linkedlist.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v00d01.
* \date Lunes 01 de Noviembre, .
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
#ifndef __linkedlist_h__
#define __linkedlist_h__ /**<@brief Definimos el Nombre del modulo */


#if (linkedlist_projectEnable == 1)

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 
 * ============================[BEGIN of project file]=======================================
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
#include <stdlib.h> /* size_t ssize_t .... */

#include <version.h>

// #include <stdctype.h>
// #include <stdc.h>

/* 
 * ======================[ END   include header file ]=================================
 */

/* 
 * ======================[ BEGIN labels enable/disable ]===============================
 */
#define linkedlist_USE_GlobalMacro     0 /**<@brief enable/disable the use Global Macros/Labels */
#define linkedlist_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define linkedlist_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define linkedlist_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define linkedlist_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
 * \def __linkedlist_version__ definimos la version actual del proyecto.
 * version 01v00d00 -> test 
 * version 01v00d01 -> test 
 * version 01v00d02 -> test
 * version 01v00d03 -> test
 * version 01v00d04 -> test
 * version 01v00d05 -> test
 *
 * */
#ifndef __linkedlist_version__
#define __linkedlist_version__        version_SetNumber(01v00d00)
#endif

/* 
 * ======================[ END   labels enable/disable ]===============================
 */
#if (version_QueryNumber(__linkedlist_version__,01v00d00))
/* 
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ────────────────────[ BEGIN __linkedlist_version__    01v00d00 ]───────────────────── │
 │                                                                                       │
 │                                                                                       │             
 └───────────────────────────────────────────────────────────────────────────────────────┘
 */

/* ======================[ BEGIN Global Macros/labels definition ]================= */
#if (linkedlist_USE_GlobalMacro == 1)



#endif /* #if(linkedlist_USE_GlobalMacro == 1) */
/* ======================[ END   Global Macros/labels definition ]================= */

/* ======================[ BEGIN Global typedef      ]============================= */
#if (linkedlist_USE_GlobalTypedef == 1)


/**
 * \typedef nnode_t; 
 * \brief redefinicion de dato primitivo para enumeracion de nodos dentro de una lista enlazada
 * \version 01v00d01.
 * \note nota.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int nnode_t;


/**
* \struct node_t; 
* \brief estructura de datos que representa un node de una lista enlazada.
* Elementos que componen a la Estructura de datos:
*  \li \ref prev;
*  \li \ref next;
*  \li \ref dato;
* \version 01v00d01.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Lunes 01 de Noviembre, .
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct __node_t
{
  struct __node_t *prev; /**<@brief direccion al nodo anterior */
  struct __node_t *next; /**<@brief direccion al nodo siguente */
  void * dato; /**<@brief dato contenido en el nodo */
} node_t;

/**
* \struct linkedlist_t; 
* \brief estructura de datos que representa una  lista enlazada.
* Elementos que componen a la Estructura de datos:
*  \li \ref nnode;
*  \li \ref node;
* \version AAvBBdCC.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date day dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  nnode_t nnode; /**<@brief numeros de nodos */ 
  node_t *node; /**<@brief nodo, cabecera de la lista*/
}linkedlist_t;






#endif /* #if(linkedlist_USE_GlobalTypedef == 1) */
/* ======================[ END   Global typedef      ]============================= */

/* =====================[ BEGIN Global variable declaration  ]===================== */
#if (linkedlist_USE_GlobalData==1)
extern unsigned int linkedlist_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (linkedlist_USE_GlobalData==1) */
/* =====================[ END   Global variable declaration  ]===================== */ 

/* =====================[ BEGIN Global functions declaration ]===================== */
#if (linkedlist_USE_GlobalFunctions == 1)




/**
 * * ******************************************************************************
 * \fn linkedlist_t * linkedlist_new(void *pdato, int * errnum);
 * \brief Funcion para crear una lista enlazada. 
 * \param pdato     : Puntero al dato alocado en memoria dinamica.  
 * \param errnum    : Puntero a un int donde se almacenara el erro enc aso de que 
 * ocurra uno, es opcional puede ser NULL.
 * \return estado
 *  + success Punero a la lista creada con un nodo
 *  + failure NULL
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
 *********************************************************************************/
linkedlist_t * linkedlist_new(void *pdato, int * errnum);

/**
 * * ******************************************************************************
 * \fn int linkedlist_free(linkedlist_t * list);
 * \brief Funcion para liberar toda la memoria reservada por una lista enlazada. 
  * \param list      : direccion de memoria del Puntero a la lista. 
 *  \b linkedlist_t * list ...
 *  \b linkedlist_free( &list) ...
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_free(linkedlist_t ** list);

/**
 * 
 * ********************************************************************************
 * \fn int linkedlist_init(linkedlist_t *plinklist, void *pdato);
 * \brief Funcion para inicializar una estructura del tipo \b linkedlist_t.
 * enlazada
 * \param plinklist : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pdato     : Puntero al dato alocado en memoria dinamica.  
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_init(linkedlist_t *plinklist, void *pdato);

/**
 *
 * ********************************************************************************
 * \fn int linkedlist_deinit(linkedlist_t *list);
 * \brief Funcion para liberar todos los nodos de una lista, este no libera la 
 * estructur de la lista, esta queda vaica. * 
 * \param list      : direccion de memoria del Puntero a la lista. 
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_deinit(linkedlist_t *list);

/**
 * 
 * ********************************************************************************
 * \fn int linkedlist_push_bach(linkedlist_t *plinklist, void *pdato);
 * \brief Funcion para insertar un nodo, al final de una lista doblemente enlazada.
 * \param plinklist : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pdato     : Puntero al dato alocado en memoria dinamica. 
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_push_back(linkedlist_t *list, void *pdato);

/**
 *
 * ******************************************************************************
 * \fn int linkedlist_push_front(linkedlist_t *list, void *pdato);
 * \brief Funcion para insertar un nodo con su dato en inicio de la lista
 *  doblemente enlazada.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pdato : Puntero al dato alocado en memoria dinamica. 
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_push_front(linkedlist_t *list, void *pdato);

/**
 *
 * ********************************************************************************
 * \fn int linkedlist_push(linkedlist_t *list, uint32_t pos ,void *pdato);
 * \brief Funcion para insertar un nodo en la posicion indicada en una 
 * lista doblemente enlazada.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pos   : Posicion donde queremos colocar el nodo con el dato. Si esta no existe 
 * se coloca el nodo al final.
 * \param pdato : Puntero al dato alocado en memoria dinamica. 
 * \return estado
 *  + success
 *        0 : creo y coloco el nodo con el dato en la posicion solicitada
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_push(linkedlist_t *list, nnode_t pos ,void *pdato);

/**
 *
 * ********************************************************************************
 * \fn int linkedlist_pop_back(linkedlist_t *list, void **dato);
 * \brief Funcion para remover un nodo con su dato desde el final de la lista
 *  doblemente enlazada.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t. 
 * \param pdato : Puntero al puntero donde se almacenara el dato del nodo que 
 * se eliminara de la lista. Si este es NULL se librea toda la meoria del nodo. 
 * Recordar que este puntero copiado debe ser liberado despues de su uso.
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_pop_back(linkedlist_t *list, void **dato);

/**
 *
 * ********************************************************************************
 * \fn int linkedlist_pop_front(linkedlist_t *list, void **dato);
 * \brief Funcion para remover un nodo con su dato desde el principio de la lista
 *  doblemente enlazada.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t. 
 * \param pdato : Puntero al puntero donde se almacenara el dato del nodo que 
 * se eliminara de la lista. Si este es NULL se librea toda la meoria del nodo. 
 * Recordar que este puntero copiado debe ser liberado despues de su uso.
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_pop_front(linkedlist_t *list, void **dato);

/**
 *
 * ********************************************************************************
 * \fn int linkedlist_pop(linkedlist_t *list, uint32_t pos ,void **pdato);
 * \brief Funcion para remover un nodo con su dato en una posicion especificada.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pos   : Posicion de donde queremos sacar el nodo con el dato. Si esta no existe 
 * se saca el nodo al final.
 * \param pdato : Puntero al dato alocado en memoria dinamica. 
 * \return estado
 *  + success
 *        0 : creo y coloco el nodo con el dato en la posicion solicitada
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_pop(linkedlist_t *list, nnode_t pos ,void **dato);

/**
 * ********************************************************************************
 * \fn int linkedlist_print(linkedlist_t *pLinkList, int (*fncallback)(void*,char*,unsigned int) );
 * \brief Funcion para imprimir el contenido de una lista doblemente enlazada.
 * \param plinklist   : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param fncallback  : funcion del tipo
 *  int fncallback (void* data,char* buff,unsigned int lenbuff) 
 *    data  : dato que se debe convertir
 *    buff  : buffer donde debe colocar el tring
 *    lbuff : longitud del buffer
 *    Valor de retorno 'int', que reresenta el error (0: succes / Mayor a 0 failure ) *    
 *  Esta fncion se encarga de convertir el dato en un string. Es recomendable
 *  utilizar 'snprintf(buff,lenbuff,fmt,..)'
 * 
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_print(linkedlist_t *pLinkList, int (*fncallback)(void*,char*,unsigned int) );



/**
 *
 * ********************************************************************************
 * \fn int linkedlist_write(linkedlist_t *list, uint32_t pos ,void *pdato);
 * \brief Funcion para escribir (sobre escribir) un dato en un nodo.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pos   : Posicion donde queremos escribir el dato. Si esta no existe 
 * se coloca en el nodo final. El contenido actual es liberado
 * \param pdato : Puntero al dato alocado en memoria dinamica. 
 * \return estado
 *  + success
 *        0 : creo y coloco el nodo con el dato en la posicion solicitada
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_write(linkedlist_t *list, nnode_t pos ,void *pdato);

/**
 *
 * ********************************************************************************
 * \fn int linkedlist_sort(linkedlist_t *list, int (*fncallback)(void*,void *));
 * \brief Funcion para ordenar una lista doblemente enlazada.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param fncallback : Funcion callback del tipo 'int fn (void* d1,void* d2)'
 * la cual se encarga de la comparacion del tipo de dato almacenado en la lista.
 * Esta debe retornar '0' en caso de que sean iguales 'menor 0' si d1 < d2 y 
 * 'mayor 0' si d1 > d2.
 * 
 * \return estado
 *  + success
 *        0 : creo y coloco el nodo con el dato en la posicion solicitada
 *  + failure valor positivo que indica el error ocurrido
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
 *********************************************************************************/
int linkedlist_sort(linkedlist_t *list, int (*fncallback)(void*,void *));



/**
 *
 * ********************************************************************************
 * \fn linkedlist_t * linkedlist_fillfromfile( const char * pathfile, char * token, int *errnum);
 * \brief Funcion para llenar una lista enlazada desde un archivo.
 * \param pathfile  : path file, rua y nombre del archivo.
 * \param token     : Token en caso de necesitar discriminar caracteres de cada linea 
 * es opcional, puede ser \b NULL en caso de no necesitarlo.
 * \param errnum    : Puntero a donde almacenaremos el erro en caso de que suceda.
 * es opcional, puede ser \b NULL en caso de no necesitarlo.
 * \return 
 *  + success la lista enlazada donde se coloco la informacion del archivo.
 *  + failure \b NULL 
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
 *********************************************************************************/
linkedlist_t * linkedlist_fillfromfile( const char *pathfile, char * token, int *errnum);

/**
 *
 * ********************************************************************************
 * \fn int linkedlist_list2file(linkedlist_t *list, const char *pathfile, char * token);
 * \brief Funcion que escribe el contenido de una lista enlazada en un archivo.
 * \param list      : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pathfile  : path file, rua y nombre del archivo.
 * \param token     : Token en caso de necesitar escribir al final de cada item 
 * de la lista.
 * \param errnum    : Puntero a donde almacenaremos el erro en caso de que suceda.
 * es opcional, puede ser \b NULL en caso de no necesitarlo.
 * \return 
 *  + success la lista enlazada donde se coloco la informacion del archivo.
 *  + failure \b NULL 
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
 *********************************************************************************/
int linkedlist_list2file(linkedlist_t *list, const char *pathfile, char * token\
    ,int (*fncallback) (void*,size_t*,size_t*));







#endif /* #if (linkedlist_USE_GlobalFunctions == 1) */
/* =====================[ END   Global functions declaration ]===================== */

/* ======================[ BEGIN Global Macros functions ]========================= */
#if ( linkedlist_USE_GlobalMacroApis == 1 )
/**
 * 
 * ********************************************************************************
 * \def linkedlist_macro_ex(Arg1,Arg2)
 * \details Descripcion detallada sobre la macro funcion \ref linkedlist_macro_ex().
 * \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
 * \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
 *
 * \brief Descripcion breve sobre la macro funcion \ref linkedlist_macro_ex().
 * \param Arg1 : Argumento uno, de la macro funcion.
 * \param Arg2 : Argumento dos, de la macro funcion.
 * \return nothinig
 * \version 01v00d01.
 * \note nota.
 * \warning mensaje de "warning".
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>
 
 </PRE> 
 *********************************************************************************/ 
#define linkedlist_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( linkedlist_USE_GlobalMacroApis == 1 ) */
/* ======================[ END   Global Macros functions ]========================= */

/*
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ────────────────────[ END   __linkedlist_version__    01v00d00 ]───────────────────── │
 │                                                                                       │
 │                                                                                       │             
 └───────────────────────────────────────────────────────────────────────────────────────┘
 *
 */
#elif (version_QueryNumber(__linkedlist_version__,01v00d01))
/* 
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ────────────────────[ BEGIN __linkedlist_version__    01v00d01 ]───────────────────── │
 │                                                                                       │
 │                                                                                       │             
 └───────────────────────────────────────────────────────────────────────────────────────┘
 */



/*
 ┌───────────────────────────────────────────────────────────────────────────────────────┐           
 │                                                                                       │  
 │                                                                                       │  
 │ ────────────────────[ END   __linkedlist_version__    01v00d01 ]───────────────────── │
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
#endif /* #ifndef __linkedlist_h__ */
/*
 * 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =============================[END of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(linkedlist_projectEnable == 1) */

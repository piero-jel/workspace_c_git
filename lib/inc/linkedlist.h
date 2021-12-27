#ifndef linkedlist_projectEnable
#define linkedlist_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup linkedlist 
* @{
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
* \par email
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* ********************************************************************************** */ 
#ifndef __linkedlist_h__
#define __linkedlist_h__ /**<@brief Definimos el Nombre del modulo */


#if (linkedlist_projectEnable == 1)

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 
 * ============================[BEGIN of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* ============================[Open, cplusplus]============================  */
#ifdef __cplusplus
extern "C" 
{ 
#endif

/* ======================[ BEGIN include header file ]================================= */
#include <version.h>
#include <stdlib.h> /* size_t ssize_t .... */
#include <stdio.h> /* FLIE streams */

/* ======================[ END   include header file ]================================= */

/* ======================[ BEGIN labels enable/disable ]=============================== */
#define linkedlist_USE_GlobalMacro     0 /**<@brief enable/disable the use Global Macros/Labels */
#define linkedlist_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define linkedlist_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define linkedlist_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define linkedlist_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/*
 * \def __linkedlist_version__  
 * version 01v00d00 -> test 
 * version 01v00d01 -> test 
 * version 01v00d02 -> test
 * version 01v00d03 -> test
 * version 01v00d04 -> test
 * version 01v00d05 -> test
 *
 * */
#ifndef __linkedlist_version__
#define __linkedlist_version__        version_SetNumber(01v00d00) /**<@brief definimos la version actual del proyecto. */
#endif

/* ======================[ END   labels enable/disable ]=============================== */
#if 1 /* (version_QueryNumber(__linkedlist_version__,01v00d00)) */
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
 * \date Lunes 01 de Noviembre.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int nnode_t;



/**
* \brief estructura de datos que representa un node de una lista doblemente enlazada.
* Elementos que componen a la Estructura de datos:
*  \li \b prev
*  \li \b next
*  \li \b dato
* \version 01v00d01.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Lunes 01 de Noviembre, .
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par email
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
* \version 01v00d01.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Lunes 01 de Noviembre.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par email
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

/* ====================[ BEGIN init/new/deinit/free group  ]=================== */
/**
 * * ******************************************************************************
 * \fn linkedlist_t * linkedlist_new(void *pdato, int * errnum);
 * \brief Funcion para crear una lista enlazada. 
 * \param pdato     : Puntero al dato alocado en memoria dinamica.  
 * \param errnum    : Puntero a un int donde se almacenara el error en caso de que 
 * ocurra uno, es opcional puede ser \b NULL.
 * \return estado
 *  + success Punero a la lista creada con un nodo
 *  + failure \b NULL
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int main(int argc, char **argv)
{
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\tEl numero de Argumentos ([%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\tPath File Source vacio\n");    
  }
  FILE *fp;
  // inicializamos, para leer el archivo linea por linea 
  char *line = NULL;
  size_t len = 0;
  int errn;
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
   PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",pathfile);   
  }    
  linkedlist_t *lista = linkedlist_new(NULL,NULL);  
  //separamos por espacios y \n      
  while(getline(&line, &len, fp) > 0)
  {
    if((errn=linkedlist_push_back(lista,(void*) strdup(line))) != 0)
    {
      if(line != NULL)
        free(line);
      //
      fclose(fp);
      //
      linkedlist_free(&lista,NULL);
      PERROR(errno,FAILURE,"\tError linkedlist_push_back()\n");
    }
  }    
  if(line != NULL)
    free(line);  
  fclose(fp);  
  //...
  // more code
}
 \endcode  
 *********************************************************************************/
linkedlist_t * linkedlist_new(void *pdato, int * errnum);

/**
 ******************************************************************************* 
 * \brief Funcion para liberar toda la memoria reservada por una lista enlazada. 
 * \param list      : direccion de memoria del Puntero a la lista \b lista. 
 * \param fn_freedata : funcion callback para liberar la memoria alocada que se 
 * coloco en la region \b dato del nodo. Si se pasa \b NULL toma por defecto la
 * funcion free() para liberar dicha memoria.
 *  \b linkedlist_t * list ...
 *  \b linkedlist_free( &list) ...
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
\code
int main(int argc, char **argv)
{
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\tEl numero de Argumentos ([%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\tPath File Source vacio\n");    
  }
  FILE *fp;
  // inicializamos, para leer el archivo linea por linea 
  char *line = NULL;
  size_t len = 0;
  int errno;
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
   PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",pathfile);   
  }    
  linkedlist_t *lista = linkedlist_new(NULL,&errno);  
  if(lista == NULL)
  {
   PERROR(errno,FAILURE,"\tlinkedlist_new(NULL,&errno);\n");
  }    
  //separamos por espacios y \n      
  while(getline(&line, &len, fp) > 0)
  {
    if((errn=linkedlist_push_back(lista,(void*) strdup(line))) != 0)
    {
      if(line != NULL)
        free(line);
      //
      fclose(fp);
      //
      linkedlist_free(&lista,NULL);
      PERROR(errno,FAILURE,"\tError linkedlist_push_back()\n");
    }
  }    
  if(line != NULL)
    free(line);  
  fclose(fp);    
  //...
  if((errnum = linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  //....
  // more code
  linkedlist_free(&lista,free);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
\endcode  
 *********************************************************************************/
int linkedlist_free(linkedlist_t ** list, void (*fn_freedata) (void*));

/**
 * 
 * ******************************************************************************** 
 * \brief Funcion para inicializar una estructura del tipo \b linkedlist_t.
 * Si esta contiene nodos, los mismos son liberados y los datos en cada nodo 
 * usan la funcion \b fn_freedata para ser liberados, si es valida. De lo contrario 
 * utiliza la funcion de libreria \b free().
 * \param list : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pdato     : Puntero al dato alocado en memoria dinamica.  
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int fn_test(char* pathname)
{
  if(pathname == NULL)
    return EINVAL;
    
  if(*pathname == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
  int errnum = 0;
  FILE *fp;
  // inicializamos, para leer el archivo linea por linea 
  char *line = NULL;
  size_t len = 0;
  fp = fopen(pathname, "r");
  if (fp == NULL)
  {
    PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",pathname);    
  }    
  char *token = " \n";
  linkedlist_t lista;
  if ((errnum=linkedlist_init(&lista,NULL)) != 0)
  {
    PERROR(errno,FAILURE,"\tlinkedlist_init()\n");    
  }    
  
  char *pch;  
  while(getline(&line, &len, fp) > 0)
  {
    pch = strtok(line,token);
    while (pch != NULL)
    {      
      if((errnum = linkedlist_push_back(&lista,(void*) strdup(pch))) != 0)      
      {
        if(line != NULL)
          free(line);

        fclose(fp);

        linkedlist_deinit(&lista,free);

        PERROR(errnum,FAILURE,"\t linkedlist_push_back()\n");
      }      
      pch = strtok (NULL, token);
    }
  }
  
  if(line != NULL)
    free(line);
  
  fclose(fp);

  if((errnum=linkedlist_print(&lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  } 
  
  // liberamos lo que qeudo de la lista
  linkedlist_deinit(&lista,free);
  printf("fin del programa...\n\n");
  return 0;
}
// main fn
int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  int errnum = 0;
  if((errnum = fn_test(argv[1]) != 0))
  {
    PERROR(0,FAILURE,"\t fn_test(%s)\n",argv[1]);
  }
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_init(linkedlist_t *list, void *pdato/*,void (*fn_freedata) (void*)*/);

/**
 *
 * ******************************************************************************** 
 * \brief Funcion para liberar todos los nodos de una lista, este no libera la 
 * estructur de la lista, esta queda vaica. * 
 * \param list        : direccion de memoria del Puntero a la lista. 
 * \param fn_freedata : funcion callback, del tipo 'void fn (void *data)' que llama,
 * la funcion para liberar el dato. En caso de ser \b NULL usa la estandar \b free().
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
  \code
int fn_test(char* pathname)
{
  if(pathname == NULL)
    return EINVAL;
    
  if(*pathname == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
  int errnum = 0;
  FILE *fp;
  // inicializamos, para leer el archivo linea por linea 
  char *line = NULL;
  size_t len = 0;
  fp = fopen(pathname, "r");
  if (fp == NULL)
  {
    PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",pathname);    
  }    
  char *token = " \n";
  linkedlist_t lista;
  if ((errnum=linkedlist_init(&lista,NULL)) != 0)
  {
    PERROR(errno,FAILURE,"\tlinkedlist_init()\n");    
  }    
  
  char *pch;  
  while(getline(&line, &len, fp) > 0)
  {
    pch = strtok(line,token);
    while (pch != NULL)
    {      
      if((errnum = linkedlist_push_back(&lista,(void*) strdup(pch))) != 0)      
      {
        if(line != NULL)
          free(line);

        fclose(fp);

        linkedlist_deinit(&lista,free);

        PERROR(errnum,FAILURE,"\t linkedlist_push_back()\n");
      }      
      pch = strtok (NULL, token);
    }
  }
  
  if(line != NULL)
    free(line);
  
  fclose(fp);

  if((errnum=linkedlist_print(&lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  } 
  
  // liberamos lo que qeudo de la lista
  linkedlist_deinit(&lista,free);
  printf("fin del programa...\n\n");
  return 0;
}
// main fn
int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  int errnum = 0;
  if((errnum = fn_test(argv[1]) != 0))
  {
    PERROR(0,FAILURE,"\t fn_test(%s)\n",argv[1]);
  }
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_deinit(linkedlist_t *list,void (*fn_freedata) (void*));

/* ====================[ END   init/new/deinit/free group  ]=================== */

/* =========================[ BEGIN push and pop data ]======================== */
/**
 * 
 * ********************************************************************************
 * \fn int linkedlist_push_back(linkedlist_t *list, void *pdato);
 * \brief Funcion para insertar un nodo, al final de una lista doblemente enlazada.
 * \param list : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pdato     : Puntero al dato alocado en memoria dinamica. 
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
  int errnum = 0;
  FILE *fp;
  //inicializamos, para leer el archivo linea por linea
  char *line = NULL;
  size_t len = 0;
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);    
  }    
  char *token = " \n";
  linkedlist_t *lista = linkedlist_new(NULL,NULL);
  char *pch;  
  while(getline(&line, &len, fp) > 0)
  {
    pch = strtok(line,token);
    while (pch != NULL)
    {      
      if((errnum = linkedlist_push_back(lista,(void*) strdup(pch))) != 0)      
      {
        if(line != NULL)
          free(line);
        fclose(fp);
        linkedlist_free(&lista,NULL);
        PERROR(errnum,FAILURE,"\t linkedlist_push_back()\n");
      }      
      pch = strtok (NULL, token);
    }
  }  
  if(line != NULL)
    free(line);  
  fclose(fp);
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }   
  // liberamos la lista
  linkedlist_free(&lista,free);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
 \endcode  
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
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
  int errnum = 0;
  FILE *fp;
  //inicializamos, para leer el archivo linea por linea
  char *line = NULL;
  size_t len = 0;
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);    
  }    
  char *token = " \n";
  linkedlist_t *lista = linkedlist_new(NULL,NULL);
  char *pch;  
  while(getline(&line, &len, fp) > 0)
  {
    pch = strtok(line,token);
    while (pch != NULL)
    {       
      if((errnum = linkedlist_push_front(lista,(void*) strdup(pch))) != 0)      
      {
        if(line != NULL)
          free(line);
        fclose(fp);
        linkedlist_free(&lista,NULL);
        PERROR(errnum,FAILURE,"\t linkedlist_push_back()\n");
      }      
      pch = strtok (NULL, token);
    }
  }  
  if(line != NULL)
    free(line);  
  fclose(fp);
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }   
  // liberamos la lista
  linkedlist_free(&lista,free);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_push_front(linkedlist_t *list, void *pdato);

/**
 *
 * ********************************************************************************
 * \fn int linkedlist_push(linkedlist_t *list, nnode_t pos ,void *pdato);
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
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
  int errnum = 0;
  FILE *fp;
  //inicializamos, para leer el archivo linea por linea
  char *line = NULL;
  size_t len = 0;
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);    
  }    
  char *token = " \n";
  linkedlist_t *lista = linkedlist_new(NULL,NULL);
  char *pch;  
  while(getline(&line, &len, fp) > 0)
  {
    pch = strtok(line,token);
    while (pch != NULL)
    {      
      if((errnum = linkedlist_push(lista,5,(void*) strdup(pch))) != 0)
      {
        if(line != NULL)
          free(line);
        fclose(fp);
        linkedlist_free(&lista,NULL);
        PERROR(errnum,FAILURE,"\t linkedlist_push_back()\n");
      }      
      pch = strtok (NULL, token);
    }
  }  
  if(line != NULL)
    free(line);  
  fclose(fp);
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }   
  // liberamos la lista
  linkedlist_free(&lista,free);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_push(linkedlist_t *list, nnode_t pos ,void *pdato);

/**
 *
 * ******************************************************************************** 
 * \brief Funcion para remover un nodo con su dato desde el final de la lista
 *  doblemente enlazada.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t. 
 * \param dato : Puntero al puntero donde se almacenara el dato del nodo que 
 * se eliminara de la lista. Si este es \b NULL se librea toda la meoria del nodo. 
 * Recordar que este puntero copiado debe ser liberado despues de su uso.
 * \param fn_freedata : funcion callback, del tipo 'void fn (void *data)' que llama,
 * la funcion para liberar el dato. En caso de ser \b NULL usa la estandar \b free().
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
  int errnum = 0;
  FILE *fp;
  // inicializamos, para leer el archivo linea por linea
  char *line = NULL;
  size_t len = 0;
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);    
  }    
  char *token = " \n";
  linkedlist_t *lista = linkedlist_new(NULL,NULL);
  char *pch;  
  while(getline(&line, &len, fp) > 0)
  {
    pch = strtok(line,token);
    while (pch != NULL)
    {      
      if( (errnum = linkedlist_push_back(lista,(void*) strdup(pch)) ) != 0)
      {
        if(line != NULL)
          free(line);
        fclose(fp);
        linkedlist_free(&lista,NULL);
        PERROR(errnum,FAILURE,"\t linkedlist_push_back()\n");
      }      
      pch = strtok (NULL, token);
    }
  }  
  if(line != NULL)
    free(line);  
  fclose(fp);
  // imprimimos la lista
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  fputs("\n",stdout);
  char *dato = NULL;
  nnode_t i = 0;
  nnode_t max = linkedlist_getnnode(lista);
  do{    
    errnum = linkedlist_pop_back(lista,(void**) &dato,NULL);    
    // consultamso si no tiene mas nodo la lista '-1'
    if( errnum == -1 )
      break;    
    CFPRINTF(BLUE,stdout,"\tnodo[%04d]:\t %s\n",i,(dato == NULL)? "null":dato);
    free(dato);
    dato = NULL;
    i++;
  }while( i <= max);
  //
  if(errnum == -1)
    CFPRINTF(YELLOW,stdout,"\tFinal de la Lista\n");  
  // liberamos lo que quedo de la lista
  linkedlist_free(&lista,free);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_pop_back(linkedlist_t *list, void **dato,void (*fn_freedata) (void*));

/**
 *
 * ********************************************************************************
 * \brief Funcion para remover un nodo con su dato desde el principio de la lista
 *  doblemente enlazada.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t. 
 * \param dato : Puntero al puntero donde se almacenara el dato del nodo que 
 * se eliminara de la lista. Si este es \b NULL se librea toda la meoria del nodo. 
 * Recordar que este puntero copiado debe ser liberado despues de su uso.
 * \param fn_freedata : funcion callback, del tipo 'void fn (void *data)' que llama,
 * la funcion para liberar el dato. En caso de ser \b NULL usa la estandar \b free().
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
  int errnum = 0;
  FILE *fp;
  // inicializamos, para leer el archivo linea por linea
  char *line = NULL;
  size_t len = 0;
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);    
  }    
  char *token = " \n";
  linkedlist_t *lista = linkedlist_new(NULL,NULL);
  char *pch;  
  while(getline(&line, &len, fp) > 0)
  {
    pch = strtok(line,token);
    while (pch != NULL)
    {      
      if( (errnum = linkedlist_push_back(lista,(void*) strdup(pch)) ) != 0)
      {
        if(line != NULL)
          free(line);
        fclose(fp);
        linkedlist_free(&lista,NULL);
        PERROR(errnum,FAILURE,"\t linkedlist_push_back()\n");
      }      
      pch = strtok (NULL, token);
    }
  }  
  if(line != NULL)
    free(line);  
  fclose(fp);
  // imprimimos la lista
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  fputs("\n",stdout);
  char *dato = NULL;
  nnode_t i = 0;
  nnode_t max = linkedlist_getnnode(lista);
  do{
    errnum = linkedlist_pop_front(lista,(void**) &dato,NULL);
    // consultamso si no tiene mas nodo la lista '-1'
    if( errnum == -1 )
      break;    
    CFPRINTF(BLUE,stdout,"\tnodo[%04d]:\t %s\n",i,(dato == NULL)? "null":dato);
    free(dato);
    dato = NULL;
    i++;
  }while( i <= max);
  //
  if(errnum == -1)
    CFPRINTF(YELLOW,stdout,"\tFinal de la Lista\n");  
  // liberamos lo que quedo de la lista
  linkedlist_free(&lista,free);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_pop_front(linkedlist_t *list, void **dato,void (*fn_freedata) (void*));

/**
 *
 * ******************************************************************************** 
 * \brief Funcion para remover un nodo con su dato en una posicion especificada.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pos   : Posicion de donde queremos sacar el nodo con el dato. Si esta no existe 
 * se saca el nodo al final.
 * \param dato : Puntero al dato alocado en memoria dinamica. 
 * \param fn_freedata : funcion callback, del tipo 'void fn (void *data)' que llama,
 * la funcion para liberar el dato. En caso de ser \b NULL usa la estandar \b free().
 * \return estado
 *  + success
 *        0 : creo y coloco el nodo con el dato en la posicion solicitada
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
  int errnum = 0;
  FILE *fp;
  // inicializamos, para leer el archivo linea por linea
  char *line = NULL;
  size_t len = 0;
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);    
  }    
  char *token = " \n";
  linkedlist_t *lista = linkedlist_new(NULL,NULL);
  char *pch;  
  while(getline(&line, &len, fp) > 0)
  {
    pch = strtok(line,token);
    while (pch != NULL)
    {      
      if( (errnum = linkedlist_push_back(lista,(void*) strdup(pch)) ) != 0)
      {
        if(line != NULL)
          free(line);
        fclose(fp);
        linkedlist_free(&lista,NULL);
        PERROR(errnum,FAILURE,"\t linkedlist_push_back()\n");
      }      
      pch = strtok (NULL, token);
    }
  }  
  if(line != NULL)
    free(line);  
  fclose(fp);
  // imprimimos la lista
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  fputs("\n",stdout);
  char *dato = NULL;
  nnode_t i = 0;
  nnode_t max = linkedlist_getnnode(lista);
  do{
    errnum = linkedlist_pop(lista,5,(void**) &dato,NULL);    
    // consultamso si no tiene mas nodo la lista '-1'
    if( errnum == -1 )
      break;    
    CFPRINTF(BLUE,stdout,"\tnodo[%04d]:\t %s\n",i,(dato == NULL)? "null":dato);
    free(dato);
    dato = NULL;
    i++;
  }while( i <= max);
  //
  if(errnum == -1)
    CFPRINTF(YELLOW,stdout,"\tFinal de la Lista\n");  
  // liberamos lo que quedo de la lista
  linkedlist_free(&lista,free);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_pop(linkedlist_t *list, nnode_t pos ,void **dato\
    ,void (*fn_freedata) (void*));


/* =========================[ END   push and pop data ]======================== */

/* =========================[ BEGIN delete and write  ]======================== */
/**
 *
 * ******************************************************************************** 
 * \brief Funcion para eliminar el ultimo nodo de una lista doblemente enlazada
 * representada con la estructura \b linkedlist_t. 
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t. 
 * \param fn_freedata : funcion callback, del tipo 'void fn (void *data)' que llama,
 * la funcion para liberar el dato. En caso de ser \b NULL usa la estandar \b free(). 
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido o '-1' que indica 
 *    que la lista esta vacia.
 * \version 01v00d01.
 * \note note
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code 
int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
  // llenamos la lista 
  int errnum = 0;
  linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
  if (lista == NULL && errnum != 0)
  {
    PERROR(errno,FAILURE,"\t linkedlist_fillfromfile(%s,...)\n",argv[1]);    
  }
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  } 
  // eliminamos uno por uno los nodos de la lista 
  nnode_t i = 0;
  nnode_t max = linkedlist_getnnode(lista);
  do{    
    errnum = linkedlist_delete_back(lista,free);
    if(errnum == -1 )
      break;    
    i++;
  }while(i <= max);
  // liberamos lo que qeudo de la lista
  free(lista);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_delete_back(linkedlist_t *list,void (*fn_freedata) (void*));

/**
 *
 * ******************************************************************************** 
 * \brief Funcion para eliminar el primer nodo de una lista doblemente enlazada
 * representada con la estructura \b linkedlist_t. 
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t. 
 * \param fn_freedata : funcion callback, del tipo 'void fn (void *data)' que llama,
 * la funcion para liberar el dato. En caso de ser \b NULL usa la estandar \b free(). 
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido o '-1' que indica 
 *    que la lista esta vacia.
 * \version 01v00d01.
 * \note note
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code 
int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
  // llenamos la lista 
  int errnum = 0;
  linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
  if (lista == NULL && errnum != 0)
  {
    PERROR(errno,FAILURE,"\t linkedlist_fillfromfile(%s,...)\n",argv[1]);    
  }
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  } 
  // eliminamos uno por uno los nodos de la lista 
  nnode_t i = 0;
  nnode_t max = linkedlist_getnnode(lista);
  do{    
    errnum = linkedlist_delete_front(lista,free);
    if(errnum == -1 )
      break;    
    i++;
  }while(i <= max);
  // liberamos lo que qeudo de la lista
  free(lista);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_delete_front(linkedlist_t *list,void (*fn_freedata) (void*));

/**
 *
 * ******************************************************************************** 
 * \brief Funcion para eliminar un nodo 'n' de una lista doblemente enlazada
 * representada con la estructura \b linkedlist_t. 
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t. 
 * \param pos   : Posicion del nodo eliminar.
 * \param fn_freedata : funcion callback, del tipo 'void fn (void *data)' que llama,
 * la funcion para liberar el dato. En caso de ser \b NULL usa la estandar \b free(). 
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido o \b '-1' que indica 
 *    que la lista esta vacia y '-2' que el item no fue localizado dentro de la lista.
 * \version 01v00d01.
 * \note note
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code 
 int main(int argc, char **argv)
{ 
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");
  }
    
  int errnum = 0;
  linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
  if (lista == NULL && errnum != 0)
  {
    PERROR(errno,FAILURE,"\t linkedlist_fillfromfile(%s,...)\n",argv[1]);    
  }
  
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  } 
  // eliminamos uno por uno los nodos de la lista 
  nnode_t i = 0;
  nnode_t max = linkedlist_getnnode(lista);
  nnode_t del = 5;
  do{
    errnum = linkedlist_delete(lista,del,free);    
    if(errnum == -1 )
      break;    
    if(errnum == -2 )
    {
      del = 0;
      continue;
    }
    i++;
  }while(i <= max);
  // liberamos lo que qeudo de la lista
  free(lista);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_delete(linkedlist_t *list, nnode_t pos,void (*fn_freedata) (void*));


/**
 *
 * ******************************************************************************** 
 * \brief Funcion para escrir (sobre escribir) el dato dentro del 
 * nodo inicial de la lista.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t. 
 * \param pdato : Puntero al dato alocado en memoria dinamica. 
 * \param fn_freedata : Funcion callback \b Opcional que se utilizara en caso de tener que 
 * liberar la memoria alocada en \b dato. Por defecto utilizar \b free(), si este argumento 
 * es \b NULL.
 * \return estado
 *  + success
 *        0 : creo y coloco el nodo con el dato en la posicion solicitada
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
if( errnum != 0 )
{
  PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);
}
linkedlist_write_front(lista,strdup(SET_COLOR(FONT,YELLOW)"Primer Nodo"SET_COLOR(FONT,RESET)),NULL);
 \endcode  
 *********************************************************************************/
int linkedlist_write_front(linkedlist_t *list, void *pdato,void (*fn_freedata) (void*));

/**
 *
 * ******************************************************************************** 
 * \brief Funcion para escrir (sobre escribir) el dato en el nodo finla de la lista.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t. 
 * \param pdato : Puntero al dato alocado en memoria dinamica. 
 * \param fn_freedata : Funcion callback \b Opcional que se utilizara en caso de tener que 
 * liberar la memoria alocada en \b dato. Por defecto utilizar \b free(), si este argumento 
 * es \b NULL.
 * \return estado
 *  + success
 *        0 : creo y coloco el nodo con el dato en la posicion solicitada
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
if( errnum != 0 )
{
  PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);
}
linkedlist_write_back(lista,strdup(SET_COLOR(FONT,YELLOW)"Ultimo Nodo"SET_COLOR(FONT,RESET)),free);
 \endcode  
 *********************************************************************************/
int linkedlist_write_back(linkedlist_t *list, void *pdato,void (*fn_freedata) (void*));

/**
 *
 * ******************************************************************************** 
 * \brief Funcion para escribir (sobre escribir) un dato en un nodo.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pos   : Posicion donde queremos escribir el dato. Si esta no existe 
 * se coloca en el nodo final. El contenido actual es liberado
 * \param pdato : Puntero al dato alocado en memoria dinamica. 
 * \param fn_freedata : Funcion callback \b Opcional que se utilizara en caso de tener que 
 * liberar la memoria alocada en \b dato. Por defecto utilizar \b free(), si este argumento 
 * es \b NULL.
 * \return estado
 *  + success
 *        0 : creo y coloco el nodo con el dato en la posicion solicitada
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
  linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
  if( errnum != 0 )
  {
    PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);
  }  
  nnode_t n = linkedlist_getnnode(lista);
  nnode_t i;
  // Buscamos en la mitad superior el valor "laborando"
  for(i = (n>>1) ; i < n ; i++)
  {    
    char * tmp = (char*)linkedlist_getdata(lista,i,NULL);
    if(strcmp(tmp,"laborando") == 0)
    {
      linkedlist_write(lista,i,strdup(SET_COLOR(FONT,YELLOW)"trabajando"SET_COLOR(FONT,RESET)),free);
    }
  }
 \endcode  
 *********************************************************************************/
int linkedlist_write(linkedlist_t *list, nnode_t pos ,void *pdato\
    ,void (*fn_freedata) (void*));




/* =========================[ END   delete and write  ]======================== */

/* =========================[ BEGIN get data and info ]======================== */
/**
 *
 * ********************************************************************************
 * \brief Funcion para obtener el dato del primer nodo de una lista doblemente 
 * enlazada, con la finalidad de manipularlo, esta accion no quita el nodo en cuestion.
 * \param list : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param errnum : Puntero donde colocaremos el valor de error en caso de que suceda
 * \return 
 *  Dato del ultimo nodo de la lista.
 *  \b NULL, si la lista esta vacia.
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
\code
linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
if( errnum != 0 )
{
  PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);
}
fprintf(stdout,"\tDato del Primer Nodo [%25.24s]\n",(char*) linkedlist_getdata_front(lista,NULL));    
\endcode
 *********************************************************************************/
void* linkedlist_getdata_front(linkedlist_t *list, int *errnum);

/**
 *
 * ********************************************************************************
 * \brief Funcion para obtener el dato del ultimo nodo de una lista enlazada,
 * con la finalidad de manipularlo, esta accion no quita el nodo en cuestion.
 * \param list : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param errnum : Puntero donde colocaremos el valor de error en caso de que suceda
 * \return
 *  Dato del ultimo nodo de la lista.
 *  \b NULL, si la lista esta vacia.
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
\code
linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
if( errnum != 0 )
{
  PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);
}
fprintf(stdout,"\tDato del Ultimo Nodo [%25.24s]\n",(char*) linkedlist_getdata_back(lista,NULL));    
\endcode
 *********************************************************************************/
void * linkedlist_getdata_back(linkedlist_t *list, int *errnum);

/**
 *
 * ********************************************************************************
 * \fn void* linkedlist_getdata(linkedlist_t *list, nnode_t pos, int *errnum );
 * \brief Funcion para obtener el dato desde el nodo en la posicion \b pos
 * , con la finalidad de manipularlo, esta accion no quita el nodo en cuestion.
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pos   : Posicion del nodo, dentro de la lista, desde donde queremos
 * obtener el dato.
 * \param errnum : Puntero del tipo \b int en el cual se puede colocar notificaciones
 * de errores ocurridos, como el de posicion no localizada '-1'.
 * \return puntero al dato contenido en el nodo de la posicion \b pos.
 * Si la lista no posee el nodo y se pasa un puntero valido para \b errnum
 * en este se coloca '-1', con el que indicamos que la lista no cuenta con 
 * ese nodo. Y retorna \b NULL. 
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int main(int argc, char **argv)
{
  int errnum;
  if(argc != 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n",argc);    
  }
  linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
  if( errnum != 0 )
  {
    PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);
  }
  nnode_t n = linkedlist_getnnode(lista);
  nnode_t i;
  for(i = (n>>1) ; i < n ; i++)
  {
    CFPRINTF(BLUE,stdout,"\tNodo [%04d] Contenido [%25.24s]\n",i,(char*) linkedlist_getdata(lista,i,NULL));
    char * tmp = (char*)linkedlist_getdata(lista,i,NULL);
    if(strcmp(tmp,"laborando") == 0)
    {
      linkedlist_write(lista,i,strdup(SET_COLOR(FONT,YELLOW)"trabajando"SET_COLOR(FONT,RESET)));
    }
  }
  if( (errnum = linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  exit(EXIT_SUCCESS);
}
 \endcode
 *********************************************************************************/
void* linkedlist_getdata(linkedlist_t *list, nnode_t pos, int *errnum );

/**
 *
 * ********************************************************************************
 * \fn nnode_t linkedlist_getnnode(linkedlist_t *list);
 * \brief Funcion para obtener el numero de nodos contenido en la lista \b list 
 * \param list  : Puntero a la lista enlazada, del tipo \ref linkedlist_t. 
 * \return Cantidad de Nodos, este valor es del tipo \b nnode_t 
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
if( errnum != 0 )
{
  PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);
}
nnode_t n = linkedlist_getnnode(lista);
CFPRINTF(BLUE,stdout,"\tNumero de Nodos %d\n",n);
 \endcode
 *********************************************************************************/
nnode_t linkedlist_getnnode(linkedlist_t *list);
/* =========================[ END   get data and info ]======================== */

/* ==========================[ BEGIN APIs Utilities ]========================== */

/**
 * ******************************************************************************** 
 * \brief Funcion para imprimir el contenido de una lista doblemente enlazada.
 * \param list   : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param stream      : Stream/file donde se desea imprimir los datos.
 * \param fncallback  : funcion callback para imprimir el tipo de dato del nodo de la lista
 *  int fncallback (void* data,char* buff,unsigned int lenbuff) 
 *  int fncallback)(FILE* stream ,void* data)
 *    stream : Stream para imprimir implementando \b fprintf(stream,fmt,...)
 *    data   : dato que se debe imprimir, de poendede de su tipo.
 *  
 *    Valor de retorno 'int', que reresenta el error (0: succes / Mayor a 0 failure )
 * \return estado
 *  + success 0
 *  + failure valor positivo que indica el error ocurrido
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
 static inline int fn_printstr(FILE *stream, void *pdato)
{
  if(stream == NULL)
    return EINVAL;  
  
  if(pdato == NULL)
    fprintf(stream,"%s","null");    
  else
    fprintf(stream,"%s",(char*) pdato );    
  return 0;
}
//
int main(int argc, char **argv)
{
  if(argc < 2)
  {
    PERROR(0,FAILURE,"\tEl numero de Argumentos ([%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\tPath File Source vacio\n");    
  }
  FILE *fp;
  // inicializamos, para leer el archivo linea por linea 
  char *line = NULL;
  size_t len = 0;
  int errno;
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
   PERROR(errno,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",pathfile);   
  }    
  linkedlist_t *lista = linkedlist_new(NULL,&errno);  
  if(lista == NULL)
  {
   PERROR(errno,FAILURE,"\tlinkedlist_new(NULL,&errno);\n");
  }    
  //separamos por espacios y \n      
  while(getline(&line, &len, fp) > 0)
  {
    if((errn=linkedlist_push_back(lista,(void*) strdup(line))) != 0)
    {
      if(line != NULL)
        free(line);
      //
      fclose(fp);
      //
      linkedlist_free(&lista,NULL);
      PERROR(errno,FAILURE,"\tError linkedlist_push_back()\n");
    }
  }    
  if(line != NULL)
    free(line);  
  fclose(fp);    
  //...
  if((errnum = linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  //....
  // more code
  linkedlist_free(&lista,free);
  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_print(linkedlist_t *list, FILE * stream \
    ,int (*fncallback)(FILE* ,void*));

/**
 *
 * ********************************************************************************
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
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int main(int argc, char **argv)
{
  int errnum;
  if(argc != 2)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ([%04d]) pasado es incorrecto\n",argc);    
  }

  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");    
  }
  // llenamos la lista con el contenido del archivo source
  linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
  if( errnum != 0 )
  {
    PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);
  }
  // imprimimos la lista 
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  // Iniciamos la accion de Ordenar la lista
  CPRINTF(BLUE,"\n\tOrdenamos la lista\n");
  if( (errnum = linkedlist_sort(lista,fn_cmpstr)) != 0 )
  {
    PERROR(errnum,FAILURE,"\tError al intentar ordenar la lista\n");
  }
  // Imprimimos la lista Ordenada
  if( (errnum = linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  //...
  //more code
  // Libreamos la lista, antes de terminar
  linkedlist_free(&lista,free);  
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_sort(linkedlist_t *list, int (*fncallback)(void*,void *));

/**
 *
 * ********************************************************************************
 * \brief Funcion para obtener un nodo / buscar un dato dentro del nodo
 * \param list    : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param fncallbackcmp : Funcion callback del tipo 'int fncallbackcmp(void* data,void* value) *    
 *    data  : es el dato del nodo
 *    value : es el arguemtno \b value
 * Este callback debe retornar 
 *    '0' en caso de que el item dentro del \b dato de un nodo sea igual a \b value.
 *    'menor 0' item dentro del \b dato de un nodo sea menor a \b value. 
 *    'mayor 0' item dentro del \b dato de un nodo sea mayor a \b value. 
 * 
 * \param value   : puntero que representa el valor a buscar.
 * \param errnum  : puntero a la variable del tipo \b int donde alamcenaremos el
 * valor de error si este sucede (valirable la cual podemos usar para constrastar
 * si \b value esta dentro de alguno de los nodos )
 * \return 
 *  + success
 *    puntero al \b dato si se localizo (en cual se localizo el item la primer 
 *    aparicion desde la cabezera al final). Si no se localizo retorna \b NULL
 *    y si se paso \b errnum en este coloca un '-1' indicando que el valor 
 *    no se localizo dentro de la lista.
 * 
 *  + failure retorna \b NULL y si se paso \b errnum, en el se coloca un valor
 *    positivo que indica el error del S.O ocurrido en la busqueda del item.
 *    O '-2' para indicar que la lista esta vacia.
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
 void* linkedlist_find(linkedlist_t *list, int (*fncallbackcmp)(void*,void *), void * value,int *errnum);
 \endcode  
 *********************************************************************************/
void* linkedlist_find(linkedlist_t *list, int (*fncallbackcmp)(void*,void *)\
    , void * value,int *errnum);


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
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
int main(int argc, char **argv)
{
  int errnum;
  if(argc != 3)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ([%04d]) pasado es incorrecto\n",argc);    
  }
  if(*(argv[1]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Source vacio\n");    
  }
  if(*(argv[2]) == '\0')
  {
    PERROR(0,FAILURE,"\t Path File Destino vacio\n");    
  }
  linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
  if( errnum != 0 )
  {
    PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);
  }
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  // ...
  // more code
  // ...
  linkedlist_free(&lista,free);  
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
linkedlist_t * linkedlist_fillfromfile( const char *pathfile, char * token\
    ,int *errnum);

/**
 *
 * ******************************************************************************** 
 * \brief Funcion que escribe el contenido de una lista enlazada en un archivo.
 * \param list      : Puntero a la lista enlazada, del tipo \ref linkedlist_t.
 * \param pathfile  : path file, rua y nombre del archivo.
 * \param token     : Token en caso de necesitar escribir al final de cada item 
 * de la lista.
 * \param fncallback : Funcion qcallback que nos permite obtener los bloques de memoria
 * ,desde el dato del nodo, para ser volcados al \b stream
 * \return 
 *  + success la lista enlazada donde se coloco la informacion del archivo.
 *  + failure \b NULL 
 * \version 01v00d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Lunes 01 de Noviembre, .
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
 // callback para la funcion print 
static inline int fn_printstr(FILE *stream, void *pdato)
{
  if(stream == NULL)
    return EINVAL;  
  
  if(pdato == NULL)
    fprintf(stream,"%s","null");    
  else
    fprintf(stream,"%s",(char*) pdato );    
  return 0;
}
// callback para la funcion sort
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
// callback para la funcion de volcado a un archivo, escritura por bloques 
static inline int fn_getsizestr(void* data, size_t *nbyte, size_t *nitem)
{
  if( data == NULL || nbyte == NULL || nitem == NULL)
    return EINVAL;

  char *str = (char*) data;
  *nbyte = strlen(str);
  *nitem = 1;
  return 0;
}
// Funcion principal
int main(int argc, char **argv)
{
  int errnum;
  if(argc != 3)
  {
    PERROR(0,FAILURE,"\t El numero de Argumentos ([%04d]) pasado es incorrecto\n",argc);    
  }
  linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",&errnum);
  if( errnum != 0 )
  {
    PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[1]);
  }
  if((errnum=linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  CPRINTF(BLUE,"\n\tOrdenamos la lista\n");
  if( (errnum = linkedlist_sort(lista,fn_cmpstr)) != 0 )
  {
    PERROR(errnum,FAILURE,"\tError al intentar ordenar la lista\n");
  }
  if( (errnum = linkedlist_print(lista,stdout,fn_printstr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al imprimir la lista\n");
  }
  if( (errnum = linkedlist_list2file(lista,argv[2],"\n",fn_getsizestr)) != 0)
  {
    PERROR(errnum,FAILURE,"\tError al intentar abrir el archivo \"%s\"\n",argv[2]);
  }
  linkedlist_free(&lista,free);  
  exit(EXIT_SUCCESS);
}
 \endcode  
 *********************************************************************************/
int linkedlist_list2file(linkedlist_t *list, const char *pathfile, char * token\
    ,int (*fncallback) (void*,size_t*,size_t*));


/* ==========================[ END   APIs Utilities ]========================== */

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
 * \par email
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 \code
 
 \endcode 
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

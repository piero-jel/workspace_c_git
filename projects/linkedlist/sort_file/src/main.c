 /**
 * 
 * *************************************************************************************
 * \addtogroup sort_file 
 * @{ 
 * \copyright  
 * 2021, Luccioni Jesús Emanuel \n
 * All rights reserved.\n 
 * This file is part of sort_file .\n
 * Redistribution is not allowed on binary and source forms, with or without \n
 * modification. Use is permitted with prior authorization by the copyright 
 * holder. &copy;
 * \file main.c
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
#include <main.h>


/*
* ******************************************************************************** 
* \fn int main(int argc, char **argv);
* \brief Funcion Principal
* \param argc : cantidad de Argumentos pasados al invocar la app.
* \param argv : puntero a puntero que contiene el listado de
* \return status de la ejecucion de la app.
*      \li 0, success
*      \li 1, failure
*********************************************************************************/
int main(int argc, char *argv[])
{


  if(argc != 3)
  {
    CPRINTF(RED,"\t El numero de Argumentos ( [%04d]) pasado es incorrecto\n"\
        ,argc);
    exit(EXIT_FAILURE);
  }

  if(*(argv[1]) == '\0')
  {
    CPRINTF(RED,"\t Path File Source vacio\n");
    exit(EXIT_FAILURE);
  }

  if(*(argv[2]) == '\0')
  {
    CPRINTF(RED,"\t Path File Destino vacio\n");
    exit(EXIT_FAILURE);
  }

  


  linkedlist_t *lista = linkedlist_fillfromfile(argv[1]," \n",NULL);

  linkedlist_print(lista,fn_printstr);

  CPRINTF(BLUE,"\n\tOrdenamos la lista\n");
  linkedlist_sort(lista,fn_cmpstr);
  
  linkedlist_print(lista,fn_printstr);

  linkedlist_list2file(lista,argv[2],"\n",fn_getsizestr);
  

  
  

  linkedlist_free(&lista);

  printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}




//BEGIN fn 

char* stdc_strdup(const char *str)
{
  if(str == NULL)
    return NULL;
  return strdup(str);
}

int* stdc_intdup(int data, int *errnum)
{
  int *rval = (int*) malloc(sizeof(int));
  if(rval == NULL)
  {
    if(errnum != NULL)
      *errnum = errno;
    else
      return NULL;
  }

  *rval = data;
  return rval;
}


//END   fn 


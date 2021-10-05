/**
 * 
 * *************************************************************************************
 * \addtogroup template 
 * @{ 
 * \copyright  
 * 2021, Luccioni Jesús Emanuel \n
 * All rights reserved.\n 
 * This file is part of template .\n
 * Redistribution is not allowed on binary and source forms, with or without \n
 * modification. Use is permitted with prior authorization by the copyright 
 * holder. &copy;
 * \file main.cpp
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


/* **********************************************************************************************
 *
 * ===========================[ BEGIN include header file ]============================
 *
 * ********************************************************************************************** 
 * 
 */
#include <stdc.h>

#include <main.h>



#ifndef __main_version__
#define __main_version__        version_SetNumber(01v00d01)
#endif
/*
 * version 01v0d0 -> test test basico c, print arg list
 * version 01v0d1 -> test 
 * version 01v0d2 -> test
 * version 01v0d3 -> test
 * version 01v0d4 -> test
 * version 01v0d5 -> test
 * version 01v0d6 -> test
 * version 01v0d7 -> test
 * version 01v0d8 -> test
 * version 01v0d9 -> test
 * version 01v1d0 -> test
 * version 01v1d1 -> test
 * version 01v1d2 -> test
 *
 * */
/*
* 
* *********************************************************************************************
*
* =================================[ END include header file ]================================
*
* ******************************************************************************************** 
* 
*/
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =======================================[begin of project file]=======================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
*  
*/

#if (version_QueryNumber(__main_version__,01v00d00))
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ BEGIN apis main version 01v00d00 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
#include <iso8583.h>

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
int main(int argc, char **argv)
{
 
  if(argc <= 1)
  {    
    CFPRINTF(RED,stdout,"\tNo se ingresaron Argumentos\n");
    exit(EXIT_SUCCESS);
  }  
  uint8_t rawprint = (iso8583_FLGPRINT_COLOR|iso8583_FLGPRINT_TBL);
  if(argc > 1)
  {
    if(strcmp("-r",argv[1]) == 0 || strcmp("--raw",argv[1]) == 0)
      rawprint = 0;

    else if(strcmp("-t",argv[1]) == 0 || strcmp("--table",argv[1]) == 0)
      rawprint = iso8583_FLGPRINT_TBL;

    else if(strcmp("-c",argv[1]) == 0 || strcmp("--color",argv[1]) == 0)
      rawprint = iso8583_FLGPRINT_COLOR;
  }

  
#if defined(DEBUG_ENABLE)
  if(rawprint != 0)
    CFPRINTF(GREEN,stdout,"\n Iniciando Conversion:\n\n");  
#endif /* #if defined(DEBUG_ENABLE) */

  uint32_t narg = 1;
  while(narg < argc)
  {
    if(rawprint != 0)
    {
      char *isoframe = iso8583_GetFrameFromStr(argv[narg],NULL);
      if(isoframe != NULL)
      {     
        if(rawprint & iso8583_FLGPRINT_COLOR)
          printf("FRAME: "SET_COLOR(FONT,BLUE)"[%s]\n"SET_COLOR(FONT,RESET),isoframe);
        else
          printf("FRAME: [%s]\n",isoframe);
        free(isoframe);
      }
    }      
    
    iso8583_sT * msg = iso8583_ParseFromStr(argv[narg],NULL);    
    iso8583_print(stdout,msg,rawprint);    
    iso8583_free(msg);    
    narg++;
  }
  
  

#if defined(DEBUG_ENABLE)  
  if(rawprint != 0)
    printf("fin del programa...\n\n");
#endif /*#if defined(DEBUG_ENABLE) */
  exit(EXIT_SUCCESS);
}





/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d01 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d01))
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ BEGIN apis main version 01v00d01 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
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
int main(int argc, char* argv[])
{
  exit(EXIT_SUCCESS);
}
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d01 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d02))
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ BEGIN apis main version 01v00d02 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
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
int main(int argc, char* argv[])
{
  exit(EXIT_SUCCESS);
}
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d03 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d03))
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ BEGIN apis main version 01v00d03 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
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
int main(int argc, char* argv[])
{
  exit(EXIT_SUCCESS);
}
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d03 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d04))
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ BEGIN apis main version 01v00d04 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
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
int main(int argc, char* argv[])
{

}
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d04 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d05))
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ BEGIN apis main version 01v00d05 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
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
int main(int argc, char* argv[])
{

}
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d05 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d06))
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ BEGIN apis main version 01v00d06 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
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
int main(int argc, char* argv[])
{

}
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d06 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d07))
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ BEGIN apis main version 01v00d07 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
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
int main(int argc, char* argv[])
{

}
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d07 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d08))
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ BEGIN apis main version 01v00d08 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
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
int main(int argc, char* argv[])
{

}

/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d08 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d09))
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ BEGIN apis main version 01v00d09 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/
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
int main(int argc, char* argv[])
{

}
/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d09 ]─────────────────────── │
│                                                                                     │
│                                                                                     │             
└─────────────────────────────────────────────────────────────────────────────────────┘
*/

#else/* #if(version_QueryNumber(__main_version__,01v0d0)) */
#warning "main_version definido de forma incorrecta"
#endif/* #if(version_QueryNumber(__main_version__,01v0d0)) */















/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* ========================================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

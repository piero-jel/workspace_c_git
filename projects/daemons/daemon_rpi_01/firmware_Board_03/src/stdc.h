/**
* 
* *********************************************************************************//**
* \addtogroup modules "Modulos/Librerias Arduino" 
* @{ 
* \copyright  
* 2019, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of modules .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright holder. &copy;
* \file stdc.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \brief Descripcion breve.
* \details Descripcion detallada.
* 
*
* \version 01v01d01.
* \date Domingo 25 de Octubre, 2020.
* \pre pre, condiciones que deben cuplirse antes del llamado, example: First
* initialize the system.
* \bug bug, depuracion example: Not all memory is freed when deleting an object 
* of this class.
* \warning mensaje de precaucion, warning.
* \note nota.
* 
* @} doxygen end group definition 
* ********************************************************************************** */


#ifndef __stdc_h__
#define __stdc_h__ /**<@brief definimos el header file, para evitar includes recursivos */
/* 
* ***** [ Add header files ] *****
*/
#include <Arduino.h>
#include "stdctype.h"
/*
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =======================================[begin of project file]=======================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ 
* 
*/
/*
* 
* ============================[Open, cplusplus]============================
* 
*/
#ifdef __cplusplus
extern "C" {
#endif   






/**
* 
* ******************************************************************************//**
* \fn bool stdc_strcmp(const char *str,char *buff, uint16_t len);
* \brief Funcion que inicializa el hardware necesario para el o los pulsadores
* 
* \param pHdl : Puntero al Handler o array de Handler de Pulsadores.
* \param nroSw : Cantidad de Pulsadores que contine el Handler podemos 
*  usar "sizeof(hdl)/sizeof(hdl[0])" para obtener este valor de forma 
* automatica.
* \return nothing.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 24 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
stdc_hdl_sT hdlSw[]= { // Definimos un array de handler "Hdl" 
  // y asignamos el numero de pin 
  {.pin=2}, // pin 0 
  {.pin=7}, // pin 1
};


void setup()
{ 
  //.. more code
  // le pasamos el array y la cantidad de pulsadores en esta caso '2'
  stdc_init(hdlSw ,2);
  
}
void loop()
{
  
}
</PRE>
*************************************************************************************/
bool stdc_strcmp(const char *str,char *buff, uint16_t len);




/*
* ============================[close, cplusplus]============================
*/
#ifdef __cplusplus
}
#endif
/*==============================[end of file]==============================*/
/*
* 
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* ========================================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #ifndef __stdc_h__ */

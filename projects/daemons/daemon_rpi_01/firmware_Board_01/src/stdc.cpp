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
* \file stdc.cpp
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
// #include "stdctype.h"
#include "stdc.h"



/*
* \fn uint8_t stdc_update(uint8_t nSw));
* \details 
* \brief Funcion para actualizar la FSM para Switch. En caso de detectar
* la presion retorna el valor del SW o 0.
* \param nSw : Numero de SW que deseamos actualizar.
* \return El valor del SW presinado o stdc_NOT_PUSH
*   + 0 se presiono el Switch por el cual consultamos.
*   + stdc_NOT_PUSH, en caso de no detectar un pulsador presionado
*/
bool stdc_strcmp(const char *str,char *buff, uint16_t len)
{
  uint16_t i;
  i = 0;
  while(str[i] != '\0' && i < len)
  {
    if(str[i] != buff[i]) 
      return false;
    i++;
  }
  return true;
}

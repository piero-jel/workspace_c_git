/***********************************************************************************//**
* \addtogroup modules "Modulos/Librerias Arduino"
* @{ 
* \copyright  
* 2019, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of modules .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright holder. &copy;
* \file switch.cpp
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
// #include "systick.h"
#include "switch.h"



#if (__switch_VERSION__ == 0)
/*
 * BEGIN __switch_VERSION__ 0
 **/

static switch_hdl_sT * pHldLocal;
static uint8_t nroSwLocal;

void switch_init(switch_hdl_sT * pHdl, uint8_t nroSw)
{
  uint8_t i;
  if(pHdl == NULL)
  {
    pHldLocal == NULL;
    nroSwLocal = 0;
    return;
  }
  pHldLocal = pHdl;
  nroSwLocal = nroSw;
  i = 0;
  while( i< nroSwLocal )
  {
    switch_GPIO_CONFIG((pHldLocal+i)->pin, switch_PIN_INPUT);
//     pinMode((pHldLocal+i)->pin, INPUT);
    i++;    
  }
  
}


/*
* \fn uint8_t switch_update(uint8_t nSw));
* \details 
* \brief Funcion para actualizar la FSM para Switch. En caso de detectar
* la presion retorna el valor del SW o 0.
* \param nSw : Numero de SW que deseamos actualizar.
* \return El valor del SW presinado o switch_NOT_PUSH
*   + 0 se presiono el Switch por el cual consultamos.
*   + switch_NOT_PUSH, en caso de no detectar un pulsador presionado
*/
uint8_t switch_update(uint8_t nSw)
{
  if((pHldLocal == NULL) || (nSw >= nroSwLocal) ) return switch_NOT_PUSH;   
  /*
    * 
    */
  switch((pHldLocal+nSw)->status)
  {
    default:
      (pHldLocal+nSw)->status = 0;
    case 0:
      /*-- escaneamos para detectar un flanco ascendente */
      if(!switch_GPIO_READ((pHldLocal+nSw)->pin))
      {
        systick_Init((pHldLocal+nSw)->time,ms);        
        break;
      }
      return switch_NOT_PUSH;
    case 1:
      /*-- esperamos hasta agotar el debounce time  */
      if(systick_TimeOut_ms(&((pHldLocal+nSw)->time),switch_NOISE_TIME,TRUE))
          return switch_NOT_PUSH;
      break;
    case 2:
      /*-- consultamos si se mantiene el estado del sw */
      if(!switch_GPIO_READ((pHldLocal+nSw)->pin)) break;
      else 
      {
        /*-- ruido en la linea */
        (pHldLocal+nSw)->status = 0;
        return switch_NOT_PUSH ;
      }        
    case 3:
      /*-- esperamos hasta que se suelte el pulsador */
      if(switch_GPIO_READ((pHldLocal+nSw)->pin))
      {
        systick_Init((pHldLocal+nSw)->time,ms);
        break;
      }
      return switch_NOT_PUSH ;
    case 4:
      /*-- esperamos hasta agotar el debounce time  */
      if(systick_TimeOut_ms(&((pHldLocal+nSw)->time),switch_NOISE_TIME,TRUE))
        return switch_NOT_PUSH;
      break;        
    case 5:
      /*-- consultamos si se mantiene el estado del sw */
      if(switch_GPIO_READ((pHldLocal+nSw)->pin))
      {
        /*-- reiniciamos la FSM*/
        (pHldLocal+nSw)->status = 0;
        return 0;
      }
      /*-- no se pudo validar el estado */
      (pHldLocal+nSw)->status = 3 ;
      return switch_NOT_PUSH;
  }
  (pHldLocal+nSw)->status += 1;
  return switch_NOT_PUSH;    
}
/*
 * END __switch_VERSION__ 0
 **/

#elif (__switch_VERSION__ == 1)
/*
 * BEGIN __switch_VERSION__ 1
 **/

#define MASK_GET_PIN   0xEF /* para obtener el numero de PIN 0 ~ 128 */
#define MASK_GET_TYPE  0x80 /* para obtener el tipo de SW ( pulsador o fin de carrera )*/

void switch_init(switch_hdl_sT * pHdl,uint8_t pin \
    ,switch_fncallback_fpT fncallback ,void * arg)
{
  ASSERT( pHdl == NULL, return);
  
  pHdl->pin = pin;
  pHdl->fncallback = fncallback;
  pHdl->arg = arg;
  pHdl->status = 0;
    
#if (switch_PULL_UP_ENABLE == 1)
  switch_GPIO_CONFIG(pHdl->pin,switch_PIN_INP_PULL_UP);
#else
  switch_GPIO_CONFIG(pHdl->pin,switch_PIN_INPUT);
#endif
}

void switch_set(switch_hdl_sT * pHdl, switch_fncallback_fpT fncallback ,void * arg)
{
  ASSERT( pHdl == NULL, return);
  pHdl->fncallback = fncallback;
  pHdl->arg = arg;
  pHdl->status = 0;
}

/*
* \fn uint8_t switch_update(uint8_t nSw));
* \details 
* \brief Funcion para actualizar la FSM para Switch. En caso de detectar
* la presion retorna el valor del SW o 0.
* \param nSw : Numero de SW que deseamos actualizar.
* \return El valor del SW presinado o switch_NOT_PUSH
*   + 0 se presiono el Switch por el cual consultamos.
*   + switch_NOT_PUSH, en caso de no detectar un pulsador presionado
*/
void switch_update(switch_hdl_sT * pHdl)
{
  ASSERT( pHdl == NULL, return);
  /*
    * 
    */
  switch(pHdl->status)
  {
    default:
      pHdl->status = 0;
    case 0:
      /*-- escaneamos para detectar un flanco ascendente */
      if(!switch_GPIO_READ(pHdl->pin))
      {
        systick_Init(pHdl->time,ms);        
        break;
      }
      return ;
    case 1:
      /*-- esperamos hasta agotar el debounce time  */
      if(systick_TimeOut_ms(&(pHdl->time),switch_NOISE_TIME,TRUE))
        return;
      break;
    case 2:
      /*-- consultamos si se mantiene el estado del sw */
      if(!switch_GPIO_READ(pHdl->pin))
        break;      
      else
      {
        /*-- ruido en la linea */
        pHdl->status = 0;
        return;
      }      
          
    case 3:
      /*-- esperamos hasta que se suelte el pulsador */
      if(switch_GPIO_READ(pHdl->pin))
      {
        systick_Init(pHdl->time,ms);
        break;
      }
      return ;
    case 4:
      /*-- esperamos hasta agotar el debounce time  */
      if(systick_TimeOut_ms(&(pHdl->time),switch_NOISE_TIME,TRUE))
        return ;
      break;        
    case 5:
      /*-- consultamos si se mantiene el estado del sw */
      if(switch_GPIO_READ(pHdl->pin))
      {
        /*-- reiniciamos la FSM*/
        pHdl->status = 0;
        /* =====[ Ejecutamos el callback ]=====*/
        if(pHdl->fncallback != NULL)
        {
          (pHdl->fncallback) (pHdl->arg);
        }
        return;
      }
      /*-- no se pudo validar el estado */
      pHdl->status = 3 ;
      return ;
  }
  pHdl->status += 1;
  return ;
}
/*
 * END __switch_VERSION__ 1
 **/

#endif

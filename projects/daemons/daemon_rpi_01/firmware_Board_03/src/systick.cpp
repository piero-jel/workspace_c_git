/***********************************************************************************//**
* \addtogroup modules "Modulos/Librerias Arduino" 
* @{ 
* \copyright  
* 2019, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of systick.cpp .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright holder. &copy;
* \file systick.cpp
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
* \version Numero descriptivo de la version.
* \date 2019 Domingo 18 Octubre.
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
#include "systick.h"



/* **********************************************************************************
 * \fun bool_t systick_TimeOut_us(tick_t *pAcu, const tick_t time);
 * \brief	funcion para verificar time out (si se agoto el tiempo) de una
 * tarea en particular.
 * \param pAcu : puntero al acumulador del tipo tick_t, el cual retiene el tiempo
 * o tick de la tarea a ejecutar en tiempo real.
 * \param time : tiempo de agotamiento, en caso de que este se cumpla el valor se
 * actualiza sobre la variable acumulador.
 * \return retorna el estado del agotamiento.
 * 		+ TRUE : El tiempo se agoto, y el valor del acumulador se actualizo.
 * 		+ FALSE : El tiempo aun no se agoto y el valor del acumulador no se actualizo.
 * @note
 * \par example :
 <pre>
 tick_t acu ;
 systick_Init_us(acu);
 if( !systick_TimeOut_us(&acu,1000)) return;
 TASK_01(ON);
 </pre>
*************************************************************************************/
bool_t systick_TimeOut_us(tick_t *pAcu, const tick_t time, bool_t nret)
{
  if(( systick_getsystem_us() - *pAcu ) > time )
  {
    *pAcu = systick_getsystem_us();        
    nret = (nret)? FALSE : TRUE ;
    return nret;
  }
  else return nret;
}
/*
 * **********************************************************************************
 * \fun bool_t systick_TimeOut_ms(tick_t *pAcu, const tick_t time);
 * \brief	funcion para verificar time out (si se agoto el tiempo) de una
 * tarea en particular.
 * \param pAcu : puntero al acumulador del tipo tick_t, el cual retiene el tiempo
 * o tick de la tarea a ejecutar en tiempo real.
 * \param time : tiempo de agotamiento, en caso de que este se cumpla el valor se
 * actualiza sobre la variable acumulador.
 * \return retorna el estado del agotamiento.
 * 		+ TRUE : El tiempo se agoto, y el valor del acumulador se actualizo.
 * 		+ FALSE : El tiempo aun no se agoto y el valor del acumulador no se actualizo.
 * @note
 * \par example :
 <pre>
 tick_t acu;
 if( systick_TimeOut_ms(&acu,1000))
 {
 	 LED(ON);
 }
 else
 {
 	 LED(OFF);
 }
 </pre>
*************************************************************************************/
bool_t systick_TimeOut_ms(tick_t *pAcu, const tick_t time,bool_t nret)
{
  if(( systick_getsystem_ms() - *pAcu ) > time )
  {
    *pAcu = systick_getsystem_ms();
    nret = (nret == TRUE)? FALSE : TRUE ;
    return nret;
  }
  else return nret;
}

/*
 * **********************************************************************************
 * \fun bool_t systick_nTimeOut_ms(tick_t *pAcu, const tick_t time);
 * \brief  funcion para verificar time out (si se agoto el tiempo) de una
 * tarea en particular. Es la negacion de la funcion \ref systick_TimeOut_ms()
 * \param pAcu : puntero al acumulador del tipo tick_t.
 * \param time : tiempo de agotamiento, en caso de que este se cumpla el valor se
 * actualiza sobre la variable acumulador.
 * \return retorna el estado del agotamiento.
 *    + FALSE : El tiempo se agoto, y el valor del acumulador se actualizo.
 *    + TRUE : El tiempo aun no se agoto y el valor del acumulador no se actualizo.
 * @note
 * \par example :
 <pre>
 tick_t acu ;
 systick_nTimeOut_ms(acu);
 if( systick_nTimeOut_ms(&acu,1000)) return;
 TASK_01(ON);
 </pre>
*************************************************************************************/
void systick_pause_ms(const tick_t time)
{
  static tick_t lacu;
  lacu = systick_getsystem_ms();
  lacu += time;
  while(lacu > systick_getsystem_ms());
}

/*
 * **********************************************************************************
 * \fun bool_t systick_nTimeOut_ms(tick_t *pAcu, const tick_t time);
 * \brief  funcion para verificar time out (si se agoto el tiempo) de una
 * tarea en particular. Es la negacion de la funcion \ref systick_TimeOut_ms()
 * \param pAcu : puntero al acumulador del tipo tick_t.
 * \param time : tiempo de agotamiento, en caso de que este se cumpla el valor se
 * actualiza sobre la variable acumulador.
 * \return retorna el estado del agotamiento.
 *    + FALSE : El tiempo se agoto, y el valor del acumulador se actualizo.
 *    + TRUE : El tiempo aun no se agoto y el valor del acumulador no se actualizo.
 * @note
 * \par example :
 <pre>
 tick_t acu ;
 systick_nTimeOut_ms(acu);
 if( systick_nTimeOut_ms(&acu,1000)) return;
 TASK_01(ON);
 </pre>
*************************************************************************************/
void systick_pause_us(const tick_t time)
{
  static tick_t lacu;
  lacu = systick_getsystem_us();
  lacu += time;
  while(lacu > systick_getsystem_us());
}

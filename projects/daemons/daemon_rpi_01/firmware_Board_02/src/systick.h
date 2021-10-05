/* *********************************************************************************//**
* \addtogroup modules "Modulos/Librerias Arduino"
* @{ 
* \copyright  
* 2019, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of systick.h .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright holder. &copy;
* \file systick.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
* 
*
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

#ifndef __systick_h__
#define __systick_h__ /**<@brief definimos el header file, para evitar includes recursivos */
/**/
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
    
/* ****************************************************************************//**
* \def systick_getsystem_ms();
* \brief Esta es una de las dos macros mas importante del sistema, ya que 
* redirecciona y configura para poder utilizar las librerias nativas
* de Arduino. En caso de que estas cambien (arduino modifique) debemos 
* solo modificar aqui para mantener la portabilidad del sistema.
* \return 
* Es la Etiqueta que se la puede considerar como puntero a funcion,
* de forma analoga pero no funcional, la cual invoca el core de este
* modulo para relizar las siguentes Tareas.
*   \li systick_getsystem_ms() millis()
* Establecemos de que forma o mediante que funcion obtendremos 
* los tick de milis segundos del sistema.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 18 de Octubre 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
*********************************************************************************/   
#define systick_getsystem_ms() millis()
/* ****************************************************************************//**
* \def systick_getsystem_us();
* \brief Esta es una de las dos macros mas importante del sistema, ya que 
* redirecciona y configura para poder utilizar las librerias nativas
* de Arduino. En caso de que estas cambien (arduino modifique) debemos 
* solo modificar aqui para mantener la portabilidad del sistema.
* \return 
* Es la Etiqueta que se la puede considerar como puntero a funcion,
* de forma analoga pero no funcional, la cual invoca el core de este
* modulo para relizar las siguentes Tareas.
*   \li systick_getsystem_us() micros()
* Establecemos de que forma o mediante que funcion obtendremos 
* los tick de micro segundos del sistema.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 18 de Octubre 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
*********************************************************************************/ 
#define systick_getsystem_us() micros()
    


#define __systick_sizeof_var_ticks__    4   /**< @brief Definimos la cantidad de Bytes de la variables ticks */

/* ******************************************************************************//** 
* \typedef tick_t;
* \details Esta es la redefinicion del tipo de variable que se utilizara y que 
* utilizaremos en esta librerias.
* \brief Variable que almacenara los ticks, variable que almacena las 
* referencias de tiempos.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Domingo  18 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> 
* * ********************************************************************************/
#if (__systick_sizeof_var_ticks__ == 1)
typedef unsigned char tick_t;
#elif (__systick_sizeof_var_ticks__ == 2)
typedef unsigned short int tick_t;
#else
typedef unsigned long int tick_t;
#endif

/* ******************************************************************************//**
* \def systick_Init_ms(Acu);
* \brief api para obtener el tiempo actual del tick del systema.
* \param Acu : Nombre del acumulador donde almacenaremos dicho valor.
* \return nothing
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 18 de Octubre 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>.
* \par example :
<PRE>
tick_t acu ;
systick_Init_ms(acu);
if(systick_TimeOut_ms(&acu,1000,FALSE))
{
  LED_TOOGLE();
}
</PRE>
* **********************************************************************************/
#define systick_Init_ms(Acu)    Acu = millis()
/* ******************************************************************************//**
 * \def systick_Init_us(Acu);
 * \brief api para obtener el tiempo actual del tick en micro segundos del systema.
 * \param Acu : Nombre del acumulador donde almacenaremos dicho valor.
 * \return nothing
 * \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 18 de Octubre 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>. 
 * \par example :
 <PRE>
 tick_t acu ;
 systick_Init_us(acu);
 if( !millis_TimeOut_us(&acu,1000)) return;
 TASK_01(ON);
 </PRE>
 * **********************************************************************************/
#define systick_Init_us(Acu) Acu = micros()
/* *******************************************************************************//**
* \def systick_Init(Acu,ms_or_us);
* \brief api para obtener el tiempo actual trasncurido desde que el sistema inicio. 
* \param Acu : Nombre de la variable acumuladora de tick de la tarea/funcion/fsm.
* \param ms_or_us : Con este Argumento especificamos si deseamso obtener los tick
* actual del sistema en valores de :
*   \li ms : Mili segundos.
*   \li us : Micro Segundos.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 18 de Octubre 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
 tick_t acu ;
 systick_Init(acu,ms);
if(systick_TimeOut_ms(&acu,1000,FALSE))
{
  LED_TOOGLE();
}
</PRE> 
*************************************************************************************/ 
#define systick_Init(Acu,ms_or_us)  systick_Init_##ms_or_us(Acu)
/* ****************************************************************************//**
* \def systick_mupdate(Acu,ms_or_us);
* \brief api para obtener el tiempo actual trasncurido desde que el sistema inicio. 
* Esta es identica a la funcion \ref systick_Init();.
* \param Acu : Nombre de la variable acumuladora de tick de la tarea/funcion/fsm.
* \param ms_or_us : Con este Argumento especificamos si deseamso obtener los tick
* actual del sistema en valores de :
*   \li ms : Mili segundos.
*   \li us : Micro Segundos.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 18 de Octubre 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>.
* \par example :
<PRE>
tick_t acu ;
systick_mupdate(acu,ms);
// more code
if(systick_TimeOut_ms(&acu,1000,FALSE))
{
  LED_TOOGLE();
}
</PRE> 
*********************************************************************************/ 
#define systick_mupdate(Acu,ms_or_us)  systick_Init_##ms_or_us(Acu)

/* ******************************************************************************//**
 * \fn bool_t systick_TimeOut_ms(tick_t *pAcu, const tick_t time,bool_t nret);
 * \brief	funcion para verificar time out (si se agoto el tiempo) de una
 * tarea en particular.
 * \param pAcu : puntero al acumulador del tipo tick_t, el cual retiene el tiempo
 * o tick de la tarea a ejecutar en tiempo real.
 * \param time : tiempo de agotamiento, en caso de que este se cumpla el valor se
 * actualiza sobre la variable acumulador.
 * \param nret : Con este Argumenta especificamos si deseamos que se invierta la
 * logica o no.
 *  + TRUE, se inivierte la logica, si se vence el time out Retorna FALSE.
 *  + FALSE, se mantiene la logica, si se vence el time out Retorna TRUE.
 * \return retorna el estado de Time Out.
 * 		+ TRUE : Si el argumento nret es FALSE, este indica que el tiempo se 
 *      agoto, y el valor del acumulador se actualizo.
 * 		+ TRUE : Si el argumento nret es TRUE, este indica que el tiempo no se
 *      agoto aun, no se actualiza el acumulador.
 * 
 * 		+ FALSE : Si el argumento nret es FALSE, este indica que el tiempo aun
 *      no se agoto y el valor del acumulador no se actualizo.
 * 		+ FALSE : Si el argumento nret es TRUE, este indica que el tiempo se
 *      agoto y el valor del acumulador fue actuaizado .
 * \version 01v01d01.
 * \note nota.
 * \warning mensaje de "warning".
 * \date Domingo 18 de Octubre 2020.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>.
 * \par example :
<PRE>
  // .. more code  
  TIME_OUT = 700;
  tick_t acu = 0;
  // ... more code
  if( systick_TimeOut_ms(&acu,TIME_OUT,FALSE))
  {
      // time out succes
  }

</PRE>
*************************************************************************************/
bool_t systick_TimeOut_ms(tick_t *pAcu, const tick_t time,bool_t nret);
/* ******************************************************************************//**
 * \fn bool_t systick_TimeOut_us(tick_t *pAcu, const tick_t time);
 * \brief	funcion para verificar time out (si se agoto el tiempo) de una
 * tarea en particular.
 * \param pAcu : puntero al acumulador del tipo tick_t, el cual retiene el tiempo
 * o tick de la tarea a ejecutar en tiempo real.
 * \param time : tiempo de agotamiento, en caso de que este se cumpla el valor se
 * actualiza sobre la variable acumulador.
 * \return retorna el estado del agotamiento.
 *  + TRUE : El tiempo se agoto, y el valor del acumulador se actualizo.
 *  + FALSE : El tiempo aun no se agoto y el valor del acumulador no se actualizo.
 * \version 01v01d01.
 * \note nota.
 * \warning mensaje de "warning".
 * \date Domingo 18 de Octubre 2020.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>.
 * \par example :
 <PRE>
 tick_t acu ;
 systick_Init_us(acu);
 // ... more code
 if(systick_TimeOut_us(&acu,500,TRUE)) return;
 TASK_01(ON);
 </PRE>
*************************************************************************************/
bool_t systick_TimeOut_us(tick_t *pAcu, const tick_t time);

/* ******************************************************************************//**
 * 
 * \fn void systick_pause_ms(const tick_t time);
 * \brief Funcion para generar una pausa en mili segundos. Esto mantine al hilo 
 * de ejecucion en un bucle, hasta que el tiempo establecido se agote.
 * \param time : tiempo de agotamiento.
 * \return nothing.
 * \version 01v01d01.
 * \note nota.
 * \warning mensaje de "warning".
 * \date Domingo 18 de Octubre 2020.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>.
 * \par example :
 <PRE>
  LED_INI();
  LED_OFF();
  //... more code
  
  uint16_t ret = 1024;
  // more code
  do
  {    
    systick_pause_ms(700);
    LED_ON();
    systick_pause_ms(300);
    LED_OFF();    
  }while(--ret);
  
 </PRE>
*************************************************************************************/
void systick_pause_ms(const tick_t time);
/* ******************************************************************************//**
 * 
 * \fn void systick_pause_us(const tick_t time);
 * \brief Funcion para generar una pausa en micros segundos. Esto mantine al hilo 
 * de ejecucion en un bucle, hasta que el tiempo establecido se agote.
 * \param time : tiempo de agotamiento.
 * \return nothing.
 * \version 01v01d01.
 * \note nota.
 * \warning mensaje de "warning".
 * \date Domingo 18 de Octubre 2020.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>.
 * \par example :
 <PRE>
  TASK_INI();
  TASK_SET_STATUS(1);
  //... more code
  
  uint16_t ret = 1024;
  // more code
  do
  {    
    systick_pause_us(250);
    TASK_SET_STATUS(1);
    systick_pause_us(250);
    TASK_SET_STATUS(2);
    //... 
  }while(--ret);  
 </PRE>
*************************************************************************************/
void systick_pause_us(const tick_t time);


/*
 *============================[close, cplusplus]============================
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
#endif /* #ifndef __systick_h__ */

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
#include <version.h>
#include <stdctype.h>
#include <stdio.h>
#include <stdlib.h>

#include <stdctimer.h>
#include <prpi_gpio.h>


#define _GNU_SOURCE /*para habilitar todas las funcionalidades */
#include <pthread.h>

#include <main.h>



#ifndef __main_version__
#define __main_version__        version_SetNumber(01v00d00)
#endif
/*
 * version 01v0d0 -> test test basico c++, print arg list
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
TODO: main version 01v0d0
*/
/* GPIO disponibles 
 * GPIO 2 3 4 5 6
 */
#define MAX_INTERACTION   10
blinky_led_t led1 = {.gpion = 2, .time_on=100,.time_off=900} ;
blinky_led_t led2 = {.gpion = 3, .time_on=200,.time_off=800} ;
blinky_led_t led3 = {.gpion = 4, .time_on=300,.time_off=700} ;
blinky_led_t led4 = {.gpion = 5, .time_on=400,.time_off=600} ;
blinky_led_t led5 = {.gpion = 6, .time_on=500,.time_off=500} ;

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
  /* mapeamos el periferico GPIO */
  if(!prpi_gpio_init(NULL/*pointer err-notify*/))
    exit(EXIT_SUCCESS);
    
  /* definimos los handler para las thread */
  pthread_t pth_led1,pth_led2,pth_led3,pth_led4,pth_led5;
  pthread_t pth_main;
  
  /* creamos las thread */
  
  pthread_create( &pth_led1, NULL, (void*) blinky_led, (void*) &led1);  
  pthread_create( &pth_led2, NULL, (void*) blinky_led, (void*) &led2);
  pthread_create( &pth_led3, NULL, (void*) blinky_led, (void*) &led3);
  pthread_create( &pth_led4, NULL, (void*) blinky_led, (void*) &led4);
  pthread_create( &pth_led5, NULL, (void*) blinky_led, (void*) &led5);
  pthread_create( &pth_main, NULL, (void*) thread_main, (void*) MAX_INTERACTION);
  
  /* adjuntamos las thread al scheduler */
  pthread_join( pth_led1, NULL);
  pthread_join( pth_led2, NULL);
  pthread_join( pth_led3, NULL);
  pthread_join( pth_led4, NULL);
  pthread_join( pth_led5, NULL);  
  pthread_join( pth_main, NULL);
  
  /*-- En este punto finalizaron todas las Threads, 
   * Po lo tanto liberamos los gpio */
  prpi_gpio_deinit(NULL/*pointer err-notify*/);
  exit(EXIT_SUCCESS);
}


void blinky_led(void * arg)
{
  if(arg == NULL)
    return;
  
  /*-- Tomamos el argumento */
  blinky_led_t *led = (blinky_led_t*) arg;
  /* para darle salida al loop */
  led->i = 0;
  /* configuramos el pin, como salida */
  prpi_gpio_config(led->gpion,prpi_PINCONFIG_OUTPUT);
  /*-- apagamos el led*/
  prpi_gpio_write(led->gpion,TRUE);
  while(1)
  {
    prpi_gpio_write(led->gpion,FALSE);    
    stdctimer_msleep(led->time_on,NULL/*pointer err-notify*/);
    prpi_gpio_write(led->gpion,TRUE);
    stdctimer_msleep(led->time_off,NULL/*pointer err-notify*/); 
    if(++led->i == MAX_INTERACTION)
      break;
  }
  /* reestablecemos la configuracion por defecto */
  prpi_gpio_config(led->gpion,prpi_PINCONFIG_DEFAULT);  
}

void thread_main(void * arg)
{
  if(arg == NULL)
    return;
  
  uint8_t j = CAST_VOID(PVOID2UINT,arg);
  
  CFPRINTF(BLUE,stdout,"\t%s\n","Inicio del loop");
  while(j)
  {
    CFPRINTF(BLUE,stdout,"\tInteraccion Numero: %i\n",j);
    sleep(1);
    j--;      
  }  
  CFPRINTF(BLUE,stdout,"\t%s\n","Fin del loop");  
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
TODO: main version 01v00d01
*/

/* GPIO disponibles 
 * GPIO 2 3 4 5 6
 */
#define MAX_INTERACTION   10
blinky_led_t hdlLed[] = {{.gpion = 2, .time_on=100,.time_off=900} 
                     ,{.gpion = 3, .time_on=400,.time_off=600} 
                     ,{.gpion = 4, .time_on=800,.time_off=200} 
                     ,{.gpion = 5, .time_on=400,.time_off=600}
                     ,{.gpion = 6, .time_on=500,.time_off=500}};

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
  /* Inicializamos los GPIO */
  if(!prpi_gpio_init(NULL/*pointer err-notify*/))
    exit(EXIT_SUCCESS);
    
  /* definimos los handler para las thread */
  pthread_t pth_led[ARRAY_SIZE(hdlLed)];
  pthread_t pth_main;
  
  /* creamos las thread */
  int i;
  for(i = 0 ; i<ARRAY_SIZE(hdlLed) ; i++) 
  {
    pthread_create( &pth_led[i], NULL, (void*) blinky_led, (void*) &hdlLed[i]);    
  }
  pthread_create( &pth_main, NULL, (void*) thread_main, (void*) MAX_INTERACTION);
  
  /* adjuntamos las thread al scheduler */
  for( i = 0 ; i<ARRAY_SIZE(hdlLed);i++)
  {
    pthread_join( pth_led[i], NULL);    
  }
  
  pthread_join( pth_main, NULL);

  
  /*-- En este punto finalizaron todas las Threads, 
   * Po lo tanto liberamos los gpio */
  prpi_gpio_deinit(NULL/*pointer err-notify*/);
  exit(EXIT_SUCCESS);
}


void blinky_led(void * arg)
{
  if(arg == NULL)
    return;
  
  /*-- Tomamos el argumento */
  blinky_led_t *led = (blinky_led_t*) arg;
  /* para darle salida al loop */
  led->i = 0;
  /* configuramos el pin, como salida */
  prpi_gpio_config(led->gpion,prpi_PINCONFIG_OUTPUT);
  /*-- apagamos el led*/
  prpi_gpio_write(led->gpion,TRUE);
  while(1)
  {
    prpi_gpio_write(led->gpion,FALSE);    
    stdctimer_msleep(led->time_on,NULL/*pointer err-notify*/);
    prpi_gpio_write(led->gpion,TRUE);
    stdctimer_msleep(led->time_off,NULL/*pointer err-notify*/); 
    if(++led->i == MAX_INTERACTION)
      break;
  }
  /* reestablecemos la configuracion por defecto */
  prpi_gpio_config(led->gpion,prpi_PINCONFIG_DEFAULT);  
}

void thread_main(void * arg)
{
  if(arg == NULL)
    return;
  
  uint8_t j = CAST_VOID(PVOID2UINT,arg);
  int i;  
  CFPRINTF(BLUE,stdout,"\t%s\n","Inicio del loop");
  for(i = 0; i < j; i++)
  {
    CFPRINTF(BLUE,stdout,"\tInteraccion Numero: %i\n",i);
    stdctimer_msleep(1000,NULL/*pointer err-notify*/);
  }  
  CFPRINTF(BLUE,stdout,"\t%s\n","Fin del loop");  
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
TODO: main version 01v00d02
*/

#include <signal.h>


uint8_t loop = 1;

/* GPIO disponibles 
 * GPIO 2 3 4 5 6
 */
#define MAX_INTERACTION   10
blinky_led_t hdlLed[] = {{.gpion = 2, .time_on=100,.time_off=900} 
                     ,{.gpion = 3, .time_on=400,.time_off=600} 
                     ,{.gpion = 4, .time_on=800,.time_off=200} 
                     /*,{.gpion = 5, .time_on=400,.time_off=600}
                     ,{.gpion = 6, .time_on=500,.time_off=500}*/  
};

switch_hdl_t hdlSw[] = {
   {.st = 0, .debounce_time = 10, .gpion = 5, .callback = fncallback_sw}
  ,{.st = 0, .debounce_time = 10, .gpion = 6, .callback = fncallback_sw}  
};

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
  /* Inicializamos los GPIO */
  if(!prpi_gpio_init(NULL/*pointer err-notify*/))
    exit(EXIT_SUCCESS);
    
  loop = 1;  
  signal(SIGINT, signal_capture);

  /* definimos los handler para las thread */
  pthread_t pth_led[ARRAY_SIZE(hdlLed)];
  pthread_t pth_sw[ARRAY_SIZE(hdlSw)];
  pthread_t pth_main;
  
  /* creamos las thread */
  int i;
  for(i = 0 ; i<ARRAY_SIZE(hdlLed) ; i++) 
  {
    pthread_create( &pth_led[i], NULL, (void*) blinky_led, (void*) &hdlLed[i]);    
  }
  pthread_create( &pth_sw[0], NULL, (void*) switch_update, (void*) &hdlSw[0]);
  pthread_create( &pth_sw[1], NULL, (void*) switch_update, (void*) &hdlSw[1]);
  
  pthread_create( &pth_main, NULL, (void*) thread_main, (void*) MAX_INTERACTION);
  
  /* adjuntamos las thread al scheduler */
  for( i = 0 ; i<ARRAY_SIZE(hdlLed);i++)
  {
    pthread_join( pth_led[i], NULL);    
  }
  
  pthread_join( pth_sw[0], NULL);
  pthread_join( pth_sw[1], NULL);
  
  pthread_join( pth_main, NULL);

  
  /*-- En este punto finalizaron todas las Threads, 
   * Po lo tanto liberamos los gpio */
  prpi_gpio_deinit(NULL/*pointer err-notify*/);
  exit(EXIT_SUCCESS);
}


void blinky_led(void * arg)
{
  if(arg == NULL)
    return;
  
  /*-- Tomamos el argumento */
  blinky_led_t *led = (blinky_led_t*) arg;
  /* para darle salida al loop */
  led->i = 0;
  /* configuramos el pin, como salida */
  prpi_gpio_config(led->gpion,prpi_PINCONFIG_OUTPUT);
  /*-- apagamos el led*/
  prpi_gpio_write(led->gpion,TRUE);
  while(loop)
  {
    prpi_gpio_write(led->gpion,FALSE);    
    stdctimer_msleep(led->time_on,NULL/*pointer err-notify*/);
    prpi_gpio_write(led->gpion,TRUE);
    stdctimer_msleep(led->time_off,NULL/*pointer err-notify*/);     
  }
  
  /* reestablecemos la configuracion por defecto */
  prpi_gpio_config(led->gpion,prpi_PINCONFIG_DEFAULT);  
  CPRINTF(GREEN,"\t Fin de la Thread %s(LED:GPIO %d)\n",__FUNCTION__,led->gpion);
  pthread_exit(NULL);
}


void switch_update(void * arg)
{
  if(arg == NULL)
    return;  
  /*-- Tomamos el argumento */
  switch_hdl_t *sw = (switch_hdl_t*) arg;
  /* configuramos el GPIO, com entrada */
  prpi_gpio_config(sw->gpion,prpi_PINCONFIG_INPUT);
  sw->st = 0;
  /* inicio del loop principale */
  while(loop)
  {    
    switch(sw->st)
    {
      case 0:
        if(prpi_gpio_read(sw->gpion))
        {
          sched_yield();
          /* saltamos al while */
          continue;
        }
        stdctimer_msleep(sw->debounce_time,NULL/*pointer err-notify*/); 
        break;
      case 1:
        if(prpi_gpio_read(sw->gpion))
        {
          /*paso debounce time y cambio el estado del pin, ruido */
          sw->st = 0;
          continue;
        }
        break;
        
      case 2:
        if(!prpi_gpio_read(sw->gpion))
        {
          sched_yield();
          /* saltamos al while */
          continue;
        }  
        stdctimer_msleep(sw->debounce_time,NULL/*pointer err-notify*/); 
        break;
        
      case 3:
        if(!prpi_gpio_read(sw->gpion))
        {
          /*paso debounce time y cambio el estado del pin, ruido */
          sw->st = 2;          
          continue;
        }  
        sw->st = 0;
        /* se valida el sw presionado */
        if(sw->callback != NULL)
          (sw->callback) (sw);
        
        sched_yield();
        continue;
    }
    sw->st++;
    
  }
  CPRINTF(GREEN,"\t Fin de la Thread %s(SW:GPIO %d)\n",__FUNCTION__,sw->gpion);
  pthread_exit(NULL);
}

void thread_main(void * arg)
{
  if(arg == NULL)
    return;
  
  uint8_t j = CAST_VOID(PVOID2UINT,arg);
  int i;  
  CFPRINTF(BLUE,stdout,"\t%s\n","Inicio del loop");
  for(i = 0; i < j; i++)
  {
    CFPRINTF(BLUE,stdout,"\tInteraccion Numero: %i\n",i);
    stdctimer_msleep(1000,NULL/*pointer err-notify*/);
  }  
  CFPRINTF(BLUE,stdout,"\t%s\n","Fin del loop");  
  pthread_exit(NULL);
}


void fncallback_sw(void *arg)
{
  switch_hdl_t *sw = (switch_hdl_t*) arg;
  CFPRINTF(BLUE,stdout,"\tSe presiono el SW en el GPIO %d\n",sw->gpion);    
}

/* captura de la señal */
static void signal_capture(int signal)
{
  CPRINTF(GREEN,"\t Se capturo la señal N° : %d\n",signal);
  loop = 0;
  sleep(1);
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
TODO: main version 01v00d03
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
TODO: main version 01v00d04
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
TODO: main version 01v00d05
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
TODO: main version 01v00d06
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
TODO: main version 01v00d07
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
TODO: main version 01v00d08
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
TODO: main version 01v00d09
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

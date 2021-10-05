/***********************************************************************************//**
* \addtogroup modules "Modulos/Librerias Arduino" 
* @{ 
* \copyright  
* 2019, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of modules .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright holder. &copy;
* \file switch.h
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


#ifndef __switch_h__
#define __switch_h__ /**<@brief definimos el header file, para evitar includes recursivos */
/* 
* ***** [ Add header files ] *****
*/
#include <Arduino.h>
#include "stdctype.h"
#include "systick.h"

#define __switch_VERSION__  1 /**<@brief Establecemos la version a compilar, esto cambia la funcionalidad*/
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


  
#define switch_PIN_INPUT        INPUT   /**<@brief Definimos El macro label para establecer el Pin como entrada.*/
// #define switch_PIN_OUTPUT       OUTPUT  /**<@brief Definimos El macro label para establecer el Pin como Salida.*/
#define switch_PIN_INP_PULL_UP  INPUT_PULLUP/**<@brief Definimos el label para el pin configurado como entrada Pull Up habilitado.*/
#define switch_NOISE_TIME   10 /**<@brief Establecemos el tiempo considerado como ruido
para los Switch/pulsadores.*/  


/******************************************************************************//**
* \def switch_GPIO_CONFIG(Pin,Type);
* \brief Macro para establecer que funciones internas usara el modulo para acceder
* a los pines. Esta es para garantizar Portabilidad. En caso de ser necesario una
* interfaces podemos definirla antes de esta macro para poder llamarla desde 
* ella.
* \param Pin : Argumento que representa el pin a configurar.
* \param Type : este valor representa si el mismo lo configramos como entrada 
* o Como salida. Debemos configura los Macros labels tambien, el valor de este
* debe ser:
*   + switch_PIN_INPUT, el cual usamos por el momento dentro del modulo.
*   + switch_PIN_OUTPUT
* \return nothing.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
*********************************************************************************/
#define switch_GPIO_CONFIG(Pin,Type) \
  pinMode(Pin,Type)
  
/******************************************************************************//**
* \def switch_GPIO_READ(Pin);
* \brief Macro para Leer el estado del Pin Digital (Pin de entrada salida de 
* proposito general - GPIO), esta es la que usa internamente 
* el modulo para llebar a cabo la operacion y poder tener un modulo portable
* a otra plataforma.
* \param Pin : Argumento que representa el pin a Leer.
* \return 
*   + 1 Estado Alto.
*   + 0 Estado Bajo.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
*********************************************************************************/ 
#define switch_GPIO_READ(Pin) \
  digitalRead(Pin)
  
  
 
/*
 * BEGIN __switch_VERSION__ 0
 **/  
#if (__switch_VERSION__ == 0)
  
/**
*\def switch_NOT_PUSH
* \details
* \brief Etiqueta que nos indica que el switch no fue presionado. Un valor 
* distinito a este nos indica que fue pulsado el mismo.
* \note
* \warning */
#define switch_NOT_PUSH     0xAA

/**
* \struct switch_hdl_sT; 
* \brief Esturcutra de dato con almacenara la configuracion del 
* blinky led.
* Elementos de la configuracion:
*  \li \ref pin;
*  \li \ref status;
*  \li \ref time;
* \version  01v01d01.
* \note nota sobre la estructura.
* \warning Este tipo de estructura no puede ser almacenada 
* en memoria de programa. Por lo que no puede usar el cualificador 'const'.
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  uint8_t pin;    /**<@brief Pin para el switch */
  uint8_t status; /**<@brief Para almacenar el status de la FSM */
  tick_t time;    /**<@brief Para almacenar el tiempo de la FSM */  
}switch_hdl_sT;


/*******************************************************************************//**
* \fn void switch_init(switch_hdl_sT * pHdl, uint8_t nroSw);
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

switch_hdl_sT hdlSw[]= { // Definimos un array de handler "Hdl" 
  // y asignamos el numero de pin 
  {.pin=2, .fncallback=fn_push_sw, .arg=(void*) (&enc)}, // pin 0 
  {.pin=7}, // pin 1
};

void setup()
{ 
 //.. more code
      // le pasamos el array y la cantidad de pulsadores en esta caso '2'
  switch_init(hdlSw,2);
  
}
void loop()
{
  if(switch_update(0) != switch_NOT_PUSH )
  {
    // code here, para el Switch 0
  }
    
}

</PRE>
*************************************************************************************/
void switch_init(switch_hdl_sT * pHdl, uint8_t nroSw);

/********************************************************************************//**
* \fn uint8_t switch_update(uint8_t nSw);
* \brief Funcion que actualiza la FSM del Pulsador indicado mediante el argumento nSw.
* \param nSw : Indice dentro del array de Handler de Pulsadores, o lo que se 
* simplifica en el numero de pulsador.
* \return 
*   + 0, En caso de que el nSw se pulso.
*   + switch_NOT_PUSH, para el caso de que no se pulso aun.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Domingo 24 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
switch_hdl_sT hdlSw[]= { // Definimos un array de handler "Hdl" 
  // y asignamos el numero de pin 
  {.pin=2}, // pin 0 
  {.pin=7}, // pin 1
};

void setup()
{ 
 //.. more code
 blinkyled_set(0);
      // le pasamos el array y la cantidad de pulsadores en esta caso '2'
  switch_init(hdlSw ,2);
  
}
void loop()
{
  static uint8_t blk=0;
  blinkyled_update();
  if(switch_update(0) == 0)
  {
    if(blk < 5) blk++;
    else blk = 0;
    blinkyled_set(blk);
  }
  if(switch_update(1) == 0)
  {
    if(blk > 0) blk--;
    else blk = 5;
    blinkyled_set(blk);    
  }
  
}
</PRE>
*************************************************************************************/
uint8_t switch_update(uint8_t nSw);
 
/*
 * END __switch_VERSION__ 0
 **/  
#elif (__switch_VERSION__ == 1) 
/*
 * BEGIN __switch_VERSION__ 1
 **/  
#define switch_PULL_UP_ENABLE   1 /**<@brief Habilitamos '1'/Deshabilitamos '0' el pull up interno para el pin.*/

typedef void (*switch_fncallback_fpT) (void *);

/**
* \struct switch_hdl_sT; 
* \brief Esturcutra de dato con almacenara la configuracion del 
* blinky led.
* Elementos de la configuracion:
*  \li \ref pin;
*  \li \ref status;
*  \li \ref time;
*  \li \ref fncallback;
*  \li \ref arg;
* \version  01v01d01.
* \note nota sobre la estructura.
* \warning Este tipo de estructura no puede ser almacenada 
* en memoria de programa. Por lo que no puede usar el cualificador 'const'.
* \date Domingo 25 de Octubre, 2020.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  uint8_t pin;    /**<@brief Pin para el switch */
  uint8_t status; /**<@brief Para almacenar el status de la FSM */
  tick_t time;    /**<@brief Para almacenar el tiempo de la FSM */  
  switch_fncallback_fpT fncallback; /**<@brief Definimos la funcion a llamar cuando presionamos el pulsador */  
  void * arg; /**<@brief Argumento que pasaremos al callback fncallback */  
}switch_hdl_sT;


/*******************************************************************************//**
* \fn void switch_init(switch_hdl_sT * pHdl,uint8_t pin,switch_fncallback_fpT fncallback ,void * arg);
* \brief Funcion que inicializa el hardware necesario para un pulsador. 
* \param pHdl : Puntero al Handler
* \param pin : Pin que se asignara al handler.
* \param fncallback : Funcion que se llamara cuando se presiones el pulsador.
* \param arg : Argumento con el cual se llamara a la funcion anterior.
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
void fn_test(void* arg);

uint8_t ar = 0;
switch_hdl_sT sw1;

void setup()
{ 
  //.. more code
  // le pasamos el array y la cantidad de pulsadores en esta caso '2'
  switch_init(&sw1,A4,fn_test,(void*) (&ar));
  
  blinkyled_init();
  blinkyled_set(2);
  // ... 
}
void loop()
{
  blinkyled_update();
  switch_update(&sw1);
}
void fn_test(void* arg)
{
  uint8_t *a = (uint8_t*) arg;
  if(*a == 6)
    *a = 0;
  else
    *a = *a + 1;
  blinkyled_set(*a);
}
</PRE>
*************************************************************************************/
void switch_init(switch_hdl_sT * pHdl,uint8_t pin \
    ,switch_fncallback_fpT fncallback ,void * arg);


/********************************************************************************//**
* \fn uint8_t switch_update(switch_hdl_sT * pHdl);
* \brief Funcion que actualiza la FSM de un Pulsador.
* \param pHdl : Puntero al Handler del pulsador a actualizar.
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
void fn_test(void* arg);

uint8_t ar = 0;
switch_hdl_sT sw1;

void setup()
{ 
  //.. more code
  // le pasamos el array y la cantidad de pulsadores en esta caso '2'
  switch_init(&sw1,A4,fn_test,(void*) (&ar));
  
  blinkyled_init();
  blinkyled_set(2);
  // ... 
}
void loop()
{
  blinkyled_update();
  switch_update(&sw1);
}
void fn_test(void* arg)
{
  uint8_t *a = (uint8_t*) arg;
  if(*a == 6)
    *a = 0;
  else
    *a = *a + 1;
  blinkyled_set(*a);
}
</PRE>
*************************************************************************************/
void switch_update(switch_hdl_sT * pHdl);

/*******************************************************************************//**
* \fn void switch_set(switch_hdl_sT * pHdl, switch_fncallback_fpT fncallback ,void * arg);
* \brief Funcion para establecer la funcion de callback y el argumento para esta.
* \param pHdl : Puntero al Handler
* \param fncallback : Funcion que se llamara cuando se presiones el pulsador.
* \param arg : Argumento con el cual se llamara a la funcion anterior.
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
void fn_test_01(void* arg);
void fn_test_02(void* arg);

uint8_t arg1 = 0;
uint8_t arg2 = 0;
switch_hdl_sT sw1;

void setup()
{ 
  //.. more code
  // le pasamos el array y la cantidad de pulsadores en esta caso '2'
  switch_init(&sw1,A4,fn_test,(void*) (&arg1));  
  blinkyled_init();
  blinkyled_set(2);
  // ... 
}

void loop()
{
  blinkyled_update();
  switch_update(&sw1);
}
void fn_test_01(void* arg)
{
  // more code here
  switch_set(&sw1,fn_test_02,(void*) (&arg2));
}
void fn_test_02(void* arg)
{
  // more code here
  switch_set(&sw1,fn_test_01,(void*) (&arg1));  
}
</PRE>
*************************************************************************************/
void switch_set(switch_hdl_sT * pHdl, switch_fncallback_fpT fncallback ,void * arg);



/********************************************************************************//**
* \def switch_mset(Hdl,Fncallback,Arg);
* \brief Macro Funcion que actualiza la FSM del Pulsador indicado mediante el argumento nSw.
* \param Hdl : Estructura del tipo Handler para el pulsador.
* \param Fncallback : Funcion que se llamara cuando se presiones el pulsador.
* \param Arg : Argumento con el cual se llamara a la funcion anterior.
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
void fn_test_01(void* arg);
void fn_test_02(void* arg);

uint8_t arg1 = 0;
uint8_t arg2 = 0;
switch_hdl_sT sw1;

void setup()
{ 
  //.. more code
  // le pasamos el array y la cantidad de pulsadores en esta caso '2'
  switch_init(&sw1,A4,fn_test,(void*) (&arg1));  
  blinkyled_init();
  blinkyled_set(2);
  // ... 
}

void loop()
{
  blinkyled_update();
  switch_update(&sw1);
}
void fn_test_01(void* arg)
{
  // more code here
  switch_mset(sw1,fn_test_02,&arg2);
}
void fn_test_02(void* arg)
{
  // more code here
  switch_mset(sw1,fn_test_01,&arg1);  
}
</PRE>
*************************************************************************************/
#define switch_mset(Hdl,Fncallback,Arg) \
{\
  Hdl.fncallback = Fncallback;\
  Hdl.arg = (void *) (Arg);\
  Hdl.status = 0;\
}

/********************************************************************************//**
* \def switch_minit(Hdl,Pin,Fncallback,Arg);
* \brief Macro Funcion para inicializar el handler del pulsador.
* \param Hdl : Estructura del tipo Handler para el pulsador.
* \param Pin : Pin al cual se conectara el pulsador.
* \param Fncallback : Funcion que se llamara cuando se presiones el pulsador.
* \param Arg : Argumento con el cual se llamara a la funcion anterior.
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
void fn_test_01(void* arg);
void fn_test_02(void* arg);

uint8_t arg1 = 0;
uint8_t arg2 = 0;
switch_hdl_sT sw1;

void setup()
{ 
  //.. more code
  // le pasamos el array y la cantidad de pulsadores en esta caso '2'
  switch_minit(sw1,A4,fn_test,&arg1);  
  blinkyled_init();
  blinkyled_set(2);
  // ... 
}

void loop()
{
  blinkyled_update();
  switch_update(&sw1);
}
void fn_test_01(void* arg)
{
  // more code here
  switch_mset(sw1,fn_test_02,&arg2);
}
void fn_test_02(void* arg)
{
  // more code here
  switch_mset(sw1,fn_test_01,&arg1);  
}
</PRE>
*************************************************************************************/
#if (switch_PULL_UP_ENABLE == 1)
#define switch_minit(Hdl,Pin,Fncallback,Arg) \
{\
  Hdl.pin = Pin;\
  Hdl.fncallback = Fncallback;\
  Hdl.arg = (void *) (Arg);\
  Hdl.status = 0;\
  switch_GPIO_CONFIG(Hdl.pin,switch_PIN_INP_PULL_UP);\
}
#else
#define switch_minit(Hdl,Pin,Fncallback,Arg) \
{\
  Hdl.pin = Pin;\
  Hdl.fncallback = Fncallback;\
  Hdl.arg = (void *) (Arg);\
  Hdl.status = 0;\
  switch_GPIO_CONFIG(Hdl.pin,switch_PIN_INPUT);\
}
#endif /* #if (switch_PULL_UP_ENABLE == 1) */

/*
 * END __switch_VERSION__ 1
 **/

#elif (__switch_VERSION__ == 2)  
/*
 * BEGIN __switch_VERSION__ 2
 **/

/*
 * END __switch_VERSION__ 2
 **/
#elif (__switch_VERSION__ == 3)  
/*
 * BEGIN __switch_VERSION__ 3
 **/



/*
 * BEGIN __switch_VERSION__ 3
 **/
#else 
#warning " __switch_VERSION__ establecido de Forma Incorrecta, revisar typedef.h linea 56 "
#endif




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
#endif /* #ifndef __switch_h__ */

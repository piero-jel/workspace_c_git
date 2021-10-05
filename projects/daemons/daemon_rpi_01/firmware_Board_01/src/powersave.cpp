/*************************************************************************************//**
* \addtogroup modules "Modulos/Librerias Arduino"
* @{ 
* \copyright  
* 2019, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of modules .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright holder. &copy;
* \file powersave.cpp
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
* @} doxygen end group definition 
* ********************************************************************************** */
#include "powersave.h"




#if (defined(ARDUINO_ARCH_AVR) && defined(ARDUINO_AVR_NANO))


  static powersave_flag_t flags;

  static inline void power_down(void)
  {    
    PRR |= flags;
  }
  
  static inline void power_up(void)
  {
    PRR &= ~flags;    
  }
  
#elif (defined(ARDUINO_ARCH_AVR) && defined(ARDUINO_AVR_MICRO))

  /**<\var Estructura de datos para el manejo de gpio */
  typedef uint16_t AVR_PRR_t ;
  
  /**<@brief definimos un registro de 16-bit para PPR1|PPR0 */
  #define AVR_PPR               _SFR_MEM16(0x64)
  
  static powersave_flag_t flags;

  static inline void power_down(void)
  {    
    AVR_PPR |= flags;
  }
  
  static inline void power_up(void)
  {
    AVR_PPR &= ~flags;    
  }

#elif (defined(ARDUINO_ARCH_AVR) && defined(ARDUINO_AVR_MEGA2560))

  /** @brief Estructura de datos para el manejo de gpio */
  typedef uint16_t AVR_PRR_t ;
  
  /**<@brief definimos un registro de 16-bit para PPR1|PPR0 */
  #define AVR_PPR               _SFR_MEM16(0x64)
  
  static powersave_flag_t flags;

  static inline void power_down(void)
  {    
    AVR_PPR |= flags;
  }
  
  static inline void power_up(void)
  {
    AVR_PPR &= ~flags;    
  }



#else
#warning "soporte para el micro no existente"

  #define power_down()
  #define power_up()

#endif





void powersave_init(void)
{
  memset(&flags,0,sizeof(powersave_flag_t));  
}


void powersave_set(powersave_flag_t flg,powersave_action_t action)
{
  switch(action)
  {
    case powersave_ENABLE:
      flags |= flg;
      return;      
    case powersave_DISABLE:
      flags &= ~flg;
      return;
    case powersave_SET:
      flags = flg;
    default:
      return;    
  }    
}


/**
 * Nos ponemos a dormir a la espera de una interupcion
 * sleep wait for interrupt
 */
void powersave_sleepwfi(void)
{
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  /*Aqui debemos colocar los power_down para los perifericos qe no nos deben despertar */
  power_down();
  sleep_mode();
  sleep_disable();
  /*Antes de irnos debemos volver a energizar los perifericos */\
  power_up();  
}

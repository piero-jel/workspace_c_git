/** ***********************************************************************************//**
 * \addtogroup template 
 * @{
 * \copyright  
 * 2021, Luccioni Jesús Emanuel \n
 * All rights reserved.\n 
 * This file is part of template .\n
 * Redistribution is not allowed on binary and source forms, with or without \n
 * modification. Use is permitted with prior authorization by the copyright 
 * holder. &copy;
 * \file main.h
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
/*
 * -- Definimos el Nombre del modulo
*/
#ifndef __main_h__
#define __main_h__
/*
 * ===========================[ BEGIN include header file ]===========================
 */

/** @example : #include <nmbHeaderFile.h> */

/*
 * ===========================[ END include header file   ]===========================
 * */


/*
 * ==========================[ BEGIN Main APIs Declaration ]==========================
 */
/**
* ******************************************************************************** 
* \fn int main(int argc, char **argv);
* \brief Funcion Principal
* \param argc : cantidad de Argumentos pasados al invocar la app.
* \param argv : puntero a puntero que contiene el listado de arguementos.
* \return status de la ejecucion de la app.
*      \li 0, success
*      \li 1, failure
* \version numero de version a la cual corresponde.
* \note nota.
* \warning mensaje de "warning". 
* \date date dayOfMonth de month, years.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
*********************************************************************************/
int main(int argc, char **argv);

/*
 * ==========================[ END   Main APIs Declaration ]==========================
 */


 #if (version_QueryNumber(__main_version__,01v00d00))
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d00 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d00
*/
#include "serialterminal.h"
#include "macro_apis.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/*#define DAEMON_DEFAULT_NAMEID     "MonitoringBoard"
const char* defaultname = DAEMON_DEFAULT_NAMEID;*/

#define DAEMON_DEBUG        1 /**<@brief Enable/Disable debug, este debe 
estar deshabilitado cuando pase a prodicion, ya que este corta al secuencia */

#define ERROR_INSERT_SYSLOG         LOG_WARNING
#define NOTIFY_INSERT_SYSLOG        LOG_WARNING
#define MSG_SYS_LOG_LEN             BUFFER_LEN_M    /*  128 */




/* Definimos el numero de interacciones de loop del Daemon 
 * para debug  */
#define DAEMON_INTERATOR            100
/* Configuracion de la Teminal */
#define TERMINAL_BAUD_RATE          115200
/* definimos el prefix de puerto por defecto */
#define TERMINAL_PORT               "ttyUSB"


#define TERMINAL_BUFF               BUFFER_LEN_1K   /* 1024 */

#define menu_opt_NAME_ENABLE        0 /* habilitamos/deshabilitamos el nombre descriptivo 
dentro de la estructura de menu. Aun no esta en uso este dentro del servicio. */

/* Analizamos los Arguemtnos: 
  * -d : devices {TempBoard|FeederBoard} 
  * -p : puerto {ttyUSB|ttyACM|....}
  * -b : baud rate {9200 | 115200 | .... }
  */
typedef struct
{
  char * device;
  char * port;  
  uint32_t baudrate;
  uint32_t maxportnumber;
  uint32_t retryconn;
  uint32_t timeoutdev;
  uint32_t timeoutfailprocdata;
  char * logger_path;
}argument_list_t;

#define DEFAULT_DEVICE                "FeederBoard"
#define DEFAULT_PORT                  "ttyUSB"
#define DEFAULT_BAUDRATE              115200
#define DEFAULT_MAXPORTNUMBER         10
#define DEFAULT_RETRYCONN             10
#define DEFAULT_TIMEOUTDEV            2 /**<@brief Segundos */
#define DEFAULT_TIMEOUTFAILPROCDATA   10 /**<@brief Segundos */

/*
  * Argumentos:
  *  -d | --device            DEVICE            string
  *  -p | --port              PUERTO            string
  *  -b | --baudrate          BAUD_RATE         number  
  *  -m | --max_port_number   MAX PORT NUMBER   number
  *  -r | --retry_con_dev     retry conect
  *                           devices           number
  *  -t | --timeout_dev       devices 
  *                           disconect timeout number
  *  -f | --fail_proc_data    fail api process 
  *                           data, timeout     number 
  */
#define menu_INDEX_DEVICE       0x01
#define menu_INDEX_PORT         0x02
#define menu_INDEX_BAUDRATE     0x03
#define menu_INDEX_MAX_PORTN    0x04
#define menu_INDEX_RETRY_CON    0x05
#define menu_INDEX_TIMEOUT_DEV  0x06
#define menu_INDEX_FAIL_PROCD   0x07
#define menu_LOGGER_PATH        0x08


typedef struct 
{  
  const char *opt_short;
  const char *opt_long;
  uint32_t idx;    
}menu_t;

/**
 * \var menu_opt;
 * \brief      Estructura que contiene la definiciones del comando.
 * Opcion corta, larga,leyenda/msg para cada una de las opciones.
 * \version    numero de version/es a la cual corresponde.
 * \warning mensaje de "warning".
 */
menu_t menu_opt[] = \
{
   {"-d","--device",menu_INDEX_DEVICE}
  ,{"-p","--port",menu_INDEX_PORT}
  ,{"-b","--baudrate",menu_INDEX_BAUDRATE}
  ,{"-m","--max_port_number",menu_INDEX_MAX_PORTN}
  ,{"-r","--retry_con_dev",menu_INDEX_RETRY_CON}
  ,{"-t","-timeout_dev",menu_INDEX_TIMEOUT_DEV}
  ,{"-f","--fail_proc_data",menu_INDEX_FAIL_PROCD}
  ,{"-l","--logger_path",menu_LOGGER_PATH}
  ,{NULL}
};


int argument_FillList(const char *str, argument_list_t *list, menu_t *pmenu);
void argument_Check(argument_list_t *list);
void argument_FreeList(argument_list_t *list);

// #define NUMBER_RETRY_CONNECT_DEVICES    10
// #define DEVICES_DISCONNECTED_TIMEOUT    2 /* Dos Segundos */
#define FAIL_API_PROCESS_DATA_TIMEOUT   10 /* 10 segundos */

#define MAX_PORT_NUMBERS            10


/** Establecemos los valores por defeto de reintentos
 *    + Falla en el procesamiento de la informacion.
 *    + Falla en el intento de obtener el ID del Dispositivo.
 */
#define RETRY_FAIL_PROCDATA     10
#define RETRY_GET_DEVICES_ID    10
#define STRING_QUERY_ID         "id"




#if (defined(DEBUG_ENABLE))
#define SYSLOG_DEBUG(...)\
  syslog(LOG_DEBUG, __VA_ARGS__ )
  
#else /**/  
#define SYSLOG_DEBUG(...)  
#endif 


static uint8_t stop_daemon = 1;

static void daemonize( const char *idname );
static void handle_signal(int sig);



static serialterminal_hdl_t hdl_port;
/*
  serialterminal_cfg_t cfg;
  cfg.BaudRate = TERMINAL_BAUD_RATE;
  cfg.Frame = 0;
  cfg.CtrlFlow = 0;  
*/
static serialterminal_cfg_t cfg_port = {.BaudRate = TERMINAL_BAUD_RATE, .Frame = 0, .CtrlFlow = 0};



/*static bool_t terminal_init( const char *portprefix ,const char *devname\
                           , serialterminal_hdl_t *hdlTerminal \
                           , serialterminal_cfg_t *cfgTerminal);*/

static bool_t terminal_init( argument_list_t *parglst \
                           , serialterminal_hdl_t *hdlTerminal \
                           , serialterminal_cfg_t *cfgTerminal);

static bool_t terminal_deinit(serialterminal_hdl_t *hdlTerminal);

static bool_t terminal_update( serialterminal_hdl_t *hdlTerminal \
                             , macro_hdl_apis_t * hdlapis \
                             , int *errMgs, uint8_t *errflag);






/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d00 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d01))
/**
* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d01 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d01
*/
#include "serialterminal.h"
#include "macro_apis.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define DAEMON_DEFAULT_NAMEID     "MonitoringBoard"
const char* defaultname = DAEMON_DEFAULT_NAMEID;

#define ERROR_INSERT_SYSLOG         LOG_WARNING
#define NOTIFY_INSERT_SYSLOG        LOG_WARNING
#define MSG_SYS_LOG_LEN             BUFFER_LEN_M    /*  128 */




/* Definimos el numero de interacciones de loop del Daemon 
 * para debug  */
#define DAEMON_INTERATOR            100
/* Configuracion de la Teminal */
#define TERMINAL_BAUD_RATE          115200
/* definimos el prefix de puerto por defecto */
#define TERMINAL_PORT               "ttyUSB"


#define TERMINAL_BUFF               BUFFER_LEN_1K   /* 1024 */

#define menu_opt_NAME_ENABLE        0 /* habilitamos/deshabilitamos el nombre descriptivo 
dentro de la estructura de menu. Aun no esta en uso este dentro del servicio. */

/* Analizamos los Arguemtnos: 
  * -d : devices {TempBoard|FeederBoard} 
  * -p : puerto {ttyUSB|ttyACM|....}
  * -b : baud rate {9200 | 115200 | .... }
  */
typedef struct
{
  char * device;
  char * port;
  uint32_t baudrate;
  uint32_t maxportnumber;
  uint32_t retryconn;
  uint32_t timeoutdev;
  uint32_t timeoutfailprocdata;
}argument_list_t;
/*
  * Argumentos:
  *  -d | --device            DEVICE            string
  *  -p | --port              PUERTO            string
  *  -b | --baudrate          BAUD_RATE         number  
  *  -m | --max_port_number   MAX PORT NUMBER   number
  *  -r | --retry_con_dev     retry conect
  *                           devices           number
  *  -t | --timeout_dev       devices 
  *                           disconect timeout number
  *  -f | --fail_proc_data    fail api process 
  *                           data, timeout     number 
  */
#define menu_INDEX_DEVICE       0x01
#define menu_INDEX_PORT         0x02
#define menu_INDEX_BAUDRATE     0x03
#define menu_INDEX_MAX_PORTN    0x04
#define menu_INDEX_RETRY_CON    0x05
#define menu_INDEX_TIMEOUT_DEV  0x06
#define menu_INDEX_FAIL_PROCD   0x07

#if (menu_opt_NAME_ENABLE == 1)
typedef struct 
{  
  const char *opt_short;
  const char *opt_long;
  uint32_t idx;  
  const char * name;
}menu_t;

/**
 * \var menu_opt;
 * \brief      Estructura que contiene la definiciones del comando.
 * Opcion corta, larga,leyenda/msg para cada una de las opciones.
 * \version    numero de version/es a la cual corresponde.
 * \warning mensaje de "warning".
 */
menu_t menu_opt[] = \
{
   {"-d","--device",menu_INDEX_DEVICE,"DEVICE"}
  ,{"-p","--port",menu_INDEX_PORT,"PREFIX PORT TERMINAL"}
  ,{"-b","--baudrate",menu_INDEX_BAUDRATE,"BAUD RATE"}
  ,{"-m","--max_port_number",menu_INDEX_MAX_PORTN,"MAX PORT NUMBER"}
  ,{"-r","--retry_con_dev",menu_INDEX_RETRY_CON,"retry conect device"}
  ,{"-t","-timeout_dev",menu_INDEX_TIMEOUT_DEV,"devices disconect timeout"}
  ,{"-f","--fail_proc_data",menu_INDEX_FAIL_PROCD,"timeout fail api process data"}    
  ,{NULL}
};
#else
typedef struct 
{  
  const char *opt_short;
  const char *opt_long;
  uint32_t idx;    
}menu_t;

/**
 * \var menu_opt;
 * \brief      Estructura que contiene la definiciones del comando.
 * Opcion corta, larga,leyenda/msg para cada una de las opciones.
 * \version    numero de version/es a la cual corresponde.
 * \warning mensaje de "warning".
 */
menu_t menu_opt[] = \
{
   {"-d","--device",menu_INDEX_DEVICE}
  ,{"-p","--port",menu_INDEX_PORT}
  ,{"-b","--baudrate",menu_INDEX_BAUDRATE}
  ,{"-m","--max_port_number",menu_INDEX_MAX_PORTN}
  ,{"-r","--retry_con_dev",menu_INDEX_RETRY_CON}
  ,{"-t","-timeout_dev",menu_INDEX_TIMEOUT_DEV}
  ,{"-f","--fail_proc_data",menu_INDEX_FAIL_PROCD}
  ,{NULL}
};

#endif


int argument_FillList(const char *str, argument_list_t *list, menu_t *pmenu);


#define NUMBER_RETRY_CONNECT_DEVICES    10
#define DEVICES_DISCONNECTED_TIMEOUT    2 /* Dos Segundos */
#define FAIL_API_PROCESS_DATA_TIMEOUT   10 /* 10 segundos */

#define MAX_PORT_NUMBERS            10




#if (defined(DEBUG_ENABLE))
#define SYSLOG_DEBUG(...)\
  syslog(LOG_DEBUG, __VA_ARGS__ )
  
#else /**/  
#define SYSLOG_DEBUG(...)  
#endif 


static uint8_t stop_daemon = 1;

static void daemonize( const char *idname );
static void handle_signal(int sig);



static serialterminal_hdl_t hdl_port;
/*
  serialterminal_cfg_t cfg;
  cfg.BaudRate = TERMINAL_BAUD_RATE;
  cfg.Frame = 0;
  cfg.CtrlFlow = 0;  
*/
static serialterminal_cfg_t cfg_port = {.BaudRate = TERMINAL_BAUD_RATE, .Frame = 0, .CtrlFlow = 0};



static bool_t terminal_init( const char *portprefix \
                           , serialterminal_hdl_t *hdlTerminal \
                           , serialterminal_cfg_t *cfgTerminal);

static bool_t terminal_deinit(serialterminal_hdl_t *hdlTerminal);

static bool_t terminal_update( serialterminal_hdl_t *hdlTerminal \
                             , macro_hdl_apis_t * hdlapis \
                             , buffer_t *errMgs, uint8_t *errflag);



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d01 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d02))
/**
* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d02 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d02
*/

#include "serialterminal.h"
#include "macro_apis.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define DAEMON_DEFAULT_NAMEID     "MonitoringBoard"
const char* defaultname = DAEMON_DEFAULT_NAMEID;

#define ERROR_INSERT_SYSLOG         LOG_WARNING
#define NOTIFY_INSERT_SYSLOG        LOG_WARNING
#define MSG_SYS_LOG_LEN             BUFFER_LEN_M    /*  128 */




/* Definimos el numero de interacciones de loop del Daemon 
 * para debug  */
#define DAEMON_INTERATOR            100
/* Configuracion de la Teminal */
#define TERMINAL_BAUD_RATE          115200
/* definimos el prefix de puerto por defecto */
#define TERMINAL_PORT               "ttyUSB"


#define TERMINAL_BUFF               BUFFER_LEN_1K   /* 1024 */

#define menu_opt_NAME_ENABLE        0 /* habilitamos/deshabilitamos el nombre descriptivo 
dentro de la estructura de menu. Aun no esta en uso este dentro del servicio. */

/* Analizamos los Arguemtnos: 
  * -d : devices {TempBoard|FeederBoard} 
  * -p : puerto {ttyUSB|ttyACM|....}
  * -b : baud rate {9200 | 115200 | .... }
  */
typedef struct
{
  char * device;
  char * port;
  uint32_t baudrate;
  uint32_t maxportnumber;
  uint32_t retryconn;
  uint32_t timeoutdev;
  uint32_t timeoutfailprocdata;
}argument_list_t;

#define DEFAULT_DEVICE                "FeederBoard"
#define DEFAULT_PORT                  "ttyUSB"
#define DEFAULT_BAUDRATE              115200
#define DEFAULT_MAXPORTNUMBER         10
#define DEFAULT_RETRYCONN             10
#define DEFAULT_TIMEOUTDEV            2 /**<@brief Segundos */
#define DEFAULT_TIMEOUTFAILPROCDATA   10 /**<@brief Segundos */

/*
  * Argumentos:
  *  -d | --device            DEVICE            string
  *  -p | --port              PUERTO            string
  *  -b | --baudrate          BAUD_RATE         number  
  *  -m | --max_port_number   MAX PORT NUMBER   number
  *  -r | --retry_con_dev     retry conect
  *                           devices           number
  *  -t | --timeout_dev       devices 
  *                           disconect timeout number
  *  -f | --fail_proc_data    fail api process 
  *                           data, timeout     number 
  */
#define menu_INDEX_DEVICE       0x01
#define menu_INDEX_PORT         0x02
#define menu_INDEX_BAUDRATE     0x03
#define menu_INDEX_MAX_PORTN    0x04
#define menu_INDEX_RETRY_CON    0x05
#define menu_INDEX_TIMEOUT_DEV  0x06
#define menu_INDEX_FAIL_PROCD   0x07


typedef struct 
{  
  const char *opt_short;
  const char *opt_long;
  uint32_t idx;    
}menu_t;

/**
 * \var menu_opt;
 * \brief      Estructura que contiene la definiciones del comando.
 * Opcion corta, larga,leyenda/msg para cada una de las opciones.
 * \version    numero de version/es a la cual corresponde.
 * \warning mensaje de "warning".
 */
menu_t menu_opt[] = \
{
   {"-d","--device",menu_INDEX_DEVICE}
  ,{"-p","--port",menu_INDEX_PORT}
  ,{"-b","--baudrate",menu_INDEX_BAUDRATE}
  ,{"-m","--max_port_number",menu_INDEX_MAX_PORTN}
  ,{"-r","--retry_con_dev",menu_INDEX_RETRY_CON}
  ,{"-t","-timeout_dev",menu_INDEX_TIMEOUT_DEV}
  ,{"-f","--fail_proc_data",menu_INDEX_FAIL_PROCD}
  ,{NULL}
};


int argument_FillList(const char *str, argument_list_t *list, menu_t *pmenu);
void argument_Check(argument_list_t *list);
void argument_FreeList(argument_list_t *list);

// #define NUMBER_RETRY_CONNECT_DEVICES    10
// #define DEVICES_DISCONNECTED_TIMEOUT    2 /* Dos Segundos */
#define FAIL_API_PROCESS_DATA_TIMEOUT   10 /* 10 segundos */

#define MAX_PORT_NUMBERS            10




#if (defined(DEBUG_ENABLE))
#define SYSLOG_DEBUG(...)\
  syslog(LOG_DEBUG, __VA_ARGS__ )
  
#else /**/  
#define SYSLOG_DEBUG(...)  
#endif 


static uint8_t stop_daemon = 1;

static void daemonize( const char *idname );
static void handle_signal(int sig);



static serialterminal_hdl_t hdl_port;
/*
  serialterminal_cfg_t cfg;
  cfg.BaudRate = TERMINAL_BAUD_RATE;
  cfg.Frame = 0;
  cfg.CtrlFlow = 0;  
*/
static serialterminal_cfg_t cfg_port = {.BaudRate = TERMINAL_BAUD_RATE, .Frame = 0, .CtrlFlow = 0};



static bool_t terminal_init( const char *portprefix ,const char *devname\
                           , serialterminal_hdl_t *hdlTerminal \
                           , serialterminal_cfg_t *cfgTerminal);

static bool_t terminal_deinit(serialterminal_hdl_t *hdlTerminal);

static bool_t terminal_update( serialterminal_hdl_t *hdlTerminal \
                             , macro_hdl_apis_t * hdlapis \
                             , buffer_t *errMgs, uint8_t *errflag);



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d02 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d03))
/**
* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d03 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d03
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d03 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d04))
/**
* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d04 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d04
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d04 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d05))
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d05 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d05
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d05 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d06))
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d06 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d06
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d06 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d07))
/**
* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d07 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d07
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d07 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d08))
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d08 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d08
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d08 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__main_version__,01v00d09))
/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ BEGIN Global Macros/labels version 01v00d09 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01v00d09
*/



/**
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ───────────────────[ END   Global Macros/labels version 01v00d09 ]─────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/

#endif /* #if(version_QueryNumber(__main_version__,01v00d00)) */
/* **********************************************************************************************
 *
 * ===========================[ END Global Macros functions ]==================================
 *
 **********************************************************************************************
 * 
 */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef __main_h__ */


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
/* header file del sistema */
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <string.h>

/* Header local */
#include <stdcfile.h>
#include <stdctimer.h>
#include <logger.h>



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
  static uint32_t i = 1;    
  static uint8_t status; 
  
  /* Estas dos variables las podemos sacar y utilizar las reservadas 
   * ya que estas se liberan al finalizar el servicio
   */
  /*static char servicename[64];
  static char portname[64];*/
  
  /* Contexto de las APIs de macro */
  static macro_hdl_apis_t hdl_apis;
  /* lsita de argumentos */
  static argument_list_t arg_list;
  /*-- Contexto para el logger */
  static logger_hdl_t hdl_logger;
  int errnumber; /*para el manejo de errores estandar*/
  
  memset(&arg_list,0,sizeof(argument_list_t));
  

  
  if( argc <= 1)
    PERROR(EINVAL,FAILURE,"\tEl numero de Argumentos pasados son incorrectos %i\n"\
          , argc);    

  /* Analizamos los Arguemtnos: 
    * -d : devices {TempBoard|FeederBoard} 
    * -p : puerto {ttyUSB|ttyACM|....}
    * -b : baud rate {9200 | 115200 | .... }
    */
  while(i < argc)
  {  
    if(argument_FillList((const char*) argv[i],&arg_list,menu_opt) < 0 )
      PERROR(EINVAL,SUCCESS,"\tFalla al intentar Obtener los Argumentos Pasados.\n\t \"%s\"\n"\
            , strerror(EINVAL) );
    i++;
  }  
  
   
  /* Verificamos y llenamos con los valores por defecto
   * el listado de argumentos: 
   */
  argument_Check(&arg_list);
  /* Realizamos el logger de los datos para armar el contexto
   */  
  DEBUG_PRINTF("Parametros Obtenidos \n"\
                 "\tdevice/library name: %s\n"\
                 "\tport: \"%s\", baudrate: %d\n"\
                 "\tEnumeracion Max Port: \"%d\", Reintentos de conexion: \"%d\"\n"\
                 "\tTimeout Desconecion Port: \"%d [Seg]\", Timeout Espera/Libraries response \"%d[Seg]\"\n"\
                 "\tLog Daemon Path: \"%s\"\n"\
               , arg_list.device\
               , arg_list.port, arg_list.baudrate\
               , arg_list.maxportnumber, arg_list.retryconn\
               , arg_list.timeoutdev, arg_list.timeoutfailprocdata \
               , arg_list.logger_path );
  /*
   * Creamos el contexto para el logger 
   * FIXME Nos falta cargar el arguetno "-l log-path"
   */
  if(!logger_init(&errnumber,&hdl_logger,1,arg_list.logger_path,NULL))
  {
    /* No se pudo crear el contexto para el logger */
    logger_deinit();
    PERROR(errnumber, FAILURE,"\tError \"%s\" al intentar crear el contexto de logger\n"\
      , strerror(errnumber));      
  }    
  

  /* Realizamos el logger de los datos para armar el contexto
   */  
  logger_mprintf(0, logger_OK,"Parametros Obtenidos: \n"\
                 "\tdevice/library name: %s\n"\
                 "\tport \"%s\", baudrate %d\n"\
                 "\tEnumeracion Max Port %d, Reintentos de conexion %d\n"\
                 "\tTimeout Port %d [Seg], Timeout Espera/Libraries response %d[Seg]\n"\
               , arg_list.device\
               , arg_list.port, arg_list.baudrate\
               , arg_list.maxportnumber, arg_list.retryconn\
               , arg_list.timeoutdev, arg_list.timeoutfailprocdata);
     
  do{  
    if(arg_list.device == NULL)
    {
      logger_mprintf(0,logger_ERROR,"No se localizo el argumento -d|--device. finalizamos el daemon\n");
      break;
    }
    
    /*
    * FIXME
    * Los Nombres debemos lebantarlos desde los arguementos 
    * y contrastarlo con las librerias de enlace dinamico cargadas
    * en el sistema. Por lo que esta validacion no se realizaria 
    * con los nombres si no directamente con las APIs de -PIC
    * 
    * Obtenemos los Punteros a funciones para cada API
    */  
  /*
    * BEGIN Get libraries APIs
    */
    if(strcmp(arg_list.device,"TempBoard") == 0)
    {
      hdl_apis.fn_init = macro_TempBoard_Init;
      hdl_apis.fn_deinit = macro_TempBoard_Deinit;
      hdl_apis.fn_processdata = macro_TempBoard_ProcessData ;
      hdl_apis.fn_notify = macro_TempBoard_Notify;      
    }  
    else if(strcmp(arg_list.device,"FeederBoard") == 0)
    {
      hdl_apis.fn_init = macro_FeederBoard_Init;
      hdl_apis.fn_deinit = macro_FeederBoard_Deinit;
      hdl_apis.fn_processdata = macro_FeederBoard_ProcessData ;
      hdl_apis.fn_notify = macro_FeederBoard_Notify;    
    }
    else if(strcmp(arg_list.device,"FeederBoard_01") == 0)
    {
      hdl_apis.fn_init = macro_FeederBoard_Init;
      hdl_apis.fn_deinit = macro_FeederBoard_Deinit;
      hdl_apis.fn_processdata = macro_FeederBoard_ProcessData ;
      hdl_apis.fn_notify = macro_FeederBoard_Notify;    
    }
    else
    {     
      logger_mprintf(0,logger_ERROR,"Argumento -d|--device Invalido {TempBoard|FeederBoard|FeederBoard_01}.\n");
      break;      
    }
    logger_mprintf(0,logger_OK,"Librerias Cargadas para \"%s\"\n",arg_list.device);
    
  /*
    * END Get libraries APIs
    */    
    
    /*
    * BEGIN CRACION DEL SERVICIO 
    */   
    daemonize((const char*) arg_list.device/*servicename*/);      
    
    signal(SIGINT,handle_signal);
    signal(SIGHUP,handle_signal);  
    
    syslog (LOG_NOTICE, "Daemon Iniciado.");  
    
    logger_mprintf(0,logger_OK,"Daemon \"%s\" Iniciado.\n",arg_list.device/*servicename*/); 
    /*
    * END CRECION DEL SERVICIO, dentro del servicio 
    * 
    */
    
    /* Iniciamos la aplicacion llamando a la API correspondiente:  
     *       macro_{TempBoard|OtherBoard}_Init();
     *    */
    if( (hdl_apis.fn_init != NULL) && ((hdl_apis.fn_init)(NULL,&errnumber) == FALSE))
    {
      syslog(LOG_ERR,"%s",strerror(errnumber));
      logger_mprintf( 0,logger_ERROR,"Error \"%s\" al intentar ejecutar fn_init() de la libreria\n"\
                   , strerror(errnumber));
      break;
    }      
    
    /* Intentamos abrir el Puerto */
    i = 0;    
    while(!terminal_init(&arg_list/*portname,servicename,arg_list.maxportnumber*/,&hdl_port,&cfg_port) && (++i < arg_list.retryconn))
    {
      logger_mprintf(0,logger_ERROR,"Dispositivo \"%s\" Desconectado, esperamos %d segundos.\n"\
            , arg_list.port/*portname*/,arg_list.timeoutdev);
      sleep(arg_list.timeoutdev);
    }
    if(i >= arg_list.retryconn)
    {
      /* Salimos por reintentos agotados de conexion con el dispositivo. */
      logger_mprintf(0,logger_ERROR,"Se agotaron los reintentos (%d). Salimos.\n",i);
      break;      
    }
    logger_mprintf(0, logger_OK,"Inicio exitoso para el Dispositivo \"%s\" "\
                   "Identificado en el Puerto \"%s\".\n"\
                 ,arg_list.device/*servicename*/,hdl_port.name);
    
    /* Para el retry del debug fuera del control del sistema "systemctl" */
    i = 0;
    /*solo para debug del servicio y no quedar en el loop de forma indefinida  */
    uint32_t retryfailprocdata = 0;
    while(stop_daemon) /* super loops */
    {         
      
#if (defined(DEBUG_ENABLE))
      if(i++ == DAEMON_INTERATOR )
        break;
#endif       
      if(terminal_update(&hdl_port,&hdl_apis,&errnumber,&status))
      {
        retryfailprocdata = 0;
        continue;
      }
        
      
      logger_mprintf( 0,logger_WARNING,"Error \"%s\", Staus Error %d  llamado terminal_update().\n"\
                    , strerror(errnumber),status);
      syslog(LOG_ERR,"%s",strerror(errnumber));
      
      if(status == 1)
      {
        /*-- Se perdio comunicacion con el Dispositivo, esperamos */
        logger_mprintf(0,logger_ERROR,"Se Perdio comunicacion con el dispositivo,"\
                      "esperamos %d [seg].\n"\
                      , arg_list.timeoutdev );
        
        sleep(arg_list.timeoutdev);
        terminal_init(&arg_list,&hdl_port,&cfg_port);
        if(++retryfailprocdata < RETRY_FAIL_PROCDATA)
          continue;
        break;          
      }
      if(status == 2)
      {
        /* Fallo la aplicacion que recibe los datos para procesarlos 
          * esperamos un tiempo considerado           */
        logger_mprintf(0,logger_ERROR,"Error \"%s\", Fallo la aplicacion que procesa los datos,"\
                      " esperamos %d [seg]\n",strerror(errnumber),arg_list.timeoutfailprocdata);
        sleep(arg_list.timeoutfailprocdata);
        if(++retryfailprocdata < RETRY_FAIL_PROCDATA)
          continue;
        break;
      }
      /* falla al llamar a la apis de _ProcessData() */
      /* Se produjo un error desconocido, terminamos el proceso */
      logger_mprintf(0,logger_ERROR,"Se produjo un error desconocido.\n"\
                      "Finalizamos el Daemon.");
      syslog(LOG_ERR,"Se Produjo un Error Desconocido.");      
      break;     
    }  
    terminal_deinit(&hdl_port);  
  }while(0);  

  /*-- liberamos las libreria */
  if(hdl_apis.fn_deinit != NULL)
  {
    if(!(hdl_apis.fn_deinit)(&errnumber))
      logger_mprintf(0,logger_ERROR,"Error \"%s\" Al ejecutar fn_deinit() de librerias.\n",strerror(errnumber));      
    else
      logger_mprintf(0,logger_OK,"Ejecucion sastifactoria de fn_deinit(), de la librerias.\n");
  }    
  
  logger_mprintf(0,logger_OK,"Daemon Finalizado.\n");  
  logger_deinit();  
  syslog(LOG_NOTICE,"Daemon Finalizado.");    
  closelog();
  
  /* Esperasmo uno un tiempo, para que se vacien todos los buffer y 
   * liberacion de memroia reservada */  

  
  argument_FreeList(&arg_list);
  sleep(10); 
  /*-- fin */
  exit(EXIT_SUCCESS);
}

/* debemos llamarla con un nombre si no tendremos no se podra generar */
static void daemonize( const char *idname )
{
  const char *id;
  
  if(idname == NULL)
  {
    logger_mprintf(0,logger_ERROR,"No se crea el Daemon, call \"daemonize(NULL);\".\n");
    return;
  }
  if(strlen(idname) == 0)
  {
    logger_mprintf(0,logger_ERROR,"No se crea el Daemon, call \"daemonize(\"\"); Setring Vacio\".\n");
    return;
  }
  /* */
  logger_mprintf(0,logger_OK,"Se Inicia la creacion del Daemon: \"%s\".\n",idname);
  id = idname;
  pid_t pid;  
  /* Fork off the parent process 
   *  Valor menor a cero : error
   *  Valor Mayor a Cero : Estamos en el Procesos Padre, el valor corresponde al PID del hijo.
   *  Valor Igual a Cero : Estamos en el proceso Hijo.
   */
  pid = fork();
  
  /* An error occurred */
  if (pid < 0)
  {
    logger_mprintf( 0,logger_ERROR,"Error \"%s\", al intentar crear el primer child proccess.\n"\
                 , strerror(errno));
    exit(EXIT_FAILURE);
  }
        
  /* Success: Let the parent terminate */
  if (pid > 0)
  {
    logger_mprintf( 0,logger_OK,"Primer Proceso Hijo PID \"%d\", creado sastifactoriamente.\n"\
                 , pid);
    exit(EXIT_SUCCESS);
  }
      
  
  /* On success: The child process becomes session leader */
  if( setsid() < 0)
  {
    logger_mprintf( 0,logger_ERROR,"Error \"%s\", al intentar crear una nueva session.\n"\
                 , strerror(errno));
    exit(EXIT_FAILURE);
  }
  
  
  /* Ignore signal sent from child to parent process */
  signal(SIGCHLD, SIG_IGN);
  signal(SIGHUP, SIG_IGN);
   
  
  /* Fork off for the second time*/
  pid = fork();
  
  /* An error occurred */
  if (pid < 0)
  {
    logger_mprintf( 0,logger_ERROR,"Error \"%s\", al intentar crear el segundo child proccess.\n"\
                 , strerror(errno));
    exit(EXIT_FAILURE);
  }    
        
  /* Success: Let the parent terminate */
  if (pid > 0)
  {
    logger_mprintf( 0,logger_OK,"Segundo Proceso Hijo PID \"%d\", creado sastifactoriamente.\n"\
                 , pid);
    exit(EXIT_SUCCESS);
  }
     
  /* Set new file permissions */
  umask(0);
  
  /* Change the working directory to the root directory */
  /* or another appropriated directory */
  chdir("/");
  
  /* Close all open file descriptors */
  int x;
  for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
  {
    close(x);
  }  
  
  /* Reopen stdin (fd = 0), stdout (fd = 1), stderr (fd = 2) */
  stdin = fopen("/dev/null", "r");
  stdout = fopen("/dev/null", "w+");
  stderr = fopen("/dev/null", "w+");
  
  /* Open the log file */
  logger_mprintf( 0,logger_OK,"Abrimos el syslog con el ID \"%s\".\n"\
                 , id);
  openlog(id, LOG_PID, LOG_DAEMON);
}




/** debemos armar una estructura handler_terminal_t 
 * y encapsular. Esto nos permitira establecer un valor por defecto y tambien 
 * customizar por arguemtos a la hora de llamar a la aplicacion.
 * 
 *      portprefix
 *      devname
 *      queryid : current value "id", string para pedir el id del dispositivo
 *      enummax : current value MAX_PORT_NUMBERS
 *      retryidquery : Numero de reintentos en el pedido del ID del dispositivo.
 *      port : donde guardaremos el nombre y numero del puerto localizado 
 *             el cual se verifique con el string de pedido de id
 *      
 */

static bool_t terminal_init( argument_list_t *parglst /*const char *portprefix ,const char *devname, uint8_t maxportnumber*/\
                           , serialterminal_hdl_t *hdlTerminal \
                           , serialterminal_cfg_t *cfgTerminal)
{
  uint8_t i;  
  char port[64];
  char path_port[128];
  uint32_t retry;
  
  /* buffer para mensaje de error */
  int errnum;
  
  
  /* Debemos iniciar el puerto disponible, leer el primier mensaje y 
   * comprobar que sea el ID de la placa correspondiente
   *  por ejemplo:
   *    >> ttyUSB
   *    >> ttyACM
   *    >> etc
   * Consideramos un byte de enumeracion, lo cual es 0~255 posibilidades.
   */  
  i = 0;
  do
  {
    snprintf(port,sizeof(port),"%s%d",parglst->port/*portprefix*/,i);
    snprintf(path_port,sizeof(path_port),"/dev/%s",port);
    /* */
    if(stdcfile_CheckPathFile((const char*)path_port))
      break;    
    LOGGER_ONLY_DEBUG(0,logger_ERROR,"No se encontro el Puerto %s\n",path_port);    
  }while(++i < parglst->maxportnumber);
  
  if(i == parglst->maxportnumber)
  {
    LOGGER_INFO_DEBUG( 0,logger_ERROR,"No se encontro un Puerto Disponible, %d enumeraciones realizadas\n"\
                 , i );
    return FALSE;
  }
  
  /* Encontramos un Puerto Valido, Intentamos abrir el mismo  */
  if(serialterminal_OpenPort(hdlTerminal,(const char*)port,TRUE,&errnum ) == FALSE)
  {    
    LOGGER_INFO_DEBUG( 0,logger_ERROR,"Error \"%s\" al intentar Abrir el puerto \"%s\"\n"\
                 , strerror(errnum),hdlTerminal->name);
//     syslog(ERROR_INSERT_SYSLOG,"%s",strerror(errnum));
    return FALSE;
  }   

  /*-- configuramos la velocidad, la trama y el control de flujo de la terminal */
  if(serialterminal_SetConfig(hdlTerminal,cfgTerminal->BaudRate,NULL,&errnum) == FALSE)
  {    
    LOGGER_INFO_DEBUG( 0,logger_ERROR,"Error \"%s\" al intentar configurar el puert \"%s\"\n"\
                 , strerror(errnum),hdlTerminal->name);
//     syslog(ERROR_INSERT_SYSLOG,"%s",strerror(errnum));
    return FALSE; 
  }
  /**/
  sleep(2);
  
  /*-- Obtenemos la presentacion de la Board */    
  char boardTx[64];
  /* necesitmaos un buffer grande ya que podemos recivir una trama grande */
  char boardRx[1024];
  
  /*-- enviamos el query id al dispositivo conectado al puerto  */
  snprintf(boardTx,sizeof(boardTx),"%s",STRING_QUERY_ID);  
  LOGGER_INFO_DEBUG( 0,logger_INFO,"Enviando el String \"%s\", por el puerto\"%s\"\n"\
               , boardTx,hdlTerminal->name);
    
  /* el buffer de recepcion del dispoitivo se lleno, esperamos a que responda con el id */
  serialterminal_Transmit(hdlTerminal,boardTx,strlen(boardTx),'\r');
  retry = 0;
  do
  {    
    serialterminal_Receive(hdlTerminal,boardRx,sizeof(boardRx),'\r');
    LOGGER_INFO_DEBUG( 0,logger_INFO,"Se recibio el String \"%s\", desde el puerto \"%s\"\n"\
                 , boardRx,hdlTerminal->name);    
    
    if(strcmp(parglst->device,boardRx) == 0)
      return TRUE;      
    LOGGER_INFO_DEBUG( 0,logger_ERROR,"\tError Id Recibido: \n\t\"%s\"\n\t Se esperaba: \"%s\" \t reintentos: %d\n\n"\
                 , boardRx, parglst->device,retry);    
    stdctimer_msleep(725,NULL);
    
  }while(++retry < RETRY_GET_DEVICES_ID);
  
  
  logger_mprintf( 0,logger_ERROR,"Error con el Id Recibido \"%s\", reintentos %d agotados\n"\
               , boardRx, retry);
  return FALSE;   
}

static bool_t terminal_update( serialterminal_hdl_t *hdlTerminal \
                             , macro_hdl_apis_t *hdlapis \
                             ,int *errMgs, uint8_t *errflag)
{
  char buff[1024];    
  /* buffer para mensaje de error */
  int errnum;

  LOGGER_ONLY_DEBUG(0,logger_WARNING,"call stdcfile_CheckPathFile(%s).\n",hdlTerminal->name);
  if(!stdcfile_CheckPathFile(hdlTerminal->name))
  {
    /* Se desconecto el dispositivo */
    if(errMgs != NULL)
      *errMgs = ENODEV;    
    /* Llamamos a notify si esta disponible para pasarle el mensaje */
    if(hdlapis->fn_notify != NULL)
      (hdlapis->fn_notify) ((void*) "Device was disconnected.\n",&errnum);
    
    if(errflag != NULL)
      *errflag = 1;
    return FALSE;
  }
  /* Antes de pedir datos desde el puerto serie, debemos chequear si 
   * el puerto esta disponible.   
   * 
   * Pedimos los datos por puerto serie     
   * Leemos el puerto serie y sacamos los datos por consola  */
  serialterminal_Receive(hdlTerminal,buff,sizeof(buff),'\r');
  if(strlen(buff) == 0)
  {
    /*se reinicio el dispositivo, sin ueva enumeracion */
    logger_mprintf(0,logger_WARNING,"Se reinicio el Dispositivo., posible causa WDT\n");
    if(errflag != NULL)
      *errflag = 1;
    return FALSE;    
  }
    
  LOGGER_ONLY_DEBUG(0,logger_WARNING,"Se recibio \"%s\".\n",buff);
  /*-- llamamos a la funcion que se encarga de procesar los datos */
  if(hdlapis->fn_processdata == NULL)
  {
    /*-- Notificamos que no existe la apis */
    if(errflag != NULL)
      *errflag = 3;    
    return FALSE;
  }
  
  LOGGER_ONLY_DEBUG(0,logger_WARNING,"call (hdlapis->fn_processdata)().\n");
  if(!(hdlapis->fn_processdata)((void*) buff,&errnum))
  {
    LOGGER_INFO_DEBUG(0,logger_WARNING,"Fallo el call (hdlapis->fn_processdata)().\n");
    /* Fallo la escritura de datos al log */    
    if(errMgs != NULL)
      *errMgs = EBUSY;
    /* Llamamos a notify si esta disponible para pasarle el mensaje */
    if(hdlapis->fn_notify != NULL)
      (hdlapis->fn_notify) ((void*) "Failure in data Process.\n",&errnum);
    
    if(errflag != NULL)
      *errflag = 2;
    
    return FALSE;
  }
  /* No es necesario pero en caso de realizar un doble check desde quien llama */
  if(errflag != NULL)
    *errflag = 0;
  return TRUE;    
}

static bool_t terminal_deinit(serialterminal_hdl_t *hdlTerminal)
{

  int errnum;
  
  /*-- Restaurmaso y Cerramos la terminal */
  if(serialterminal_ClosePort(hdlTerminal,TRUE,&errnum) == FALSE)
  {
    syslog(ERROR_INSERT_SYSLOG,"%s",strerror(errnum));
    return FALSE; 
  }
  return TRUE;    
}
/**
 * \brief Callback function for handling signals.
 * \param sig identifier of signal
 */
static void handle_signal(int sig)
{
  /* FIXME: buscar la api para un flush() del syslog()
   * Ya que no muestra el mensaje, puede ser que cierra el log antes de 
   * hacer un dump del buffer.
   */
//   char buff[128];
  if (sig == SIGTERM) 
  {
#if 1   
    logger_mprintf(0,logger_WARNING,"Señal %d capturada, STOP Signals", sig);
#else    
    snprintf(buff,sizeof(buff),"Señal %d capturada, STOP Signals", sig);
    syslog(LOG_NOTICE,"%s",(const char*) buff);  
#endif    
    stop_daemon = 0;
  }
  else if (sig == SIGHUP)
  {    
#if 1   
    logger_mprintf(0,logger_WARNING,"Señal %d capturada, RELOAD Signals", sig);
#else    
    snprintf(buff,sizeof(buff),"Señal %d capturada, RELOAD Signals", sig);
    syslog(LOG_NOTICE,"%s",(const char*) buff);  
#endif         
    stop_daemon = 0;
  } 
  else if (sig == SIGCHLD) 
  {
#if 1   
    logger_mprintf(0,logger_WARNING,"Señal %d capturada, SIGCHLD Signals", sig);
#else    
    snprintf(buff,sizeof(buff),"Señal %d capturada, SIGCHLD Signals", sig);
    syslog(LOG_NOTICE,"%s",(const char*) buff); 
#endif       
    stop_daemon = 0;
  }
}


int argument_FillList(const char *str, argument_list_t *list, menu_t *pmenu)
{
  if(str == NULL || list == NULL || pmenu == NULL)
    return -1;
  
  static int item = 0;
  static bool_t flg = FALSE;

  
  while(pmenu->opt_short != NULL && flg == FALSE)
  {
    if((strcmp(pmenu->opt_short,str) == 0) || \
        (strcmp(pmenu->opt_long,str) == 0) )
    {
      item = pmenu->idx;
      flg = TRUE;
      return 0;
    }
    pmenu++;
  }
  
  switch(item)
  {
    default:
      break;
    case menu_INDEX_DEVICE:
      list->device = strdup(str);
      break;
    case menu_INDEX_PORT:      
      list->port = strdup(str);
      break;
      
    case menu_LOGGER_PATH:
      list->logger_path = strdup(str);
      break;      
      
    case menu_INDEX_BAUDRATE:
      list->baudrate = (uint32_t) strtol(str,NULL,10);
      break;    
      
    case menu_INDEX_MAX_PORTN:
      list->maxportnumber = (uint32_t) strtol(str,NULL,10);
      break;      
    case menu_INDEX_RETRY_CON:
      list->retryconn = (uint32_t) strtol(str,NULL,10);      
      break;      
    case menu_INDEX_TIMEOUT_DEV:
      list->timeoutdev = (uint32_t) strtol(str,NULL,10);
      break;
    case menu_INDEX_FAIL_PROCD:
      list->timeoutfailprocdata = (uint32_t) strtol(str,NULL,10);
      break;

  }  
  flg = FALSE;
  return 0;  
}

void argument_Check(argument_list_t *list)
{
  if(list == NULL)
    return;
  
  if( list->device == NULL )
    list->device = strdup(DEFAULT_DEVICE);
  
  if(list->port == NULL)
    list->port = DEFAULT_PORT;
  
  if(list->baudrate == 0)
    list->baudrate = DEFAULT_BAUDRATE;
  
  if(list->maxportnumber == 0)
    list->maxportnumber = DEFAULT_MAXPORTNUMBER;
  
#if (DEFAULT_RETRYCONN != 0)  
  if(list->retryconn == 0)
    list->retryconn = DEFAULT_RETRYCONN;
#endif
  
  if(list->timeoutdev == 0)
    list->timeoutdev = DEFAULT_TIMEOUTDEV;
  
  if(list->timeoutfailprocdata == 0)
    list->timeoutfailprocdata = DEFAULT_TIMEOUTFAILPROCDATA;  
}


void argument_FreeList(argument_list_t *list)
{
  if(list == NULL)
    return;
  
  if(list->device != NULL)
    free(list->device);
  
  if(list->port != NULL)
    free(list->port);
  
  if(list->logger_path != NULL)
    free(list->logger_path);  
}


/*
┌─────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                     │  
│                                                                                     │  
│ ────────────────────────[ END   apis main version 01v00d00 ]─────────────────────── │
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
/* header file del sistema */
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <string.h>

/* Header local */
#include <stdcfile.h>
#include <stdctimer.h>
#include <logger.h>



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
  static uint32_t i = 1;    
  static uint8_t status; 
  
  /* Estas dos variables las podemos sacar y utilizar las reservadas 
   * ya que estas se liberan al finalizar el servicio
   */
 
  /* Contexto de las APIs de macro */
  static macro_hdl_apis_t hdl_apis;
  /* lsita de argumentos */
  static argument_list_t arg_list;
  /*-- Contexto para el logger */
  static logger_hdl_t hdl_logger;
  int errnumber; /*para el manejo de errores estandar*/
  uint32_t retryfailprocdata = 0;
  memset(&arg_list,0,sizeof(argument_list_t));
    
  if( argc <= 1)
    PERROR(EINVAL,FAILURE,"\tEl numero de Argumentos pasados son incorrectos %i\n"\
          , argc);    

  /* Analizamos los Arguemtnos: 
    * -d : devices {TempBoard|FeederBoard} 
    * -p : puerto {ttyUSB|ttyACM|....}
    * -b : baud rate {9200 | 115200 | .... }
    */
  while(i < argc)
  {  
    if(argument_FillList((const char*) argv[i],&arg_list,menu_opt))
      i++;
    else
      PERROR(EINVAL,SUCCESS,"\tFalla al Procesar los Argumentos. Error \"%s\"\n",strerror(EINVAL) );    
  }  
  
   
  /* Verificamos y llenamos con los valores por defecto
   * el listado de argumentos: 
   */
  argument_Check(&arg_list);
  /* Realizamos el logger de los datos para armar el contexto
   */  
  DEBUG_PRINTF("Parametros Obtenidos \n"\
                 "\tdevice/library name: %s\n"\
                 "\tport: \"%s\", baudrate: %d\n"\
                 "\tEnumeracion Max Port: \"%d\", Reintentos de conexion: \"%d\"\n"\
                 "\tTimeout Desconecion Port: \"%d [Seg]\", Timeout Espera/Libraries response \"%d[Seg]\"\n"\
                 "\tLog Daemon Path: \"%s\"\n"\
               , arg_list.device\
               , arg_list.port, arg_list.baudrate\
               , arg_list.maxportnumber, arg_list.retryconn\
               , arg_list.timeoutdev, arg_list.timeoutfailprocdata \
               , arg_list.logger_path );
  /*
   * Creamos el contexto para el logger 
   * FIXME Nos falta cargar el arguetno "-l log-path"
   */
  if(!logger_init(&errnumber,&hdl_logger,1,arg_list.logger_path,NULL))
  {
    /* No se pudo crear el contexto para el logger */
    logger_deinit();
    PERROR(errnumber, FAILURE,"\tError \"%s\" al intentar crear el contexto de logger\n"\
      , strerror(errnumber));      
  }    
  

  /* Realizamos el logger de los datos para armar el contexto
   */  
  logger_mprintf(0, logger_OK,"Parametros Obtenidos: \n"\
                 "\tdevice/library name: %s\n"\
                 "\tport \"%s\", baudrate %d\n"\
                 "\tEnumeracion Max Port %d, Reintentos de conexion %d\n"\
                 "\tTimeout Port %d [Seg], Timeout Espera/Libraries response %d[Seg]\n"\
               , arg_list.device\
               , arg_list.port, arg_list.baudrate\
               , arg_list.maxportnumber, arg_list.retryconn\
               , arg_list.timeoutdev, arg_list.timeoutfailprocdata);
     
  do{  
    if(arg_list.device == NULL)
    {
      logger_mprintf(0,logger_ERROR,"No se localizo el argumento -d|--device. finalizamos el daemon\n");
      break;
    }
    
    /*
    * FIXME
    * Los Nombres debemos lebantarlos desde los arguementos 
    * y contrastarlo con las librerias de enlace dinamico cargadas
    * en el sistema. Por lo que esta validacion no se realizaria 
    * con los nombres si no directamente con las APIs de -PIC
    * 
    * Obtenemos los Punteros a funciones para cada API
    */  
  /*
    * BEGIN Get libraries APIs
    */
  /*
   *      Name
   *      path_log (reserva de memoria)
   *      callback_init
   *      callback_deinit
   *      callback_processdaa
   *      callback_notify
   *      index
   * 
   *      Arg ==> &arg_list
   */
    if(strcmp(arg_list.device,"TempBoard") == 0)
    {
      hdl_apis.fn_init = macro_TempBoard_Init;
      hdl_apis.fn_deinit = macro_TempBoard_Deinit;
      hdl_apis.fn_processdata = macro_TempBoard_ProcessData ;
      hdl_apis.fn_notify = macro_TempBoard_Notify;      
    }  
    else if(strcmp(arg_list.device,"FeederBoard") == 0)
    {
      hdl_apis.fn_init = macro_FeederBoard_Init;
      hdl_apis.fn_deinit = macro_FeederBoard_Deinit;
      hdl_apis.fn_processdata = macro_FeederBoard_ProcessData ;
      hdl_apis.fn_notify = macro_FeederBoard_Notify;    
    }
    else if(strcmp(arg_list.device,"FeederBoard_01") == 0)
    {
      hdl_apis.fn_init = macro_FeederBoard_Init_01;
      hdl_apis.fn_deinit = macro_FeederBoard_Deinit_01;
      hdl_apis.fn_processdata = macro_FeederBoard_ProcessData_01 ;
      hdl_apis.fn_notify = macro_FeederBoard_Notify_01;    
    }
    else
    {     
      logger_mprintf(0,logger_ERROR,"Argumento -d|--device Invalido {TempBoard|FeederBoard|FeederBoard_01}.\n");
      break;      
    }
    
    logger_mprintf(0,logger_OK,"Librerias Cargadas para \"%s\"\n",arg_list.device);
    
  /*
    * END Get libraries APIs
    */    
    
    /*
    * BEGIN CRACION DEL SERVICIO 
    */   
    daemonize((const char*) arg_list.device/*servicename*/);      
    
    signal(SIGINT,handle_signal);
    signal(SIGHUP,handle_signal);  
    
    syslog (LOG_NOTICE, "Daemon Iniciado.");  
    
    logger_mprintf(0,logger_OK,"Daemon \"%s\" Iniciado.\n",arg_list.device/*servicename*/); 
    /*
    * END CRECION DEL SERVICIO, dentro del servicio 
    * 
    */
    
    /* Iniciamos la aplicacion llamando a la API correspondiente:  
     *       macro_{TempBoard|OtherBoard}_Init();
     *    */
    if( (hdl_apis.fn_init != NULL) && ((hdl_apis.fn_init)(NULL,&errnumber) == FALSE))
    {
      syslog(LOG_ERR,"%s",strerror(errnumber));
      logger_mprintf( 0,logger_ERROR,"Error \"%s\" al intentar ejecutar fn_init() de la libreria\n"\
                   , strerror(errnumber));
      break;
    }      
    
    /* Intentamos abrir el Puerto */
main_loop_init:    
    i = 0;    
    while(!terminal_init(&arg_list,&hdl_port,&cfg_port) && (++i < arg_list.retryconn))
    {
      logger_mprintf(0,logger_ERROR,"Dispositivo \"%s\" Desconectado, esperamos %d segundos.\n"\
            , arg_list.port/*portname*/,arg_list.timeoutdev);
      sleep(arg_list.timeoutdev);
    }
    if(i >= arg_list.retryconn)
    {
      /* Salimos por reintentos agotados de conexion con el dispositivo. */
      logger_mprintf(0,logger_ERROR,"Se agotaron los reintentos (%d). Salimos.\n",i);
      break;      
    }
    logger_mprintf(0, logger_OK,"Inicio exitoso para el Dispositivo \"%s\" "\
                   "Identificado en el Puerto \"%s\".\n"\
                 ,arg_list.device/*servicename*/,hdl_port.name);
    
    /* Para el retry del debug fuera del control del sistema "systemctl" */
    i = 0;
    /*solo para debug del servicio y no quedar en el loop de forma indefinida  */
    
    while(stop_daemon) /* super loops */
    {         
      
#if (defined(DEBUG_ENABLE))
      if(i++ == DAEMON_INTERATOR )
        break;
#endif       
      if(terminal_update(&hdl_port,&hdl_apis,&errnumber,&status))
      {
        retryfailprocdata = 0;
        continue;
      }
        
      
      LOGGER_INFO_DEBUG( 0,logger_WARNING,"Error \"%s\", Staus Error %d  llamado terminal_update().\n"\
                    , strerror(errnumber),status);
      syslog(LOG_ERR,"%s",strerror(errnumber));
      
      if(status == 1)
      {
        /*-- Se perdio comunicacion con el Dispositivo, esperamos */
        LOGGER_INFO_DEBUG(0,logger_ERROR,"Se Perdio comunicacion con el dispositivo,"\
                      "esperamos %d [seg].\n"\
                      , arg_list.timeoutdev );
        
        sleep(arg_list.timeoutdev);
        goto main_loop_init;
//         terminal_init(&arg_list,&hdl_port,&cfg_port);
        
//         if(++retryfailprocdata < RETRY_FAIL_PROCDATA)
//           goto main_loop_init;//continue;
//         break;          
      }
      if(status == 2)
      {
        /* Fallo la aplicacion que recibe los datos para procesarlos 
          * esperamos un tiempo considerado           */
        LOGGER_INFO_DEBUG(0,logger_ERROR,"Error \"%s\", Fallo la aplicacion que procesa los datos,"\
                      " esperamos %d [seg]\n",strerror(errnumber),arg_list.timeoutfailprocdata);
        sleep(arg_list.timeoutfailprocdata);
        if(++retryfailprocdata < RETRY_FAIL_PROCDATA)
          continue;
        break;
      }
      /* falla al llamar a la apis de _ProcessData() */
      /* Se produjo un error desconocido, terminamos el proceso */
      LOGGER_INFO_DEBUG(0,logger_ERROR,"Se produjo un error desconocido.\n"\
                      "Finalizamos el Daemon.");
      syslog(LOG_ERR,"Se Produjo un Error Desconocido.");      
      break;     
    }  
    terminal_deinit(&hdl_port);  
  }while(0);  

  /*-- liberamos las libreria */
  if(hdl_apis.fn_deinit != NULL)
  {
    if(!(hdl_apis.fn_deinit)(&errnumber))
      LOGGER_INFO_DEBUG(0,logger_ERROR,"Error \"%s\" Al ejecutar fn_deinit() de librerias.\n",strerror(errnumber));      
    else
      LOGGER_INFO_DEBUG(0,logger_OK,"Ejecucion sastifactoria de fn_deinit(), de la librerias.\n");
  }    
  
  LOGGER_INFO_DEBUG(0,logger_OK,"Daemon Finalizado.\n");  
  logger_deinit();  
  syslog(LOG_NOTICE,"Daemon Finalizado.");    
  closelog();
  
  /* Esperasmo uno un tiempo, para que se vacien todos los buffer y liberacion de memroia reservada */  
  sleep(10);   
  argument_FreeList(&arg_list);  
  /*-- fin */
  exit(EXIT_SUCCESS);
}

/* debemos llamarla si o si con un nombre, d elo contrario no tendremos syslog() */
static void daemonize( const char *idname )
{
  const char *id;
  
  if(idname == NULL)
  {
    logger_mprintf(0,logger_ERROR,"No se crea el Daemon, call \"daemonize(NULL);\".\n");
    return;
  }
  if(strlen(idname) == 0)
  {
    logger_mprintf(0,logger_ERROR,"No se crea el Daemon, call \"daemonize(\"\"); Setring Vacio\".\n");
    return;
  }
  /* */
  logger_mprintf(0,logger_OK,"Se Inicia la creacion del Daemon: \"%s\".\n",idname);
  id = idname;
  pid_t pid;  
  /* Fork off the parent process 
   *  Valor menor a cero : error
   *  Valor Mayor a Cero : Estamos en el Procesos Padre, el valor corresponde al PID del hijo.
   *  Valor Igual a Cero : Estamos en el proceso Hijo.
   */
  pid = fork();
  
  /* An error occurred */
  if (pid < 0)
  {
    logger_mprintf( 0,logger_ERROR,"Error \"%s\", al intentar crear el primer child proccess.\n"\
                 , strerror(errno));
    exit(EXIT_FAILURE);
  }
        
  /* Success: Let the parent terminate */
  if (pid > 0)
  {
    logger_mprintf( 0,logger_OK,"Primer Proceso Hijo PID \"%d\", creado sastifactoriamente.\n"\
                 , pid);
    exit(EXIT_SUCCESS);
  }
      
  
  /* On success: The child process becomes session leader */
  if( setsid() < 0)
  {
    logger_mprintf( 0,logger_ERROR,"Error \"%s\", al intentar crear una nueva session.\n"\
                 , strerror(errno));
    exit(EXIT_FAILURE);
  }
  
  
  /* Ignore signal sent from child to parent process */
  signal(SIGCHLD, SIG_IGN);
  signal(SIGHUP, SIG_IGN);
   
  
  /* Fork off for the second time*/
  pid = fork();
  
  /* An error occurred */
  if (pid < 0)
  {
    logger_mprintf( 0,logger_ERROR,"Error \"%s\", al intentar crear el segundo child proccess.\n"\
                 , strerror(errno));
    exit(EXIT_FAILURE);
  }    
        
  /* Success: Let the parent terminate */
  if (pid > 0)
  {
    logger_mprintf( 0,logger_OK,"Segundo Proceso Hijo PID \"%d\", creado sastifactoriamente.\n"\
                 , pid);
    exit(EXIT_SUCCESS);
  }
     
  /* Set new file permissions */
  umask(0);
  
  /* Change the working directory to the root directory */
  /* or another appropriated directory */
  chdir("/");
  
  /* Close all open file descriptors */
  int x;
  for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
  {
    close(x);
  }  
  
  /* Reopen stdin (fd = 0), stdout (fd = 1), stderr (fd = 2) */
  stdin = fopen("/dev/null", "r");
  stdout = fopen("/dev/null", "w+");
  stderr = fopen("/dev/null", "w+");
  
  /* Open the log file */
  logger_mprintf( 0,logger_OK,"Abrimos el syslog con el ID \"%s\".\n"\
                 , id);
  openlog(id, LOG_PID, LOG_DAEMON);
}




static bool_t terminal_init( argument_list_t *parglst /*const char *portprefix ,const char *devname, uint8_t maxportnumber*/\
                           , serialterminal_hdl_t *hdlTerminal \
                           , serialterminal_cfg_t *cfgTerminal)
{
  uint8_t i;  
  char port[64];
  char path_port[128];
  uint32_t retry;
  /*-- Obtenemos la presentacion de la Board */    
  char boardTx[64];
  /* necesitmaos un buffer grande ya que podemos recivir una trama grande */
  char boardRx[1024];
  /* buffer para mensaje de error */
  int errnum;
  
  
  /* Debemos iniciar el puerto disponible, leer el primier mensaje y 
   * comprobar que sea el ID de la placa correspondiente
   *  por ejemplo:
   *    >> ttyUSB
   *    >> ttyACM
   *    >> etc
   * Consideramos un byte de enumeracion, lo cual es 0~255 posibilidades.
   */  
  i = 0;
  do
  {
    snprintf(port,sizeof(port),"%s%d",parglst->port/*portprefix*/,i);
    snprintf(path_port,sizeof(path_port),"/dev/%s",port);
    /* Chequeamos si esxite el archivo */
    if(stdcfile_CheckPathFile((const char*)path_port) == FALSE)
    {
      LOGGER_ONLY_DEBUG(0,logger_ERROR,"No se encontro el Puerto %s\n",path_port);    
      continue;      
    } 
    LOGGER_ONLY_DEBUG(0,logger_INFO,"Se encontro el Puerto %s\n",path_port);
    /* Tenemos un archivo o Puerto Valido, Intentamos abrir el mismo  */
    if(serialterminal_OpenPort(hdlTerminal,(const char*)port,TRUE,&errnum ) == FALSE)
    {    
      LOGGER_INFO_DEBUG( 0,logger_ERROR,"Error \"%s\" al intentar Abrir el puerto \"%s\"\n"\
                  , strerror(errnum),hdlTerminal->name);
      continue;
    }   
    LOGGER_ONLY_DEBUG( 0,logger_INFO,"Se pudo Abrir correctamente el puerto \"%s\"\n",hdlTerminal->name);
    
    /*-- Configuramos la velocidad, la trama y el control de flujo de la terminal */
    if(serialterminal_SetConfig(hdlTerminal,cfgTerminal->BaudRate,NULL,&errnum) == FALSE)
    {    
      LOGGER_INFO_DEBUG( 0,logger_ERROR,"Error \"%s\" al intentar configurar el puert \"%s\"\n"\
                  , strerror(errnum),hdlTerminal->name);
      continue;
    }
    LOGGER_ONLY_DEBUG( 0,logger_INFO,"Se Configuro correctamente el Puerto \"%s\"\n",hdlTerminal->name);
        
    /* Esperamos para consultar por el ID, en caso que sea la primera ves */
    sleep(2);  
    /*-- enviamos el query id al dispositivo conectado al puerto  */
    snprintf(boardTx,sizeof(boardTx),"%s",STRING_QUERY_ID);  
    LOGGER_INFO_DEBUG( 0,logger_INFO,"Enviando el String \"%s\", por el puerto\"%s\"\n"\
                , boardTx,hdlTerminal->name);
      
    /* el buffer de recepcion del dispoitivo se lleno, esperamos a que responda con el id */
    serialterminal_Transmit(hdlTerminal,boardTx,strlen(boardTx),'\r');
    retry = 0;
    do
    {    
      serialterminal_Receive(hdlTerminal,boardRx,sizeof(boardRx),'\r');
      LOGGER_INFO_DEBUG( 0,logger_INFO,"Se recibio el String \"%s\", desde el puerto \"%s\"\n"\
                  , boardRx,hdlTerminal->name);    
      
      if(strcmp(parglst->device,boardRx) == 0)
        return TRUE;      
      LOGGER_INFO_DEBUG( 0,logger_ERROR,"\tError Id Recibido: \n\t\"%s\"\n\t Se esperaba: \"%s\" \t reintentos: %d\n\n"\
                  , boardRx, parglst->device,retry);    
      stdctimer_msleep(725,NULL);
      
    }while(++retry < parglst->retryconn/*RETRY_GET_DEVICES_ID*/);
    
    logger_mprintf( 0,logger_ERROR,"Error con el Id Recibido \"%s\", reintentos %d agotados\n"\
               , boardRx, retry);
    /* FIXME Se abrio un puerto, lo debemos cerrar */
    if(serialterminal_ClosePort(hdlTerminal,TRUE,&errnum) == FALSE)
    {
      syslog(ERROR_INSERT_SYSLOG,"%s",strerror(errnum));    
      LOGGER_INFO_DEBUG( 0,logger_INFO,"Erro al intentar cerrar el puerto \"%s\"\n"\
                  ,hdlTerminal->name);
    }     
  }while(++i < parglst->maxportnumber);
  
  
  LOGGER_INFO_DEBUG( 0,logger_ERROR,"No se encontro un Puerto Disponible, %d enumeraciones realizadas\n",i);
  return FALSE;
#if 0  
  if(i == parglst->maxportnumber)
  {
    LOGGER_INFO_DEBUG( 0,logger_ERROR,"No se encontro un Puerto Disponible, %d enumeraciones realizadas\n",i);
    return FALSE;
  }
  
  

  return FALSE;   
#endif  
}

static bool_t terminal_update( serialterminal_hdl_t *hdlTerminal \
                             , macro_hdl_apis_t *hdlapis \
                             ,int *errMgs, uint8_t *errflag)
{
  char buff[1024];    
  /* buffer para mensaje de error */
  int errnum;

  LOGGER_ONLY_DEBUG(0,logger_INFO,"call stdcfile_CheckPathFile(%s).\n",hdlTerminal->name);
  /* Antes de pedir datos desde el puerto serie, debemos chequear si 
   * el puerto esta disponible.   */
  if(!stdcfile_CheckPathFile(hdlTerminal->name))
  {
    /* Se desconecto el dispositivo */
    if(errMgs != NULL)
      *errMgs = ENODEV;    
    /* Llamamos a notify si esta disponible para pasarle el mensaje */
    if(hdlapis->fn_notify != NULL)
      (hdlapis->fn_notify) ((void*) "Device was disconnected.\n",&errnum);
    
    if(errflag != NULL)
      *errflag = 1;
    
    LOGGER_INFO_DEBUG(0,logger_WARNING,"Device \"%s\" was disconnected.\n",hdlTerminal->name);
    return FALSE;
  }  
  /*
   * 
   * Pedimos los datos por puerto serie     
   * Leemos el puerto serie y sacamos los datos por consola  */
  memset(buff,'\0',sizeof(buff));
  serialterminal_Receive(hdlTerminal,buff,sizeof(buff),'\r');
  if(strlen(buff) == 0)
  {
    /*se reinicio el dispositivo, sin ueva enumeracion */
    LOGGER_INFO_DEBUG(0,logger_WARNING,"Se reinicio el Dispositivo., posible causa WDT\n");
    if(errflag != NULL)
      *errflag = 1;
    return FALSE;    
  }
    
  LOGGER_ONLY_DEBUG(0,logger_WARNING,"Se recibio \"%s\".\n",buff);
  /*-- llamamos a la funcion que se encarga de procesar los datos */
  if(hdlapis->fn_processdata == NULL)
  {
    /*-- Notificamos que no existe la apis */
    if(errflag != NULL)
      *errflag = 3;    
    return FALSE;
  }
  
  LOGGER_ONLY_DEBUG(0,logger_WARNING,"call (hdlapis->fn_processdata)().\n");
  if(!(hdlapis->fn_processdata)((void*) buff,&errnum))
  {
    LOGGER_INFO_DEBUG(0,logger_WARNING,"Fallo el call (hdlapis->fn_processdata)().\n");
    /* Fallo la escritura de datos al log */    
    if(errMgs != NULL)
      *errMgs = EBUSY;
    /* Llamamos a notify si esta disponible para pasarle el mensaje */
    if(hdlapis->fn_notify != NULL)
      (hdlapis->fn_notify) ((void*) "Failure in data Process.\n",&errnum);
    
    if(errflag != NULL)
      *errflag = 2;
    
    return FALSE;
  }
  /* No es necesario pero en caso de realizar un doble check desde quien llama */
  if(errflag != NULL)
    *errflag = 0;
  return TRUE;    
}

static bool_t terminal_deinit(serialterminal_hdl_t *hdlTerminal)
{

  int errnum;
  
  /*-- Restaurmaso y Cerramos la terminal */
  if(serialterminal_ClosePort(hdlTerminal,TRUE,&errnum) == FALSE)
  {
    syslog(ERROR_INSERT_SYSLOG,"%s",strerror(errnum));
    return FALSE; 
  }
  return TRUE;    
}
/**
 * \brief Callback function for handling signals.
 * \param sig identifier of signal
 */
static void handle_signal(int sig)
{
  /* FIXME: buscar la api para un flush() del syslog()
   * Ya que no muestra el mensaje, puede ser que cierra el log antes de 
   * hacer un dump del buffer.
   */
  if (sig == SIGTERM) 
  {
    LOGGER_INFO_DEBUG(0,logger_WARNING,"Señal %d capturada, STOP Signals", sig);   
    stop_daemon = 0;
  }
  else if (sig == SIGHUP)
  {    
    LOGGER_INFO_DEBUG(0,logger_WARNING,"Señal %d capturada, RELOAD Signals", sig);        
    stop_daemon = 0;
  } 
  else if (sig == SIGCHLD) 
  { 
    LOGGER_INFO_DEBUG(0,logger_WARNING,"Señal %d capturada, SIGCHLD Signals", sig);    
    stop_daemon = 0;
  }
}


bool_t argument_FillList(const char *str, argument_list_t *list, menu_t *pmenu)
{
  if(str == NULL || list == NULL || pmenu == NULL)
    return -1;
  
  static int item = 0;
  static bool_t flg = FALSE;

  
  while(pmenu->opt_short != NULL && flg == FALSE)
  {
    if((strcmp(pmenu->opt_short,str) == 0) || \
        (strcmp(pmenu->opt_long,str) == 0) )
    {
      item = pmenu->idx;
      flg = TRUE;
      return TRUE;
    }
    pmenu++;
  }
  /* no se localizo una opcion valida */
  if(pmenu->opt_short == NULL)
    return FALSE;
  
  switch(item)
  {
    default:
      break;
    case menu_INDEX_DEVICE:
      list->device = strdup(str);
      break;
    case menu_INDEX_PORT:      
      list->port = strdup(str);
      break;
      
    case menu_LOGGER_PATH:
      list->logger_path = strdup(str);
      break;      
      
    case menu_INDEX_BAUDRATE:
      list->baudrate = (uint32_t) strtol(str,NULL,10);
      break;    
      
    case menu_INDEX_MAX_PORTN:
      list->maxportnumber = (uint32_t) strtol(str,NULL,10);
      break;      
    case menu_INDEX_RETRY_CON:
      list->retryconn = (uint32_t) strtol(str,NULL,10);      
      break;      
    case menu_INDEX_TIMEOUT_DEV:
      list->timeoutdev = (uint32_t) strtol(str,NULL,10);
      break;
    case menu_INDEX_FAIL_PROCD:
      list->timeoutfailprocdata = (uint32_t) strtol(str,NULL,10);
      break;

  }  
  flg = FALSE;
  return TRUE;  
}

void argument_Check(argument_list_t *list)
{
  if(list == NULL)
    return;
  
  if( list->device == NULL )
    list->device = strdup(DEFAULT_DEVICE);
  
  if(list->port == NULL)
    list->port = DEFAULT_PORT;
  
  if(list->baudrate == 0)
    list->baudrate = DEFAULT_BAUDRATE;
  
  if(list->maxportnumber == 0)
    list->maxportnumber = DEFAULT_MAXPORTNUMBER;
  
#if (DEFAULT_RETRYCONN != 0)  
  if(list->retryconn == 0)
    list->retryconn = DEFAULT_RETRYCONN;
#endif
  
  if(list->timeoutdev == 0)
    list->timeoutdev = DEFAULT_TIMEOUTDEV;
  
  if(list->timeoutfailprocdata == 0)
    list->timeoutfailprocdata = DEFAULT_TIMEOUTFAILPROCDATA;  
}


void argument_FreeList(argument_list_t *list)
{
  if(list == NULL)
    return;
  
  if(list->device != NULL)
    free(list->device);
  
  if(list->port != NULL)
    free(list->port);
  
  if(list->logger_path != NULL)
    free(list->logger_path);  
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
│ ────────────────────────[ END   apis main version 01v00d02 ]─────────────────────── │
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

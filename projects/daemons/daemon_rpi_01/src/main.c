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
#include <stdc.h>

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

#if (version_QueryNumber(__main_version__,01v00d00)\
  && version_QueryNumber(__boards_apis_version__,01v00d00) )
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
  
  uint32_t i;    
  static uint8_t status; 
  
  /* Estas dos variables las podemos sacar y utilizar las reservadas 
   * ya que estas se liberan al finalizar el servicio
   */
  static serialterminal_hdl_t hdl_port;
  /*
    serialterminal_cfg_t cfg;
    cfg.BaudRate = TERMINAL_BAUD_RATE;
    cfg.Frame = 0;
    cfg.CtrlFlow = 0;  
  */
  static serialterminal_cfg_t cfg_port = { 
      .BaudRate = TERMINAL_BAUD_RATE, .Frame = 0\
    , .CtrlFlow = 0    
  };


  /* Contexto de las APIs de macro */
  static boards_apis_hdl_t hdl_apis;
  /* lsita de argumentos */
  static argument_list_t arg_list;
  /*-- Contexto para el logger */
  static logger_hdl_t hdl_logger;
  int errnumber; /*para el manejo de errores estandar*/
  uint32_t retryfailprocdata = 0;
  memset(&arg_list,0,sizeof(argument_list_t));
  
  /* definimos la estructura local para el analisis de los operandos pasados */
    static stdcmenu_getopt_t menu[] = {
     stdcmenu_FillRow("-d","--devices","%s",MSG_HELP_DEVICES,NULL,NULL)
    ,stdcmenu_FillRow("-p", "--port","%s",MSG_HELP_PORT,NULL,NULL)
    ,stdcmenu_FillRow("-b", "--baudrate","%u",MSG_HELP_BAUDRATE,NULL,NULL)
    ,stdcmenu_FillRow("-m", "--max_port_number","%u",MSG_HELP_MAXPORTNUMBER,NULL,NULL)
    ,stdcmenu_FillRow("-r","--retry_con_dev","%u",MSG_HELP_RETRYCONNDEV,NULL,NULL)
    ,stdcmenu_FillRow("-t","-timeout_dev","%u",MSG_HELP_TIMEOUTDEV,NULL,NULL)
    ,stdcmenu_FillRow("-f","--fail_proc_data","%u",MSG_HELP_FAILPROCDATA,NULL,NULL)
    ,stdcmenu_FillRow("-l","--logger_path","%s",MSG_HELP_LOGGERPATH,NULL,NULL)    
    ,stdcmenu_getopt_END /* marcamos el fin del menu */
    };    
    

  
  
  if( argc < 1)
    PERROR(EINVAL,FAILURE,"\tNo se pasaron Argumentos\n", argc);
    
  if(stdcmenu_FillMenuOpts(argc,argv,menu,1/* Descartamos argv[0] */) == FALSE)
  {
    PERROR(EINVAL,FAILURE,"\tLos parametros pasados son Incorrectos.\n");
    stdcmenu_PrintHelp(menu,stdout);  
    exit(EXIT_SUCCESS);  
  }
  
  stdcmenu_PrintStruct_getopt(menu,stdout,stdcmenu_PRINT_OPT);  
  stdcmenu_GetOperandByOptions("-d",menu,1,(void*) &arg_list.device);
  stdcmenu_GetOperandByOptions("-p",menu,1,(void*) &arg_list.port);
  stdcmenu_GetOperandByOptions("-l",menu,1,(void*) &arg_list.logger_path);  
  stdcmenu_GetOperandByOptions("-b",menu,1,(void*) &arg_list.baudrate);
  stdcmenu_GetOperandByOptions("-b",menu,1,(void*) &arg_list.baudrate);
  stdcmenu_GetOperandByOptions("-m",menu,1,(void*) &arg_list.maxportnumber);
  stdcmenu_GetOperandByOptions("-r",menu,1,(void*) &arg_list.retryconn);
  stdcmenu_GetOperandByOptions("-t",menu,1,(void*) &arg_list.timeoutdev);
  stdcmenu_GetOperandByOptions("-f",menu,1,(void*) &arg_list.timeoutfailprocdata); 
      
   
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
     
    
    
  if(stdcmenu_StatusOperandByOptions("-d",menu) < 1)
  {
    logger_mprintf(0,logger_WARNING,"No se localizo el argumento -d|--device."\
      " se toma por defecto \"%s\"\n",arg_list.device);
    DEBUG_PRINTF("No se localizo el argumento -d|--device."\
      " se toma por defecto \"%s\"\n",arg_list.device);
  }
    
    
  /* finalizamos el uso del menu, libreramos los recursos */
  stdcmenu_FreeMenuOpts(menu);
  
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
  if(strcmp(arg_list.device,"Board_01") == 0)
  {
    hdl_apis.fn_init = boards_apis_Board_01_Init;
    hdl_apis.fn_deinit = boards_apis_Board_01_Deinit;
    hdl_apis.fn_processdata = boards_apis_Board_01_ProcessData ;
    hdl_apis.fn_notify = boards_apis_Board_01_Notify;      
  }  
  else if(strcmp(arg_list.device,"Board_02") == 0)
  {
    hdl_apis.fn_init = boards_apis_Board_02_Init;
    hdl_apis.fn_deinit = boards_apis_Board_02_Deinit;
    hdl_apis.fn_processdata = boards_apis_Board_02_ProcessData ;
    hdl_apis.fn_notify = boards_apis_Board_02_Notify;    
  }
  else if(strcmp(arg_list.device,"Board_03") == 0)
  {
    hdl_apis.fn_init = boards_apis_Board_03_Init;
    hdl_apis.fn_deinit = boards_apis_Board_03_Deinit;
    hdl_apis.fn_processdata = boards_apis_Board_03_ProcessData ;
    hdl_apis.fn_notify = boards_apis_Board_03_Notify;    
  }
  else
  {     
    logger_mprintf(0,logger_ERROR,"Argumento -d|--device Invalido {Board_01|Board_02....}.\n");
    DEBUG_PRINTF("Argumento -d|--device \"%s\" Invalido {Board_01|Board_02....}.\n"\
      ,arg_list.device);
    /* Liberamos los recursos utilizados */
    argument_FreeList(&arg_list);  
    /*-- fin del programa */
    exit(EXIT_FAILURE);
  }
  
  logger_mprintf(0,logger_OK,"Librerias Cargadas para \"%s\"\n",arg_list.device);    
 
  do
  {
    daemonize((const char*) arg_list.device/*servicename*/);      
    
    signal(SIGINT,handle_signal);
    signal(SIGHUP,handle_signal);  
    
    syslog (LOG_NOTICE, "Daemon Iniciado.");  
    syslog (LOG_NOTICE,"[Log Daemon Path: \"%s\" | "\
            "port: \"%s\" | baudrate: %d |"\
            "library name: \"%s\" ]"                
          , arg_list.logger_path \
          , arg_list.port, arg_list.baudrate\
          ,arg_list.device);
    
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
  }
  while(0);  

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

}

static bool_t terminal_update( serialterminal_hdl_t *hdlTerminal \
                             , boards_apis_hdl_t *hdlapis \
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



void argument_Check(argument_list_t *list)
{
  if(list == NULL)
    return;
  
  if( list->device == NULL )
    list->device = strdup(DEFAULT_DEVICE);
  
  if(list->port == NULL)
    list->port = DEFAULT_PORT;
  
  if(list->logger_path == NULL)
  {
    char buff[256];
    snprintf(buff,sizeof(buff),"%s/DaemonLog_%s" \
      ,getenv("HOME"), list->device);
    list->logger_path = strdup(buff);
  }
  
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
#elif (version_QueryNumber(__main_version__,01v00d01) \
  && version_QueryNumber(__boards_apis_version__,01v00d01) )
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
  
  uint32_t i;    
  static uint8_t status; 
  

  static serialterminal_hdl_t hdl_port;
  /*
    serialterminal_cfg_t cfg;
    cfg.BaudRate = TERMINAL_BAUD_RATE;
    cfg.Frame = 0;
    cfg.CtrlFlow = 0;  
  */
  static serialterminal_cfg_t cfg_port = {.BaudRate = TERMINAL_BAUD_RATE, .Frame = 0, .CtrlFlow = 0};
  /* Contexto de las APIs de macro */
  static boards_apis_hdl_t hdl_apis;
  /* lsita de argumentos */
  static argument_list_t arg_list;
  /*-- Contexto para el logger */
  static logger_hdl_t hdl_logger;
  int errnumber; /*para el manejo de errores estandar*/
  uint32_t retryfailprocdata = 0;  
  memset(&arg_list,0,sizeof(argument_list_t));
  
  /* definimos la estructura local para el analisis de los operandos pasados */
    static stdcmenu_getopt_t menu[] = {
     stdcmenu_FillRowId("-d","--devices","%s",MSG_HELP_DEVICES\
      ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_INDEX_DEVICE)
    ,stdcmenu_FillRowId("-p", "--port","%s",MSG_HELP_PORT\
      ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_INDEX_PORT)
    ,stdcmenu_FillRowId("-b", "--baudrate","%u",MSG_HELP_BAUDRATE\
      ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_INDEX_BAUDRATE)
    ,stdcmenu_FillRowId("-m", "--max_port_number","%u",MSG_HELP_MAXPORTNUMBER\
      ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_INDEX_MAX_PORTN)
    ,stdcmenu_FillRowId("-r","--retry_con_dev","%u",MSG_HELP_RETRYCONNDEV\
      ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_INDEX_RETRY_CON)
    ,stdcmenu_FillRowId("-t","-timeout_dev","%u",MSG_HELP_TIMEOUTDEV\
      ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_INDEX_TIMEOUT_DEV)
    ,stdcmenu_FillRowId("-f","--fail_proc_data","%u",MSG_HELP_FAILPROCDATA\
      ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_INDEX_FAIL_PROCD)
    ,stdcmenu_FillRowId("-l","--logger_path","%s",MSG_HELP_LOGGERPATH\
      ,argument_FillList,CAST_VOID(STRUCT2PPVOID,arg_list),menu_LOGGER_PATH)
    ,stdcmenu_getopt_END /* marcamos el fin del menu */
    };    
    

  
  
  if( argc < 1)
    PERROR(EINVAL,FAILURE,"\tNo se pasaron Argumentos\n", argc);
    
  if(stdcmenu_FillMenuOpts(argc,argv,menu,1/* Descartamos argv[0] */) == FALSE)
  {
    PERROR(EINVAL,FAILURE,"\tLos parametros pasados son Incorrectos.\n");
    stdcmenu_PrintHelp(menu,stdout);  
    exit(EXIT_SUCCESS);  
  }
  
  stdcmenu_Print(menu,stdout,stdcmenu_PRINT_OPT);  
  /* liberamos los recursos usados para el menu */
//   stdcmenu_FreeMenuOpts(menu);

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
  
  if(stdcmenu_StatusOperandByOptions("-d",menu) < 1)
    logger_mprintf(0,logger_WARNING,"No se localizo el argumento -d|--device."\
      " se toma por defecto \"%s\"\n",arg_list.device);
    
  /* finalizamos el uso del menu, libreramos los recursos */
  stdcmenu_FreeMenuOpts(menu);
  
  /*-- */
  if(boards_apis_menu_FillHandler(arg_list.device,&hdl_apis) == FALSE)
  {
    logger_mprintf(0,logger_ERROR,"Argumento -d|--device Invalido {Board_01|Board_02....}.\n");
    DEBUG_PRINTF("Argumento -d|--device \"%s\" Invalido {Board_01|Board_02....}.\n"\
      ,arg_list.device);
    /* Liberamos los recursos utilizados */
    argument_FreeList(&arg_list);  
    /*-- fin del programa */
    exit(EXIT_FAILURE);    
  }
    
  do
  {   
    logger_mprintf(0,logger_OK,"Librerias Cargadas para \"%s\"\n",arg_list.device);   
    
    /*
    * BEGIN CRACION DEL SERVICIO 
    */   
    daemonize((const char*) arg_list.device/*servicename*/);      
    
    signal(SIGINT,handle_signal);
    signal(SIGHUP,handle_signal);  
    /*Informamos mediante el log del sistema los parametros importantes */
    syslog (LOG_NOTICE, "Daemon Iniciado.");      
    syslog (LOG_NOTICE,"[Log Daemon Path: \"%s\" | "\
                "port: \"%s\" | baudrate: %d |"\
                "library name: \"%s\" ]"                
              , arg_list.logger_path \
              , arg_list.port, arg_list.baudrate\
              ,arg_list.device);
    
    logger_mprintf(0,logger_OK,"Daemon \"%s\" Iniciado.\n",arg_list.device/*servicename*/); 
    /*
    * END CREACION DEL SERVICIO, dentro del servicio 
    * 
    */
    
    /* Iniciamos la aplicacion llamando a la API correspondiente:  
     *       macro_{TempBoard|OtherBoard}_Init();
     *    */
    if( (hdl_apis.fn_init != NULL) && ((hdl_apis.fn_init)(&hdl_apis) == FALSE))
    {
      syslog(LOG_ERR,"%s",strerror(hdl_apis.errnum));
      logger_mprintf( 0,logger_ERROR,"Error \"%s\" al intentar ejecutar fn_init() de la libreria\n"\
                   , strerror(hdl_apis.errnum));
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
    if(!(hdl_apis.fn_deinit)(&hdl_apis))
      LOGGER_INFO_DEBUG(0,logger_ERROR,"Error \"%s\" Al ejecutar fn_deinit() de librerias.\n"\
        ,strerror(hdl_apis.errnum));      
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
}

static bool_t terminal_update( serialterminal_hdl_t *hdlTerminal \
                             , boards_apis_hdl_t *hdlapis \
                             ,int *errMgs, uint8_t *errflag)
{
  char buff[1024];    
  /* buffer para mensaje de error */
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
      (hdlapis->fn_notify) (hdlapis,(void*) "Device was disconnected.\n");
    
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
  if(!(hdlapis->fn_processdata)(hdlapis,(void*) buff))
  {
    LOGGER_INFO_DEBUG(0,logger_WARNING,"Fallo el call (hdlapis->fn_processdata)().\n");
    /* Fallo la escritura de datos al log */    
    if(errMgs != NULL)
      *errMgs = EBUSY;
    /* Llamamos a notify si esta disponible para pasarle el mensaje */
    if(hdlapis->fn_notify != NULL)
      (hdlapis->fn_notify) (hdlapis,(void*) "Failure in data Process.\n");
    
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


void argument_FillList(stdcmenu_getopt_t *arg)
{
  stdcmenu_AssertCallback(Rval,arg);
  argument_list_t *list = stdcmenu_GetRvalInCallback(arg, argument_list_t* );
  /* analizamos la precedencia del callback */
  switch(arg->id)
  {
    default:
      break;
    case menu_INDEX_DEVICE:
      stdcmenu_GetOperand(arg,1,&list->device);
      break;
      
    case menu_INDEX_PORT:      
      stdcmenu_GetOperand(arg,1,&list->port);
      break;
      
    case menu_LOGGER_PATH:
      stdcmenu_GetOperand(arg,1,&list->logger_path);
      break;      
      
    case menu_INDEX_BAUDRATE:      
      stdcmenu_GetOperand(arg,1,&list->baudrate);      
      break;    
      
    case menu_INDEX_MAX_PORTN:
      stdcmenu_GetOperand(arg,1,&list->maxportnumber);
      break;      
      
    case menu_INDEX_RETRY_CON:
      stdcmenu_GetOperand(arg,1,&list->retryconn);
      break;      
      
    case menu_INDEX_TIMEOUT_DEV:
      stdcmenu_GetOperand(arg,1,&list->timeoutdev);
      break;
      
    case menu_INDEX_FAIL_PROCD:
      stdcmenu_GetOperand(arg,1,&list->timeoutfailprocdata);      
      break;
  }  
  
}

void argument_Check(argument_list_t *list)
{
  if(list == NULL)
    return;
  
  if( list->device == NULL )
    list->device = strdup(DEFAULT_DEVICE);
  
  if(list->port == NULL)
    list->port = strdup(DEFAULT_PORT);
  
  if(list->logger_path == NULL)
  {
    char buff[256];
    snprintf(buff,sizeof(buff),"%s/DaemonLog_%s" \
      ,getenv("HOME"), list->device);
    list->logger_path = strdup(buff);
  }
      
  
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

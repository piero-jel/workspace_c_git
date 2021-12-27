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
#include <stdc.h>


#include <main.h>



#ifndef __main_version__
#define __main_version__        version_SetNumber(01v00d00)
#endif

/**
 * version 01v0d0 -> socket de flujo Cliente/Servidor recibe datos y los muestra
 * version 01v0d1 -> socket de flujo Cliente/Servidor Trasmite Datos desde Archivo y espera un mensage 
 * version 01v0d2 -> Version 01v0d1 con log opcional
 * version 01v0d3 -> Version 01v0d2 con help, truncated log opcional, enable/disable send EOF
 * version 01v0d4 -> TODO: actual Vesrion 01v0d3 con la opcion de directory sort options {date (fecha de modificacion o creacion)| alpha (ordena alfabetico)}
 * version 01v0d5 -> XXX: se despalaza Vesrion 01v0d4 con el agregado del simetrico, {recv -> send} o {send -> recv}
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
  /* FIXME argc siempre sera mayor a cero */
  if(argc <= 1)
  {
    CPRINTF(BLUE,"\tNo se pasaron Argumentos, intente con los siguentes:\n");
    stdcmenu_PrintHelp(menu,stdout);
    exit(EXIT_SUCCESS);
  }
    

  if(stdcmenu_FillMenuOpts(argc,argv,menu,1/* Descartamos argv[0] */) == FALSE)
  {
    PERROR(0,NONE,"Los parametros pasados son Incorrectos.\n");
    CPRINTF(BLUE,"Listado de Arg permitidos:\n");
    stdcmenu_PrintHelp(menu,stdout);
    exit(EXIT_SUCCESS);
  }

  arg_sT arg = {0};
  

  /* Imprimimos la los parametros parceados en la variable menu */
  //stdcmenu_PrintStruct_getopt(menu,stdout,stdcmenu_PRINT_OPT);  
  /* obtenemos parametros por parametros
   *  + Opcion "-d"
   *  + La variable donde se parceo los arguemtnos 'menu' 
   *  + La Posicion dentro de la cantidad de Argumento correspondiente a la opcion '1'
   *    Si esperamos dos para un argumeto este se debe intera indicando la posicion 
   *    dentro del formato
   *  + Donde almacenaremos el parametro
  */
  char *streofen = NULL;
  char *logtruncated = NULL;
  char trncatedlog[16];
  stdcmenu_GetOperandByOptions("-t",menu,1,(void*) &arg.type);
  stdcmenu_GetOperandByOptions("-i",menu,1,(void*) &arg.ip);
  stdcmenu_GetOperandByOptions("-p",menu,1,(void*) &arg.port);  
  stdcmenu_GetOperandByOptions("-r",menu,1,(void*) &arg.retry);  
  stdcmenu_GetOperandByOptions("--path",menu,1,(void*) &arg.pathname);
  stdcmenu_GetOperandByOptions("-f",menu,1,(void*) &arg.format);
  stdcmenu_GetOperandByOptions("-l",menu,1,(void*) &arg.logpath);
  stdcmenu_GetOperandByOptions("-l",menu,2,(void*) &logtruncated);
  stdcmenu_GetOperandByOptions("--eof",menu,1,(void*) &streofen);
  stdcmenu_GetOperandByOptions("-d",menu,1,(void*) &arg.pathdir);
  
  /* Almacenamos y liberamos las variables fuera de la estructura de 
   * argumentos, como el states de send eof para los archivos y logtruncated */
  if(streofen != NULL)    
  {
    if(strcmp(streofen,OPTIONS(EOF,0)/*"yes"*/)== 0 || strcmp(streofen,OPTIONS(EOF,1)/*"y"*/) == 0)
    {
      arg.sendeof = TRUE;
    }
    else
    {
      arg.sendeof = FALSE;
    }
    free(streofen);
  }
  else
  {
    arg.sendeof = FALSE;
  }    

  if(logtruncated != NULL)    
  {
    if(strcmp(logtruncated,OPTIONS(LOG,0)/*"trun"*/)== 0 || strcmp(logtruncated,OPTIONS(LOG,1)/*"truncate"*/) == 0)
    {
      snprintf(trncatedlog,sizeof(trncatedlog),"w+");
    }
    else
    {
      snprintf(trncatedlog,sizeof(trncatedlog),"a+");
    }
    free(logtruncated);
  }
  else
  {
    snprintf(trncatedlog,sizeof(trncatedlog),"a+");
  }
    
  


  /*=====[logger]=====*/
  /*-- Contexto para el logger */
  static logger_hdl_t hdl_logger;
  int errnumber;

  do{
    /*
    * Creamos el contexto para el logger 
    * FIXME Nos falta cargar el arguetno "-l log-path"
    */
    if(!logger_init(&errnumber,&hdl_logger,1,arg.logpath /* path */,trncatedlog /*mode */))
    {
      /* No se pudo crear el contexto para el logger */
      logger_deinit();
      PERROR(errnumber, FAILURE,"\tError \"%s\" al intentar crear el contexto de logger\n"\
        , strerror(errnumber));      
    }    

    logger_mprintf(MAIN_LOG,logger_INFO,"Logger adjuntado\n");
    logger_mprintf(MAIN_LOG,logger_INFO,"Listado de Argumentos Pasados:\n");
    if(!stdcmenu_Print(menu,logger_getfile(&errnumber,0),stdcmenu_PRINT_OPT))
    {
      logger_merror(MAIN_LOG,errnumber,"Error al intentar obtener el FD del Socket socket()\n");
      break;
    }
    /* Salvado todos los parametros, liberamos la estructura, 
    * Recordar liberar los %s   */  
    stdcmenu_FreeMenuOpts(menu);

  
    /*===========[ Chequeamos los parametros pasados ]===========*/  
    /* Consultamos si el type es cliente y de no serlo saltamos la ejecucion */
    if(arg.type == NULL )
    {
      arg.type = strdup(OPTIONS(TYPE,0)/*"client"*/);
    }
    else if((strcmp(arg.type,OPTIONS(TYPE,0)/*"client"*/) && strcmp(arg.type,OPTIONS(TYPE,1)/*"server"*/)))
    {      
      logger_mprintf(MAIN_LOG,logger_ERROR,"Modo '%s' no Soportado\n",arg.type);
      break;     
    }    
      

    if(arg.ip == NULL && strcmp(arg.type,OPTIONS(TYPE,0)/*"client"*/) == 0 )
    {
      logger_mprintf(MAIN_LOG,logger_ERROR,"No se paso la direccion IP entre los Argumentos\n");
      break;
    }
      
    
    if(arg.port == 0 )
    {
      logger_mprintf(MAIN_LOG,logger_ERROR,"El numero de puerto (%d) pasado no corresponde.\n"\
        , arg.port);
      break;
    }
    
    /** FIXME: debemos crear una sola API para chec path para file/dir y others*/
    /* check del pathfile */
    if(arg.pathname != NULL && stdcfile_checkpath(arg.pathname,stdcfile_CHECK_FILE) == FALSE)
    {
      logger_merror(MAIN_LOG,EINVAL,"La ruta especificada '%s' para el Archivo a enviar"\
        " no es valida.\n",arg.pathname);
      break;
    }
    
    /* check del pathdir */
    if(arg.pathdir != NULL && stdcfile_checkpath(arg.pathdir,stdcfile_CHECK_DIR) == FALSE)
    {
      logger_merror(MAIN_LOG,0,"La ruta especificada '%s' para el Directorio de Archivos"\
        " a enviar no es valida.\n",arg.pathdir);
      break;
    }
    
    
    /* chequemos primero si se paso un path de archivo o un parh de directoios */
    if(arg.pathname == NULL && arg.pathdir == NULL)
    {
      logger_merror(MAIN_LOG,EINVAL,"No se Especifico un Archivo o Directorio valido, para el envio.\n");
      break;
    }
    /* De aqui en adelante si 
     *  arg.pathname != NULL
     *  arg.pathdir != NULL)
     * los path son validos, estos serian los Flags de query
     */
      
     
    if(arg.format == NULL )
    {
      arg.convert = DEFAULT_FORMAT;
    }
    else
    {
      if(strcmp(arg.format,OPTIONS(FORMAT,1)/*"hexchar"*/) && strcmp(arg.format,OPTIONS(FORMAT,0)/*"binary"*/) )
      {
        logger_mprintf(MAIN_LOG,logger_ERROR,"Formato de codificacion/decodificacion No soportado\n"\
          , arg.format);
        // logger_merror(MAIN_LOG,EINVAL,"Formato de codificacion/decodificacion No soportado\n", arg.format);
        break;
        // PERROR(EINVAL,FAILURE,"\t Formato No soportado\n", arg.format);
      }        
      if(strcmp(arg.format,OPTIONS(FORMAT,0)/*"binary"*/) == 0 )
        arg.convert = TRUE;
      else 
      arg.convert = FALSE;        
    }

    /* por defecto, tambien lo podemos pasar desde operandos */
    arg.timeretry = DEFAULT_TIME_RETRY;
    /*===========[]===========*/
    bool_t rstate;
    if(strcmp(arg.type,OPTIONS(TYPE,0)/*"client"*/) == 0)
    {
      cliente_connect(&arg,NULL,&rstate);
    }    
    else /* if(strcmp(arg.type,"server") == 0) */
    {
      arg.srvbacklog = DEFAULT_SRV_BACKLOG;
      server_connect(&arg,NULL,&rstate);
    }
    
  /* loop null */
  }while(0);

  logger_mprintf(MAIN_LOG,logger_INFO,"fin del programa...\n\n");
  /*-- Liberamos la memoria ocupada para obtener el arguemnto IP y el tipo */
  logger_deinit();
  free_arg_sT(&arg);  
  // printf("fin del programa...\n\n");
  exit(EXIT_SUCCESS);
}



/** 
 * \fn void help(stdcmenu_getopt_t*arg)
 * \brief funcion calback para imprimir mensaje de error
 * \param arg estructura del tipo \b stdcmenu_getopt_t con todas las
 * opciones disponibles.
 * \return nothing
*/
void help(stdcmenu_getopt_t*arg)
{
  stdcmenu_PrintHelp(menu,stdout);

  exit(EXIT_SUCCESS);
}

/** 
 * \fn bool_t cliente_connect( arg_sT *parg, transfer_pfT pfn, bool_t *state )
 * \brief
 * \param
 * \return 
*/
bool_t cliente_connect( arg_sT *parg, transfer_pfT pfn, bool_t *state )
{
  if(/*pfn == NULL ||*/ parg == NULL) 
  {
    RETURN_STATE(FALSE,state);    
  }

  uint32_t arg_retry = parg->retry;

  int fd ;
  /* estructura que recibirá información sobre el nodo remoto */
  struct hostent *remote_host;         
   
  /* información sobre la dirección del servidor */
  struct sockaddr_in server;   

  remote_host = gethostbyname(parg->ip);
  logger_mprintf(MAIN_LOG,logger_INFO,"Exec gethostbyname(%s);\n",parg->ip);
  if(remote_host == NULL)
  {       
    /* llamada a gethostbyname() */
    logger_merror(MAIN_LOG,errno,"'%s' Error al intentar obtener el"\
      " host gethostbyname(%s)\n",parg->ip);    
    RETURN_STATE(FALSE,state);    
  }
  logger_mprintf(MAIN_LOG,logger_INFO,"Exec socket(AF_INET, SOCK_STREAM, 0);\n");
  fd = socket(AF_INET, SOCK_STREAM, 0);
  if ( fd < 0 )
  {     
    logger_merror(MAIN_LOG,errno,"Error al intentar obtener el FD del Socket socket()\n");
    RETURN_STATE(FALSE,state);    
  }

  server.sin_family = AF_INET;
  server.sin_port = htons(parg->port);   
  server.sin_addr = *((struct in_addr *) remote_host->h_addr);  
  bzero(&(server.sin_zero),8);



  uint32_t i = 0;
  logger_mprintf(MAIN_LOG,logger_INFO,"Loop '%d' \t connect();\n",arg_retry);
  while(connect(fd, (struct sockaddr *)&server, sizeof(struct sockaddr)) < 0 )
  { 
    if(arg_retry-- == 0)
    {      
      logger_mprintf(MAIN_LOG,logger_ERROR,"Reintentos Agotados para Conectar con %s:%d\n",\
        parg->ip,parg->port);      
      RETURN_STATE(FALSE,state);          
    }  
    
    logger_mprintf(MAIN_LOG,logger_WARNING,"Reintento %d para Conectar con %s:%d, esperamos %d [s]\n",\
      i,parg->ip,parg->port,(parg->timeretry/1000));

    stdctimer_msleep(parg->timeretry,state);
    i++;    
  }

  
  /* Iniciamos la transferencia */    
  bool_t rval = FALSE,rstate=FALSE;
  do{
    
    if(parg->pathname != NULL)
    {
      logger_mprintf(0,logger_INFO,"Send File '%s'\n",parg->pathname);
      rval = sendbysocket_file(fd,parg->pathname,parg,&rstate);
      if(!rval)
        break;  
    }
    if(parg->pathdir != NULL)
    {
      uint32_t nfile;      
      stdcfile_list_t *list = stdcfile_listregdir(parg->pathdir,"txt");
      for(nfile=0; nfile<list->nitem;nfile++)
      {
        logger_mprintf(0,logger_INFO,"Send File '%s'\n",list->vitem[nfile].path);
        rval = sendbysocket_file(fd,list->vitem[nfile].path,parg,&rstate);
        if(rval == FALSE)
          break;  
      }
      stdcfile_freelist(list);
      if(rval == FALSE)
        break;  
    }
    

    rval = recvbysocket_msg(fd,parg,&rstate);    
    if(rval && !rstate)
    {
      shutdown(fd, SHUT_RDWR);      
      break;
    }    
  }while(0);

  /* muestra el mensaje de bienvenida del servidor =) */
  close(fd);   /* cerramos fd =) */
  return rval;
}

/** 
 * \fn
 * \brief
 * \param
 * \return 
*/
bool_t server_connect( arg_sT *parg, transfer_pfT pfn, bool_t *state )
{
  if(/*pfn == NULL ||*/ parg == NULL) 
  {
    RETURN_STATE(FALSE,state);
  }

  int fd, fd2; 
  /* socket addres para el server */
  struct sockaddr_in server; 
  /* socket addres para el cliente */
  struct sockaddr_in client; 
   
  int sin_size;
  int option = 1;
   /* A continuación la llamada a socket() */
  fd = socket(AF_INET, SOCK_STREAM, 0);
  /* para que el socket este disponible de forma inmediata al cerrarse la comunicacion */
  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
  if( fd < 0 ) 
  {  
    logger_merror(MAIN_LOG,errno,"error en socket()\n");
    RETURN_STATE(FALSE,state);
  }

  server.sin_family = AF_INET;
  /* host to network */
  server.sin_port = htons(parg->port); 
  /* Tomamos la direccion IP por defecto del Host, de forma automatica */
  server.sin_addr.s_addr = INADDR_ANY;    
  bzero(&(server.sin_zero),8); // set struct
  /* A continuación la llamada a bind() */
  if( bind(fd,(struct sockaddr*)& server, sizeof(struct sockaddr)) < 0 ) 
  {    
    logger_merror(MAIN_LOG,errno,"error en bind()\n");
    close(fd);
    RETURN_STATE(FALSE,state);
  }     

  if(listen(fd,parg->srvbacklog) < 0)
  {
    /* llamada a listen() */
    logger_merror(MAIN_LOG,errno,"error en listen()\n");    
    close(fd);
    RETURN_STATE(FALSE,state);
  }
  /*-- Mostramos la informacion respecto al server 
   * ip=inet_ntoa(dest.sin_addr);
   Esto debemos sacarlo por log
  */    
  logger_mprintf(0,logger_INFO,"A la espera de conexion. \tServer IP: %s : %d\n"\
    , inet_ntoa(server.sin_addr),ntohs(server.sin_port));


  sin_size = sizeof(struct sockaddr_in);
  /* A continuación la llamada a accept()
   * int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
   */
  fd2 = accept(fd,(struct sockaddr *) &client,(socklen_t*) &sin_size);
  if( fd2 < 0 ) 
  {
    logger_merror(MAIN_LOG,errno,"error en accept()\n");
    close(fd);
    RETURN_STATE(FALSE,state);
  }

  /* Imprimimos la direccion del cliente conectado 
   * Debemos colocarlo en un log   */
  logger_mprintf(0,logger_INFO,"Se obtuvo una conexión desde %s\n" \
    ,inet_ntoa(client.sin_addr) );    
  
  /* Iniciamos la transferencia */    
  bool_t rval = FALSE,rstate=FALSE;
  do{
    
    if(parg->pathname != NULL)
    {
      logger_mprintf(0,logger_INFO,"Send File '%s'\n",parg->pathname);
      rval = sendbysocket_file(fd2,parg->pathname,parg,&rstate);
      if(!rval)
        break;  
    }
    if(parg->pathdir != NULL)
    {
      uint32_t nfile;
      //bool_t state = FALSE;
      stdcfile_list_t *list = stdcfile_listregdir(parg->pathdir,"txt");
      for(nfile=0; nfile<list->nitem;nfile++)
      {
        logger_mprintf(0,logger_INFO,"Send File '%s'\n",list->vitem[nfile].path);
        rval = sendbysocket_file(fd2,list->vitem[nfile].path,parg,&rstate);
        if(rval == FALSE)
          break;  
      }
      stdcfile_freelist(list);
      if(rval == FALSE)
        break;  
    }
    

    rval = recvbysocket_msg(fd2,parg,&rstate);    
    if(rval && !rstate)
    {
      shutdown(fd, SHUT_RDWR);      
      break;
    }    
  }while(0);
  

  close(fd2); /* cierra fd2 */  
  close(fd); /* cierra fd2 */  
  return rval;  
}



/** 
 * \fn bool_t sendbysocket_file(int fd,arg_sT *parg, bool_t *state);
 * \brief Funcion para el envio de un archivo mediante un socket.
 * \param fd    : Descriptro de archivo del Socket
 * \param parg  : Puntero a la estructura con el Listado de Argumentos necesarios para 
 * la operacion.
 * \param state : puntero a donde almacenaremos el state de la operacion.
 * \return Estado de la operacion desde el host.
 *  \li TRUE    success
 *  \li FALSE   failure
*/

  /* Este envia el archivo o los Archivos segun el contenido del listado de ARGumentos
   * 
   * Que parametros necesito:
   *  >> parg->pathname
   *  >> parg->sendeof
   *  >> parg->convert
   */
  
bool_t sendbysocket_file(int fd,const char *pathname,arg_sT *parg, bool_t *state)
{
  if (parg == NULL )
  {
    // PERROR(EINVAL,NONE,"\tError con los Argumentos Pasados\n");
    logger_merror(MAIN_LOG,EINVAL,"Error con los Argumentos Pasados\n");
    RETURN_STATE(FALSE,state);
  }

  int src_file; 
  char buff[DEFAULT_BUFF_LEN];
  int32_t len_read = 0, numbytes;
  uint32_t acu = 0;
  uint32_t i = 0, len = 0; 
  
  /* abrimos el archivo */
  src_file = open(pathname,O_RDONLY);
  if (src_file < 0 )
  {    
    logger_merror(MAIN_LOG,errno,"\tError al Intentar abrir el archivo '%s'\n"\
      ,pathname);
    RETURN_STATE(FALSE,state);
  }
    
  do
  {
    bzero(buff,sizeof(buff));

    len_read = read(src_file,&buff[2],(sizeof(buff)-2));
    if(len_read < 0 )
    {
      close(src_file); 
      logger_merror(MAIN_LOG,errno,"Error al leer el archivo '%s'\n"\
        ,pathname);
      RETURN_STATE(FALSE,state);     
    }
    if(len_read == 0 )
    {     
      /* EOF del Archivo */
      break;
    }
    


    if(parg->convert)
    {
      char tmpbuff[DEFAULT_BUFF_LEN] = {0};
      uint32_t lbuff = sizeof(buff);      
      memcpy(tmpbuff,buff,DEFAULT_BUFF_LEN);
      bzero(buff,sizeof(buff));
      stdc_hexascii2hex(&tmpbuff[2], len_read,&buff[2],&lbuff);      
      len_read = lbuff;
    }

    stdc_number2bytes(len_read,&buff[0],&buff[1]);

    numbytes = 0, acu = 0;
    i = 0, len = len_read + 2;
    do{      
      numbytes = send(fd, (const void*) &buff[i],len,0);      
      if(numbytes < 0)
      {  
        /* llamada a send() */
        logger_merror(MAIN_LOG,errno,"Error al Enviar informacion send()\n");
        close(src_file);
        RETURN_STATE(FALSE,state);
      }
      acu += numbytes;
      if( numbytes == len)
      {
        
        logger_mprintf(0,logger_INFO,"Numero de Bytes Enviados: %d\n",acu); 
        break;
      }
      /* calculamos la longitud remanente */
      i = numbytes;
      if(numbytes > len) 
      {
        logger_merror(MAIN_LOG,0,"Error Bytes enviados superan a la longitud del buffer: %u > %u\n"\
          ,numbytes,len);
        close(src_file);     
        RETURN_STATE(FALSE,state);
      }
      len -= numbytes;
    }while(len);

  }while(len_read > 0);

  if(parg->sendeof && len_read == 0)
  {     
    logger_mprintf(0,logger_INFO,"Enviando EOF del Archivo.\n");        
    buff[0] = 0;
    buff[1] = 1;
    buff[2] = '\0';    
    numbytes = send(fd, (const void*) &buff[i],3,0);
    if(numbytes != 3) 
    {
      logger_merror(MAIN_LOG,0,"Error al intentar enviar el EOF\n");
      close(src_file);
      RETURN_STATE(FALSE,state);
    }
  }
  

  /* cerramos el archivo */
  close(src_file);
  RETURN_STATE(TRUE,state);
}


/** 
 * \fn bool_t recvbysocket_msg(int fd,arg_sT *parg, bool_t *state);
 * \brief Funcion para la recepcion de un mensaje mediante un socket. Esto implica
 * que el mismo se imprimira por pantalla o en un log.
 * \param fd    : Descriptro de archivo del Socket
 * \param parg  : Puntero a la estructura con el Listado de Argumentos necesarios para 
 * la operacion.
 * \param state : puntero a donde almacenaremos el state de la operacion (en la mayoria de 
 * los casos relacionados al remote).
 * \return Estado de la operacion desde el host.
 *  \li TRUE    success
 *  \li FALSE   failure
*/
bool_t recvbysocket_msg(int fd,arg_sT *parg, bool_t *state)
{
  if (parg == NULL )
  {
    logger_merror(MAIN_LOG,EINVAL,"Error con los Argumentos Pasados\n");    
    RETURN_STATE(FALSE,state);
  }

  char buff[DEFAULT_BUFF_LEN]; 
  char buffexpand[DEFAULT_BUFF_LEN<<1]; 
  int32_t numbytes = 0;
  uint32_t arvbytes = 0;
  int32_t lenread = 0;
  size_t remainder;
  do
  {  
    /* obtenemos el numero de bytes arrivado */
    int rcvlen=0;
    if((rcvlen = read(fd,buff,2)) != 2)
    {
      /* hacemos un pull del socket remoto para saver si lo debemos cerrar */
      struct pollfd ufds[1];
      ufds[0].fd = fd;
      ufds[0].events = POLLRDHUP;
      /* No esta activo el FD del socket */          
      if(poll(ufds, 1, 0))
      {
        /* Tenemos el FD activo */
        if (ufds[0].revents & POLLRDHUP /*|| ufds[1].revents & POLLRDHUP */)
        {
          logger_mprintf(0,logger_WARNING,"Se cerro el socket desde el punto remoto\n");
          RETURN_STATE(NONE,TRUE,state,FALSE);
        }
        logger_mprintf(0,logger_INFO, "\t Pull() => 'revents = 0x%X  remoto', revents = 0x%X  local'\n"\
          ,ufds[0].revents,ufds[1].revents);
   
        RETURN_STATE(NONE,TRUE,state,FALSE);       
      }                  
      RETURN_STATE(TRUE,state);
     
      /* llamada a recv() */

      logger_merror(MAIN_LOG,0,"No se pudo obtener la longitud del mensaje.\n");

      logger_mprintf(0,logger_WARNING,"\t Longitud %d \t Contenido del Buffer = '%s' \n"\
        ,rcvlen,buff);

      RETURN_STATE(FALSE,state);
    }
    arvbytes = 0;
    stdc_bytes2number(&buff[0],&buff[1],(int32_t*) &arvbytes);
    logger_mprintf(0,logger_INFO,"El numero de Bytes Esperados es %u:%u = %u \n"\
      ,(uint8_t) buff[0],(uint8_t) buff[1],arvbytes);

        
    numbytes = 0;
    remainder = arvbytes ;
    do{      
      lenread = recv(fd,buff\
        ,(remainder>sizeof(buff))?sizeof(buff):remainder\
        ,0);
      if(lenread < 0)
      {  
        /* llamada a recv() */        
        logger_merror(MAIN_LOG,EINVAL,"Error al recibir informacion recv()\n");
        RETURN_STATE(FALSE,state);
      }
      if(lenread == 0)
      {
        /*FIXME, no tenemos datos desde el socket 
         * debemos considerar si se cerro el socket o fallo la conexion de el
        */
        break;
      }
      numbytes += lenread;
      remainder -= lenread;
      
      logger_mprintf(0,logger_INFO,"Mensaje, de longitud %d, Arribado:\n",lenread);
      /* FIXME add para ver el dato codificado en binario */
      if(parg->convert)
      {
        logger_mprintf(0,logger_INFO,"Convertimos la cadena a formato ASCII\n");
        uint32_t lbuffexpand = sizeof(buffexpand);
        stdc_hex2hexascii(buff,lenread, buffexpand,&lbuffexpand);      
        buffexpand[lbuffexpand]='\0';
        logger_mprintf(0,logger_RAW,"%s\n",buffexpand);
      
      }
      else
      {
        buff[lenread]='\0';
        logger_mprintf(0,logger_RAW,"%s\n",buff);
      }
    
    }while(remainder /*numbytes < arvbytes && lenread */);

  } while(buff[0]!='\0' || arvbytes != 1); /* EOF */

  RETURN_STATE(TRUE,state);
}




/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* ========================================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

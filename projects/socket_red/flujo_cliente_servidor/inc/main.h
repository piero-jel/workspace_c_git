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


/* ==============================[ BEGIN Header Files ]=============================== */
#if !defined(__USE_GNU)
  #define __USE_GNU
#endif
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>  
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/poll.h>
/* libreria externa */
/* #include <sysutils.h> */
/* ==============================[ END   Header Files ]=============================== */


/* Definimos etiquetas para los mensajes del menu de parametros
 */
#define MSG_HELP_TYPE   "Tipo Servidor ('-t server') o Cliente ('-t client' , modo por defecto)"
#define MSG_HELP_IP     "Direccion IP (ex '--ip 192.168.0.4'), si usamos '-t sever' es desestimada"
#define MSG_HELP_PORT   "Puerto de Conexion (ex: -p 6550"
#define MSG_HELP_RETRY  "Reintentos de Conexion, util para el modo cliente"
#define MSG_HELP_PATH   "Path, ruta y nombre (ex '--path path/name/file')"
#define MSG_HELP_FORMAT "Formato del mensaje (ex '-f binary'), hexchar / binary"
#define MSG_HELP_LOG    "Path y Opcion (si el mismo debe ser truncado o no 'por defecto') para el log de eventos (ex: -l /home/user/file.txt truncated ). Es opcional por defecto stdout"
#define MSG_HELP_EOF    "Enable (y/yes) o Disable (n/no) el envio del eof de archivos, por defecto es deshabilitado"
#define MSG_HELP_DIR    "Mediante este podemos especificar un directorio donde tomara los archivos a enviar"
#define MSG_HELP_HELP   "Muestra el mensaje de ayuda"



#define DEFAULT_BUFF_LEN    BUFFER_SIZE(2K)
#define DEFAULT_RETRY       10
#define DEFAULT_TIME_RETRY  1000 /* en milisegundos */
#define DEFAULT_SRV_BACKLOG 1
#define DEFAULT_FORMAT      FALSE

/** Tabulamos las opciones para el ingreso por Opciones */
/* --type */
#define OPTIONS_TYPE_0    "client"
#define OPTIONS_TYPE_1    "server"
#define OPTIONS_TYPE(Num) OPTIONS_TYPE_##Num
/* --format */
#define OPTIONS_FORMAT_0    "binary"
#define OPTIONS_FORMAT_1    "hexchar"
#define OPTIONS_FORMAT(Num) OPTIONS_FORMAT_##Num
/* --eof */
#define OPTIONS_EOF_0    "yes"
#define OPTIONS_EOF_1    "y"
#define OPTIONS_EOF_2    "no"
#define OPTIONS_EOF_3    "n"
#define OPTIONS_EOF(Num) OPTIONS_EOF_##Num
/* --log */
#define OPTIONS_LOG_0    "trun"
#define OPTIONS_LOG_1    "truncate"
#define OPTIONS_LOG(Num) OPTIONS_LOG_##Num

/** 
 * 
*/
#define OPTIONS(Type,Num) OPTIONS_##Type(Num)\

/* tenemos un solo log file y este es cero */
#define MAIN_LOG 0

void help(stdcmenu_getopt_t*arg);

stdcmenu_getopt_t menu[] = {
   stdcmenu_FillRow("-t", "--type","%s",MSG_HELP_TYPE,NULL,NULL)
  ,stdcmenu_FillRow("-i", "--ip","%s",MSG_HELP_IP,NULL,NULL)
  ,stdcmenu_FillRow("-p", "--port","%u",MSG_HELP_PORT,NULL,NULL)
  ,stdcmenu_FillRow("-r", "--retry","%u",MSG_HELP_RETRY,NULL,NULL)
  ,stdcmenu_FillRow(NULL, "--path","%s",MSG_HELP_PATH,NULL,NULL)
  ,stdcmenu_FillRow("-f", "--format","%s",MSG_HELP_FORMAT,NULL,NULL)
  ,stdcmenu_FillRow("-l", "--log","%s%s",MSG_HELP_LOG,NULL,NULL)
  ,stdcmenu_FillRow("-d", "--dir","%s%s",MSG_HELP_DIR,NULL,NULL)
  ,stdcmenu_FillRow(NULL, "--eof","%s",MSG_HELP_EOF,NULL,NULL)
  ,stdcmenu_FillRow("-h", "--help",NULL,MSG_HELP_HELP,help/*fn callback*/,NULL)
  ,stdcmenu_getopt_END /* marcamos el fin del menu */
};

/* ========================[ BEGIN redefinition of variables ]======================== */
/** 
 * \struct arg_sT
 * \brief 
*/
typedef struct 
{
  char * ip;  /**<@brief para alamaenar la IP */
  char *type; /**<@brief tipo, server/client*/
  uint32_t port; /**<@brief Numero de puerto */
  uint32_t srvbacklog ; /**<@brief back log para el server */
  uint32_t retry; /**<@brief reintento de conexion */
  uint32_t timeretry; /**<@brief tiempo de espera entre reintentos */
  char * pathname ;/**<@brief Ruta y Nombre del archivo donde colocar/dejar los datos 
  arrivados/enviar */
  char *format; /* deberiamos sacarla */
  bool_t convert; /**<@brief si debemos convertir el fromato que debe tener el mensaje mensaje*/  
  bool_t sendeof; /**<@brief */
  char *logpath;  /**<@brief ruta y nombre para el log. */
  char *pathdir ; /**<@brief ruta y nombre de un directorio. */

} arg_sT;

/**
 * \typedef transfer_pfT 
 * \brief puntero a funcion, a prototipos del tipo transferencia  
 * Prototipo de la funcion, al acual debe apuntar:
 *  + bool_t Fx(int fd, arg_sT *parg, bool_t *state);
 *  fd    : descriptor de archivo correspondiente a socket
 *  parg  : puntero a la estructura de argumetnos necesarios
 *  state : Donde almacenaremos el estado de la trasnferencia.
 * \version AAvBBdCC.
 * \note nota.
 * \warning mensaje de "warning". 
 * \date day dayOfMonth de month, years.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef bool_t (*transfer_pfT) (int,arg_sT*,bool_t *);
/* ========================[ END   redefinition of variables ]======================== */

/* ========================[ BEGIN declaration of variables  ]======================== */

/* ========================[ END   declaration of variables  ]======================== */
/* ==========================[ BEGIN Function declaration  ]========================== */

bool_t cliente_connect( arg_sT *parg,transfer_pfT pfn, bool_t *state );
bool_t server_connect( arg_sT *parg, transfer_pfT pfn,bool_t *state );
bool_t transfer_data(int fd, arg_sT *parg, bool_t *state);
bool_t sendbysocket_file(int fd,const char *pathname,arg_sT *parg, bool_t *state);
bool_t recvbysocket_msg(int fd,arg_sT *parg, bool_t *state);

static inline void free_arg_sT(arg_sT * parg)
{
  if(parg->ip != NULL)
    free(parg->ip);

  if(parg->type != NULL)
    free(parg->type);

  if(parg->pathname != NULL)
    free(parg->pathname);

  if(parg->format != NULL)
    free(parg->format);

  if(parg->logpath != NULL)
    free(parg->logpath);
  
  if(parg->pathdir != NULL)
    free(parg->pathdir);
}


/* ==========================[ END   Function declaration  ]========================== */
/* ==========================[ BEGIN macros definitions    ]========================== */

/* ==========================[ END   macros definitions    ]========================== */






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

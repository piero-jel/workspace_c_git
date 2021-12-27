#define terminal_projectEnable 1 /**<@brief enable/disable the project in case of versioned */
/** \addtogroup terminal_h terminal.h module
 ** @{ */
/********************************[ copyright ]*************************************//**
 *@copyright 2018, Luccioni Jesús Emanuel
 * All rights reserved.
 * This file is part of terminal
 * Redistribution is not allowed on binary and source forms,
 * with or without modification.
 * Use is permitted with prior authorization by
 * the copyright holder
 * \n meil :
 * 	- piero.jel@gmail.com
 *************************************************************************************/
//
/********************************[Header File]*************************************//**
 * @file    terminal.h.h
 * @brief	<descripcion breve> ej. Libraries for System In Real Time
 * @versiones
 * 				v1v0d0, relese
 * 				brief
 * 					>> ...more
 * 					>> ...more...
 * @date   20 mar. 2018
 * @note none
 * @author Luccioni, Jesus Emanuel
 *************************************************************************************/
/*
 * -- Definimos el Nombre del modulo
*/
#ifndef __terminal_h__
#define __terminal_h__
//
//
#if (terminal_projectEnable == 1 && defined(SO_LINUX))
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =======================================[begin of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*
 * ============================[Open, cplusplus]============================
 * 
 */
#ifdef __cplusplus
extern "C" {
#endif
//
//
//
/* **********************************************************************************************
 *
 * =================================[ Begin include header file ]================================
 *
 * ******************************************************************************************** */
/*
 * TODO: include header file sector, "only in case especific"
*/
#include <termios.h>
#include <stdctype.h>
#include <stdc_print.h>





//
/* **********************************************************************************************
 *
 * ==================================[ End include header file ]=================================
 *
 * ******************************************************************************************** **/

/* **********************************************************************************************
 *
 * ==========================[ Begin labels enable/disable functions ]===========================
 *
 * ******************************************************************************************** **/
//
// TODO: labels enable/disable functions
//
// -- global
#define terminal_USE_GlobalMacro      1  /**<@brief enable/disable the use Global Macros/Labels */
#define terminal_USE_GlobalTypedef    1 /**<@brief enable/disable the use Global Typedef */
#define terminal_USE_GlobalData       0 /**<@brief enable/disable the use Global Data */
#define terminal_USE_GlobalFunctions  1 /**<@brief enable/disable the use Gobal functions */
#define terminal_USE_GlobalMacroApis  0 /**<@brief enable/disable the use Gobal macros functions */
//-- versionado
/**@brief versiones :
 * 	+ 1v0d0 -> Version inicial,
 *
 *  + 1v0d1 -> es la version 1v0d0 mas el ....
 *
 *  + 1v0d2 -> es la version 1v0d0 mas el agregado de
 *
 *  + 1v0d3 ->  FIXME working in 1v0d2 	*/
// #define terminal_USE_VERSION    version_SetNumber(01v00d00)
/**<@brief Definimos la Version que utilizaremos
en caso de eitar el mismo realizarlo con cuidado*/
/*
* Formato :
* 	<y1>v<y0>{d:e}<x>
*    |    |    |   |
*    |    |    |    --> 1 ~ 9, indicamos los pasos, cambios pequeños locales
*    |    |    --> d : provisoria, en estado de Depuracion "debbug"
*    |    |        e : estable
*    |    --> Cifra menos sisgnificativa del control de versionado 0~9
*    --> Cifra mas Significativa del control de versionado 1~9
*    Amaba cifras conforman la especificacion en cuanto a cambio globales
*    should be
*    		+ 1v0d1
*    		+ 1v1d1
*    		+ 1v2d1
*
*/






/* **********************************************************************************************
 *
 * ==========================[ End labels enable/disable functions ]===========================
 *
 * ******************************************************************************************** **/
//
//
//
/* **********************************************************************************************
 *
 * ==========================[ Begin Global Macros/labels definition]===========================
 *
 * ******************************************************************************************** **/
#if(terminal_USE_GlobalMacro==1)
//
// TODO : Macros/labels definition
//
#define terminal_LENG_NAME    64


//
//
//
#endif //#if(terminal_USE_GlobalMacro==1)
/* **********************************************************************************************
 *
 * ==========================[ End Macros/labels Globals ]===========================
 *
 * ******************************************************************************************** **/
//
//
//
/* **********************************************************************************************
 *
 * ====================================[Begin Global typedef]====================================
 *
 * ******************************************************************************************** */
#if(terminal_USE_GlobalTypedef==1)
//
// TODO: Global typedef
//
/** @brief definimos el tipo de estrucura para el handler de la terminal */
typedef struct
{
	struct termios option; 		/**<@brief estrucutura de configuracion de la terminal */
	int fd;					/**<@brief descriptor de archivo que le corresponde */
	//
	char nameTerminal[terminal_LENG_NAME];	/**<@brief nombre de la terminal*/
	int BaudRate;
	int Frame;
	int CtrlFlow;
}hdlTerminal_t;
//
//
/** @brief example definition global enum, <brief> */
typedef enum
{
  speed_0bps=B0,
  speed_50bps=B50,
  speed_75bps=B75,
  speed_110bps=B110,
  speed_134bps=B134,
  speed_150bps=B150,
  speed_200bps=B200,
  speed_300bps=B300,
  speed_600bps=B600,
  speed_1200bps=B1200,
  speed_1800bps=B1800,
  speed_2400bps=B2400,
  speed_4800bps=B4800,
  speed_9600bps=B9600,
  speed_19200bps=B19200,
  speed_38400bps=B38400,
  speed_57600bps=B57600,
  speed_115200bps=B115200,
  speed_230400bps=B230400,
}terminalSpeed_eT;


//
//
#endif//#if(terminal_USE_GlobalTypedef==1)
/* **********************************************************************************************
 *
 * ====================================[End Global typedef]====================================
 *
 * ******************************************************************************************** */
//
//
//
//
#ifdef __terminal_c__
/* **********************************************************************************************
 *
 * ==================================[ Begin local declaration ]=================================
 *
 ********************************************************************************************** */
//
//
//

//
//
//
/* **********************************************************************************************
 *
 * ==================================[ End local declaration ]=================================
 *
 ********************************************************************************************** */
//
//
#else // ifdef __terminal_c__
//
//
/* **********************************************************************************************
 *
 * ==============================[ Begin Only externa declaration ]=============================
 *
 ********************************************************************************************** */
/* SECTOR excluido de -> terminal.c, utlizar con cuidado*/
//
// TODO : Only external declaration
//


//
//
/* **********************************************************************************************
 *
 * ==============================[ End Only externa declaration ]=============================
 *
 ********************************************************************************************** */
//
//
//
 #endif // ifdef __terminal_c__
//
//
//
//
/* **********************************************************************************************
 *
 * ==================================[ Begin Global declaration ]=================================
 *
 ********************************************************************************************** */
//
//
//
/* ---------------------------------------------------------------------------------
 *
 * ==================[Begin Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------*/
#if(terminal_USE_GlobalData==1)
//
// TODO : Global data declaration
//
// extern unsigned int globalExample; /**<@brief variable global example, brief of data */

//
//
#endif//#if(terminal_USE_GlobalTypedef==1)
/* ---------------------------------------------------------------------------------
 *
 * ==================[End Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------*/
//
//
//
/* ---------------------------------------------------------------------------------
 *
 * ==================[Begin Global functions declaration]=========================
 *
 * --------------------------------------------------------------------------------*/
#if(terminal_USE_GlobalFunctions==1)
//
// TODO : Global functions declaration
//
//
//
/*******************************************************************//**
 * @brief Funcion para abrir un puerto Serie
 * @param name : puntero al string que contiene el nombre del
 * Puerto que se dese abrir
 * @return file descriptor, descriptor de archivo del Puerto Abierto
 * @note
 * @par example :
 <pre>
 a = main_nombreAPI_1(Arg);
 </pre>
 *********************************************************************/
int terminal_OpenPort(hdlTerminal_t *terminal,const char* name);
//
//
/*******************************************************************//**
 * @brief Api para cerrar un puerto serial determinado
 * @param ptrFileDesc : puntero al descriptor de archivo correspondiete
 * al puerto serie que se desa cerrar.
 * @return nothing
 * @note
 * @par example :
 <pre>
 a = main_nombreAPI_1(Arg);
 </pre>
 *********************************************************************/
int terminal_ClosePort(hdlTerminal_t *terminal);
//
//
/*******************************************************************//**
 * @brief Funcion para salvar la configuracion actual de la terminal
 * @param fd : descriptor de archivo de la terminal en cuestion
 * @param pHdlTerminal : Handler del tipo 'hdlTerminal_t', donde a
 * salvaremos las configuraciones actuales del terminal.
 * @return
 * 	+ 0 succes, accion realizada de forma sastifactoria
 * 	+ -1 Error
 * @note
 * @par example :
 <pre>
 if(serial_SaveConfig(fd_1,&hdlTerminal)==-1) RETURN(ERROR);
 </pre>
 *********************************************************************/
int terminal_SaveConfig(int fd,hdlTerminal_t *pHdlTerminal);
//
//
/*******************************************************************//**
 * @brief Funcion para restablecer la configuracion de la terminal
 * @param pHdlTerminal : Handler del tipo 'hdlTerminal_t', donde
 * contenemos la informacion a restablecer
 * @return
 * 	+ 0 succes, accion realizada de forma sastifactoria
 * 	+ -1 Error
 * @note
 * @par example :
 <pre>
 if(serial_RestoreConfig(&hdlTerminal)==-1) RETURN(ERROR);
 </pre>
 *********************************************************************/
int terminal_RestoreConfig(hdlTerminal_t *pHdlTerminal);

//
//
/*******************************************************************//**
* @brief Api para la configuracion de la terminal
* @param pHdlTerminal : Puntero del tipo 'hdlTerminal_t' que nos permite
* manejar/manipular una terminal deseada.
* @param BaudRate : baud rate, velocidad deseada para la terminal
* @param Frmae : trama, configuracion de la palabra. Bit de Datos,
* Bit de stop, paridad y tipo.
* @param flowContrl Control de Flujo de datos
* @return
* 	+ 0 configuracion realizada de forma sastifactoria
* 	+ -1 error al establecer la configuracion deseada
* @note
* @par example :
<pre>
a = terminal_nombreAPI_2(Arg);
</pre>
*********************************************************************/
int terminal_SetConfig(hdlTerminal_t *pHdlTerminal,int BaudRate\
    ,int Frame,int flowContrl );
//
//
/*
 * *****************************************************************//**
 * \fn size_t terminal_Receive(hdlTerminal_t * terminal,void *pBuff ,size_t lBuff, const char charEndRcv );
 * @brief Funcion para la recepcion de datos mediante terminal, los datos 
 * arribados son encolados en el buffer colocando al final el caracter 
 * de terminacion. En caso de que el buffer pasado sea de menor tamañao 
 * que el mensaje este caracter se omite.
 * @param terminal : puntero del tipo 'hdlTerminal_t' que contiene
 * toda la informacion necesaria para poder realizar la accion
 * @param pBuff : puntero al buffer donde se almacenaran los datos
 * arribados
 * @param lBuff : longitud del buffer
 * @param charEndRcv : char de fin de recepcion por ejemplo '\n'
 * @return la cantidad de caracteres pendientes que no fueron alojados
 * en el biffer.
 * \warning En caso de que retorne un numero de bytes, debemos considerar
 * que los datos actuales en el buffer no tienen caracter de terminacion.
 * @note
 * @par example :
 <pre>
 a = terminal_nombreAPI_1(Arg);
 </pre>
 *********************************************************************/
size_t terminal_Receive(hdlTerminal_t * terminal,void *pBuff\
    ,size_t lBuff, const char charEndRcv );
//
//
/*******************************************************************//**
 * @brief API para el envio de datos mediante terminal
 * @param terminal : puntero del tipo 'hdlTerminal_t' que contiene
 * toda la informacion necesaria para poder realizar la accion
 * @param pBuff : puntero al buffer donde se almacenaran los datos
 * a ser transmitidos
 * @param lBuff : longitud del buffer
 * @param charEndTrx : char a inscrustar para indicar el fin de
 * transmision. por ejemplo '\r'
 * @return la cantidad de caracteres enviados de forma sastifactoria
 * @note
 * @par example :
 <pre>
 a = terminal_nombreAPI_1(Arg);
 </pre>
 *********************************************************************/
int terminal_Transmit(hdlTerminal_t * terminal,void *pBuff\
  ,size_t lBuff, char charEndTrx);
//
//
/*********************************************************************
 * @brief API para Imprimir la informacion de la terminal
 * @param terminal : puntero del tipo 'hdlTerminal_t' que contiene
 * toda la informacion necesaria para poder realizar la accion
 * @param pFile : puntero del tipo FILE, que representa el archivo
 * donde imprimiremos la info. Este puede ser 'stdout'
 * @return la cantidad de caracteres enviados de forma sastifactoria
 * @note
 * @par example :
 <pre>
 a = terminal_nombreAPI_1(Arg);
 </pre>
 *********************************************************************/
void terminal_PrintInfo(hdlTerminal_t * terminal,FILE *pFile);


//
//
#endif//#if(terminal_USE_GlobalFunctions==1)
/* ---------------------------------------------------------------------------------
 *
 * ==================[End Global functions declaration]=========================
 *
 * --------------------------------------------------------------------------------*/
//
//
//
/* **********************************************************************************************
 *
 * ===========================[ Begin Global Macros functions ]==================================
 *
 ********************************************************************************************** */
 #if(terminal_USE_GlobalMacroApis==1)
//
//
//
/********************************************************************//**
 * @brief Bit Clear File
 * @param file : register file
 * @param posBit : position bit in the register file
 * @return	Nothing
 *********************************************************************/
#define terminal_BITcLEARfILE(file,posBit)\
 /**********************************************************************
 * @brief Bit Clear File
 * @param file : register file
 * @param posBit : position bit in the register file
 * @return	Nothing
  *********************************************************************/\
(file &=(~(0x01UL<<posBit)))
//
//
//
#endif// #if(terminal_USE_GlobalMacroApis==1)
/* **********************************************************************************************
 *
 * ===========================[ End Global Macros functions ]==================================
 *
 ********************************************************************************************** */


 //
 //
 //
/* **********************************************************************************************
 *
 * ==================================[ END GLOBAL declaration ]=================================
 *
 ********************************************************************************************** */
//
/*============================[close, cplusplus]============================*/
//
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/*==============================[end of file]==============================*/
#endif //#ifndef __terminal_h__
//
//
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * ========================================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif//#if(terminal_projectEnable == 1)

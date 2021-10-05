/** ***********************************************************************************//**
* \addtogroup boards_apis 
* @{ borrarme, solo para mantener la identacion -> }@
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of boards_apis .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file boards_apis.c
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v01d01.
* \date Lunes 08 de Marzo, 2021.
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
#define __boards_apis_c__ /**<@brief : defined the file name */

/*
* ================================[ BEGIN include header file ]===============================
* */
#include <stdc.h>
// #include <logger.h>
#include <prpi_gpio.h>
/* -- for end, header file this module */
#include <boards_apis.h>

/*
* ================================[ END   include header file ]===============================
* */
#if (boards_apis_projectEnable == 1)

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =======================================[begin of project file]=======================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* 
* ======================[ BEGIN labels enable/disable ]===============================
*/
#define boards_apis_USE_LocalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define boards_apis_USE_LocalTypedef   0 /**<@brief enable/disable the use Global Typedef */
#define boards_apis_USE_LocalData      1 /**<@brief enable/disable the use Global Data */
#define boards_apis_USE_LocalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define boards_apis_USE_LocalMacroApis 0 /**<@brief enable/disable the use Gobal boards_apiss functions */

/* 
* ======================[ END   labels enable/disable ]===============================
*/

#if (version_QueryNumber(__boards_apis_version__,01v00d00))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ BEGIN __boards_apis_version__    01v00d00 ]──────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/


/* 
* =================================[ BEGIN local boards_apis   ]=================================
*/
#if ( boards_apis_USE_LocalMacro == 1)

#define EXAMPLE_LOCAL_MACRO     2000 /**<@brief brief */


#endif /* #if ( boards_apis_USE_LocalMacro == 1) */
/*
* =================================[ END   local boards_apis   ]=================================
* */
/*
* =================================[ BEGIN Local typedef ]=================================
*/ 
#if (boards_apis_USE_LocalTypedef == 1)

/**
* \typedef tvar_ex_vT;
* \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
* \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int tvar_ex_vT;


/**
* \typedef pfun_ex_fT;
* \details Descripcion detallada sobre la redefinicion de puntero a funcion.
* \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
* Prototipo de la funcion, al acual debe apuntar:
*  + void * function ( void * arg )
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*pfun_ex_fT) (void *); 


/**
* \struct struct_ex_sT;
* \brief Descripcion breve sobre el tipo de estructura.
* Elementos que componen a la Estructura de datos:
*  \li \ref vtchar;
*  \li \ref vtint;
*  \li \ref vtdouble;
* \version 01v01d01.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} struct_ex_sT ; 

/**
* \union union_ex_uT;
* \brief Descripcion breve sobre el tipo de union.
* Elementos que componen la union:
*   \li \ref item1 
*   \li \ref item2 
* \version 01v01d01.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} union_ex_uT;


/**
* \enum enum_eT;
* \details Descripcion detallada sobre la redefinicion de enumeracio.
* \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
* Elementos que componen la enumeracion:
*  \li \ref eITEM0 . 
*  \li \ref eITEM1 .
*  \li \ref eITEM2 .
* \version 01v01d01.
* \warning mensaje de "warning".
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'eITEM0' de Enumeracion */
  eITEM1,     /**<@brief descripcion breve de la etiqueta 'eITEM1' de Enumeracion */
  eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'eITEM2' de Enumeracion */
} enum_eT;


#endif /* #if (boards_apis_USE_LocalTypedef == 1) */
/*
* =================================[ END   Local typedef ]=================================
* */
/* 
* ==========================[ BEGIN local Functions Declaraction ]=========================
* */
#if (boards_apis_USE_LocalFunctions == 1)



#endif /* #if (boards_apis_USE_LocalFunctions == 1) */
/* 
* ==========================[ END   local Functions Declaraction ]=========================
* */
/* 
* ================================[ BEGIN local variables ]================================
* */
#if (boards_apis_USE_LocalData == 1)
// static unsigned int exampleLocalData; /**<@brief local data declaration */


#endif /* #if (boards_apis_USE_LocalData == 1) */
/* 
* ================================[ END   local variables ]================================
* */
/* 
* ============================[ BEGIN local Macros Functions   ]===========================
* */
#if (boards_apis_USE_LocalMacroApis == 1)
/**
* 
* ********************************************************************************
* \def local_boards_apis_ex(Arg1,Arg2);
* \brief Descripcion breve sobre la boards_apis funcion \ref local_boards_apis_ex().
* \param Arg1 : Argumento uno, de la boards_apis funcion.
* \param Arg2 : Argumento dos, de la boards_apis funcion.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/ 
#define local_boards_apis_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}
#endif /* #if (boards_apis_USE_LocalMacroApis == 1) */
/* 
* ==========================[ END   local Macros Functions       ]=========================
* */
/* 
* ==========================[ BEGIN local Functions Definitions  ]=========================
* */
#if (boards_apis_USE_LocalFunctions == 1)



#endif /* #if (boards_apis_USE_LocalFunctions == 1) */
/* 
* ==========================[ END   local Functions Definitions  ]=========================
* */
/* 
* ==========================[ BEGIN Global Data Declaration      ]=========================
* */
unsigned int globalExample; /**<@brief variable global example, brief of data */

/* 
* ==========================[ END   Global Data Declaration      ]=========================
* */
/* 
* ==========================[ BEGIN Global APIs Definition       ]=========================
* */

#define LOG_WRITE_APPEND            0x01
#define LOG_WRITE_TIMESTAMP         0x02
#define LOG_WRITE_CLEAN             0x00

#define PIN_LED_SW0                 2 

#include <logger.h>
#include <prpi_gpio.h>

static bool_t log_WriteMsg(const char *file,char *msg, uint8_t flg, int *errmsg)
{  
  FILE * logFile = NULL;
  if (msg == NULL || file == NULL)
  {
#if (defined(DEBUG_ENABLE))    
    logger_mprintf( 0,logger_WARNING,"%s:%d Salida defecto %s,%s\n"\
               , __FILE__,__LINE__,file,msg);
#endif /* #if (defined(DEBUG_ENABLE)) */  
    
    return FALSE;
  }
    
  
  if(flg & LOG_WRITE_APPEND)
  {
    /* Si no existe lo crea.
     * En caso de existir escribe desde la ultima linea.
     */
    logFile = fopen(file,"a+");
  }
  else
  {
    /* Si no existe lo crea.
     * En caso de existir escribe desde el inicio del archivo
     */
    logFile = fopen(file,"w+");
  }  
#if (defined(DEBUG_ENABLE))  
  logger_mdebug( 0,logger_WARNING, "File \"%s\" Open\n",file );
#endif  
  if( logFile == NULL )
  {
    if(errmsg != NULL)
      *errmsg = errno;      
    return FALSE;
  }  
  if(flg & LOG_WRITE_TIMESTAMP)
  {
    char buff[64];
    timestamp_FillBuff(buff,sizeof(buff),"- :",timestamp_FMT_YYYYMMDD);
    fprintf(logFile,"%s\t%s\n",buff,msg);    
  }
  else
  {
    fprintf(logFile,"%s",msg);
  }  
  
  
  if (fclose(logFile) == 0)
  {
#if (defined(DEBUG_ENABLE))    
    logger_mdebug( 0,logger_WARNING,"File \"%s\" Close\n", file);
#endif    
    return TRUE;
  }
    
  
  if(errmsg != NULL)
      *errmsg = errno; 
  return FALSE; 

}

static bool_t log_Init(const char *namefile, char **dstpath, int *errmsg)
{
  char buff[1024];
  snprintf(buff,sizeof(buff),"%s/%s",boards_apis_LOG_FOLDER,namefile);
  *dstpath = strdup(buff);
  return log_WriteMsg(*dstpath,"",LOG_WRITE_CLEAN,errmsg); 
  
}



static char *log_board_01 = NULL;
static char *log_board_02 = NULL;
static char *log_board_03 = NULL;

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t boards_apis_Board_01_Init(void * arg, int *errmsg)
{   
  return log_Init(boards_apis_NAME_LOG_BOARD_01,&log_board_01,errmsg);
}

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t boards_apis_Board_01_Deinit(int *errmsg)
{ 
    /*-- liberamos el path */
  if(log_board_01 != NULL)
    free(log_board_01);
    
  return TRUE;  
}

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t boards_apis_Board_01_ProcessData(void * arg, int *errmsg)
{    
  return log_WriteMsg( log_board_01,(char*) arg, \
                       (LOG_WRITE_APPEND|LOG_WRITE_TIMESTAMP)\
                      , errmsg);
}

bool_t boards_apis_Board_01_Notify(void * arg, int *errmsg)
{  
  return TRUE;  
}




/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t boards_apis_Board_02_Init(void * arg, int *errmsg)
{
#if (defined(CROSS_COMPILER_ENABLE))
  /* mapeamos el periferico GPIO */
  if(!prpi_gpio_init(errmsg))
  {
    logger_mdebug( 0,logger_ERROR,"Error %s al intentar inicializar gpio\n"\
                 , strerror(*errmsg));
    return FALSE /* no pudo inicializar el periferico GPIO */;
  }
    
  
  /* configuramos el pin, como salida */
  prpi_gpio_config(PIN_LED_SW0,0);
  /*-- apagamos el led, pull-up */
  prpi_gpio_write(PIN_LED_SW0,HIGH);
#endif /* #if (defined(CROSS_COMPILER_ENABLE)) */  
  
#if (defined(DEBUG_ENABLE))
  if(!log_Init(boards_apis_NAME_LOG_BOARD_02,&log_board_02,errmsg))
  {
    logger_mdebug( 0,logger_ERROR,"Error %s al intentar inicializar loger file: \"%s\"\n"\
                 , strerror(*errmsg),log_board_02);
    return FALSE;
  }
  return TRUE;
#else
  return log_Init(boards_apis_NAME_LOG_BOARD_02,&log_board_02,errmsg);
#endif   
}


/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t boards_apis_Board_02_Deinit(int *errmsg)
{ 
    /*-- liberamos el path */
  if(log_board_02 != NULL)
    free(log_board_02);
#if (defined(CROSS_COMPILER_ENABLE))
  /*-- para otro uso del gpio */
  prpi_gpio_config(PIN_LED_SW0,1);
  prpi_gpio_deinit(errmsg/*pointer err-notify*/);
#endif /* #if (defined(CROSS_COMPILER_ENABLE)) */  
  return TRUE;  
}


#if (defined(CROSS_COMPILER_ENABLE))
#define SET_GPIO(Pin,St) prpi_gpio_write(Pin,St)
#else
#define SET_GPIO(Pin,St)
#endif /* #if (defined(CROSS_COMPILER_ENABLE)) */  

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t boards_apis_Board_02_ProcessData(void * arg, int *errmsg)
{
  /* procesamos los datos arrivados */  
    /* Debemos procesar los datos antes de mostrarlos 
     * <SW1: off >          
     */
  char *str = (char*) arg;
  char *ptm1;
  char *ptm;
  bool_t lret;  
  if(stdcstr_breaktoken(str,"<SW0:",&ptm1) == NULL) 
    return FALSE;
  
  if(strcmp(ptm1," off >") == 0)
  {
    ptm = strdup("SW Desactivado");    
    SET_GPIO(PIN_LED_SW0,HIGH);
  }
  else if( strcmp(ptm1," on >") == 0)
  {
    ptm = strdup("SW Activado");
    SET_GPIO(PIN_LED_SW0,LOW);
  }
  else
  {
    ptm = strdup("SW Indefinido");
  }
  
  lret = log_WriteMsg( log_board_02,(char*) ptm\
                     ,(LOG_WRITE_APPEND|LOG_WRITE_TIMESTAMP),errmsg);
  if(ptm != NULL)
    free(ptm);
  
  return lret;
}

bool_t boards_apis_Board_02_Notify(void * arg, int *errmsg)
{  
  return TRUE;  
}


/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t boards_apis_Board_03_Init(void * arg, int *errmsg)
{
#if (defined(CROSS_COMPILER_ENABLE))
  /* mapeamos el periferico GPIO */
  if(!prpi_gpio_init(errmsg))
  {
    logger_mdebug( 0,logger_ERROR,"Error %s al intentar inicializar gpio\n"\
                 , strerror(*errmsg));
    return FALSE /* no pudo inicializar el periferico GPIO */;
  }    
  
  /* configuramos el pin, como salida */
  prpi_gpio_config(PIN_LED_SW0,0);
  /*-- apagamos el led, pull-up */
  prpi_gpio_write(PIN_LED_SW0,HIGH);
#endif /* #if (defined(CROSS_COMPILER_ENABLE)) */  
  
#if (defined(DEBUG_ENABLE))
  if(!log_Init(boards_apis_NAME_LOG_BOARD_03,&log_board_03,errmsg))
  {
    logger_mdebug( 0,logger_ERROR,"Error %s al intentar inicializar loger file: \"%s\"\n"\
                 , strerror(*errmsg),log_board_03);
    return FALSE;
  }
  return TRUE;
#else
  return log_Init(boards_apis_NAME_LOG_BOARD_03,&log_board_03,errmsg);
#endif   
}


/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t boards_apis_Board_03_Deinit(int *errmsg)
{ 
    /*-- liberamos el path */
  if(log_board_03 != NULL)
    free(log_board_03);
#if (defined(CROSS_COMPILER_ENABLE))
  /*-- para otro uso del gpio */
  prpi_gpio_config(PIN_LED_SW0,1);
  prpi_gpio_deinit(errmsg/*pointer err-notify*/);
#endif /* #if (defined(CROSS_COMPILER_ENABLE)) */  
  return TRUE;  
}

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t boards_apis_Board_03_ProcessData(void * arg, int *errmsg)
{
  /* procesamos los datos arrivados */
  
    /* Debemos procesar los datos antes de mostrarlos 
     * <SW1: off >          
     */
  char *str = (char*) arg;
  char *ptm1;
  char *ptm;
  bool_t lret;  
  if(stdcstr_breaktoken(str,"<SW0:",&ptm1) == NULL) 
    return FALSE;
  
  if(strcmp(ptm1," off >") == 0)
  {
    ptm = strdup("SW Desactivado");    
    SET_GPIO(PIN_LED_SW0,HIGH);
  }
  else if( strcmp(ptm1," on >") == 0)
  {
    ptm = strdup("SW Activado");
    SET_GPIO(PIN_LED_SW0,LOW);
  }
  else
  {
    ptm = strdup("SW Indefinido");
  }
  
  lret = log_WriteMsg( log_board_03,(char*) ptm\
                     ,(LOG_WRITE_APPEND|LOG_WRITE_TIMESTAMP),errmsg);
  if(ptm != NULL)
    free(ptm);
  
  return lret;
}


bool_t boards_apis_Board_03_Notify(void * arg, int *errmsg)
{  
  return TRUE;  
}
/* 
* ==========================[ END   Global APIs Definition       ]=========================
* */


/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ END   __boards_apis_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (version_QueryNumber(__boards_apis_version__,01v00d01))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ BEGIN __boards_apis_version__    01v00d01 ]──────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/


/* 
* =================================[ BEGIN local boards_apis   ]=================================
*/
#if ( boards_apis_USE_LocalMacro == 1)

#define LOG_WRITE_APPEND            0x01 /**<@brief brief */
#define LOG_WRITE_TIMESTAMP         0x02 /**<@brief brief */  
#define LOG_WRITE_CLEAN             0x00 /**<@brief brief */

#define PIN_LED_SW0                 2  /**<@brief brief */


#endif /* #if ( boards_apis_USE_LocalMacro == 1) */
/*
* =================================[ END   local boards_apis   ]=================================
* */
/*
* =================================[ BEGIN Local typedef ]=================================
*/ 
#if (boards_apis_USE_LocalTypedef == 1)

/**
* \typedef tvar_ex_vT;
* \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
* \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef unsigned int tvar_ex_vT;


/**
* \typedef pfun_ex_fT;
* \details Descripcion detallada sobre la redefinicion de puntero a funcion.
* \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
* Prototipo de la funcion, al acual debe apuntar:
*  + void * function ( void * arg )
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*pfun_ex_fT) (void *); 


/**
* \struct struct_ex_sT;
* \brief Descripcion breve sobre el tipo de estructura.
* Elementos que componen a la Estructura de datos:
*  \li \ref vtchar;
*  \li \ref vtint;
*  \li \ref vtdouble;
* \version 01v01d01.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} struct_ex_sT ; 

/**
* \union union_ex_uT;
* \brief Descripcion breve sobre el tipo de union.
* Elementos que componen la union:
*   \li \ref item1 
*   \li \ref item2 
* \version 01v01d01.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} union_ex_uT;


/**
* \enum enum_eT;
* \details Descripcion detallada sobre la redefinicion de enumeracio.
* \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
* Elementos que componen la enumeracion:
*  \li \ref eITEM0 . 
*  \li \ref eITEM1 .
*  \li \ref eITEM2 .
* \version 01v01d01.
* \warning mensaje de "warning".
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'eITEM0' de Enumeracion */
  eITEM1,     /**<@brief descripcion breve de la etiqueta 'eITEM1' de Enumeracion */
  eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'eITEM2' de Enumeracion */
} enum_eT;


#endif /* #if (boards_apis_USE_LocalTypedef == 1) */
/*
* =================================[ END   Local typedef ]=================================
* */
/* 
* ==========================[ BEGIN local Functions Declaraction ]=========================
* */
#if (boards_apis_USE_LocalFunctions == 1)


/** *****************************************************************************//** 
* \fn static int localfn_test(unsigned int a,const char* name); 
* \brief descripcion breve sobre la funcion, \ref localfn_test();
* \param a : Puntero al array.
* \param name : longitud del array.
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v01d01.
* \note note.
* \warning mensaje de "warning". 
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
/* -- Para la Temperature Board (Termistores, Acelerometro) */
static bool_t boards_apis_Board_01_Init(boards_apis_hdl_t *arg);
static bool_t boards_apis_Board_01_Deinit(boards_apis_hdl_t *arg);
static bool_t boards_apis_Board_01_ProcessData(boards_apis_hdl_t *arg, void *data);
static bool_t boards_apis_Board_01_Notify(boards_apis_hdl_t *arg,void *notify);

/* -- Para la Feeder Board (RFID, GLCD, Fin de filamento) */
static bool_t boards_apis_Board_02_Init(boards_apis_hdl_t *arg);
static bool_t boards_apis_Board_02_Deinit(boards_apis_hdl_t *arg);
static bool_t boards_apis_Board_02_ProcessData(boards_apis_hdl_t *arg, void *data);
static bool_t boards_apis_Board_02_Notify(boards_apis_hdl_t *arg,void *notify);

/* -- Para la Feeder Board (RFID, GLCD, Fin de filamento) */
static bool_t boards_apis_Board_03_Init(boards_apis_hdl_t *arg);
static bool_t boards_apis_Board_03_Deinit(boards_apis_hdl_t *arg);
static bool_t boards_apis_Board_03_ProcessData(boards_apis_hdl_t *arg, void *data);
static bool_t boards_apis_Board_03_Notify(boards_apis_hdl_t *arg,void *notify);

/* -- for other borads */
#if 0 /*disabel for compiler time warning */
static bool_t boards_apis_OtherBoard_Init(boards_apis_hdl_apis_t *arg);
static bool_t boards_apis_OtherBoard_Deinit_01(boards_apis_hdl_apis_t *arg);
static bool_t boards_apis_OtherBoard_ProcessData(boards_apis_hdl_apis_t *arg, void *data);
static bool_t boards_apis_OtherBoard_Notify(boards_apis_hdl_apis_t *arg,void *notify);
#endif

#endif /* #if (boards_apis_USE_LocalFunctions == 1) */
/* 
* ==========================[ END   local Functions Declaraction ]=========================
* */
/* 
* ================================[ BEGIN local variables ]================================
* */
#if (boards_apis_USE_LocalData == 1)

/**
 *\var menu_apis
 * \brief Definimos el array/menu local de APIS relacionadas a un nombre de indentificaion 
 */
static boards_apis_menu_t menu_apis[] =
{ /* boards_apis_menu_FillRow(ApiName,FnIni,FnDeini,FnProcces,FnNotify,NameLog) */  
    boards_apis_menu_FillRow("Board_01", boards_apis_Board_01_Init, boards_apis_Board_01_Deinit \
      , boards_apis_Board_01_ProcessData, boards_apis_Board_01_Notify, boards_apis_NAME_LOG_BOARD_01)
  , boards_apis_menu_FillRow("Board_02", boards_apis_Board_02_Init, boards_apis_Board_02_Deinit \
      , boards_apis_Board_02_ProcessData, boards_apis_Board_02_Notify, boards_apis_NAME_LOG_BOARD_02)
  , boards_apis_menu_FillRow("Board_02", boards_apis_Board_03_Init, boards_apis_Board_03_Deinit \
      , boards_apis_Board_03_ProcessData, boards_apis_Board_03_Notify, boards_apis_NAME_LOG_BOARD_03)
  , boards_apis_menu_END()
};


#endif /* #if (boards_apis_USE_LocalData == 1) */
/* 
* ================================[ END   local variables ]================================
* */
/* 
* ============================[ BEGIN local Macros Functions   ]===========================
* */
#if (boards_apis_USE_LocalMacroApis == 1)
/**
* 
* ********************************************************************************
* \def local_boards_apis_ex(Arg1,Arg2);
* \brief Descripcion breve sobre la boards_apis funcion \ref local_boards_apis_ex().
* \param Arg1 : Argumento uno, de la boards_apis funcion.
* \param Arg2 : Argumento dos, de la boards_apis funcion.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Lunes 08 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/ 
#define local_boards_apis_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}
#endif /* #if (boards_apis_USE_LocalMacroApis == 1) */
/* 
* ==========================[ END   local Macros Functions       ]=========================
* */
/* 
* ==========================[ BEGIN local Functions Definitions  ]=========================
* */
#if (boards_apis_USE_LocalFunctions == 1)

static bool_t log_WriteMsg(const char *file,char *msg, uint8_t flg, int *errmsg)
{  
  FILE * logFile = NULL;
  if (msg == NULL || file == NULL)
  {
#if (defined(DEBUG_ENABLE))    
    logger_mprintf( 0,logger_WARNING,"%s:%d Salida defecto %s,%s\n"\
               , __FILE__,__LINE__,file,msg);
#endif /* #if (defined(DEBUG_ENABLE)) */  
    
    return FALSE;
  }
    
  
  if(flg & LOG_WRITE_APPEND)
  {
    /* Si no existe lo crea.
     * En caso de existir escribe desde la ultima linea.
     */
    logFile = fopen(file,"a+");
  }
  else
  {
    /* Si no existe lo crea.
     * En caso de existir escribe desde el inicio del archivo
     */
    logFile = fopen(file,"w+");
  }  
#if (defined(DEBUG_ENABLE))  
  logger_mdebug( 0,logger_WARNING, "File \"%s\" Open\n",file );
#endif  
  if( logFile == NULL )
  {
    if(errmsg != NULL)
      *errmsg = errno;      
    return FALSE;
  }  
  if(flg & LOG_WRITE_TIMESTAMP)
  {
    char buff[64];
    timestamp_FillBuff(buff,sizeof(buff),"- :",timestamp_FMT_YYYYMMDD);
    fprintf(logFile,"%s\t%s\n",buff,msg);    
  }
  else
  {
    fprintf(logFile,"%s",msg);
  }  
  
  
  if (fclose(logFile) == 0)
  {
#if (defined(DEBUG_ENABLE))    
    logger_mdebug( 0,logger_WARNING,"File \"%s\" Close\n", file);
#endif    
    return TRUE;
  }
    
  
  if(errmsg != NULL)
      *errmsg = errno; 
  return FALSE; 

}

static bool_t log_Init(const char *namefile, char **dstpath, int *errmsg)
{
  char buff[1024];
  snprintf(buff,sizeof(buff),"%s/%s",boards_apis_LOG_FOLDER,namefile);
  *dstpath = strdup(buff);
  return log_WriteMsg(*dstpath,"",LOG_WRITE_CLEAN,errmsg); 
  
}

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
static bool_t boards_apis_Board_01_Init(boards_apis_hdl_t *arg)
{   
  return log_Init(arg->namelog,&arg->pathlog,&arg->errnum);
}

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
static bool_t boards_apis_Board_01_Deinit(boards_apis_hdl_t *arg)
{ 
    /*-- liberamos el path */
  if(arg->pathlog != NULL)
    free(arg->pathlog);
    
  return TRUE;  
}


/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
static bool_t boards_apis_Board_01_ProcessData(boards_apis_hdl_t *arg, void *data)
{    
  return log_WriteMsg( arg->pathlog,(char*) data, \
                       (LOG_WRITE_APPEND|LOG_WRITE_TIMESTAMP)\
                      , &arg->errnum);
}

static bool_t boards_apis_Board_01_Notify(boards_apis_hdl_t *arg,void *notify)
{  
  return TRUE;  
}

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
static bool_t boards_apis_Board_02_Init(boards_apis_hdl_t *arg)
{
#if (defined(CROSS_COMPILER_ENABLE))
  /* mapeamos el periferico GPIO */
  if(!prpi_gpio_init(&arg->errnum))
  {
    logger_mdebug( 0,logger_ERROR,"Error %s al intentar inicializar gpio\n"\
                 , strerror(arg->errnum));
    return FALSE /* no pudo inicializar el periferico GPIO */;
  }
    
  
  /* configuramos el pin, como salida */
  prpi_gpio_config(PIN_LED_SW0,0);
  /*-- apagamos el led, pull-up */
  prpi_gpio_write(PIN_LED_SW0,HIGH);
#endif /* #if (defined(CROSS_COMPILER_ENABLE)) */  
  
#if (defined(DEBUG_ENABLE))
  if(!log_Init(arg->namelog,&arg->pathlog,&arg->errnum))
  {
    logger_mdebug( 0,logger_ERROR,"Error %s al intentar inicializar loger file: \"%s\"\n"\
                 , strerror(arg->errnum),arg->pathlog);
    return FALSE;
  }
  return TRUE;
#else
  return log_Init(arg->namelog,&arg->pathlog,&arg->errnum);
#endif   
}

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
static bool_t boards_apis_Board_02_Deinit(boards_apis_hdl_t *arg)
{ 
    /*-- liberamos el path */
  if(arg->pathlog != NULL)
    free(arg->pathlog);
#if (defined(CROSS_COMPILER_ENABLE))
  /*-- para otro uso del gpio */
  prpi_gpio_config(PIN_LED_SW0,1);
  prpi_gpio_deinit(&arg->errnum/*pointer err-notify*/);
#endif /* #if (defined(CROSS_COMPILER_ENABLE)) */  
  return TRUE;  
}


#if (defined(CROSS_COMPILER_ENABLE))
#define SET_GPIO(Pin,St) prpi_gpio_write(Pin,St)
#else
#define SET_GPIO(Pin,St)
#endif /* #if (defined(CROSS_COMPILER_ENABLE)) */  

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
static bool_t boards_apis_Board_02_ProcessData(boards_apis_hdl_t *arg, void *data)
{
  /* procesamos los datos arrivados */
  
    /* Debemos procesar los datos antes de mostrarlos 
     * <SW1: off >          
     */
  char *str = (char*) data;
  char *ptm1;
  char *ptm;
  bool_t lret;  
  /* buscamos el token */
  if(stdcstr_breaktoken(str,"<SW0:",&ptm1) == NULL) 
    return FALSE;
  
  if(strcmp(ptm1," off >") == 0)
  {
    ptm = strdup("SW Desactivado");    
    SET_GPIO(PIN_LED_SW0,HIGH);
  }
  else if( strcmp(ptm1," on >") == 0)
  {
    ptm = strdup("SW Activado");
    SET_GPIO(PIN_LED_SW0,LOW);
  }
  else
  {
    ptm = strdup("SW Indefinido");
  }
  
  lret = log_WriteMsg( arg->pathlog,(char*) ptm\
                     ,(LOG_WRITE_APPEND|LOG_WRITE_TIMESTAMP),&arg->errnum);
  if(ptm != NULL)
    free(ptm);
  
  return lret;
}


static bool_t boards_apis_Board_02_Notify(boards_apis_hdl_t *arg,void *notify)
{  
  return TRUE;  
}


/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
static bool_t boards_apis_Board_03_Init(boards_apis_hdl_t *arg)
{
#if (defined(CROSS_COMPILER_ENABLE))
  /* mapeamos el periferico GPIO */
  if(!prpi_gpio_init(&arg->errnum))
  {
    logger_mdebug( 0,logger_ERROR,"Error %s al intentar inicializar gpio\n"\
                 , strerror(arg->errnum));
    return FALSE /* no pudo inicializar el periferico GPIO */;
  }
    
  
  /* configuramos el pin, como salida */
  prpi_gpio_config(PIN_LED_SW0,0);
  /*-- apagamos el led, pull-up */
  prpi_gpio_write(PIN_LED_SW0,HIGH);
#endif /* #if (defined(CROSS_COMPILER_ENABLE)) */  
  
#if (defined(DEBUG_ENABLE))
  if(!log_Init(arg->namelog,&arg->pathlog,&arg->errnum))
  {
    logger_mdebug( 0,logger_ERROR,"Error %s al intentar inicializar loger file: \"%s\"\n"\
                 , strerror(arg->errnum),arg->pathlog);
    return FALSE;
  }
  return TRUE;
#else
  return log_Init(arg->namelog,&arg->pathlog,&arg->errnum);
#endif   
}


/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
static bool_t boards_apis_Board_03_Deinit(boards_apis_hdl_t *arg)
{ 
    /*-- liberamos el path */
  if(arg->pathlog != NULL)
    free(arg->pathlog);
#if (defined(CROSS_COMPILER_ENABLE))
  /*-- para otro uso del gpio */
  prpi_gpio_config(PIN_LED_SW0,1);
  prpi_gpio_deinit(&arg-errnum/*pointer err-notify*/);
#endif /* #if (defined(CROSS_COMPILER_ENABLE)) */  
  return TRUE;  
}

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
static bool_t boards_apis_Board_03_ProcessData(boards_apis_hdl_t *arg, void *data)
{
  /* procesamos los datos arrivados */
  
    /* Debemos procesar los datos antes de mostrarlos 
     * <SW1: off >          
     */
  char *str = (char*) data;
  char *ptm1;
  char *ptm;
  bool_t lret;  
  if(stdcstr_breaktoken(str,"<SW0:",&ptm1) == NULL) 
    return FALSE;
  
  if(strcmp(ptm1," off >") == 0)
  {
    ptm = strdup("SW Desactivado");    
    SET_GPIO(PIN_LED_SW0,HIGH);
  }
  else if( strcmp(ptm1," on >") == 0)
  {
    ptm = strdup("SW Activado");
    SET_GPIO(PIN_LED_SW0,LOW);
  }
  else
  {
    ptm = strdup("SW Indefinido");
  }
  
  lret = log_WriteMsg( arg->pathlog,(char*) ptm\
                     ,(LOG_WRITE_APPEND|LOG_WRITE_TIMESTAMP),&arg->errnum);
  if(ptm != NULL)
    free(ptm);
  
  return lret;
}

static bool_t boards_apis_Board_03_Notify(boards_apis_hdl_t *arg,void *notify)
{  
  return TRUE;  
}


#endif /* #if (boards_apis_USE_LocalFunctions == 1) */
/* 
* ==========================[ END   local Functions Definitions  ]=========================
* */
/* 
* ==========================[ BEGIN Global Data Declaration      ]=========================
* */
unsigned int globalExample; /**<@brief variable global example, brief of data */

/* 
* ==========================[ END   Global Data Declaration      ]=========================
* */
/* 
* ==========================[ BEGIN Global APIs Definition       ]=========================
* */


bool_t boards_apis_menu_FillHandler(const char* apiname, boards_apis_hdl_t *phdlapis)
{
  uint32_t i;
  if(apiname == NULL || phdlapis == NULL)
  {
    return FALSE;
  }
  i = 0;
  while(!boards_apis_menu_MENUEND(menu_apis[i]))
  {
    if(strcmp(menu_apis[i].name,apiname) == 0)
      break;
    i++;
  }
  memcpy(phdlapis,&menu_apis[i].hdl_apis,sizeof(boards_apis_hdl_t));  
  return TRUE;
}


/* 
* ==========================[ END   Global APIs Definition       ]=========================
* */


/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ END   __boards_apis_version__    01v00d01 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#elif (version_QueryNumber(__boards_apis_version__,01v00d02))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ BEGIN __boards_apis_version__    01v00d02 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ END   __boards_apis_version__    01v00d02 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#endif


/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* ========================================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(boards_apis_projectEnable == 1) */

/** ***********************************************************************************//**
* \addtogroup macro_apis 
* @{ borrarme, solo para mantener la identacion -> }@
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of macro_apis .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file macro_apis.c
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
#define __macro_apis_c__ /**<@brief : defined the file name */

/*
* ================================[ BEGIN include header file ]===============================
* */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* -- for close()*/
/* -- for read() */
#include <unistd.h>
/*  -- error n° */
#include <errno.h> /*header file standar error, global variables for errno */
/* */
#include <fcntl.h>


#include <timestamp.h>

/* -- for end, header file this module */
#include <macro_apis.h>

/*
* ================================[ END   include header file ]===============================
* */
#if (macro_apis_projectEnable == 1)

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =======================================[begin of project file]=======================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/* 
* ======================[ BEGIN labels enable/disable ]===============================
*/
#define macro_apis_USE_LocalMacro     0 /**<@brief enable/disable the use Global Macros/Labels */
#define macro_apis_USE_LocalTypedef   0 /**<@brief enable/disable the use Global Typedef */
#define macro_apis_USE_LocalData      0 /**<@brief enable/disable the use Global Data */
#define macro_apis_USE_LocalFunctions 0 /**<@brief enable/disable the use Gobal functions */
#define macro_apis_USE_LocalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/* 
* ======================[ END   labels enable/disable ]===============================
*/

#if (version_QueryNumber(__macro_apis_version__,01v00d00))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ BEGIN __macro_apis_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/



/* 
* =================================[ BEGIN local macro   ]=================================
*/
#if ( macro_apis_USE_LocalMacro == 1)

#define EXAMPLE_LOCAL_MACRO     2000 /**<@brief brief */


#endif /* #if ( macro_apis_USE_LocalMacro == 1) */
/*
* =================================[ END   local macro   ]=================================
* */

/*
* =================================[ BEGIN Local typedef ]=================================
*/ 
#if (macro_apis_USE_LocalTypedef == 1)

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


#endif /* #if (macro_apis_USE_LocalTypedef == 1) */
/*
* =================================[ END   Local typedef ]=================================
* */


/* 
* ================================[ BEGIN local variables ]================================
* */
#if (macro_apis_USE_LocalData == 1)
static unsigned int exampleLocalData; /**<@brief local data declaration */


#endif /* #if (macro_apis_USE_LocalData == 1) */
/* 
* ================================[ END   local variables ]================================
* */


/* 
* ==========================[ BEGIN local Functions Declaraction ]=========================
* */
#if (macro_apis_USE_LocalFunctions == 1)


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
static int localfn_test(unsigned int a,const char* name);


#endif /* #if (macro_apis_USE_LocalFunctions == 1) */
/* 
* ==========================[ END   local Functions Declaraction ]=========================
* */



/* 
* ============================[ BEGIN local Macros Functions   ]===========================
* */
#if (macro_apis_USE_LocalMacroApis == 1)
/**
* 
* ********************************************************************************
* \def local_macro_ex(Arg1,Arg2);
* \brief Descripcion breve sobre la macro funcion \ref local_macro_ex().
* \param Arg1 : Argumento uno, de la macro funcion.
* \param Arg2 : Argumento dos, de la macro funcion.
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
#define local_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}
#endif /* #if (macro_apis_USE_LocalMacroApis == 1) */
/* 
* ==========================[ END   local Macros Functions       ]=========================
* */


/* 
* ==========================[ BEGIN local Functions Definitions  ]=========================
* */
#if (macro_apis_USE_LocalFunctions == 1)

/********************************************************************
* @brief descripcion 
* @b wordInTextBold <b>parrafo en bold </b>
* @return nothing
*********************************************************************/
static int localfn_test(unsigned int a,const char* name)
{  
  return 0;
}

#endif /* #if (macro_apis_USE_LocalFunctions == 1) */
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

#include <logger.h>
static bool_t log_WriteMsg(const char *file,char *msg, uint8_t flg, int *errmsg)
{  
  FILE * logFile = NULL;
  if (msg == NULL || file == NULL)
  {
    /*logger_printf( 0,logger_WARNING,"%s:%d Salida defecto %s,%s\n"\
               , __FILE__,__LINE__,file,msg);*/
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
  
/*  logger_printf( 0,logger_WARNING,"%s:%d file \"%s\" open\n"\
               , __FILE__,__LINE__,file); */   
  
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
    /*logger_printf( 0,logger_WARNING,"%s:%d file \"%s\" close\n"\
               , __FILE__,__LINE__,file);*/ 
    return TRUE;
  }
    
  
  if(errmsg != NULL)
      *errmsg = errno; 
  return FALSE; 

}

static bool_t log_Init(const char *namefile, char **dstpath, int *errmsg)
{
  char buff[1024];
  snprintf(buff,sizeof(buff),"%s/%s",macro_LOG_FOLDER/*getenv(macro_VARENVIROMENT_FOLDER)*/,namefile);
  *dstpath = strdup(buff);
  return log_WriteMsg(*dstpath,"",LOG_WRITE_CLEAN,errmsg); 
  
}



static char *log_tempboard;
static char *log_feederboard;



/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t macro_TempBoard_Init(void * arg, int *errmsg)
{   
  /* fixme en arg deberia pasar el NAME_LOG_TEMPBOARD
   */
#if 0  
  char buff[1024];
  snprintf(buff,sizeof(buff),"%s/%s",getenv(macro_VARENVIROMENT_FOLDER),macro_NAME_LOG_TEMPBOARD);
  log_tempboard = strdup(buff);
  return log_WriteMsg(log_tempboard,"",LOG_WRITE_CLEAN,errmsg);   
#else
  return log_Init(macro_NAME_LOG_TEMPBOARD,&log_tempboard,errmsg);
#endif
}

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t macro_TempBoard_Deinit(int *errmsg)
{ 
    /*-- liberamos el path */
  if(log_tempboard != NULL)
    free(log_tempboard);
    
  return TRUE;  
}




/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t macro_TempBoard_ProcessData(void * arg, int *errmsg)
{    
  return log_WriteMsg( log_tempboard,(char*) arg, \
                       (LOG_WRITE_APPEND|LOG_WRITE_TIMESTAMP)\
                      , errmsg);
}

bool_t macro_TempBoard_Notify(void * arg, int *errmsg)
{  
  return FALSE;  
}




/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t macro_FeederBoard_Init(void * arg, int *errmsg)
{   
#if 0  
  char buff[1024];
  snprintf(buff,sizeof(buff),"%s/%s",getenv(macro_VARENVIROMENT_FOLDER),macro_NAME_LOG_FEEDERBOARD);
  log_feederboard = strdup(buff);
  return log_WriteMsg(log_feederboard,"",LOG_WRITE_CLEAN,errmsg);   
#else
  return log_Init(macro_NAME_LOG_FEEDERBOARD,&log_feederboard,errmsg);
#endif
}
/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t macro_FeederBoard_Deinit(int *errmsg)
{ 
    /*-- liberamos el path */
  if(log_feederboard != NULL)
    free(log_feederboard);
    
  return TRUE;  
}

/********************************************************************
* @brief descripcion breve
* @param a : varaible a
* @param name : puntero al buffer del string
* @return valor del tipo int
*********************************************************************/
bool_t macro_FeederBoard_ProcessData(void * arg, int *errmsg)
{    
  return log_WriteMsg( log_feederboard,(char*) arg\
                       ,(LOG_WRITE_APPEND|LOG_WRITE_TIMESTAMP),errmsg);
}

bool_t macro_FeederBoard_Notify(void * arg, int *errmsg)
{
  
  return FALSE;  
}
/* 
* ==========================[ END   Global APIs Definition       ]=========================
* */




/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ END   __macro_apis_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (version_QueryNumber(__macro_apis_version__,01v00d01))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ BEGIN __macro_apis_version__    01v00d01 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ────────────────────[ END   __macro_apis_version__    01v00d01 ]───────────────────── │
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
#endif /* #if(macro_apis_projectEnable == 1) */

#ifndef stdcfile_projectEnable
#define stdcfile_projectEnable 1 /**<@brief enable/disable the project */
#endif
/** ***********************************************************************************//**
* \addtogroup miscellaneous 
* @{ borrarme, solo para mantener la identacion -> }@
* \copyright  
* 2021, Luccioni Jesús Emanuel \n
* All rights reserved.\n 
* This file is part of miscellaneous .\n
* Redistribution is not allowed on binary and source forms, with or without \n
* modification. Use is permitted with prior authorization by the copyright 
* holder. &copy;
* \file stdcfile.h
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
* \brief Descripcion breve.
* \details Descripcion detallada.
*
* \version 01v01d01.
* \date Jueves 11 de Marzo, 2021.
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


#ifndef __stdcfile_h__
#define __stdcfile_h__ /**<@brief Definimos el Nombre del modulo */

#if (stdcfile_projectEnable == 1 && defined(SO_LINUX))

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* ============================[begin of project file]=======================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/*
* ============================[Open, cplusplus]============================ 
*/
#ifdef __cplusplus
extern "C" {
#endif

/* 
* ======================[ BEGIN include header file ]=================================
*/
#include <stdio.h>
#include <stdctype.h>

/* 
* ======================[ END   include header file ]=================================
*/

/* ======================[ BEGIN labels enable/disable ]=============================== */
#define stdcfile_USE_GlobalMacro     1 /**<@brief enable/disable the use Global Macros/Labels */
#define stdcfile_USE_GlobalTypedef   1 /**<@brief enable/disable the use Global Typedef */
#define stdcfile_USE_GlobalData      0 /**<@brief enable/disable the use Global Data */
#define stdcfile_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define stdcfile_USE_GlobalMacroApis 0 /**<@brief enable/disable the use Gobal macros functions */

/**
* \def __stdcfile_version__ definimos la version actual del proyecto.
* version 01v00d00 -> test 
* version 01v00d01 -> test 
* version 01v00d02 -> test
* version 01v00d03 -> test
* version 01v00d04 -> test
* version 01v00d05 -> test
*
* */
#ifndef __stdcfile_version__
#define __stdcfile_version__        version_SetNumber(01v00d00)
#endif

/* ======================[ END   labels enable/disable ]=============================== */


#if (version_QueryNumber(__stdcfile_version__,01v00d00))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ──────────────────────[ BEGIN __stdcfile_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
/* ======================[ BEGIN Global Macros/labels definition ]================= */
#if (stdcfile_USE_GlobalMacro == 1)

#define stdcfile_CHECK_FILE   0x00
#define stdcfile_CHECK_DIR    0x01

#define stdcfile_SORT_NAME    0x00
#define stdcfile_SORT_DATE    0x01
#define stdcfile_SORT_SIZE    0x02

#endif /* #if(stdcfile_USE_GlobalMacro == 1) */
/* ======================[ END   Global Macros/labels definition ]================= */

/* ======================[ BEGIN Global typedef      ]============================= */
#if (stdcfile_USE_GlobalTypedef == 1)

/**
* \typedef stdcfile_reg_t;
* \brief Estructura de datos para almacenar info de un archivos regular.
*   \param path ruta y nombre del archivo.
*   \param name Solo nombre con extension.
*   \param date Fecha de ultima actualizacion del Archivo del tipo \b time_t.
*   Podemos usar \b timestam_time2stamp(&a.date,buff,sizeof(buff));  para 
*   obtener un formato de impresion.  
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Jueves 11 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef struct __stdcfile_reg_t
{
  char *path;     /**<@brief path name del archivo. */
  char *name;     /**<@brief Solo nombre con extencion, para listado rapido. */
  time_t date;    /**<@brief Last date (de acceso, modificacion o cambio de estado). */
  ssize_t size;   /**<@brief tamaño del archivo. */
  /*char *ext;*/
  /*uint8_t type;*/
#if 0  
  time_t lastacc; /**<@brief Last file access */
  time_t lastmod; /**<@brief Last file modification */
  time_t stchang; /**<@brief Last status change */
#endif
}stdcfile_reg_t;

/**
* \typedef stdcfile_list_t;
* \brief Estructura de datos para almacenar un listado de archivos.
*   \param vitem vector de items del tipo \b stdcfile_reg_t.
*   \param nitem Numero de item almacenados en el vector.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Jueves 11 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
*/
typedef struct __stdcfile_list_t
{
  stdcfile_reg_t *vitem;
  uint32_t nitem;  
}stdcfile_list_t;



#if 0
/**
* \typedef stdcfile_tvar_ex_vT;
* \details Descripcion detallada sobre la redefinicion de un tipo de dato primitivo.
* \brief Descripcion breve sobre la redefinicion de un tipo de dato primitivo.
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Jueves 11 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.*
* */
typedef unsigned int stdcfile_tvar_ex_vT;


/**
* \typedef stdcfile_pfun_ex_fT;
* \details Descripcion detallada sobre la redefinicion de puntero a funcion.
* \brief  Descripcion breve sobre la redefinicion de puntero a funcion.
* Prototipo de la funcion, al acual debe apuntar:
*  + void * function ( void * arg )
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning". 
* \date Jueves 11 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef void * (*stdcfile_pfun_ex_fT) (void *); 


/**
* \struct stdcfile_struct_ex_sT;
* \brief Descripcion breve sobre el tipo de estructura.
* Elementos que componen a la Estructura de datos:
*  \li \ref vtchar;
*  \li \ref vtint;
*  \li \ref vtdouble;
* \version 01v01d01.
* \note nota sobre la estructura.
* \warning mensaje de "warning". 
* \date Jueves 11 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>  */
typedef struct
{
  char vtchar ;      /**<@brief descripcion del item vtchar */
  int vtint ;        /**<@brief descripcion del item vtint */
  double vtdouble ;  /**<@brief descripcion del item vtdouble */
} stdcfile_struct_ex_sT ; 

/**
* \union stdcfile_union_ex_uT;
* \brief Descripcion breve sobre el tipo de union.
* Elementos que componen la union:
*   \li \ref item1 
*   \li \ref item2 
* \version 01v01d01.
* \warning mensaje de "warning". 
* \date Jueves 11 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef union
{
  int item1;      /**<@brief descripcion breve del item1 de int type  */
  double item2;   /**<@brief descripcion breve del item2 de char type */
} stdcfile_union_ex_uT;


/**
* \enum stdcfile_enum_eT;
* \details Descripcion detallada sobre la redefinicion de enumeracio.
* \brief Descripcion breve sobre la redefinicion de este tipo de enumeracion.
* Elementos que componen la enumeracion:
*  \li \ref stdcfile_eITEM0 . 
*  \li \ref stdcfile_eITEM1 .
*  \li \ref stdcfile_eITEM2 .
* \version 01v01d01.
* \warning mensaje de "warning".
* \date Jueves 11 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE> */
typedef enum
{
  stdcfile_eITEM0 = 0, /**<@brief descripcion breve de la etiqueta 'stdcfile_eITEM0' de Enumeracion */
  stdcfile_eITEM1,     /**<@brief descripcion breve de la etiqueta 'stdcfile_eITEM1' de Enumeracion */
  stdcfile_eITEM2 = 5  /**<@brief descripcion breve de la etiqueta 'stdcfile_eITEM2' de Enumeracion */
} stdcfile_enum_eT;
#endif

#endif /* #if(stdcfile_USE_GlobalTypedef == 1) */
/* ======================[ END   Global typedef      ]============================= */

/* ======================[ BEGIN local declaration   ]============================= */
#ifdef __stdcfile_c__


#endif /* #ifdef __stdcfile_c__ */
/* ======================[ END   local declaration   ]============================= */

/* ======================[ BEGIN Global declaration  ]============================= */
#if (stdcfile_USE_GlobalData==1)
extern unsigned int stdcfile_global_ex; /**<@brief variable global example, brief of data */

#endif /* #if (stdcfile_USE_GlobalData==1) */
/* ======================[ END   Global declaration  ]============================= */

/* ======================[ BEGIN Global functions declaration ]==================== */
#if (stdcfile_USE_GlobalFunctions == 1)
/** 
* 
* ******************************************************************************* 
* \fn int stdcfile_test_01(unsigned int a,const char* name);
* \details Descripcion detallada sobre la funcion \ref stdcfile_test_01().
* \brief descripcion breve sobre la funcion, \ref stdcfile_test_01().
* \param a : Puntero al array.
* \param name : longitud del array.
* \return status de la opreacion.
*      \li 0, success
*      \li 1, failure
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Jueves 11 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE>  
*********************************************************************************/
bool_t stdcfile_CheckModeFile(const char *mode);

#if 0 
/**
* 
* ******************************************************************************* 
* \fn bool_t stdcfile_CheckPathFile(const char *path);
* \brief Funcion que realiza el chequeo de un archivo.
* \param path : Ruta y nombre del archivo a chequear su existencia.
* \return status de la opreacion.
*      \li TRUE, success
*      \li FALSE, failure, la ruta no corresponde a un archivo valido o el path
* pasado es NULL.
* \version 01v01d01.
* \note notq.
* \warning mensaje de "warning". 
* \date Jueves 11 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>
</PRE>  
*********************************************************************************/
bool_t stdcfile_CheckPathFile(const char *path);

/**
 * \fn bool_t * stdcfile_checkPathDir(const char * pathdir)
 * \brief Funcion para chequear si un una ruta corresponde a un direcotorio.
 * \param pathdir  : Ruta y nombre del Directorio sobre el cual consultar. 
 * \return 
 *  \li TRUE el \b pathdir corresponde a un directorio.
 *  \li FALSE el \b pathdir No corresponde a un directorio o el pathdir es NULL.
 * \version 01v01d01.
 * \note notq.
 * \warning mensaje de "warning". 
 * \date Jueves 11 de Marzo, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
 <PRE>
 </PRE>  
 */
bool_t stdcfile_checkPathDir(const char * pathdir);

#else




/**
 * \fn bool_t stdcfile_checkpath(const char * pathdir, uint8_t type)
 * \brief Fucnion para chequear si un una reuta corresponde a un direcotorio.
 * \param pathdir  : Ruta y nombre del Directorio sobre el cual consultar.
 * \param type     : Tipo de archivo a verificar
 *  \li stdcfile_CHECK_FILE : Archivo regular
 *  \li stdcfile_CHECK_DIR  : Directorios 
 * \return 
 *  \li TRUE el \b pathdir corresponde a un directorio.
 *  \li FALSE el \b pathdir No corresponde a un directorio.
 */
bool_t stdcfile_checkpath(const char * pathdir, uint8_t type);

#define stdcfile_CheckPathFile(Path) \
  stdcfile_checkpath(Path,stdcfile_CHECK_FILE)
  
#define stdcfile_checkPathDir(Pathdir) \
  stdcfile_checkpath(Path,stdcfile_CHECK_DIR)

#endif

/**
 * \fn int stdcfile_checkfile(const char * pathfile);
 * \brief Funcion para checquear si un archivo existe. 
 * \param pathfile : runta y nombre del archivo que se desea chequear.
 * \return 
 *  \li 0 , el pathfile o archivo existe 
 *  \li -1, el archivo no existe
 *  \li mayor a cero, surgio un error cuyo valor representa lo sucedido 'errno'.
 * \version 01v01d01.
 * \note note.
 * \warning mensaje de "warning". 
 * \date Jueves 11 de Marzo, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>

</PRE> */
static inline int stdcfile_checkfile(const char * pathfile)
{
  if(pathfile == NULL )
    return EINVAL;

  struct stat sb;  
  if (stat(pathfile, &sb) < 0)
    return errno;
  
  if(sb.st_mode & S_IFREG)
    return 0;
  /* No sucedio un error, pero no es un archivo */
  return -1; 
}

/**
 * \fn int stdcfile_checkdir(const char * pathdir);
 * \brief Funcion para checquear si un directorio existe. 
 * \param pathdir : runta y nombre de la carpeta/directorio.
 * \return 
 *  \li 0 , el pathdir o directorio existe 
 *  \li -1, el directorio no existe
 *  \li mayor a cero, surgio un error cuyo valor representa lo sucedido 'errno'.
 * \version 01v01d01.
 * \note para muchos sistemas necesitamos un valor de retorno TRUE o FALSE. 
 * En dicho caso podemos implementar esta funcion mediante la macro:
 * \b stdcfile_mcheckdir()
 * \warning mensaje de "warning". 
 * \date Jueves 11 de Marzo, 2021.
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>

</PRE> */
static inline int stdcfile_checkdir(const char * pathdir)
{
  if(pathdir == NULL )
    return EINVAL;

  struct stat sb;  
  if (stat(pathdir, &sb) < 0)
  {    
    return errno;
  }
    
  if(sb.st_mode & S_IFDIR)
    return 0;  
  /* No sucedio un error, pero no es un directorio */
  return -1; 
}

/** 
 * \def stdcfile_mcheckdir (Pathdir);
 * \brief macro funcion para chequear si un archivo existe.
 * \param Pathfile : runta y nombre del archivo.
 * \return return value
 *    \li TRUE, el Pathfile existe.
 *    \li FALSE, no se localizo el Pathfile.
 * \note note
 * \warning warning
 * \date Tuesday 09 de November, 2021.
 * \file stdcfile
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>
</PRE>*/
#define stdcfile_mcheckfile(Pathfile) (stdcfile_checkfile(Pathfile) == 0) ? TRUE:FALSE

/** 
 * \def stdcfile_mcheckdir (Pathdir);
 * \brief macro funcion para chequear si un archivo existe.
 * \param Pathdir : runta y nombre de la carpeta/directorio. 
 * \return return value
 *    \li TRUE, el pathdir existe.
 *    \li FALSE, no se localizo el pathdir.
 * \note note
 * \warning warning
 * \date Tuesday 09 de November, 2021.
 * \file stdcfile
 * \par meil
 * <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
 * \par example :
<PRE>
</PRE>*/
#define stdcfile_mcheckdir(Pathdir) (stdcfile_checkdir(Pathdir) == 0) ? TRUE:FALSE

/**
 * \fn void stdcfile_freelist(stdcfile_list_t* plist)
 * \brief Funcion para liberar una lista de archivos bajo un directorio
 * creada por el llamado a la funcion \ref stdcfile_listregdir().
 * \param plist     : Puntero a la lista de archivos que desea liberar.
 * \return estado del ordenamiento.
 *  \li TRUE , success
 *  \li FALSE, failure 
*/
void stdcfile_freelist(stdcfile_list_t* plist);

/**
 * \fn int32_t stdcfile_sortlistreg(stdcfile_list_t* plist, uint8_t sort);
 * \brief Funcion para ordenar una lista de archivos regulares.
 * \param plist     : Puntero a la lista de archivos regulares.
 * \param sort      : Metodo de ordenamiento. 
 *  \li stdcfile_SORT_NAME
 *  \li stdcfile_SORT_DATE
 *  \li stdcfile_SORT_SIZE
 
 * \return la cantidad de saltos realizados para ordenar la lista
 * para hacer un analisis estadistico. En caso de error retorna '-1'.  
*/
int32_t stdcfile_sortlistreg(stdcfile_list_t* plist, uint8_t sort);

/**
 * \fn stdcfile_list_t* stdcfile_listregdir(const char * pathdir, const char* ext);
 * \brief Fucnion que devuelve un listado de archivos regulares contenidos dentro de
 * un directorio, en funcion de la extencion del mismo (todos los que coinciden).
 * \param pathdir   : Ruta y nombre del directorio.
 * \param ext       : Extensio de los archivos a listar, si este es NULL lista 
 * todos los archivos regulares dentro del directorio.
 * \param sort      : Tipo de ordenamiento, por date/name.
 * \return Estructura que contiene el listado de los archicos regulares peticionados
 * en caso de falla retorna NULL.
*/
stdcfile_list_t* stdcfile_listregdir(const char * pathdir, const char* ext);

/**
 * \fn stdcfile_list_t* stdcfile_dup(tdcfile_list_t* plist);
 * \brief Funcion que devuelve un duplicado de una lista de archivos.
 * \param plist   : Lista de archivos.
 * \return El duplicado de la lista, en caso de error retorna NULL.
*/
stdcfile_list_t* stdcfile_dupregdir(stdcfile_list_t* plist);


/**
 * \fn void stdcfile_printlist(FILE * stream,stdcfile_list_t *plist)
 * \brief Fucnion que imprime por stdout el listado de archivo.
 * \param stream   : Stream por donde imprimimos el listado.
 * \param plist    : Listado de Archivos.
 * \return nothind
 */
void stdcfile_printlist(FILE * stream,stdcfile_list_t *plist);







#endif /* #if (stdcfile_USE_GlobalFunctions == 1) */
/* ======================[ END   Global functions declaration ]==================== */

/* ======================[ BEGIN Global Macros functions ]========================= */
#if ( stdcfile_USE_GlobalMacroApis == 1 )
/**
* 
* ********************************************************************************
* \def stdcfile_macro_ex(Arg1,Arg2)
* \details Descripcion detallada sobre la macro funcion \ref stdcfile_macro_ex().
* \n La distancia entre dos puntos \f$(x_1;y_1)\f$ y \f$(x_2;y_2)\f$ es:
* \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.   
*
* \brief Descripcion breve sobre la macro funcion \ref stdcfile_macro_ex().
* \param Arg1 : Argumento uno, de la macro funcion.
* \param Arg2 : Argumento dos, de la macro funcion.
* \return nothinig
* \version 01v01d01.
* \note nota.
* \warning mensaje de "warning".
* \date Jueves 11 de Marzo, 2021.
* \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.
* \par meil
* <PRE> + <b><i> piero.jel@gmail.com </i></b></PRE>
* \par example :
<PRE>

</PRE> 
*********************************************************************************/ 
#define stdcfile_macro_ex(Arg1,Arg2) \
{\
  Arg1 &= (~(0x01UL<< Arg1));\
  Arg1 &= (~(0x01UL<< Arg2));\
}


#endif /* #if ( stdcfile_USE_GlobalMacroApis == 1 ) */
/* ======================[ END   Global Macros functions ]========================= */



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ──────────────────────[ END   __stdcfile_version__    01v00d00 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (version_QueryNumber(__stdcfile_version__,01v00d01))
/* 
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ──────────────────────[ BEGIN __stdcfile_version__    01v00d01 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/



/*
┌───────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                       │  
│                                                                                       │  
│ ──────────────────────[ END   __stdcfile_version__    01v00d01 ]───────────────────── │
│                                                                                       │
│                                                                                       │             
└───────────────────────────────────────────────────────────────────────────────────────┘
*/
#endif



/*
*============================[close, cplusplus]============================
*/
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/*==============================[end of file]==============================*/
#endif /* #ifndef __stdcfile_h__ */
/*
*
* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*
* =============================[end of project file]========================================
*
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(stdcfile_projectEnable == 1) */

#define version_projectEnable 1 /**<@brief enable/disable the project */
/** **********************************************************************************//**
 * \addtogroup chip "Modulos correspondiente al chip SoC"
 * @{
 * \copyright  
 * 2021, Luccioni Jesús Emanuel \n
 * All rights reserved.\n 
 * This file is part of chip .\n
 * Redistribution is not allowed on binary and source forms, with or without \n
 * modification. Use is permitted with prior authorization by the copyright 
 * holder. &copy;
 * \file version.h
 * \author <b> JEL </b> - <i> Jesus Emanuel Luccioni </i>.    
 * \brief Descripcion breve. 
 * \version 01v01d00,
 * \date Viernes 28 de Octubre, 2016.
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
#ifndef __version_h__ 
#define __version_h__


#if(version_projectEnable == 1)
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * ==================================[begin of project version ]==================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*
 *============================[Open, cplusplus]============================
 */
 
#ifdef __cplusplus
extern "C" {
#endif 
/* 
 * *********************************************************************************************
 *
 * ==========================[ Begin labels enable/disable functions ]===========================
 *
 * ******************************************************************************************** 
 *   TODO: labels enable/disable functions
 */
#define version_USE_GlobalMacro       1 /**<@brief enable/disable the use Global Macros/Labels */
#define version_USE_GlobalTypedef     0 /**<@brief enable/disable the use Global Typedef */
#define version_USE_GlobalData        0 /**<@brief enable/disable the use Global Data */
#define version_USE_GlobalMacroApis   1 /**<@brief enable/disable the use Gobal macros functions */
/*
 * *********************************************************************************************
 *
 * ==========================[ End labels enable/disable functions ]===========================
 *
 * ******************************************************************************************** **/

/* 
 * *********************************************************************************************
 *
 * ==========================[ Begin Global Macros/labels definition]===========================
 *
 * ******************************************************************************************** **/
#if(version_USE_GlobalMacro == 1)

/**
* Formato :
*   <y1>v<y0>{d:e}<x>
*    |    |    |   |
*    |    |    |   +--> Cifra Menos Significativa 
*    |    |    |        indicamos los cambios pequeños interno al Modulo
*    |    |    |        no implican cambios en la forma de utilizarlos.
*    |    |    +--> d : develop, en desarrollo
*    |    |         e : estable
*    |    +--> Cifra "0~9" que indica el agregado de funcionalidades, no
*    |         modificaciones.
*    +--> Cifra mas Significativa del control de versionado 1~9
*    este implica cambios en el funcionamiento global, modificaciones
*    en la forma de usar las APIs.
*    should be
*       + 01v00d00
*       + 01v00d01
*       + 01v01d00
*       ...
*       ..
*       + 05v04e02
*/

 
/* 
 * 
 * ===================[ Begin, Listado Versionado 'd',estado en depuracion ]==================== 
 *
 */  

/*-- 01v00d00 */
#define version_List_01v00d00    0x10d0
#define version_List_01v00d01    0x10d1
#define version_List_01v00d02    0x10d2
#define version_List_01v00d03    0x10d3
#define version_List_01v00d04    0x10d4
#define version_List_01v00d05    0x10d5
#define version_List_01v00d06    0x10d6
#define version_List_01v00d07    0x10d7
#define version_List_01v00d08    0x10d8
#define version_List_01v00d09    0x10d9
/*-- 01v01d00 */
#define version_List_01v01d00    0x11d0
#define version_List_01v01d01    0x11d1
#define version_List_01v01d02    0x11d2
#define version_List_01v01d03    0x11d3
#define version_List_01v01d04    0x11d4
#define version_List_01v01d05    0x11d5
#define version_List_01v01d06    0x11d6
#define version_List_01v01d07    0x11d7
#define version_List_01v01d08    0x11d8
#define version_List_01v01d09    0x11d9
/*-- 01v02d00 */
#define version_List_01v02d00    0x12d0
#define version_List_01v02d01    0x12d1
#define version_List_01v02d02    0x12d2
#define version_List_01v02d03    0x12d3
#define version_List_01v02d04    0x12d4
#define version_List_01v02d05    0x12d5
#define version_List_01v02d06    0x12d6
#define version_List_01v02d07    0x12d7
#define version_List_01v02d08    0x12d8
#define version_List_01v02d09    0x12d9
/*-- 01v03d00 */
#define version_List_01v03d00    0x13d0
#define version_List_01v03d01    0x13d1
#define version_List_01v03d02    0x13d2
#define version_List_01v03d03    0x13d3
#define version_List_01v03d04    0x13d4
#define version_List_01v03d05    0x13d5
#define version_List_01v03d06    0x13d6
#define version_List_01v03d07    0x13d7
#define version_List_01v03d08    0x13d8
#define version_List_01v03d09    0x13d9
/*-- 01v04d00 */
#define version_List_01v04d00    0x14d0
#define version_List_01v04d01    0x14d1
#define version_List_01v04d02    0x14d2
#define version_List_01v04d03    0x14d3
#define version_List_01v04d04    0x14d4
#define version_List_01v04d05    0x14d5
#define version_List_01v04d06    0x14d6
#define version_List_01v04d07    0x14d7
#define version_List_01v04d08    0x14d8
#define version_List_01v04d09    0x14d9
/*-- 01v05d00 */
#define version_List_01v05d00    0x15d0
#define version_List_01v05d01    0x15d1
#define version_List_01v05d02    0x15d2
#define version_List_01v05d03    0x15d3
#define version_List_01v05d04    0x15d4
#define version_List_01v05d05    0x15d5
#define version_List_01v05d06    0x15d6
#define version_List_01v05d07    0x15d7
#define version_List_01v05d08    0x15d8
#define version_List_01v05d09    0x15d9
/*-- 01v06d00 */
#define version_List_01v06d00    0x16d0
#define version_List_01v06d01    0x16d1
#define version_List_01v06d02    0x16d2
#define version_List_01v06d03    0x16d3
#define version_List_01v06d04    0x16d4
#define version_List_01v06d05    0x16d5
#define version_List_01v06d06    0x16d6
#define version_List_01v06d07    0x16d7
#define version_List_01v06d08    0x16d8
#define version_List_01v06d09    0x16d9
/*-- 01v07d00 */
#define version_List_01v07d00    0x17d0
#define version_List_01v07d01    0x17d1
#define version_List_01v07d02    0x17d2
#define version_List_01v07d03    0x17d3
#define version_List_01v07d04    0x17d4
#define version_List_01v07d05    0x17d5
#define version_List_01v07d06    0x17d6
#define version_List_01v07d07    0x17d7
#define version_List_01v07d08    0x17d8
#define version_List_01v07d09    0x17d9
/*-- 01v08d00 */
#define version_List_01v08d00    0x18d0
#define version_List_01v08d01    0x18d1
#define version_List_01v08d02    0x18d2
#define version_List_01v08d03    0x18d3
#define version_List_01v08d04    0x18d4
#define version_List_01v08d05    0x18d5
#define version_List_01v08d06    0x18d6
#define version_List_01v08d07    0x18d7
#define version_List_01v08d08    0x18d8
#define version_List_01v08d09    0x18d9
/*-- 01v09d00 */
#define version_List_01v09d00    0x19d0
#define version_List_01v09d01    0x19d1
#define version_List_01v09d02    0x19d2
#define version_List_01v09d03    0x19d3
#define version_List_01v09d04    0x19d4
#define version_List_01v09d05    0x19d5
#define version_List_01v09d06    0x19d6
#define version_List_01v09d07    0x19d7
#define version_List_01v09d08    0x19d8
#define version_List_01v09d09    0x19d9
/*-- 02v00d00 */
#define version_List_02v00d00    0x20d0
#define version_List_02v00d01    0x20d1
#define version_List_02v00d02    0x20d2
#define version_List_02v00d03    0x20d3
#define version_List_02v00d04    0x20d4
#define version_List_02v00d05    0x20d5
#define version_List_02v00d06    0x20d6
#define version_List_02v00d07    0x20d7
#define version_List_02v00d08    0x20d8
#define version_List_02v00d09    0x20d9
/*-- 02v01d00 */
#define version_List_02v01d00    0x21d0
#define version_List_02v01d01    0x21d1
#define version_List_02v01d02    0x21d2
#define version_List_02v01d03    0x21d3
#define version_List_02v01d04    0x21d4
#define version_List_02v01d05    0x21d5
#define version_List_02v01d06    0x21d6
#define version_List_02v01d07    0x21d7
#define version_List_02v01d08    0x21d8
#define version_List_02v01d09    0x21d9
/*-- 02v02d00 */
#define version_List_02v02d00    0x22d0
#define version_List_02v02d01    0x22d1
#define version_List_02v02d02    0x22d2
#define version_List_02v02d03    0x22d3
#define version_List_02v02d04    0x22d4
#define version_List_02v02d05    0x22d5
#define version_List_02v02d06    0x22d6
#define version_List_02v02d07    0x22d7
#define version_List_02v02d08    0x22d8
#define version_List_02v02d09    0x22d9
/*-- 02v03d00 */
#define version_List_02v03d00    0x23d0
#define version_List_02v03d01    0x23d1
#define version_List_02v03d02    0x23d2
#define version_List_02v03d03    0x23d3
#define version_List_02v03d04    0x23d4
#define version_List_02v03d05    0x23d5
#define version_List_02v03d06    0x23d6
#define version_List_02v03d07    0x23d7
#define version_List_02v03d08    0x23d8
#define version_List_02v03d09    0x23d9
/*-- 02v04d00 */
#define version_List_02v04d00    0x24d0
#define version_List_02v04d01    0x24d1
#define version_List_02v04d02    0x24d2
#define version_List_02v04d03    0x24d3
#define version_List_02v04d04    0x24d4
#define version_List_02v04d05    0x24d5
#define version_List_02v04d06    0x24d6
#define version_List_02v04d07    0x24d7
#define version_List_02v04d08    0x24d8
#define version_List_02v04d09    0x24d9
/*-- 02v05d00 */
#define version_List_02v05d00    0x25d0
#define version_List_02v05d01    0x25d1
#define version_List_02v05d02    0x25d2
#define version_List_02v05d03    0x25d3
#define version_List_02v05d04    0x25d4
#define version_List_02v05d05    0x25d5
#define version_List_02v05d06    0x25d6
#define version_List_02v05d07    0x25d7
#define version_List_02v05d08    0x25d8
#define version_List_02v05d09    0x25d9
/*-- 02v06d00 */
#define version_List_02v06d00    0x26d0
#define version_List_02v06d01    0x26d1
#define version_List_02v06d02    0x26d2
#define version_List_02v06d03    0x26d3
#define version_List_02v06d04    0x26d4
#define version_List_02v06d05    0x26d5
#define version_List_02v06d06    0x26d6
#define version_List_02v06d07    0x26d7
#define version_List_02v06d08    0x26d8
#define version_List_02v06d09    0x26d9
/*-- 02v07d00 */
#define version_List_02v07d00    0x27d0
#define version_List_02v07d01    0x27d1
#define version_List_02v07d02    0x27d2
#define version_List_02v07d03    0x27d3
#define version_List_02v07d04    0x27d4
#define version_List_02v07d05    0x27d5
#define version_List_02v07d06    0x27d6
#define version_List_02v07d07    0x27d7
#define version_List_02v07d08    0x27d8
#define version_List_02v07d09    0x27d9
/*-- 02v08d00 */
#define version_List_02v08d00    0x28d0
#define version_List_02v08d01    0x28d1
#define version_List_02v08d02    0x28d2
#define version_List_02v08d03    0x28d3
#define version_List_02v08d04    0x28d4
#define version_List_02v08d05    0x28d5
#define version_List_02v08d06    0x28d6
#define version_List_02v08d07    0x28d7
#define version_List_02v08d08    0x28d8
#define version_List_02v08d09    0x28d9
/*-- 02v09d00 */
#define version_List_02v09d00    0x29d0
#define version_List_02v09d01    0x29d1
#define version_List_02v09d02    0x29d2
#define version_List_02v09d03    0x29d3
#define version_List_02v09d04    0x29d4
#define version_List_02v09d05    0x29d5
#define version_List_02v09d06    0x29d6
#define version_List_02v09d07    0x29d7
#define version_List_02v09d08    0x29d8
#define version_List_02v09d09    0x29d9
/*-- 03v00d00 */
#define version_List_03v00d00    0x30d0
#define version_List_03v00d01    0x30d1
#define version_List_03v00d02    0x30d2
#define version_List_03v00d03    0x30d3
#define version_List_03v00d04    0x30d4
#define version_List_03v00d05    0x30d5
#define version_List_03v00d06    0x30d6
#define version_List_03v00d07    0x30d7
#define version_List_03v00d08    0x30d8
#define version_List_03v00d09    0x30d9
/*-- 03v01d00 */
#define version_List_03v01d00    0x31d0
#define version_List_03v01d01    0x31d1
#define version_List_03v01d02    0x31d2
#define version_List_03v01d03    0x31d3
#define version_List_03v01d04    0x31d4
#define version_List_03v01d05    0x31d5
#define version_List_03v01d06    0x31d6
#define version_List_03v01d07    0x31d7
#define version_List_03v01d08    0x31d8
#define version_List_03v01d09    0x31d9
/*-- 03v02d00 */
#define version_List_03v02d00    0x32d0
#define version_List_03v02d01    0x32d1
#define version_List_03v02d02    0x32d2
#define version_List_03v02d03    0x32d3
#define version_List_03v02d04    0x32d4
#define version_List_03v02d05    0x32d5
#define version_List_03v02d06    0x32d6
#define version_List_03v02d07    0x32d7
#define version_List_03v02d08    0x32d8
#define version_List_03v02d09    0x32d9
/*-- 03v03d00 */
#define version_List_03v03d00    0x33d0
#define version_List_03v03d01    0x33d1
#define version_List_03v03d02    0x33d2
#define version_List_03v03d03    0x33d3
#define version_List_03v03d04    0x33d4
#define version_List_03v03d05    0x33d5
#define version_List_03v03d06    0x33d6
#define version_List_03v03d07    0x33d7
#define version_List_03v03d08    0x33d8
#define version_List_03v03d09    0x33d9
/*-- 03v04d00 */
#define version_List_03v04d00    0x34d0
#define version_List_03v04d01    0x34d1
#define version_List_03v04d02    0x34d2
#define version_List_03v04d03    0x34d3
#define version_List_03v04d04    0x34d4
#define version_List_03v04d05    0x34d5
#define version_List_03v04d06    0x34d6
#define version_List_03v04d07    0x34d7
#define version_List_03v04d08    0x34d8
#define version_List_03v04d09    0x34d9
/*-- 03v05d00 */
#define version_List_03v05d00    0x35d0
#define version_List_03v05d01    0x35d1
#define version_List_03v05d02    0x35d2
#define version_List_03v05d03    0x35d3
#define version_List_03v05d04    0x35d4
#define version_List_03v05d05    0x35d5
#define version_List_03v05d06    0x35d6
#define version_List_03v05d07    0x35d7
#define version_List_03v05d08    0x35d8
#define version_List_03v05d09    0x35d9
/*-- 03v06d00 */
#define version_List_03v06d00    0x36d0
#define version_List_03v06d01    0x36d1
#define version_List_03v06d02    0x36d2
#define version_List_03v06d03    0x36d3
#define version_List_03v06d04    0x36d4
#define version_List_03v06d05    0x36d5
#define version_List_03v06d06    0x36d6
#define version_List_03v06d07    0x36d7
#define version_List_03v06d08    0x36d8
#define version_List_03v06d09    0x36d9
/*-- 03v07d00 */
#define version_List_03v07d00    0x37d0
#define version_List_03v07d01    0x37d1
#define version_List_03v07d02    0x37d2
#define version_List_03v07d03    0x37d3
#define version_List_03v07d04    0x37d4
#define version_List_03v07d05    0x37d5
#define version_List_03v07d06    0x37d6
#define version_List_03v07d07    0x37d7
#define version_List_03v07d08    0x37d8
#define version_List_03v07d09    0x37d9
/*-- 03v08d00 */
#define version_List_03v08d00    0x38d0
#define version_List_03v08d01    0x38d1
#define version_List_03v08d02    0x38d2
#define version_List_03v08d03    0x38d3
#define version_List_03v08d04    0x38d4
#define version_List_03v08d05    0x38d5
#define version_List_03v08d06    0x38d6
#define version_List_03v08d07    0x38d7
#define version_List_03v08d08    0x38d8
#define version_List_03v08d09    0x38d9
/*-- 03v09d00 */
#define version_List_03v09d00    0x39d0
#define version_List_03v09d01    0x39d1
#define version_List_03v09d02    0x39d2
#define version_List_03v09d03    0x39d3
#define version_List_03v09d04    0x39d4
#define version_List_03v09d05    0x39d5
#define version_List_03v09d06    0x39d6
#define version_List_03v09d07    0x39d7
#define version_List_03v09d08    0x39d8
#define version_List_03v09d09    0x39d9
/*-- 04v00d00 */
#define version_List_04v00d00    0x40d0
#define version_List_04v00d01    0x40d1
#define version_List_04v00d02    0x40d2
#define version_List_04v00d03    0x40d3
#define version_List_04v00d04    0x40d4
#define version_List_04v00d05    0x40d5
#define version_List_04v00d06    0x40d6
#define version_List_04v00d07    0x40d7
#define version_List_04v00d08    0x40d8
#define version_List_04v00d09    0x40d9
/*-- 04v01d00 */
#define version_List_04v01d00    0x41d0
#define version_List_04v01d01    0x41d1
#define version_List_04v01d02    0x41d2
#define version_List_04v01d03    0x41d3
#define version_List_04v01d04    0x41d4
#define version_List_04v01d05    0x41d5
#define version_List_04v01d06    0x41d6
#define version_List_04v01d07    0x41d7
#define version_List_04v01d08    0x41d8
#define version_List_04v01d09    0x41d9
/*-- 04v02d00 */
#define version_List_04v02d00    0x42d0
#define version_List_04v02d01    0x42d1
#define version_List_04v02d02    0x42d2
#define version_List_04v02d03    0x42d3
#define version_List_04v02d04    0x42d4
#define version_List_04v02d05    0x42d5
#define version_List_04v02d06    0x42d6
#define version_List_04v02d07    0x42d7
#define version_List_04v02d08    0x42d8
#define version_List_04v02d09    0x42d9
/*-- 04v03d00 */
#define version_List_04v03d00    0x43d0
#define version_List_04v03d01    0x43d1
#define version_List_04v03d02    0x43d2
#define version_List_04v03d03    0x43d3
#define version_List_04v03d04    0x43d4
#define version_List_04v03d05    0x43d5
#define version_List_04v03d06    0x43d6
#define version_List_04v03d07    0x43d7
#define version_List_04v03d08    0x43d8
#define version_List_04v03d09    0x43d9
/*-- 04v04d00 */
#define version_List_04v04d00    0x44d0
#define version_List_04v04d01    0x44d1
#define version_List_04v04d02    0x44d2
#define version_List_04v04d03    0x44d3
#define version_List_04v04d04    0x44d4
#define version_List_04v04d05    0x44d5
#define version_List_04v04d06    0x44d6
#define version_List_04v04d07    0x44d7
#define version_List_04v04d08    0x44d8
#define version_List_04v04d09    0x44d9
/*-- 04v05d00 */
#define version_List_04v05d00    0x45d0
#define version_List_04v05d01    0x45d1
#define version_List_04v05d02    0x45d2
#define version_List_04v05d03    0x45d3
#define version_List_04v05d04    0x45d4
#define version_List_04v05d05    0x45d5
#define version_List_04v05d06    0x45d6
#define version_List_04v05d07    0x45d7
#define version_List_04v05d08    0x45d8
#define version_List_04v05d09    0x45d9
/*-- 04v06d00 */
#define version_List_04v06d00    0x46d0
#define version_List_04v06d01    0x46d1
#define version_List_04v06d02    0x46d2
#define version_List_04v06d03    0x46d3
#define version_List_04v06d04    0x46d4
#define version_List_04v06d05    0x46d5
#define version_List_04v06d06    0x46d6
#define version_List_04v06d07    0x46d7
#define version_List_04v06d08    0x46d8
#define version_List_04v06d09    0x46d9
/*-- 04v07d00 */
#define version_List_04v07d00    0x47d0
#define version_List_04v07d01    0x47d1
#define version_List_04v07d02    0x47d2
#define version_List_04v07d03    0x47d3
#define version_List_04v07d04    0x47d4
#define version_List_04v07d05    0x47d5
#define version_List_04v07d06    0x47d6
#define version_List_04v07d07    0x47d7
#define version_List_04v07d08    0x47d8
#define version_List_04v07d09    0x47d9
/*-- 04v08d00 */
#define version_List_04v08d00    0x48d0
#define version_List_04v08d01    0x48d1
#define version_List_04v08d02    0x48d2
#define version_List_04v08d03    0x48d3
#define version_List_04v08d04    0x48d4
#define version_List_04v08d05    0x48d5
#define version_List_04v08d06    0x48d6
#define version_List_04v08d07    0x48d7
#define version_List_04v08d08    0x48d8
#define version_List_04v08d09    0x48d9
/*-- 04v09d00 */
#define version_List_04v09d00    0x49d0
#define version_List_04v09d01    0x49d1
#define version_List_04v09d02    0x49d2
#define version_List_04v09d03    0x49d3
#define version_List_04v09d04    0x49d4
#define version_List_04v09d05    0x49d5
#define version_List_04v09d06    0x49d6
#define version_List_04v09d07    0x49d7
#define version_List_04v09d08    0x49d8
#define version_List_04v09d09    0x49d9
/*-- 05v00d00 */
#define version_List_05v00d00    0x50d0
#define version_List_05v00d01    0x50d1
#define version_List_05v00d02    0x50d2
#define version_List_05v00d03    0x50d3
#define version_List_05v00d04    0x50d4
#define version_List_05v00d05    0x50d5
#define version_List_05v00d06    0x50d6
#define version_List_05v00d07    0x50d7
#define version_List_05v00d08    0x50d8
#define version_List_05v00d09    0x50d9
/*-- 05v01d00 */
#define version_List_05v01d00    0x51d0
#define version_List_05v01d01    0x51d1
#define version_List_05v01d02    0x51d2
#define version_List_05v01d03    0x51d3
#define version_List_05v01d04    0x51d4
#define version_List_05v01d05    0x51d5
#define version_List_05v01d06    0x51d6
#define version_List_05v01d07    0x51d7
#define version_List_05v01d08    0x51d8
#define version_List_05v01d09    0x51d9
/*-- 05v02d00 */
#define version_List_05v02d00    0x52d0
#define version_List_05v02d01    0x52d1
#define version_List_05v02d02    0x52d2
#define version_List_05v02d03    0x52d3
#define version_List_05v02d04    0x52d4
#define version_List_05v02d05    0x52d5
#define version_List_05v02d06    0x52d6
#define version_List_05v02d07    0x52d7
#define version_List_05v02d08    0x52d8
#define version_List_05v02d09    0x52d9
/*-- 05v03d00 */
#define version_List_05v03d00    0x53d0
#define version_List_05v03d01    0x53d1
#define version_List_05v03d02    0x53d2
#define version_List_05v03d03    0x53d3
#define version_List_05v03d04    0x53d4
#define version_List_05v03d05    0x53d5
#define version_List_05v03d06    0x53d6
#define version_List_05v03d07    0x53d7
#define version_List_05v03d08    0x53d8
#define version_List_05v03d09    0x53d9
/*-- 05v04d00 */
#define version_List_05v04d00    0x54d0
#define version_List_05v04d01    0x54d1
#define version_List_05v04d02    0x54d2
#define version_List_05v04d03    0x54d3
#define version_List_05v04d04    0x54d4
#define version_List_05v04d05    0x54d5
#define version_List_05v04d06    0x54d6
#define version_List_05v04d07    0x54d7
#define version_List_05v04d08    0x54d8
#define version_List_05v04d09    0x54d9
/*-- 05v05d00 */
#define version_List_05v05d00    0x55d0
#define version_List_05v05d01    0x55d1
#define version_List_05v05d02    0x55d2
#define version_List_05v05d03    0x55d3
#define version_List_05v05d04    0x55d4
#define version_List_05v05d05    0x55d5
#define version_List_05v05d06    0x55d6
#define version_List_05v05d07    0x55d7
#define version_List_05v05d08    0x55d8
#define version_List_05v05d09    0x55d9
/*-- 05v06d00 */
#define version_List_05v06d00    0x56d0
#define version_List_05v06d01    0x56d1
#define version_List_05v06d02    0x56d2
#define version_List_05v06d03    0x56d3
#define version_List_05v06d04    0x56d4
#define version_List_05v06d05    0x56d5
#define version_List_05v06d06    0x56d6
#define version_List_05v06d07    0x56d7
#define version_List_05v06d08    0x56d8
#define version_List_05v06d09    0x56d9
/*-- 05v07d00 */
#define version_List_05v07d00    0x57d0
#define version_List_05v07d01    0x57d1
#define version_List_05v07d02    0x57d2
#define version_List_05v07d03    0x57d3
#define version_List_05v07d04    0x57d4
#define version_List_05v07d05    0x57d5
#define version_List_05v07d06    0x57d6
#define version_List_05v07d07    0x57d7
#define version_List_05v07d08    0x57d8
#define version_List_05v07d09    0x57d9
/*-- 05v08d00 */
#define version_List_05v08d00    0x58d0
#define version_List_05v08d01    0x58d1
#define version_List_05v08d02    0x58d2
#define version_List_05v08d03    0x58d3
#define version_List_05v08d04    0x58d4
#define version_List_05v08d05    0x58d5
#define version_List_05v08d06    0x58d6
#define version_List_05v08d07    0x58d7
#define version_List_05v08d08    0x58d8
#define version_List_05v08d09    0x58d9
/*-- 05v09d00 */
#define version_List_05v09d00    0x59d0
#define version_List_05v09d01    0x59d1
#define version_List_05v09d02    0x59d2
#define version_List_05v09d03    0x59d3
#define version_List_05v09d04    0x59d4
#define version_List_05v09d05    0x59d5
#define version_List_05v09d06    0x59d6
#define version_List_05v09d07    0x59d7
#define version_List_05v09d08    0x59d8
#define version_List_05v09d09    0x59d9
/*-- 06v00d00 */
#define version_List_06v00d00    0x60d0
#define version_List_06v00d01    0x60d1
#define version_List_06v00d02    0x60d2
#define version_List_06v00d03    0x60d3
#define version_List_06v00d04    0x60d4
#define version_List_06v00d05    0x60d5
#define version_List_06v00d06    0x60d6
#define version_List_06v00d07    0x60d7
#define version_List_06v00d08    0x60d8
#define version_List_06v00d09    0x60d9
/*-- 06v01d00 */
#define version_List_06v01d00    0x61d0
#define version_List_06v01d01    0x61d1
#define version_List_06v01d02    0x61d2
#define version_List_06v01d03    0x61d3
#define version_List_06v01d04    0x61d4
#define version_List_06v01d05    0x61d5
#define version_List_06v01d06    0x61d6
#define version_List_06v01d07    0x61d7
#define version_List_06v01d08    0x61d8
#define version_List_06v01d09    0x61d9
/*-- 06v02d00 */
#define version_List_06v02d00    0x62d0
#define version_List_06v02d01    0x62d1
#define version_List_06v02d02    0x62d2
#define version_List_06v02d03    0x62d3
#define version_List_06v02d04    0x62d4
#define version_List_06v02d05    0x62d5
#define version_List_06v02d06    0x62d6
#define version_List_06v02d07    0x62d7
#define version_List_06v02d08    0x62d8
#define version_List_06v02d09    0x62d9
/*-- 06v03d00 */
#define version_List_06v03d00    0x63d0
#define version_List_06v03d01    0x63d1
#define version_List_06v03d02    0x63d2
#define version_List_06v03d03    0x63d3
#define version_List_06v03d04    0x63d4
#define version_List_06v03d05    0x63d5
#define version_List_06v03d06    0x63d6
#define version_List_06v03d07    0x63d7
#define version_List_06v03d08    0x63d8
#define version_List_06v03d09    0x63d9
/*-- 06v04d00 */
#define version_List_06v04d00    0x64d0
#define version_List_06v04d01    0x64d1
#define version_List_06v04d02    0x64d2
#define version_List_06v04d03    0x64d3
#define version_List_06v04d04    0x64d4
#define version_List_06v04d05    0x64d5
#define version_List_06v04d06    0x64d6
#define version_List_06v04d07    0x64d7
#define version_List_06v04d08    0x64d8
#define version_List_06v04d09    0x64d9
/*-- 06v05d00 */
#define version_List_06v05d00    0x65d0
#define version_List_06v05d01    0x65d1
#define version_List_06v05d02    0x65d2
#define version_List_06v05d03    0x65d3
#define version_List_06v05d04    0x65d4
#define version_List_06v05d05    0x65d5
#define version_List_06v05d06    0x65d6
#define version_List_06v05d07    0x65d7
#define version_List_06v05d08    0x65d8
#define version_List_06v05d09    0x65d9
/*-- 06v06d00 */
#define version_List_06v06d00    0x66d0
#define version_List_06v06d01    0x66d1
#define version_List_06v06d02    0x66d2
#define version_List_06v06d03    0x66d3
#define version_List_06v06d04    0x66d4
#define version_List_06v06d05    0x66d5
#define version_List_06v06d06    0x66d6
#define version_List_06v06d07    0x66d7
#define version_List_06v06d08    0x66d8
#define version_List_06v06d09    0x66d9
/*-- 06v07d00 */
#define version_List_06v07d00    0x67d0
#define version_List_06v07d01    0x67d1
#define version_List_06v07d02    0x67d2
#define version_List_06v07d03    0x67d3
#define version_List_06v07d04    0x67d4
#define version_List_06v07d05    0x67d5
#define version_List_06v07d06    0x67d6
#define version_List_06v07d07    0x67d7
#define version_List_06v07d08    0x67d8
#define version_List_06v07d09    0x67d9
/*-- 06v08d00 */
#define version_List_06v08d00    0x68d0
#define version_List_06v08d01    0x68d1
#define version_List_06v08d02    0x68d2
#define version_List_06v08d03    0x68d3
#define version_List_06v08d04    0x68d4
#define version_List_06v08d05    0x68d5
#define version_List_06v08d06    0x68d6
#define version_List_06v08d07    0x68d7
#define version_List_06v08d08    0x68d8
#define version_List_06v08d09    0x68d9
/*-- 06v09d00 */
#define version_List_06v09d00    0x69d0
#define version_List_06v09d01    0x69d1
#define version_List_06v09d02    0x69d2
#define version_List_06v09d03    0x69d3
#define version_List_06v09d04    0x69d4
#define version_List_06v09d05    0x69d5
#define version_List_06v09d06    0x69d6
#define version_List_06v09d07    0x69d7
#define version_List_06v09d08    0x69d8
#define version_List_06v09d09    0x69d9
/*-- 07v00d00 */
#define version_List_07v00d00    0x70d0
#define version_List_07v00d01    0x70d1
#define version_List_07v00d02    0x70d2
#define version_List_07v00d03    0x70d3
#define version_List_07v00d04    0x70d4
#define version_List_07v00d05    0x70d5
#define version_List_07v00d06    0x70d6
#define version_List_07v00d07    0x70d7
#define version_List_07v00d08    0x70d8
#define version_List_07v00d09    0x70d9
/*-- 07v01d00 */
#define version_List_07v01d00    0x71d0
#define version_List_07v01d01    0x71d1
#define version_List_07v01d02    0x71d2
#define version_List_07v01d03    0x71d3
#define version_List_07v01d04    0x71d4
#define version_List_07v01d05    0x71d5
#define version_List_07v01d06    0x71d6
#define version_List_07v01d07    0x71d7
#define version_List_07v01d08    0x71d8
#define version_List_07v01d09    0x71d9
/*-- 07v02d00 */
#define version_List_07v02d00    0x72d0
#define version_List_07v02d01    0x72d1
#define version_List_07v02d02    0x72d2
#define version_List_07v02d03    0x72d3
#define version_List_07v02d04    0x72d4
#define version_List_07v02d05    0x72d5
#define version_List_07v02d06    0x72d6
#define version_List_07v02d07    0x72d7
#define version_List_07v02d08    0x72d8
#define version_List_07v02d09    0x72d9
/*-- 07v03d00 */
#define version_List_07v03d00    0x73d0
#define version_List_07v03d01    0x73d1
#define version_List_07v03d02    0x73d2
#define version_List_07v03d03    0x73d3
#define version_List_07v03d04    0x73d4
#define version_List_07v03d05    0x73d5
#define version_List_07v03d06    0x73d6
#define version_List_07v03d07    0x73d7
#define version_List_07v03d08    0x73d8
#define version_List_07v03d09    0x73d9
/*-- 07v04d00 */
#define version_List_07v04d00    0x74d0
#define version_List_07v04d01    0x74d1
#define version_List_07v04d02    0x74d2
#define version_List_07v04d03    0x74d3
#define version_List_07v04d04    0x74d4
#define version_List_07v04d05    0x74d5
#define version_List_07v04d06    0x74d6
#define version_List_07v04d07    0x74d7
#define version_List_07v04d08    0x74d8
#define version_List_07v04d09    0x74d9
/*-- 07v05d00 */
#define version_List_07v05d00    0x75d0
#define version_List_07v05d01    0x75d1
#define version_List_07v05d02    0x75d2
#define version_List_07v05d03    0x75d3
#define version_List_07v05d04    0x75d4
#define version_List_07v05d05    0x75d5
#define version_List_07v05d06    0x75d6
#define version_List_07v05d07    0x75d7
#define version_List_07v05d08    0x75d8
#define version_List_07v05d09    0x75d9
/*-- 07v06d00 */
#define version_List_07v06d00    0x76d0
#define version_List_07v06d01    0x76d1
#define version_List_07v06d02    0x76d2
#define version_List_07v06d03    0x76d3
#define version_List_07v06d04    0x76d4
#define version_List_07v06d05    0x76d5
#define version_List_07v06d06    0x76d6
#define version_List_07v06d07    0x76d7
#define version_List_07v06d08    0x76d8
#define version_List_07v06d09    0x76d9
/*-- 07v07d00 */
#define version_List_07v07d00    0x77d0
#define version_List_07v07d01    0x77d1
#define version_List_07v07d02    0x77d2
#define version_List_07v07d03    0x77d3
#define version_List_07v07d04    0x77d4
#define version_List_07v07d05    0x77d5
#define version_List_07v07d06    0x77d6
#define version_List_07v07d07    0x77d7
#define version_List_07v07d08    0x77d8
#define version_List_07v07d09    0x77d9
/*-- 07v08d00 */
#define version_List_07v08d00    0x78d0
#define version_List_07v08d01    0x78d1
#define version_List_07v08d02    0x78d2
#define version_List_07v08d03    0x78d3
#define version_List_07v08d04    0x78d4
#define version_List_07v08d05    0x78d5
#define version_List_07v08d06    0x78d6
#define version_List_07v08d07    0x78d7
#define version_List_07v08d08    0x78d8
#define version_List_07v08d09    0x78d9
/*-- 07v09d00 */
#define version_List_07v09d00    0x79d0
#define version_List_07v09d01    0x79d1
#define version_List_07v09d02    0x79d2
#define version_List_07v09d03    0x79d3
#define version_List_07v09d04    0x79d4
#define version_List_07v09d05    0x79d5
#define version_List_07v09d06    0x79d6
#define version_List_07v09d07    0x79d7
#define version_List_07v09d08    0x79d8
#define version_List_07v09d09    0x79d9
/*-- 08v00d00 */
#define version_List_08v00d00    0x80d0
#define version_List_08v00d01    0x80d1
#define version_List_08v00d02    0x80d2
#define version_List_08v00d03    0x80d3
#define version_List_08v00d04    0x80d4
#define version_List_08v00d05    0x80d5
#define version_List_08v00d06    0x80d6
#define version_List_08v00d07    0x80d7
#define version_List_08v00d08    0x80d8
#define version_List_08v00d09    0x80d9
/*-- 08v01d00 */
#define version_List_08v01d00    0x81d0
#define version_List_08v01d01    0x81d1
#define version_List_08v01d02    0x81d2
#define version_List_08v01d03    0x81d3
#define version_List_08v01d04    0x81d4
#define version_List_08v01d05    0x81d5
#define version_List_08v01d06    0x81d6
#define version_List_08v01d07    0x81d7
#define version_List_08v01d08    0x81d8
#define version_List_08v01d09    0x81d9
/*-- 08v02d00 */
#define version_List_08v02d00    0x82d0
#define version_List_08v02d01    0x82d1
#define version_List_08v02d02    0x82d2
#define version_List_08v02d03    0x82d3
#define version_List_08v02d04    0x82d4
#define version_List_08v02d05    0x82d5
#define version_List_08v02d06    0x82d6
#define version_List_08v02d07    0x82d7
#define version_List_08v02d08    0x82d8
#define version_List_08v02d09    0x82d9
/*-- 08v03d00 */
#define version_List_08v03d00    0x83d0
#define version_List_08v03d01    0x83d1
#define version_List_08v03d02    0x83d2
#define version_List_08v03d03    0x83d3
#define version_List_08v03d04    0x83d4
#define version_List_08v03d05    0x83d5
#define version_List_08v03d06    0x83d6
#define version_List_08v03d07    0x83d7
#define version_List_08v03d08    0x83d8
#define version_List_08v03d09    0x83d9
/*-- 08v04d00 */
#define version_List_08v04d00    0x84d0
#define version_List_08v04d01    0x84d1
#define version_List_08v04d02    0x84d2
#define version_List_08v04d03    0x84d3
#define version_List_08v04d04    0x84d4
#define version_List_08v04d05    0x84d5
#define version_List_08v04d06    0x84d6
#define version_List_08v04d07    0x84d7
#define version_List_08v04d08    0x84d8
#define version_List_08v04d09    0x84d9
/*-- 08v05d00 */
#define version_List_08v05d00    0x85d0
#define version_List_08v05d01    0x85d1
#define version_List_08v05d02    0x85d2
#define version_List_08v05d03    0x85d3
#define version_List_08v05d04    0x85d4
#define version_List_08v05d05    0x85d5
#define version_List_08v05d06    0x85d6
#define version_List_08v05d07    0x85d7
#define version_List_08v05d08    0x85d8
#define version_List_08v05d09    0x85d9
/*-- 08v06d00 */
#define version_List_08v06d00    0x86d0
#define version_List_08v06d01    0x86d1
#define version_List_08v06d02    0x86d2
#define version_List_08v06d03    0x86d3
#define version_List_08v06d04    0x86d4
#define version_List_08v06d05    0x86d5
#define version_List_08v06d06    0x86d6
#define version_List_08v06d07    0x86d7
#define version_List_08v06d08    0x86d8
#define version_List_08v06d09    0x86d9
/*-- 08v07d00 */
#define version_List_08v07d00    0x87d0
#define version_List_08v07d01    0x87d1
#define version_List_08v07d02    0x87d2
#define version_List_08v07d03    0x87d3
#define version_List_08v07d04    0x87d4
#define version_List_08v07d05    0x87d5
#define version_List_08v07d06    0x87d6
#define version_List_08v07d07    0x87d7
#define version_List_08v07d08    0x87d8
#define version_List_08v07d09    0x87d9
/*-- 08v08d00 */
#define version_List_08v08d00    0x88d0
#define version_List_08v08d01    0x88d1
#define version_List_08v08d02    0x88d2
#define version_List_08v08d03    0x88d3
#define version_List_08v08d04    0x88d4
#define version_List_08v08d05    0x88d5
#define version_List_08v08d06    0x88d6
#define version_List_08v08d07    0x88d7
#define version_List_08v08d08    0x88d8
#define version_List_08v08d09    0x88d9
/*-- 08v09d00 */
#define version_List_08v09d00    0x89d0
#define version_List_08v09d01    0x89d1
#define version_List_08v09d02    0x89d2
#define version_List_08v09d03    0x89d3
#define version_List_08v09d04    0x89d4
#define version_List_08v09d05    0x89d5
#define version_List_08v09d06    0x89d6
#define version_List_08v09d07    0x89d7
#define version_List_08v09d08    0x89d8
#define version_List_08v09d09    0x89d9
/*-- 09v00d00 */
#define version_List_09v00d00    0x90d0
#define version_List_09v00d01    0x90d1
#define version_List_09v00d02    0x90d2
#define version_List_09v00d03    0x90d3
#define version_List_09v00d04    0x90d4
#define version_List_09v00d05    0x90d5
#define version_List_09v00d06    0x90d6
#define version_List_09v00d07    0x90d7
#define version_List_09v00d08    0x90d8
#define version_List_09v00d09    0x90d9
/*-- 09v01d00 */
#define version_List_09v01d00    0x91d0
#define version_List_09v01d01    0x91d1
#define version_List_09v01d02    0x91d2
#define version_List_09v01d03    0x91d3
#define version_List_09v01d04    0x91d4
#define version_List_09v01d05    0x91d5
#define version_List_09v01d06    0x91d6
#define version_List_09v01d07    0x91d7
#define version_List_09v01d08    0x91d8
#define version_List_09v01d09    0x91d9
/*-- 09v02d00 */
#define version_List_09v02d00    0x92d0
#define version_List_09v02d01    0x92d1
#define version_List_09v02d02    0x92d2
#define version_List_09v02d03    0x92d3
#define version_List_09v02d04    0x92d4
#define version_List_09v02d05    0x92d5
#define version_List_09v02d06    0x92d6
#define version_List_09v02d07    0x92d7
#define version_List_09v02d08    0x92d8
#define version_List_09v02d09    0x92d9
/*-- 09v03d00 */
#define version_List_09v03d00    0x93d0
#define version_List_09v03d01    0x93d1
#define version_List_09v03d02    0x93d2
#define version_List_09v03d03    0x93d3
#define version_List_09v03d04    0x93d4
#define version_List_09v03d05    0x93d5
#define version_List_09v03d06    0x93d6
#define version_List_09v03d07    0x93d7
#define version_List_09v03d08    0x93d8
#define version_List_09v03d09    0x93d9
/*-- 09v04d00 */
#define version_List_09v04d00    0x94d0
#define version_List_09v04d01    0x94d1
#define version_List_09v04d02    0x94d2
#define version_List_09v04d03    0x94d3
#define version_List_09v04d04    0x94d4
#define version_List_09v04d05    0x94d5
#define version_List_09v04d06    0x94d6
#define version_List_09v04d07    0x94d7
#define version_List_09v04d08    0x94d8
#define version_List_09v04d09    0x94d9
/*-- 09v05d00 */
#define version_List_09v05d00    0x95d0
#define version_List_09v05d01    0x95d1
#define version_List_09v05d02    0x95d2
#define version_List_09v05d03    0x95d3
#define version_List_09v05d04    0x95d4
#define version_List_09v05d05    0x95d5
#define version_List_09v05d06    0x95d6
#define version_List_09v05d07    0x95d7
#define version_List_09v05d08    0x95d8
#define version_List_09v05d09    0x95d9
/*-- 09v06d00 */
#define version_List_09v06d00    0x96d0
#define version_List_09v06d01    0x96d1
#define version_List_09v06d02    0x96d2
#define version_List_09v06d03    0x96d3
#define version_List_09v06d04    0x96d4
#define version_List_09v06d05    0x96d5
#define version_List_09v06d06    0x96d6
#define version_List_09v06d07    0x96d7
#define version_List_09v06d08    0x96d8
#define version_List_09v06d09    0x96d9
/*-- 09v07d00 */
#define version_List_09v07d00    0x97d0
#define version_List_09v07d01    0x97d1
#define version_List_09v07d02    0x97d2
#define version_List_09v07d03    0x97d3
#define version_List_09v07d04    0x97d4
#define version_List_09v07d05    0x97d5
#define version_List_09v07d06    0x97d6
#define version_List_09v07d07    0x97d7
#define version_List_09v07d08    0x97d8
#define version_List_09v07d09    0x97d9
/*-- 09v08d00 */
#define version_List_09v08d00    0x98d0
#define version_List_09v08d01    0x98d1
#define version_List_09v08d02    0x98d2
#define version_List_09v08d03    0x98d3
#define version_List_09v08d04    0x98d4
#define version_List_09v08d05    0x98d5
#define version_List_09v08d06    0x98d6
#define version_List_09v08d07    0x98d7
#define version_List_09v08d08    0x98d8
#define version_List_09v08d09    0x98d9
/*-- 09v09d00 */
#define version_List_09v09d00    0x99d0
#define version_List_09v09d01    0x99d1
#define version_List_09v09d02    0x99d2
#define version_List_09v09d03    0x99d3
#define version_List_09v09d04    0x99d4
#define version_List_09v09d05    0x99d5
#define version_List_09v09d06    0x99d6
#define version_List_09v09d07    0x99d7
#define version_List_09v09d08    0x99d8
#define version_List_09v09d09    0x99d9

/*-- 10v00e00 */
#define version_List_10v00e00    0x100e0
#define version_List_10v00e01    0x100e1
#define version_List_10v00e02    0x100e2
#define version_List_10v00e03    0x100e3
#define version_List_10v00e04    0x100e4
#define version_List_10v00e05    0x100e5
#define version_List_10v00e06    0x100e6
#define version_List_10v00e07    0x100e7
#define version_List_10v00e08    0x100e8
#define version_List_10v00e09    0x100e9
/*-- 10v01e00 */
#define version_List_10v01e00    0x101e0
#define version_List_10v01e01    0x101e1
#define version_List_10v01e02    0x101e2
#define version_List_10v01e03    0x101e3
#define version_List_10v01e04    0x101e4
#define version_List_10v01e05    0x101e5
#define version_List_10v01e06    0x101e6
#define version_List_10v01e07    0x101e7
#define version_List_10v01e08    0x101e8
#define version_List_10v01e09    0x101e9
/*-- 10v02e00 */
#define version_List_10v02e00    0x102e0
#define version_List_10v02e01    0x102e1
#define version_List_10v02e02    0x102e2
#define version_List_10v02e03    0x102e3
#define version_List_10v02e04    0x102e4
#define version_List_10v02e05    0x102e5
#define version_List_10v02e06    0x102e6
#define version_List_10v02e07    0x102e7
#define version_List_10v02e08    0x102e8
#define version_List_10v02e09    0x102e9
/*-- 10v03e00 */
#define version_List_10v03e00    0x103e0
#define version_List_10v03e01    0x103e1
#define version_List_10v03e02    0x103e2
#define version_List_10v03e03    0x103e3
#define version_List_10v03e04    0x103e4
#define version_List_10v03e05    0x103e5
#define version_List_10v03e06    0x103e6
#define version_List_10v03e07    0x103e7
#define version_List_10v03e08    0x103e8
#define version_List_10v03e09    0x103e9
/*-- 10v04e00 */
#define version_List_10v04e00    0x104e0
#define version_List_10v04e01    0x104e1
#define version_List_10v04e02    0x104e2
#define version_List_10v04e03    0x104e3
#define version_List_10v04e04    0x104e4
#define version_List_10v04e05    0x104e5
#define version_List_10v04e06    0x104e6
#define version_List_10v04e07    0x104e7
#define version_List_10v04e08    0x104e8
#define version_List_10v04e09    0x104e9
/*-- 10v05e00 */
#define version_List_10v05e00    0x105e0
#define version_List_10v05e01    0x105e1
#define version_List_10v05e02    0x105e2
#define version_List_10v05e03    0x105e3
#define version_List_10v05e04    0x105e4
#define version_List_10v05e05    0x105e5
#define version_List_10v05e06    0x105e6
#define version_List_10v05e07    0x105e7
#define version_List_10v05e08    0x105e8
#define version_List_10v05e09    0x105e9
/*-- 10v06e00 */
#define version_List_10v06e00    0x106e0
#define version_List_10v06e01    0x106e1
#define version_List_10v06e02    0x106e2
#define version_List_10v06e03    0x106e3
#define version_List_10v06e04    0x106e4
#define version_List_10v06e05    0x106e5
#define version_List_10v06e06    0x106e6
#define version_List_10v06e07    0x106e7
#define version_List_10v06e08    0x106e8
#define version_List_10v06e09    0x106e9
/*-- 10v07e00 */
#define version_List_10v07e00    0x107e0
#define version_List_10v07e01    0x107e1
#define version_List_10v07e02    0x107e2
#define version_List_10v07e03    0x107e3
#define version_List_10v07e04    0x107e4
#define version_List_10v07e05    0x107e5
#define version_List_10v07e06    0x107e6
#define version_List_10v07e07    0x107e7
#define version_List_10v07e08    0x107e8
#define version_List_10v07e09    0x107e9
/*-- 10v08e00 */
#define version_List_10v08e00    0x108e0
#define version_List_10v08e01    0x108e1
#define version_List_10v08e02    0x108e2
#define version_List_10v08e03    0x108e3
#define version_List_10v08e04    0x108e4
#define version_List_10v08e05    0x108e5
#define version_List_10v08e06    0x108e6
#define version_List_10v08e07    0x108e7
#define version_List_10v08e08    0x108e8
#define version_List_10v08e09    0x108e9
/*-- 10v09e00 */
#define version_List_10v09e00    0x109e0
#define version_List_10v09e01    0x109e1
#define version_List_10v09e02    0x109e2
#define version_List_10v09e03    0x109e3
#define version_List_10v09e04    0x109e4
#define version_List_10v09e05    0x109e5
#define version_List_10v09e06    0x109e6
#define version_List_10v09e07    0x109e7
#define version_List_10v09e08    0x109e8
#define version_List_10v09e09    0x109e9

/*
 * ------------------------------------------------------------------------------------
 * 
 * ==========[ End, version 9vYeX ]========== 
 *
 * ------------------------------------------------------------------------------------*/







/*  
 * ===================[ End, Listado Versionado 'e', estable ]====================
 * */

#endif /* #if(version_USE_GlobalMacro==1)*/
/* **********************************************************************************************
 *
 * ==========================[ End Macros/labels Globals ]===========================
 *
 * ******************************************************************************************** **/
/*
 * 
 * *********************************************************************************************
 *
 * ===========================[ Begin Global Macros functions ]==================================
 *
 ********************************************************************************************** */
 #if(version_USE_GlobalMacroApis==1)

/** ****************************************************************//**
 * \def version_GetNumber(XXvYYdZZ)
 * @brief Macro API, para obtener el numero interno que hace referencia
 * a la version en uso.
 * @param XXvYYdZZ : referencia a la numeracion
 * should be :
 *         + 01v00d00
 *         + 01v00d01
 *         +...
 * @return valor que representa internamente a la version que se
 * hace referenica con la etiqueta 'XXvYYdZZ'
 * @note
 * @par example :
 <pre>
 a = version_GetNumber(1v9d0);
 </pre>
 *********************************************************************/
#define version_GetNumber(XXvYYdZZ) \
        (version_List_##XXvYYdZZ)

/** ****************************************************************//**
* \def version_SetNumber(XXvYYdZZ)
* @brief Macro API, para Estblecer el numero interno que hace referencia
* a la version en uso.
* @param XXvYYdZZ : referencia a la numeracion
* should be :
*         + 01v00d00
*         + 01v00d01
*         +...
* @return valor que representa internamente a la version que se
* hace referenica con la etiqueta 'XXvYYdZZ'
* @note
* @par example :
<pre>
#define CURRENT_VERSION  version_SetNumber(01v09d00)
</pre>
*********************************************************************/
#define version_SetNumber(XXvYYdZZ) \
        (version_List_##XXvYYdZZ)


/** *****************************************************************//**
 * \def version_QueryNumber(labels,XXvYYdZZ)
 * @brief Macro API, para consultar por el valor de una etiqueta
 * previamente definida con @ref version_SetNumber(XXvYYdZZ)
 * @param label : etiqueta prevaimetne definida de la siguente manera
 * @param XXvYYdZZ : referencia a la numeracion
 * should be :
 *         + 01v09d00
 *         + 01v09d01
 *         +...
 * @return valor que representa internamente a la version que se
 * hace referenica con la etiqueta 'XvYdZ'
 * 
 * @note
 * @par example :
 <pre>
#define CURRENT_VERSION  version_SetNumber(01v09d00)
... more code
...
...
#if(version_QueryNumber(CURRENT_VERSION,01v09d00))
... more code
#elif(version_QueryNumber(CURRENT_VERSION,01v09d01))
... more code
#endif
 </pre>
 *********************************************************************/
#define version_QueryNumber(labels,XXvYYdZZ) \
    (((version_List_##XXvYYdZZ)^(labels))==0)


#endif /* #if(version_USE_GlobalMacroApis==1)*/
/* **********************************************************************************************
 *
 * ===========================[ End Global Macros functions ]==================================
 *
 ********************************************************************************************** */

/*
 * ============================[close, cplusplus]============================
*/
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/*==============================[end of version]==============================*/
#endif /* #ifndef __version_h__ */
/*
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * ===================================[end of project version]===================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif /* #if(version_projectEnable == 1) */

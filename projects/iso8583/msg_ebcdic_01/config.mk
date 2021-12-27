##
##
#####################################################################################
## Incluimos el archivo de versionado
#####################################################################################
-include ../../etc/version.mk
##
##
#####################################################################################
## BEGIN Definimos las version el tipo de host y Habilitamos/Deshabilitamos el 
##  + Debug del proyecto 	==>	DEBUG_ENABLE ?= ENABLE
##  + Cross compile (rpi | win)	==> 	CROSS_COMPILER_PLATFORM = { WIN32 | WIN64 | ARM64 | ARM32 }
##  + Linux x86              	==> 	CROSS_COMPILER_ENABLE = ENABLE
##  
#####################################################################################
main_version = $(ver_01v0d0)
#-- Definimos la version del listado de argumentos que usamos para test.
# HOST_USER = rpi
# HOST_USER = desktop



# CROSS_COMPILER_PLATFORM = WIN32
# CROSS_COMPILER_PLATFORM = WIN64
# CROSS_COMPILER_PLATFORM = ARM64
# CROSS_COMPILER_PLATFORM = ARM32
# CROSS_COMPILER_PLATFORM = LINUX32

##
# DEBUG_ENABLE ?= ENABLE
# DEBUG_ENABLE ?= ENABLE
##
##
#####################################################################################
## END   Version Host type, Enable/Disable Debug Project.
#####################################################################################

##
##
#####################################################################################
## BEGIN Definimos el nombre para la App, y un listado de ARG para target run
#####################################################################################
APP_NAME = ISO8583ParserV01d01

## definimos los argumentos para el target prj_run
ARGS ?= "F0F2F1F072BA00010A80C000F1F6F9F8F7F6F5F4F3F2F1F0F1F2F3F4F5F6F1F1F1F0F0F0F0F0F0F0F0F0F0F0F1F0F0F0F0F9F2F4F1F0F1F5F3F6F6F1F6F1F1F6F1F6F0F0F3F4F5F3F1F0F1F5F3F6F0F9F2F4F0F8F2F7F0F6F2F5F0F1F7F8F9F8F7F6F5F0F0F0F0F0F0F0F2F1E3E5D5C3D9F0F2F0F0F0F9F0F0F9"
#####################################################################################
## END   Definimos el nombre para la App, y un listado de ARG para target run
#####################################################################################

##
##
#######################################################################################
## BEGIN Definicion de las Librerias Externas a utilizar, en orden de 
## cascada descendiente (la independientes a lo ultimo)
## 	-lm 		: math
##	-lpthread	: poxis thread	
#######################################################################################
PROJECT_LIBRARIES_EXT = iso8583 miscellaneous version m
PROJECT_LIBRARIES_EXT_INCLUDE_PATH = lib/inc


ifeq ($(CROSS_COMPILER_PLATFORM),WIN32)
	PROJECT_LIBRARIES_EXT_PATH := lib/win32
	PLATFORM := windows_x86
	
else ifeq ($(CROSS_COMPILER_PLATFORM),WIN64)
	PROJECT_LIBRARIES_EXT_PATH := lib/win64
	PLATFORM := windows_x64	
	
else ifeq ($(CROSS_COMPILER_PLATFORM),ARM32)
	PROJECT_LIBRARIES_EXT_PATH := lib/arm32
	PLATFORM := linuxARM_x86
	
	
else ifeq ($(CROSS_COMPILER_PLATFORM),ARM64)
	PROJECT_LIBRARIES_EXT_PATH := lib/arm64
	PLATFORM := linuxARM_x64
	
else ifeq ($(CROSS_COMPILER_PLATFORM),LINUX32)
	PROJECT_LIBRARIES_EXT_PATH := lib/x86
	PLATFORM := linux_x86
else 
	PROJECT_LIBRARIES_EXT_PATH := lib/x64
	PLATFORM := linux_x64
endif


#######################################################################################
## END Definicion de las Librerias Externas a utilizar
#######################################################################################

##
##
#######################################################################################
## BEGIN Definimos los simbolos necesario para cada tipo de Archivo Fuente
#######################################################################################
PROJECT_LIST_CCSYMBOLS = DEBUG_PRINT_DISABLE __M64__ 
PROJECT_LIST_CPPSYMBOLS = $(PROJECT_LIST_CCSYMBOLS)
PROJECT_LIST_ASMSYMBOLS = $(PROJECT_LIST_CCSYMBOLS)

#######################################################################################
## END Definimos los simbolos necesario para cada tipo de Archivo Fuente
#######################################################################################

##
## 
#######################################################################################
## BEGIN Establecemos Los flags para cada compilador
#######################################################################################
#
# 
# Flags para definir el tipo de CPU que ejecutara la aplicacion -m....
#    
#	-marc=native : Habilita todas el subconjunto de intrucciones soportadas
#                     por la maquina local.
#      -mtune=native : optimiza el codigo para la maquina local.
#      -m32 : Establecer la compilacion de codigo para arquitectura de 32-Bits
#	       Para esto sea valido en sistemas (S.O) 64-Bits debemos instalar 
#	       algunas librerias, tanto para gcc como para g++ (para c y c++)
#		>> sudo apt-get install gcc-multilib
#		>> sudo apt-get install g++-multilib
#
#      -m64 : Establecer la compilacion de codigo para arquitectura de 64-Bits
#
#
#         --ansi : para deshabilitar las caracreristicas de GCC que son 
#                  incompatibles con el estandar ISO C90, cuando compilamos
#                  codigo fuente en C. 
#
#         -Iinclude : para notificarle al compilador donde debe buscar los 
#                  header file para las librerias 
#
#
#
##--------------------------------------------------------------------------
# 	gcc, flags for compiler C
#  >> -Wall : Esta opcion activa todos los avisos más comunes "se
#             recomienda usar siempre esta opción".
#  >> --ansi : para deshabilitar las caracreristicas de GCC que son 
#              incompatibles con el estandar ISO C90, cuando compilamos
#              codigo fuente en C. 
#
#  >> -Iinclude : para notificarle al compilador donde debe buscar los 
#                 header file para las librerias, es optativo $(INCLUDE)
#  >> -w :
#  >> -g :
#  >> -c :
#
##--------------------------------------------------------------------------
ifeq ($(DEBUG_ENABLE),ENABLE)
MSG_DEBUG := DEBUG ENABLE
## CC
# PROJECT_CCFLAGS = -Iinclude -w -g -DNDEBUG
PROJECT_CCFLAGS = -Iinclude -Wall -g -DNDEBUG
# Flags para C++
PROJECT_CPPFLAGS = $(PROJECT_CCFLAGS)
# Flags para assembler
PROJECT_ASFLAG = $(PROJECT_CCFLAGS)
## definimos el nombre de la app para debug
APP_NAME = debug_app

else
MSG_DEBUG := DEBUG DISABLE
## CC
# PROJECT_CCFLAGS = -Iinclude -w
PROJECT_CCFLAGS = -Iinclude -Wall
# Flags para C++
PROJECT_CPPFLAGS = $(PROJECT_CCFLAGS)
# Flags para assembler
PROJECT_ASFLAG = $(PROJECT_CCFLAGS)
endif


## add flag x86 compiler 
ifeq ($(CROSS_COMPILER_PLATFORM),LINUX32)
PROJECT_CCFLAGS += -m32
PROJECT_CPPFLAGS += -m32
PROJECT_ASFLAG += -m32
endif
#######################################################################################
## END Establecemos Los flags para cada compilador
#######################################################################################

##
##
#######################################################################################
## BEGIN Variable PROJECT_run
## run, particualr de cada proyecto. 
## En este caso multi instanciacion del servicio, para diferentes Board
#######################################################################################
PROJECT_run := 

#######################################################################################
## END Variable PROJECT_run
#######################################################################################



##
##
#######################################################################################
## BEGIN Variable PROJECT_push copia remota 
#######################################################################################
PROJECT_push := 

#######################################################################################
## END Variable PROJECT_run
#######################################################################################

##
##
#######################################################################################
## BEGIN Variable PROJECT_run
## run, particualr de cada proyecto. 
## En este caso multi instanciacion del servicio, para diferentes Board
#######################################################################################
# PROJECT_uninstall := 
PROJECT_install := 

#######################################################################################
## END Variable PROJECT_run
#######################################################################################

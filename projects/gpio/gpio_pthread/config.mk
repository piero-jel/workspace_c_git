##
##
#####################################################################################
## Incluimos el archivo de versionado
#####################################################################################
-include ../../etc/version.mk
##
##
#####################################################################################
## Definimos las version, del project y del listado de argumentos, p/ new, run and debug
#####################################################################################
main_version = $(ver_01v0d2)
#-- Definimos la version del listado de argumentos que usamos para test.

##
##
#####################################################################################
# BEGIN Definimos las caracteristicas de cross-compiler y remote devices
#####################################################################################
## forzamos cada variable
PLATFORM_USER = pi
PLATFORM_IP = 169.254.148.11
CROSS_COMPILER_ENABLE = ENABLE

#####################################################################################
# END Definimos los modulos que usaremos en el proyecto
#####################################################################################
##
##
#####################################################################################
# Habilitamos (TRUE)/Deshabilitamos(FALSE) el debug de la apliacion
#####################################################################################
# DEBUG_ENABLE ?= ENABLE
DEBUG_ENABLE ?= DISABLE
##
##
#####################################################################################
## Definimos el nombre para la App, en caso de que no se requeira el nombre desde PROJECT
#####################################################################################
APP_NAME = macrodaemon


## definimos los argumentos para el target prj_run
ARGS ?= "arg0" "bla bla 10" -r 10 -l "$(HOME)/"
##
##
#######################################################################################
## BEGIN Definicion de las Librerias Externas a utilizar
#######################################################################################
PROJECT_LIBRARIES_EXT = pthread miscellaneous prpi version
PROJECT_LIBRARIES_EXT_PATH = lib
PROJECT_LIBRARIES_EXT_INCLUDE_PATH = lib/inc

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
## BEGIN Configuracion de los modulos, no en uso actualmente
#######################################################################################

# PROJECT_MODULES = 
# MODULES_PATH ?= modules


##-- Establecemos la ruta para cada modulo que usaremos
##	"Modules needed by the application"
# PROJECT_MODULES_PATH := $(foreach VAR,$(PROJECT_MODULES),\
			$(MODULES_PATH)/$(VAR))

#######################################################################################
## END Configuracion de los modulos, no en uso actualmente
#######################################################################################
##

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
APP_NAME = debug_app.out

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
PROJECT_run := ./$(APP_PATH)/$(APP_NAME)$(OUT_EXT) $(ARGS1) && \
	       ./$(APP_PATH)/$(APP_NAME)$(OUT_EXT) $(ARGS2)
#######################################################################################
## END Variable PROJECT_run
#######################################################################################



##
##
#######################################################################################
## BEGIN Variable PROJECT_push copia remota 
##	$USER@$DESKTOP:~$ ./install
##	$USER@$DESKTOP:~$ sudo systemctl daemon-reload
## 	$USER@$DESKTOP:~$ sudo systemctl start MonitoringTempBoard
## 	$USER@$DESKTOP:~$ sudo systemctl status MonitoringTempBoard
## 	$USER@$DESKTOP:~$ sudo systemctl stop MonitoringTempBoard
## 	$USER@$DESKTOP:~$ sudo systemctl enable MonitoringTempBoard
## 	$USER@$DESKTOP:~$ sudo shutdown -r 0
#######################################################################################
PROJECT_push := sudo scp -r ./$(APP_PATH)/$(APP_NAME)$(OUT_EXT) $(PROJECT)/MonitoringTempBoard.service $(PROJECT)/MonitoringFeederBoard.service $(PROJECT)/install $(PLATFORM_USER)@$(PLATFORM_IP):/home/$(PLATFORM_USER)

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
PROJECT_install := sudo cp ./$(APP_PATH)/$(APP_NAME)$(OUT_EXT) /usr/bin && \
		   sudo cp $(PROJECT)/MonitoringTempBoard.service $(PROJECT)/MonitoringFeederBoard.service /etc/systemd/system

#######################################################################################
## END Variable PROJECT_run
#######################################################################################

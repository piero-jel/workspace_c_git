####################################################################################################################
## Do not edit this MAKEFILE file
## 2021, Luccioni Jesús Emanuel All rights reserved.
## Redistribution is not allowed with or without modification. 
## Use is permitted with prior authorization by the copyright holder.
####################################################################################################################

##
##
#######################################################################################
## BEGIN include '*.mk' Files, do not edit this section
## Archivos de configurcion
#######################################################################################
-include etc/version.mk
-include aplication.mk
-include configuration.mk

#######################################################################################
## END include '*.mk' Files, do not edit this section
#######################################################################################


##
##
#######################################################################################
## BEGIN Definicion de los directorios donde se colocaran los archivos compilados
#######################################################################################
OBJ_PATH := out/obj
APP_PATH := out/app
LIBS_PATH := out/lib

#######################################################################################
## END Definicion de los directorios donde se colocaran los archivos compilados
#######################################################################################




##
##
#######################################################################################
##
## BEGIN incluimos Makefile y 'config.mk' del proyecto
##
#######################################################################################
include $(PROJECT)/Makefile
-include $(PROJECT)/config.mk

#######################################################################################
## END incluimos Makefile y 'config.mk' del proyecto
#######################################################################################

##
##
#######################################################################################
##
## BEGIN Definimos los simbolos para la compilacion
##
#######################################################################################
SYMBOLS += -D__main_version__=$(main_version)
SYMBOLS += $(foreach VAR,$(PROJECT_MODULES_PATH), $($(notdir $(VAR)_SYMBOLS)))
## -- flags de depuracion 
ifeq ($(DEBUG_ENABLE),ENABLE)
SYMBOLS += -DDEBUG_ENABLE
endif

LIBRARY_EXT += m
#######################################################################################
## END Definimos los simbolos para la compilacion
#######################################################################################




##
##
#####################################################################################
# BEGIN target all 
#####################################################################################
all: $(APP_NAME)
#####################################################################################
# END target all 
#####################################################################################

##
##
#####################################################################################
# BEGIN include Makefile Modules 
# incluimos los Makefile de cada modulo del cual depende el proyectotarget all 
#####################################################################################
include $(foreach VAR,$(PROJECT_MODULES_PATH), $(VAR)/Makefile)

#####################################################################################
# END include Makefile Modules 
#####################################################################################


##
##
#######################################################################################
##
## BEGIN Listado "list project source files {cpp,c,S|s}"
##
#######################################################################################
PROJECT_CPP_FILES = $(wildcard $(PROJECT_SRC_PATH)/*.cpp)
PROJECT_CC_FILES = $(wildcard $(PROJECT_SRC_PATH)/*.c)
PROJECT_AS_FILES = $(wildcard $(PROJECT_SRC_PATH)/*.$(AS_EXT))
## 
PROJECT_SRC_FILES += $(PROJECT_CPP_FILES)\
	$(PROJECT_CC_FILES)\
	$(PROJECT_AS_FILES) 
#######################################################################################
## END Listado "list project source files {cpp,c,S|s}"
#######################################################################################	

##
##
#######################################################################################
##
## BEGIN Listado de los Object Files 
##
#######################################################################################
PROJECT_OBJ_FILES = $(addprefix $(OBJ_PATH)/,$(notdir $(PROJECT_CPP_FILES:.cpp=.o)))
PROJECT_OBJ_FILES += $(addprefix $(OBJ_PATH)/,$(notdir $(PROJECT_CC_FILES:.c=.o)))
PROJECT_OBJ_FILES += $(addprefix $(OBJ_PATH)/,$(notdir $(PROJECT_AS_FILES:.$(AS_EXT)=.o)))
PROJECT_OBJS := $(notdir $(PROJECT_OBJ_FILES))

#######################################################################################
## END Listado de los Object Files 
#######################################################################################


##
##
#####################################################################################
# BEGIN List Header File 
# Definimos el listado de directoris donde debe buscar
# Los header files
#####################################################################################

INCLUDES = -Iinclude $(addprefix -I,$(PROJECT_INC_PATH)) $(LIBRARY_EXT_INCLUDE_PATH)
#####################################################################################
# END  List Header File 
#####################################################################################

##
##
#####################################################################################
# BEGIN List format files path 
#####################################################################################
vpath %.o $(OBJ_PATH)
vpath %.c $(PROJECT_SRC_PATH) $(foreach MOD,$(PROJECT_MODULES),$($(MOD)_SRC_FOLDERS))
vpath %.cpp $(PROJECT_SRC_PATH) $(foreach MOD,$(PROJECT_MODULES),$($(MOD)_SRC_FOLDERS))
vpath %.$(EXT_ASM) $(PROJECT_SRC_PATH) $(foreach MOD,$(PROJECT_MODULES),$($(MOD)_SRC_FOLDERS))
vpath %.a $(LIBS_PATH)

#####################################################################################
# END List format files path 
#####################################################################################

##
##
#####################################################################################
# BEGIN List compiler msg
#####################################################################################
COMPILE_MSG1 = Proyecto: $(patsubst projects/%,""%,$(PROJECT)), Aplicacion: \"$(APP_NAME)\"
COMPILE_MSG2 = Depuracion: $(MSG_DEBUG), Version del Main: \"$(main_version)\"
COMPILE_MSG3 = CCFLAGS: $(CCFLAGS)
COMPILE_MSG4 = Cross-Compiler: $(CROSS_COMPILER_PLATFORM), toolchain: \"$(CROSS_COMPILER)\", platform: \"$(PLATFORM)\"
COMPILE_MSG5 = Symbols: $(SYMBOLS)

#####################################################################################
# END List compiler msg
#####################################################################################


##
##
#####################################################################################
# Creamos todos los Archivos objetos necesarios, compilamos sin llamar al linker
#####################################################################################
#
%.o : %.c
# 	$(CMD_ECHO) "\n==========[ BEGIN, compiling C file $< ]=========="
	@$(CC) $(SYMBOLS) $(CC_SYMBOLS) $(CCFLAGS) $(INCLUDES) -c $< -o $(OBJ_PATH)/$@
	@$(CC) $(SYMBOLS) $(CC_SYMBOLS) $(CCFLAGS) $(INCLUDES) -c $< -MM > $(OBJ_PATH)/$(@:.o=.d)	
# 	$(CMD_ECHO) "==========[ END, compiling C file $< ]==========\n"
#
%.o : %.$(AS_EXT)
# 	$(CMD_ECHO) "\n==========[ BEGIN, compiling assembler file $< ]=========="
	@$(AS) $(SYMBOLS) $(ASM_YMBOLS) $(ASFLAGS) $(INCLUDES) -c $< -o $(OBJ_PATH)/$@
	@$(AS) $(SYMBOLS) $(ASM_YMBOLS) $(ASFLAGS) $(INCLUDES) -c $< -MM > $(OBJ_PATH)/$(@:.o=.d)
# 	$(CMD_ECHO) "==========[ END, compiling assembler file $< ]==========\n"



$(APP_NAME): $(PROJECT_OBJS)
	$(CMD_ECHO) "\n===========[BEGIN, compiling: ]=========="
	$(PRINTF) "$(FGREEN) Informacion:\n"
	$(PRINTF) "$(FBLUE)\t$(COMPILE_MSG1)\n"
	$(PRINTF) "$(FBLUE)\t$(COMPILE_MSG2)\n"
	$(PRINTF) "$(FBLUE)\t$(COMPILE_MSG3)\n"
	$(PRINTF) "$(FBLUE)\t$(COMPILE_MSG4)\n"
	$(PRINTF) "$(FBLUE)\t$(COMPILE_MSG5)\n"
	$(PRINTF) "$(FRESET)\n"
	@$(CC) -o $(APP_PATH)/$(APP_NAME)$(OUT_EXT) $(PROJECT_OBJ_FILES)\
	$(LDFLAGS) -L $(LIBS_PATH) $(addprefix -l,$(PROJECT_MODULES)) $(addprefix -l, $(PROJECT_LIBRARIES)) \
	$(addprefix -L, $(LIBRARY_EXT_PATH)) $(addprefix -l,$(LIBRARY_EXT))
	$(CMD_ECHO) "\nTamaño del archivo ejecutable formato:" $(SIZE_FORMAT)
	$(SIZE) $(SIZE_FORMAT) $(APP_PATH)/$(APP_NAME)$(OUT_EXT)
	$(CMD_ECHO) "===========[END, compiling: \"$(PROJECT)\"]==========\n"
	
info:
	$(CMD_ECHO) "\n===========[BEGIN, info: ]=========="
	$(CMD_ECHO) "PROJECT_LIBRARIES_EXT : $(PROJECT_LIBRARIES_EXT)"
	$(CMD_ECHO) "PROJECT_LIBRARIES_EXT_PATH : $(PROJECT_LIBRARIES_EXT_PATH)"
	$(CMD_ECHO) "PROJECT_LIBRARIES_EXT_INCLUDE_PATH : $(PROJECT_LIBRARIES_EXT_INCLUDE_PATH)"	
	$(CMD_ECHO) "LIBRARY_EXT : $(LIBRARY_EXT)"
	$(CMD_ECHO) "LIBRARY_EXT_PATH : $(LIBRARY_EXT_PATH)"
	$(CMD_ECHO) "LIBRARY_EXT_INCLUDE_PATH : $(LIBRARY_EXT_INCLUDE_PATH)"
	$(CMD_ECHO) "SYMBOLS : $(SYMBOLS)"
	
	
	$(CMD_ECHO) "===========[END, info: \"$(PROJECT)\"]==========\n"
	
##
##
#####################################################################################
# BEGIN target clean, limpiar los directorios de compilacion
#####################################################################################
clean:
	$(CMD_CLEAN) $(OBJ_PATH)/*.*
	$(CMD_CLEAN) $(LIBS_PATH)/*.*
	$(CMD_CLEAN) $(APP_PATH)/$(APP_NAME)$(OUT_EXT)	
	$(CMD_CLEAN) $(APP_PATH)/*
	$(CMD_ECHO) "Archivos Borrados de Forma Sastifactoria"
#####################################################################################
# END target clean, limpiar los directorios de compilacion
#####################################################################################

##
##
#####################################################################################
## BEGIN target run
## >> Limpieza de directorios
## >> Recompilacion 
## >> Ejecucion de la aplicacion
#####################################################################################
run : new
	$(CMD_ECHO) "\n=================[Ejecutando la Aplicacion:...... $(APP_NAME) ]=================\n"
	$(PRINTF) "$(FGREEN) Ejecutando la Aplicacion:......$(FRESET) \n\n"
	./$(APP_PATH)/$(APP_NAME)$(OUT_EXT) $(ARGS)
	$(CMD_ECHO) "\n\n=================[Ejecutando la Aplicacion:...... $(APP_NAME) ]=================\n"
#####################################################################################
## END target run
#####################################################################################


##
##
#####################################################################################
## BEGIN target new
## >> Limpieza de directorios
## >> Recompilacion 
#####################################################################################
new: clean all
#####################################################################################
## END target new
#####################################################################################

##
##
#####################################################################################
## BEGIN target especiales del royecto
## >> Limpieza de directorios
## >> Recompilacion 
#####################################################################################
prj_run:
	@make new CROSS_COMPILER_ENABLE=ENABLE --no-print-directory
	${PROJECT_run}
	
prj_push: 
	@make new CROSS_COMPILER_ENABLE=ENABLE --no-print-directory
	${PROJECT_push}
	
prj_install: 
	@make new --no-print-directory
	${PROJECT_install}

#####################################################################################
## END target especiales del royecto
#####################################################################################

##
##
#####################################################################################
## BEGIN targets especiales 
## >> push	copia remotamente el ejecutable
## >> connect	remote connection
## >> 
#####################################################################################
## 
push: 
	@make new CROSS_COMPILER_ENABLE=ENABLE --no-print-directory	
	@sudo scp -r ./$(APP_PATH)/$(APP_NAME)$(OUT_EXT) $(PLATFORM_USER)@$(PLATFORM_IP):$(PLATFORM_PATH)
## 
## Datos por defecto para conexion remota con rpi, P2P "peer two peer"
## ssh -l pi 169.254.148.11	
connect:
	@sudo ssh -l $(PLATFORM_USER) $(PLATFORM_IP)
##
##
#####################################################################################
## END targets especiales 
#####################################################################################

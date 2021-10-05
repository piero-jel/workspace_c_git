##
## Este archivo define las facilidades del compilador
## Basicamente lo comandos basicos como asi tambien los
## Directorios jerarquicos del proyecto.
## El contenido de este no debe variar entre un proyecto 
## y el otro. Solo si se cambia el compilador.
## Los comandos Basicos son para GNU linux y GNU windows "cygwin"
## 
##
#####################################################################################
# Definimos los Compiladores a utilizar
#####################################################################################
AS_COMPILER = __GNU_AS__
C_COMPILER = __GNU_C__
CPP_COMPILER = __GNU_CPP__

##
##
#####################################################################################
# Definimos el cross-compiler
# A compiler that can convert instructions into machine code or low level code for
# a computer other than that on which it is run.
#####################################################################################
# $(CROSS_COMPILE) := arm-linux-gnueabihf-
# ifeq ($(CROSS_COMPILER_ENABLE),ENABLE)
# CROSS_COMPILER := arm-linux-gnueabihf-
# endif

ifeq ($(CROSS_COMPILER_PLATFORM),WIN32)
	CROSS_COMPILER := i686-w64-mingw32-
	SYMBOLS += -DSO_WIN32
	OUT_EXT = .exe
	
else ifeq ($(CROSS_COMPILER_PLATFORM),WIN64)
	CROSS_COMPILER := x86_64-w64-mingw32-
	SYMBOLS += -DSO_WIN64
	OUT_EXT = .exe
	
else ifeq ($(CROSS_COMPILER_PLATFORM),ARM32)
	CROSS_COMPILER := arm-linux-gnueabihf-
	SYMBOLS += -DSO_LINUX
	OUT_EXT = .
	
else ifeq ($(CROSS_COMPILER_PLATFORM),ARM64)
	CROSS_COMPILER := arm-linux-gnueabihf-
	SYMBOLS += -DSO_LINUX
	OUT_EXT = 
	
else 
	SYMBOLS += -DSO_LINUX
	OUT_EXT =
endif

##
##
#####################################################################################
# Definimos los conjuntos de comando para la Compilacion 
#####################################################################################
# CC = gcc
# CPP = g++
# AS = gcc

AS        = $(CROSS_COMPILER)as
LD        = $(CROSS_COMPILER)ld
CC        = $(CROSS_COMPILER)gcc
# CPP             = $(CC) -E
CPP       = @$(CROSS_COMPILER)g++
AR        = $(CROSS_COMPILER)ar
NM        = $(CROSS_COMPILER)nm
STRIP     = $(CROSS_COMPILER)strip
OBJCOPY   = $(CROSS_COMPILER)objcopy
OBJDUMP   = $(CROSS_COMPILER)objdump
SIZE      = $(CROSS_COMPILER)size

##
##
#####################################################################################
##
## Definimos los Comandos 
##
#####################################################################################
# PRINT := @echo -e "OS: $(OS)"

ifeq ($(OS),Windows_NT)
	CMD_ECHO := @echo -e
else
	CMD_ECHO := @echo
endif

PRINTF := @printf 


CMD_CLEAN := @rm -f 


##
##
##################################################
## compiler packing Files for static library 
##################################################
CMD_PACK = @$(AR) rcs
	# ar -> cmd para empaquetar
	# r : inserta los miembros de los archivos en el 
	# 	archivo final. Remplaza los existentes y agrega
	#	los nuevos
	# c : crea el archivo
	# s : agrega/actualiza el indice de archivos
	# t : no implemntando pero util, nos permite 
	#	ver el listado de archivos enpaquetados
##
##
#####################################################################################
# Definimos los Flags para los compiladores
#####################################################################################
# Flags para C Compiler
CCFLAGS = $(PROJECT_CCFLAGS)
# Flags para C++
CPPFLAGS = $(PROJECT_CPPFLAGS)
# Flags para assembler, no en uso
ASFLAGS = $(PROJECT_ASFLAG)
LDFLAGS = $(PROJECT_CCFLAGS)

##
##
#####################################################################################
# Definimos los Simbolos para los compiladores
#####################################################################################
# Simbolos para el compilador de C
CC_SYMBOLS += $(addprefix -D,$(PROJECT_LIST_CCSYMBOLS))
# Simbolos para el compilador de C++
CPP_SYMBOLS += $(addprefix -D,$(PROJECT_LIST_CPPSYMBOLS))
# Simbolos para el compilador de assembler
ASM_YMBOLS += $(addprefix -D,$(PROJECT_LIST_ASMSYMBOLS))
##


##
##
#####################################################################################
# Establecemos el listado de librerias esternas que usaremos
#####################################################################################
# PROJECT_LIBRARIES_EXT = pthread miscellaneous prpi version
# PROJECT_LIBRARIES_EXT_PATH = lib/
# PROJECT_LIBRARIES_EXT_INCLUDE_PATH = lib/inc

LIBRARY_EXT = $(PROJECT_LIBRARIES_EXT)
LIBRARY_EXT_PATH = $(PROJECT_LIBRARIES_EXT_PATH)
LIBRARY_EXT_INCLUDE_PATH = $(addprefix -I,$(PROJECT_LIBRARIES_EXT_INCLUDE_PATH))

##
##
#####################################################################################
# Definimos la extension para el compilador de Assembler 
#####################################################################################
ifeq ($(AS_COMPILER),__NASM__)
## compilador ASM para NASM
AS_EXT = s
else
## compilador ASM para GNU
AS_EXT = S
endif



# OUT_EXT = 



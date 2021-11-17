##
##
#####################################################################################
# BEGIN Definimos el Proyecto a compilar
#####################################################################################
#
#
## -------------------------------------------------------------------
## BEGIN proyectos comunes
## -------------------------------------------------------------------
# PROJECT = projects/templates/template

# PROJECT = projects/daemons/daemon_macro
# PROJECT = projects/daemons/daemon_rpi_01
# PROJECT = projects/gpio/gpio_pthread

# PROJECT = projects/iso8583/msg_ebcdic_01
PROJECT = projects/linkedlist/sort_file
## -------------------------------------------------------------------
## END proyectos comunes
## -------------------------------------------------------------------
#
#


#####################################################################################
# END Definimos el Proyecto a compilar
#####################################################################################

##
##
#####################################################################################
## BEGIN Forzamos la Definicion de la version a compilar del main
## Podemos comentarla y tomara la version por defecto.
#####################################################################################
main_version ?= $(ver_01v0d0)


#####################################################################################
## END Set main version
#####################################################################################

##
##
#####################################################################################
## BEGIN Set project Name 
## Nombre deseado para la aplicacion, en caso de DEBUGING este es descartado.
#####################################################################################
APP_NAME ?= app.out
# APP_NAME ?= prpi_gpio.out

#####################################################################################
## END Set project Name 
#####################################################################################

##
##
#####################################################################################
## BEGIN Forced Set Debug, Platform y CROSS_COMPILER_ENABLE 
## Establecemos funcionalidades como
##	>> PLATFORM, plataforma
##		[*] PLATFORM ?= RaspberryPi3Plus
##		[*] PLATFORM ?= BeagleBondBlackVerX
##	>> ENABLE/DISABLE DEBUG, compilacion
##	>> EABLE/DISBLE cross-compiler toolcahin arm, debemos verificar 32/64-Bits
#####################################################################################
# DEBUG_ENABLE = DISABLE
# CROSS_COMPILER_ENABLE = DISABLE
# PLATFORM ?= RaspberryPi3Plus
# PLATFORM ?= BeagleBondBlackVerX

#####################################################################################
## END Forced Set Debug, Platform y CROSS_COMPILER_ENABLE 
#####################################################################################

##
##
#####################################################################################
# BEGIN Include *.mk file, not edit this segment 
#####################################################################################
-include $(PROJECT)/config.mk


#####################################################################################
# END Include *.mk file, not edit this segment 
#####################################################################################

##
##
#####################################################################################
# BEGIN setting default version for modules
# Definimos la version para cada modulo que usaremos en el proyecto, de no 
# realizarlo toma la configuracion por defecto, establecida en su Makefile.
#####################################################################################
#-- master version
version_version ?= $(ver_01v0d0)
base_version ?= $(ver_01v0d0)
math_version ?= $(ver_01v0d0)
# mimath_version ?= $(ver_01v0d0)

#####################################################################################
# END setting default version for modules
#####################################################################################

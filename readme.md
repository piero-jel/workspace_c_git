# Seleccionando el Proyecto a compilar
  Dentro del archivo **aplication.mk** debemos establecer la variable **PROJECT = __path/folder_project__**. 
  
  Por ejemplo:
  
  **PROJECT = projects/templates/template**
  
  **PROJECT = projects/terminal/serial_terminal**
  
  
  
# Estableciendo el nombre del Ejecutable
  Dentro del archivo **aplication.mk** debemos establecer la variable **APP_NAME ?= Name.extension**.
  
  La extension dependera del S.O (**Sistema Operativo**), para windows debe ser __exe__ para linux podemos colocar __out__ o ninguna extension, en dicho caso tendremos **APP_NAME ?= AppName**.
  
# Habilitando/deshabilitando el cross-compiler
  Dentro del archivo **aplication.mk** debemos establecer la variable **CROSS_COMPILER_ENABLE ?= DISABLE**, para deshabilitar y **CROSS_COMPILER_ENABLE ?= ENABLE** para habiltiar.
  
  Este valor es el valor por defecto, podemos forzar el mismo dentro del archivo **aplication.mk** de cada proyecto, en este caso podmeos optar por 
    
  __CROSS_COMPILER_ENABLE = DISABLE__   : Forzamos que este deshabilitado, esto descarta la configuracion del archivo **aplication.mk**.
  
  __CROSS_COMPILER_ENABLE = ENABLE__    : Forzamos que este habilitado, esto descarta la configuracion del archivo **aplication.mk**.

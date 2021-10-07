## Seleccionando el Proyecto a compilar
  Dentro del archivo **aplication.mk** debemos establecer la variable **PROJECT = __path/folder_project__**. 
  
  Por ejemplo:
  ~~~  
  PROJECT = projects/templates/template
  ~~~
  
  ~~~
  PROJECT = projects/terminal/serial_terminal
  ~~~
  
  
  
## Estableciendo el nombre del Ejecutable
  Dentro del archivo **aplication.mk** debemos establecer la variable **APP_NAME ?= Name.extension**.
  
  La extension dependera del S.O (**Sistema Operativo**), para windows debe ser __exe__ para linux podemos colocar __out__ o ninguna extension, en dicho caso tendremos **APP_NAME ?= AppName**.
  
## Habilitando/deshabilitando y  seleccionando el cross-compiler
  En caso de necesitar compialr codigo para otras palataformas, considerando que la actual es del tipo **Linux 64**.
  Dentro del archivo **aplication.mk** debemos establecer la variable **CROSS_COMPILER_PLATFORM**. Y si deseamso deshabilitar solamente debemos comentar la linea **#CROSS_COMPILER_PLATFORM**.
  Ejemplo, habilitando la pataforma Linux 32 mientras las demas estan deshabilitanda:
  ~~~
  # CROSS_COMPILER_PLATFORM = WIN32
  # CROSS_COMPILER_PLATFORM = WIN64
  # CROSS_COMPILER_PLATFORM = ARM64
  # CROSS_COMPILER_PLATFORM = ARM32
  CROSS_COMPILER_PLATFORM = LINUX32
  ~~~
  

## Contenido
* [Seleccionando el Proyecto](#seleccionando-el-proyecto)
* [Estableciendo el nombre del Ejecutable](#estableciendo-el-nombre-del-ejecutable)
* [Estableciendo Cross-Compiler](#estableciendo-cross-compiler)
* [Compilando y corriendo el proyecto seleccionado](#compilando-y-corriendo-el-proyecto-seleccionado)
* [Configuracion](#configuracion)


## Seleccionando el Proyecto
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
  
## Compilando y corriendo el proyecto seleccionado:
  ~~~
  make new
  ~~~
  ~~~
  make run
  ~~~
  ~~~
  make run ARGS="args"
  ~~~
  ~~~
  make debug
  ~~~
  ~~~
  make debug ARGS="listado de argumentos"
  ~~~

## Configuracion

To run this app, you will need to follow these 3 steps:

#### 1. Requirements
  - a Laptop

  - Text Editor or IDE (eg. [vscode](https://code.visualstudio.com/download), [kate](https://kate-editor.org/es/), [vi/vim](https://www.vim.org/download.php))

  - [Git Bash Windows](https://git-scm.com/downloads)
  - [Git Command in Linux]
    opt 1
    ~~~
      sudo apt-get update && sudo apt-get upgrade -y          
      sudo apt-get install git
    ~~~
    opt 2
    ~~~
      sudo apt update && sudo apt upgrade -y          
      sudo apt install git
    ~~~
    


#### 2. Install cross compiler
  
  - [Linux ARM-Platform](https://platformio.org/platforms/linux_arm) 
  ~~~
    sudo apt install crossbuild-essential-armhf
    sudo apt install crossbuild-essential-arm64
  ~~~
    - others tools:
  ~~~
    sudo apt-get install -y build-essential
    sudo apt-get install -y libc6-armhf-cross
    sudo apt-get install -y libc6-dev-armhf-cross
    sudo apt-get install -y binutils-arm-linux-gnueabihf
    sudo apt-get install -y linux-libc-dev-armhf-cross
    sudo apt-get install -y libstdc++6-armhf-cross
    sudo apt-get install -y gdb-multiarch
  ~~~
  
  - Linux mingw, windows executables:
  ~~~
    sudo apt-get install mingw-w64
  ~~~
  
  - [Windows - CyG Win](https://www.cygwin.com/setup-x86_64.exe) installers.
  
  
#### 3. Local Setup and Running on Windows, Linux and Mac OS

  - Crating new directory, optional
  ~~~
    mkdir workspaces
  ~~~
  
  - Move to the new directory, optional
  ~~~
    cd ./workspaces
  ~~~
  
  - Clone this repository into the directory of your choice
  ~~~
    git clone https://github.com/piero-jel/workspace_c_git.git
  ~~~

  - Move into project folder
  ~~~
    cd ./workspace_c_git
  ~~~

  - Test workspace
  ~~~
    make new
    make run  
  ~~~
  
  
  

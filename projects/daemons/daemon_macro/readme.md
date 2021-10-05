# Ubicacion del Archivo de configuracion
  **/etc/systemd/system**

# Iniciar | detener | Habilitar el servicio:

## Iniciar el servicio
  _$USER@$DESKTOP:~$ sudo systemctl start myscript.service_

    
## Detener el servicio
  _$USER@$DESKTOP:~$ sudo systemctl stop myscript.service_

## Verificar el estado del Servicio
  _$USER@$DESKTOP:~$ sudo systemctl status myscript.service_

## Habilitar el servicio para inicio automatico con cada inicio del sistema. 

  __Debemos considerar que el Servicio corre de forma correcta y debemos crear el archivo de config para el comando service__
  
  **Cuando el test de inicio y detencion del servicio sale bien, podemos habilitar el mismo para que automaticamente se ejecute con cada inicio del sistema.**
  _$USER@$DESKTOP:~$ sudo systemctl enable myscript.service_

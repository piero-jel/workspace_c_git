## flujo_cliente_servidor
Uso de socket de flujo para el envio del contenido de un archivo. Permite la configuracion Cliente/Servidor y el envio de uno o varios archivos.

## Estableciendo la Trx:
Desde el archivo [here](./config.mk) config.mk, podemos establecer el valor en la variable 'ARGS' para la configuracion.
~~~
TEST_FILE = "$(shell pwd)/projects/socket_red/flujo_cliente_servidor/files/data.txt"
## definimos los argumentos para el target prj_run
ARGS ?= -t server -p 3550 --path $(TEST_FILE)
~~~

* Podemos establecer desde CLI (linea de comandos) a la hora de realizar el test.
~~~
  make run ARGS="-t server -p 3550 --path /path/file/data.txt"
~~~

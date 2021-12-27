## Sort File
Lee el contenido de un archivo, carga cada linea en un nodo de una lista doblemente enlazada. Ordena la misma y coloca el resultado en otro archivo.

## Estableciendo la Trx:
Desde el archivo [projects/linkedlist/sort_file/config.mk](./config.mk), podemos establecer el valor en la variable 'ARGS' para la ubicacion de los archivos.
~~~
ARGS ?= "$(shell pwd)/projects/linkedlist/sort_file/files/inputfile.log" \
        "$(shell pwd)/projects/linkedlist/sort_file/files/outfile.log"
~~~

* Podemos establecer desde CLI (linea de comandos) a la hora de realizar el test.
~~~
  make run ARGS="/path/file/Org /path/file/Dst"
~~~

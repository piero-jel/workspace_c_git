
## Ejecutable principal:
  ISO8583Parser.exe **\<thisPath>\ISO8583Parser\ISO8583Parser.exe**

  Sobre este debemos crear un aceso directo en el directorio. Click derecho sobre este, seleccionar la opcion enviar al escritroio.

## Testing:
  
  - Windows7 64-Bits , en caso de Testing sobre entorno virtual activar virtualizacion 3D para habilitar la version *OpenGL > 1.0*
  
  - Windows10 64-Bits
  
## Ubicacion del Log:
  Ejecutamos la App, en el panel superior lado derecho realizamos click sobre 'Config' , en la barra desplegada seleccionamos 'Log info'. Esta accion desplegara una ventana emergente que contiene informacion del log, como tamaño y ubicacion actual (la cual dependera de donde coloque el directorio del ejecutable).
  
  Si presionamos el boton 'Open Folder' abrira el directorio donde se encuentra el mismo. Podemos abrir este archivo con cualquier editor de texto. Se aconseja usar notepad++ para ver la evolucion, de lo contrario si utilizamos el block de notas convencional debemos Cerrar y volver abrir para ver la actualizacion del mismo.
  
  En el log podemos encontrar todas las expansiones realizadas en los diferentes formatos y con caracteres que no admite el plug-gin utf-8:
  
Ejemplo:

~~~
7/10/2021 17:1:25 - run app 
7/10/2021 17:6:29 - message to parsing F0F2F1F072BA00010A80C000F1F6F9F8F7F6F5F4F3F2F1F0F1F2F3F4F5F6F1F1F1F0F0F0F0F0F0F0F0F0F0F0F1F0F0F0F0F9F2F4F1F0F1F5F3F6F6F1F6F1F1F6F1F6F0F0F3F4F5F3F1F0F1F5F3F6F0F9F2F4F0F8F2F7F0F6F2F5F0F1F7F8F9F8F7F6F5F0F0F0F0F0F0F0F2F1E3E5D5C3D9F0F2F0F0F0F9F0F0F9
 
FRAME: [021072BA00010A80C000169876543210123456111000000000001000092410153661611616003453101536092408270625017898765000000021TVNCR020009009]

------------------------------------------------------------------------------------------------------------------------------
  MTID |   BIT MAP 1         |  Cant Campos |  Status |  Last Field 
------------------------------------------------------------------------------------------------------------------------------
  0210 | 0x72BA00010A80C000  |     15       |  0x0000 | [ 15] : 050 

------------------------------------------------------------------------------------------------------------------------------
  idx | Type | Len |                              Brief | Contenido del campo 
------------------------------------------------------------------------------------------------------------------------------
[002] | n    | 016 |                                PAN | [9876543210123456] 
[003] | n    | 006 |                    Processing code | [111000] 
[004] | n    | 012 |                Amount, transaction | [000000001000] 
[007] | n    | 010 |                    Trx date & time | [0924101536] 
[009] | n    | 008 |        Conversion rate, Settlement | [61611616] 
[011] | n    | 006 |         Systems trace audit number | [003453] 
[012] | n    | 006 |            Time, Local transaction | [101536] 
[013] | n    | 004 |      Date, Local transaction MM-DD | [0924] 
[015] | n    | 004 |                   Date, Settlement | [0827] 
[032] | n    | 006 |            Acquiring Inst. ID code | [250178] 
[037] | an   | 012 |         Retrieval reference number | [987650000000] 
[039] | an   | 002 |                      Response code | [21] 
[041] | ans  | 008 |          Card acceptor terminal ID | [TVNCR020] 
[049] | a    | 003 |         Currency code, transaction | [009] 
[050] | an   | 003 |          Currency code, settlement | [009] 
~~~

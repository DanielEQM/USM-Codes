Nombre: Daniel Quispe
Rol: 202273529-5


AVISO: se a usado la versión 11.3.0 del gcc para la compilación de todos los archivos
        en caso de algún error en la compilación existe la posibilidad que se deba
        a la versión.

Instrucciones de compilación:

    Antes: Se agregaron las siguientes variables globales en el archivo Tablero.h:
        
        extern int **tipo -> Matriz auxiliar para identificar bombas.
        extern int Tesoros -> variable de cuantos Tesoros hay en el tablero.
        extern int Turnos -> Va pasando los turnos a medida que agregan bombas.

    Para que compile en la carpeta se debe encontrar los siguientes archivos:
     - TreasureFinder.c, Tierra.h, Tablero.c, Tablero.h, Bomba.c, Bomba.h.
     Los cuales son archivos en el comprimido enviado.
     - El makefile del archivo enviado que es para la compilación del programa
    
    Para la compilación:
     - Para compilar debe estar en la dirección donde se encuentran todos los archivos
     y usar la siguiente linea de comando en la consola: make all
     - Ejecutar el archivo ejecutable llamado: programa (./programa)
     - Para borrar los archivos .o despues de la revisión, usar la siguiente linea de
     comando en la consola: make clean

## Integrantes:
Daniel Quispe 202273529-5 201; Matías Fernández 202273506-6 201

## Especificación de los nombres de los archivos:
- **cartas.hpp**: programa con el semáforo, structs de cartas, mazos, juego y las funciones auxiliares a utilizar en el programa principal para crear las cartas a utilizar, los comportamientos específicos de las cartas especiales, imprimir el estado del juego y el liberamiento de la memoria compartida y cierre de semáforo e hijos producto del fork.

- **juego.cpp**: programa principal en donde se ejecutan las funciones mencionadas en cartas.hpp y donde se tienen las funciones que controlan a los otros jugadores y el flujo de juego.

## Instrucciones generales de compilación y uso:
Los programas mencionados anteriormente son gestionados por un Makefile, tanto en compilación como ejecución. Por lo tanto, al momento de descargar los archivos pertinentes, posiciónese en la carpeta donde los tiene y ejecute la línea de comando: "make run".

## Consideraciones importantes:

* A lo más el programa tolera que se ingresen números incorrectos (por ejemplo, al elegir cartas entre 1 al 7, escribir 0 u 8 hacen que pida nuevamente el input). Ingresar un carácter 'A' u otros producirá errores, por lo que asegúrese de escribir correctamente los input.
* Por comodidad, al momento de jugar una carta ella hace un swap con la ultima y se reduce el tamaño del arreglo para poder gestionar la mano del jugador de forma más eficiente, por lo que pueden ir cambiando de posición las cartas por turno.
* Se puede ocupar el comodín para cambiar al mismo color.
* Si el mazo se queda sin cartas, se saca la pila de descarte y se reapila como mazo, dejando solamente la última puesta para seguir con la ejecución del juego.
* Las cartas de los otros jugadores están comentadas. Si quieres ver el progreso de ellos, puede descomentarlas en juego.cpp, en la función "ia_juego", las lineas "//imprimir_cartas_jugadores(...)".
* Si se hace una interrupción forzada en la consola se debe ejecutar dos veces el programa para que se ejecute normalmente.

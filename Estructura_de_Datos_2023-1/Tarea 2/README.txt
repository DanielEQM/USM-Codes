Recordatorio:
    1.- Para probar casos, hay que cambiar el nombre del archivo de lectura 
    dentro de la variable entrada, linea 15, en problema1.cpp.
    2.- Las funciones del TDA listaEnlazada del problema 1 esta en el archivo ListaEnlazada.cpp.
    3.- Las funciones del TDA tABB del problema 2 esta en el archivo arbolDef.cpp.

Recomendaciones al compilar y probar:
    1.- Para probar el TDA listaEnlazada: editar y ejecutar desde problema1.cpp
    2.- Para probar el TDA tABB: editar y ejecutar desde problema2.cpp

Formas de compilación utilizada:
    * Todos estos desde entrada estandar, por consola *
    1.- Para los casos de prueba se usó: "g++ archivo.cpp archivoTDA.hpp archivoTDA.cpp -o nombre_archivo" para compilar.
	(En el caso del problema 1: g++ problema1.cpp problema1.hpp ListaEnlazada.cpp -o nombre_archivo)
	(En el caso del problema 2: g++ problema2.cpp problema2.hpp arbolDef.cpp -o nombre_archivo)
    2.- Si se quiere ejecutar el programa compilado: "./nombre_archivo"
    3.- Si se quiere verificar los warning: "g++ archivo.cpp archivoTDA.hpp archivoTDA.cpp -o nombre_archivo -Wall".
	(En el caso del problema 1: g++ problema1.cpp problema1.hpp ListaEnlazada.cpp -o nombre_archivo -Wall)
	(En el caso del problema 2: g++ problema2.cpp problema2.hpp arbolDef.cpp -o nombre_archivo -Wall)
    4.- si se quiere verificar la liberacion de memoria: "valgrind ./nombre_archivo".


    
Recordatorio:
    1.- Las funciones del TDA Login del problema 1 estan en la carpeta Hashing, donde se encuentra el Hashing.cpp y el Hashing.hpp.
    2.- Las funciones del TDA tColaP del problema 2 estan en carpeta ColaP, donde se encuentra el ColaP.cpp y el ColaP.hpp.

Recomendaciones al compilar y probar:
    1.- Para probar el TDA Login: editar y ejecutar desde problema1.cpp
    2.- Para probar el TDA tColaP: editar y ejecutar desde problema2.cpp

Formas de compilación utilizada:
    * Todos estos desde entrada estandar *
    1.- Para los casos de prueba se usó: "g++ archivo.cpp -o nombre_archivo" para compilar.
	(En el caso del problema 1: g++ problema1.cpp Hashing/Hashing.cpp Hashing/Hashing.hpp -o nombre_archivo)
	(En el caso del problema 2: g++ problema2.cpp ColaP/ColaP.cpp ColaP/ColaP.hpp -o nombre_archivo)
    2.- Si se quiere ejecutar el programa compilado: "./nombre_archivo"
    3.- Si se quiere verificar los warning: "g++ archivo.cpp -o nombre_archivo -Wall".
	(En el caso del problema 1: g++ problema1.cpp Hashing/Hashing.cpp Hashing/Hashing.hpp -o nombre_archivo -Wall)
	(En el caso del problema 2: g++ problema2.cpp ColaP/ColaP.cpp ColaP/ColaP.hpp -o nombre_archivo -Wall)
    4.- si se quiere verificar la liberacion de memoria: "valgrind ./nombre_archivo".

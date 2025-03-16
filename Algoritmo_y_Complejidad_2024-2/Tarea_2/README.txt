Nombre: Daniel Quispe
Rol: 202273529-5

Datos necesarios antes de compilar:

    *   Para probar los algoritmos bajo distintas tablas de coste, es necesario que los archivos esten dentro de la carpeta dataCost:
        - cost_delete.txt
        - cost_insert.txt
        - cost_replace.txt
        - cost_transpose.txt
        Si dichos archivos no se encuentran en la carpeta con los nombre indicados, el programa no funcionara adecuadamente.
    *   Si se quieren probar casos de prueba, estos tienen que ser en archivos de texto con formato inputX.txt, donde "X" es un numero cualquiera. (A pesar que el programa indica que solo se aceptan numero del 1 al 10, mientras siga el formato indicado y además, se le entregue por consola bien el numero del caso, este funcionará)
    *   Es estrictamente necesario que los archivos inputX.txt tengan 2 lineas.

Instrucciones de compilación y ejecución:

    *   Para la compilación y ejecución del algoritmos de fuerza bruta, se utilice el makefile usando la linea "make FB".
    *   Para la compilación y ejecución del algoritmos de programación dinamica, se utilice el makefile usando la linea "make DP".
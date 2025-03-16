## Integrantes:
Daniel Quispe 202273529-5 201; Matías Fernández 202273506-6 201

## Especificación de los nombres de los archivos:
- **DonFondon.java**: Programa principal donde se recorren los directorios junto con los archivos de texto, se recorre la matriz utilizando forks y donde se imprime el carácter encontrado, tiempo de busqueda asociado, palabra formada y tiempo de ejecución total.
- **MatrixTask.java**: Programa auxiliar de DonFondon en el cual se recorre recursivamente la matriz y se guarda el carácter encontrado.
- **FuerzaIntergalactica.java**: Programa principal donde se recorren los directorios junto con los archivos de texto, se recorre la matriz utilizando hebras y donde se imprime el carácter encontrado, tiempo de busqueda asociado, palabra formada y tiempo de ejecución total.
- **Hebras.java**: Programa auxiliar de FuerzaIntergalactica en el cual se recorre recursivamente la matriz y se guarda el carácter encontrado.

## Instrucciones generales de compilación y uso:
Los programas mencionados anteriormente son gestionados por un Makefile, tanto en compilación como ejecución. 
* Para compilar y ejecutar el programa que contiene los forks (Don Fondon) escriba la linea de comando "make run" en la consola.
* Para compilar y ejecutar el programa que contiene las hebras (Fuerzas Intergalácticas) escriba la linea de comando "make runH" en la consola.

## Consideraciones importantes:
* Se considera que se leerán los archivos con el formato de los archivos de prueba, esto es, 
directorios con el nombre "CasoX", siendo X un número, y dentro de ellos archivos txt con el nombre "codeX", 
donde X representa un número. Estos serán leídos en orden para poder formar la palabra correcta.

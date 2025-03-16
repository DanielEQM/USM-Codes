Matías Fernández ; 202273506-6 ; Paralelo 200
Daniel Quispe ; 202273529-5 ; Paralelo 200

Se realizó una función generalizada que transforma un número en cualquiera de las bases numéricas entregadas (binario, octal y hexadecimal) en número decimal. Funciona generando el polinomio característico del número, realizando la sumatoria de las componentes y guardandolas todas en una variable que es el resultado de la función.

Ej: el polinomio característico de 110 en binario se traduciría a: 1*2^2 + 1*2^1 + 0*2^0,
que daría como resultado el número 3 en base decimal.

Luego, como se pide que la conversión sea en ambos sentidos, se creó la función que transforma un número decimal en uno cualquiera de las bases pedidas. Esto funciona dividiendo el número segun la base a la que se quiera convertir y el modulo guardandolo en una lista, la cual es invertida y luego unida en un string que representa el número resultante.

SUPUESTOS:
- Los inputs ingresados son correctos en el espacio delimitado.
- Al momento de ingresar coordenadas en binario, no es necesario que la cantidad de digitos de la coordenada "x" coincida con la "y".
- Se pide como input el tamaño del tablero y la cantidad de naves enemigas.
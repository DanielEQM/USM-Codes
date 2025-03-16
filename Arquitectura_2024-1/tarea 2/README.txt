Integrantes:
- Daniel Quispe ; 202273529-5 ; 200
- Matias Fernandez ; 202273506-6 ; 200

Especificacion de los algoritmos y desarrollo realizado:
~ Para la logica de estados se comenzó haciendo una tabla de estados con dos columnas, siendo la primera el estado inicial Qn y la segunda el estado siguiente Qn+1. Luego se hicieron las transformaciones en binario con 4 entradas A,B,C y D, de las cuales se hicieron los mapas de Karnough respectivos y se obtuvieron las funciones minimas con las que se generó el FF-D en Logisim.

~ Para la logica de salida se hizo el mismo procedimiento. Tanto la logica de estados como la de salida están más especificados en el informe.

Supuestos utilizados:
* Una vez inicializado en reloj, se escribe el input deseado, se espera un periodo de reloj y ahí recien se prende el interruptor. (para que funcione el multiplexor).
* Si se quiere resetear, se tiene que apagar el interruptor y cambiar el input.
* El subcircuito "7-sig" fue hecho con el programa Logisim metiendo los datos en la tabla de verdad que otorga el programa.
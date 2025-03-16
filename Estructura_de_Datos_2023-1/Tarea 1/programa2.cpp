#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;
int cantidad;

struct Persona { 
    string nombre;
    char fecha[11];
    int tamanio_tarjeta;
    int* tarjeta;
    bool quiere_intercambiar;
};

int* comprarTarjeta(string nombre, int dia, int &m){
    m = nombre.length(); 
    int* ficha = new int[m];  
    for (int i = 0; i < m; i++){ 
        ficha[i] = (int) nombre[i] % dia;
    }
    return ficha;
}

/*****
* int* comprarTarjeta
******
* Se crea un ciclo en el que a la posicion i-ésima de la ficha se le asigna un entero dado por el carácter i-ésimo del
nombre módulo día. 
******
* Recibe tres parámetros: 
• El string nombre de la persona 
• El entero día en el que se compra la tarjeta
• Y la dirección de memoria "m" con el tamaño del arreglo que se retornará.
******
* La función entrega un arreglo de datos tipo entero de igual tamaño que el string nombre, 
donde en la i-ésima posición tendrá el valor: nombre[i]%10.
*/

void intercambiarTarjeta(Persona*p1, Persona*p2){
    int* swap = p1->tarjeta;
    int swap2 = p1->tamanio_tarjeta;
    p1->tamanio_tarjeta = p2->tamanio_tarjeta;
    p2->tamanio_tarjeta = swap2;
    p1->tarjeta = p2->tarjeta;
    p2->tarjeta = swap;
}

/*****
* void intercambiarTarjeta
******
* Se intercambian entre las dos personas la direccion de memoria a la que apuntan sus punteros y el tamaño de la tarjeta
******
* Recibe dos parámetros del mismo tipo:
• Punteros del struct tipo Persona.
******
* La función intercambia las tarjetas entre ambas personas.
*/

int puntaje(Persona* p1){
    int contador = 0,numero;
    for(int i=0;i<p1->tamanio_tarjeta;i++){
        numero= p1->tarjeta[i] * ((int) p1->fecha[i%10]);
        contador+=numero;
    }
    return contador;
}

/*****
* int puntaje
******
* Realiza una sumatoria por cada elemento del arreglo, en el que se multiplica el carácter i-ésimo de
la tarjeta por la fecha i-ésima módulo 10.
******
* Recibe un parámetro;
• Puntero del struct tipo Persona.
******
* La función retorna el puntaje de tipo entero de la persona entregada.
*/

bool comun(Persona *p1, Persona *p2){
    int a = (p1->nombre).length();
    int b = (p2->nombre).length();
    for (int i=0; i< a;i++){
        for (int j = 0; j < b; j++){
            if (p1->tarjeta[i] == p2->tarjeta[j]){
                return 1;
            }
        }
    }
    return 0;
}

/*****
* bool comun
******
* Compara las posiciones i-ésima de la primera persona y j-ésima de la segunda persona para verificar
si comparten un mismo número. De ser verdadero, retorna 1, caso contrario, 0.
******
* Recibe dos parámetros del mismo tipo:
• Punteros del struct tipo Persona.
******
* La función retorna un booleano 1 si se cumple la condición o 0 en caso contrario.
*/

Persona* unDia(Persona* personas,int dia){
    int m;
    bool X;
    int menor = -1;
    int puntos;
    int win;
    for (int i=0; i<cantidad; i++){
        personas[i].tarjeta = comprarTarjeta(personas[i].nombre, dia, m);
        personas[i].tamanio_tarjeta = m;
    }
    for (int i=0; i<cantidad; i++){
        if (personas[i].quiere_intercambiar != 0){
            for (int j = i + 1; j < cantidad; j++){
                if (personas[j].quiere_intercambiar != 0){
                    X = comun(&personas[i], &personas[j]);
                    if (X == 1){    
                        intercambiarTarjeta(&personas[i], &personas[j]);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i<cantidad; i++){
        puntos = puntaje(&personas[i]);
        if(menor < puntos){
            menor = puntos;
            win = i;
        }
    }
    return &personas[win];
}

/*****
* Persona* unDia
******
* A cada persona rellena sus elementos del struct utilizando la funcion comprarTarjeta, revisa 
con un ciclo si las personas quieren intercambiar con la funcion intercambiarTarjeta y calcula 
sus puntajes con la funcion puntaje, comparando hasta llegar al mayor y guardar su dirección de memoria.
******
* Recibe dos parámetros:
• Puntero a un arreglo de datos tipo Persona.
• Entero día.
******
* La función retorna la dirección de memoria del arreglo de la persona con el mayor puntaje.
*/

void variosDias(Persona* personas, int cant_dias){
    Persona *pers;
    for(int i= 1; i < cant_dias + 1; i++){
        pers = unDia(personas, i);
        int score = puntaje(pers);
        cout<<pers->nombre << " " << pers->fecha << " " << score << "\n";
        for (int i = 0; i <cantidad; i++){
            delete[] personas[i].tarjeta;
        }
    }
}

/*****
* void variosDias
******
* Llama a la función unDia en un ciclo para determinar el ganador por cada día,
donde al final de la ejecución se imprime el ganador con sus datos.
******
* Recibe dos parámetros:
• Puntero a un arreglo de datos tipo Persona.
• Entero días.
******
* La función retorna el nombre, fecha de nacimiento y puntaje del ganador de cada día.
*/

int main(){
    cin>> cantidad;
    Persona per[cantidad];
    for (int i=0; i<cantidad; i++){ 
        cin >> per[i].nombre >> per[i].fecha >> per[i]. quiere_intercambiar;
    }
    variosDias(per, 2);
    return 0;
}

/*
solo funciono con nuestro main, murio con el de prueba Dx
*/

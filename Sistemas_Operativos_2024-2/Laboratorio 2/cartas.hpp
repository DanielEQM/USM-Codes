#ifndef CARTAS_HPP
#define CARTAS_HPP
#include <bits/stdc++.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <semaphore.h>

#define CS "Cambio De Sentido"
#define S "Salta"
#define R2 "Roba dos"
#define C "Comodin"
#define R4 "Roba cuatro"
#define NUM_JUGADORES 4
#define NUM_COMODINES 4

using namespace std;

sem_t *semaphore;

struct cartas{
    char* color;
    char* tipo;
};


struct mazos {
    cartas mano[108];
    int num_cartas = 0;
};


struct juego{
    mazos mazoMain;
    mazos descates;
    cartas arriba;
    bool toma = false;
    char dir;
    int sig;
    int cantCartasJugador[4];
};


int turnoJ(int j, char d, int t){
    if(d == 'R'){
        j = (j + t) % 4;
    } else {
        j -= t;
        if(j < 0){
            j = 4 + j;
        }
    }
    return j + 1;
}
/********** 
* función: turnoJ
* ********
* parámetros: int j (jugador), char d (direccion), int t (turno) 
* ********
* descripción: Realiza el flujo de turnos entre jugadores, donde si la direccion de juego sigue siendo hacia la derecha
* continúa con el jugador j-esimo + 1, en cambio, si fuera a la inversa continua con el jugador - 1.
*/

bool ganador(int lista[]){
    for(int i = 0; i < 4; i++){
        if(lista[i] == 0){
            return 1;
        }
    }
    return 0;
}
/********** 
* función: ganador
* ********
* parámetros: int lista[] (jugadores)
* ********
* descripción: retorna true en caso de que un jugador se quede sin cartas.
*/

bool verificarCarta(cartas jugador, cartas primera){
    if(jugador.color == "SinColor"){
        return 0;
    }
    if(jugador.color != primera.color){
        if(jugador.tipo != primera.tipo){
            cout << "Color o tipo no coincide.\n";
            return 1;
        }
    }
    return 0;
}

/********** 
* función: verificarCarta
* ********
* parámetros: cartas jugador, cartas primera (primera de la pila de descarte)
* ********
* descripción: retorna false si no hay necesidad de chequear la carta puesta. En caso de que la carta a jugar 
* no se pueda realizar, siendo porque no coincide el color ni el tipo, retorna true.
*/


void vacio(juego *tablero){
    for(int i = tablero->descates.num_cartas - 1; i > 0; i--){
        tablero->mazoMain.mano[tablero->mazoMain.num_cartas++] = tablero->descates.mano[i];
    }
    tablero->descates.num_cartas = 1;
}

/********** 
* función: vacio
* ********
* parámetros: juego *tablero
* ********
* descripción: en caso de que el mazo se esté quedando sin cartas se revisa la pila de descartes, se reemplaza
* por el mazo y se deja la última carta jugada para seguir con el flujo de juego.
*/


void roba(juego *tablero, mazos &mazo, int cantidad, int numJu){
    if((tablero->mazoMain.num_cartas - cantidad) <= 0){
        vacio(tablero);
    }
    for(int i = tablero->mazoMain.num_cartas - 1; i > tablero->mazoMain.num_cartas - cantidad - 1; i--){
        mazo.mano[mazo.num_cartas] = tablero->mazoMain.mano[i];
        mazo.num_cartas++;
    }
    tablero->cantCartasJugador[numJu - 1] += cantidad;
    tablero->mazoMain.num_cartas -= cantidad;
}

/********** 
* función: roba
* ********
* parámetros: juego *tablero, mazos &mazo, int cantidad, int numJu (numero jugador)
* ********
* descripción: En caso de que no queden cartas, se cambia la pila de descarte por el mazo con la funcion vacio. Si 
* las hay, entonces se toman cartas.
*/

void barajar(cartas mazo[], int size){
    vector<bool> b(size, 0);
    vector<cartas> mazo_d(size);

    srand(time(NULL));

    int index = 0;
    for(int i = 0; i < size; i++){
        while(b[index]){
            index = rand() % size;
        }
        mazo_d[i] = mazo[index];
        b[index] = 1;
    }
    for(int i = 0; i < size; i++){
        mazo[i] = mazo_d[i];
    }
}

/********** 
* función: barajar
* ********
* parámetros: cartas mazo[], int size
* ********
* descripción: Se baraja el mazo respectivo con una eleccion aleatorio por parte de la semilla elegida.
*/

int inicializar_mazo(cartas mazo[]) {
    char* colores[4] = {(char*)"Rojo", (char*)"Azul", (char*)"Amarillo", (char*)"Verde"};
    char* tipo[12] = {(char*)"1", (char*)"2", (char*)"3", (char*)"4", (char*)"5", (char*)"6",
                         (char*)"7", (char*)"8", (char*)"9", (char*)CS, (char*)S, (char*)R2};
    int indice = 0;

    for (int c = 0; c < 4; c++) {
        mazo[indice++] = (cartas){ colores[c], (char*)"0" };
        
        for (int num = 0; num < 12; num++) {
            mazo[indice++] = (cartas){ colores[c], tipo[num] };
            mazo[indice++] = (cartas){ colores[c], tipo[num] };
        }
    }
    for (int i = 0; i < NUM_COMODINES; i++) {
        mazo[indice++] = (cartas){ (char*)"SinColor", (char*)C };
        mazo[indice++] = (cartas){ (char*)"SinColor", (char*)R4 };
    }
    barajar(mazo, indice);
    return indice;
}

/********** 
* función: inicializar_mazo
* ********
* parámetros: cartas mazo[]
* ********
* descripción: Se añaden al mazo las cartas con los tipos definidos previamente al inicio del archivo, cumpliendo
* con la cantidad y funcionalidad requeridos. Luego de eso, se baraja.
*/

void imprimir_mazo(cartas mazo_compartido[], int mazo_size){
    for (int i = 0; i < mazo_size; i++){
        printf("Carta %d:\n", i+1);
        printf(" Color: %s\n",mazo_compartido[i].color);
        printf(" Tipo: %s\n",mazo_compartido[i].tipo);
    }
}

/********** 
* función: imprimir_mazo
* ********
* parámetros: cartas mazo_compartido[], int mazo_size
* ********
* descripción: Funcion auxiliar utilizada al inicio del programa para revisar si las cartas fueron creadas
* correctamente.
*/

void imprimir_cartas_jugadores(mazos jugador, int p, int numJ) {
    printf("Jugador %d (id %d)\n", numJ, p);
    for (int j = 0; j < jugador.num_cartas; j++) {
        printf("  Carta %d:\n", j + 1);
        printf("    Color: %s\n", jugador.mano[j].color);
        printf("    Tipo: %s\n", jugador.mano[j].tipo); 
    }
    printf("\n");
}

/********** 
* función: imprimir_cartas_jugadores
* ********
* parámetros: mazos jugador, int p, int numJ (numero jugador)
* ********
* descripción: Imprime las cartas del jugador en el instante en el que es llamada la función.
*/

void repartir_cartas(mazos *jugadores, cartas* mazo){
    int indice_mazo = 0;
    for(int i = 0; i < NUM_JUGADORES; i++){
        jugadores[i].num_cartas = 7;

        for(int j = 0; j < 7; j++){
            jugadores[i].mano[j] = mazo[indice_mazo++];
        }
    }
}

/********** 
* función: repartir_cartas
* ********
* parámetros: mazos *jugadores, cartas* mazo
* ********
* descripción: Guarda en cada jugador las cartas que se encuentran en la posicion mas alta del mazo.
*/

#endif
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void*** tablero;
int dimension;
int** tipo;
int Tesoros;
int Turnos;

void IniciarTablero(int n){
    /*
    * * * * * * * * *
    * Parametros:
    * - int n
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * Se inicia el tablero con vida aleatoria, además de
    * la matriz auxiliar que ayuda a saber donde hay bombas.
    *
    */
    srand(time(0));
    dimension = n;
    Tesoros = 0;
    Turnos = 1;
    tablero = malloc(dimension*sizeof(void**));
    for(int i = 0; i < dimension; i++){
        tablero[i] = malloc(dimension*sizeof(void*));
        for(int j = 0; j < dimension; j++){
            tablero[i][j] = malloc(sizeof(Tierra));
            ((Tierra *) tablero[i][j])->vida = (rand() % 3) + 1;
            if(rand() % 100 + 1 <= 5 ){
                ((Tierra *) tablero[i][j])->es_tesoro = 1;
                Tesoros++;
            } else{
                ((Tierra *) tablero[i][j])->es_tesoro = 0;
            }
        }
    }
    tipo = (int**) malloc(dimension*sizeof(int*));
    for(int i = 0; i < dimension; i++){
        tipo[i] = (int*) malloc(dimension*sizeof(int));
        for(int j = 0; j < dimension; j++){
            tipo[i][j] = 0;
        }
    }
    return;
}


void PasarTurno(){
    /*
    * * * * * * * * *
    * Parametros:
    * - Ninguno
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * Recorre la matriz auxiliar, y si encuentra que hay alguna bomba
    * las manda a la función TryExplotar para hacerla explotar.
    */
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(tipo[i][j] == 1){
                TryExplotar(i,j);
            }
        }
    }
    return;
}


void ColocarBomba(Bomba* b, int fila, int columna){
    /*
    * * * * * * * * *
    * Parametros:
    * - Bomba* b
    * - int fila
    * - int columna
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * Coloca la Bomba en el tablero y la Tierra que había la coloca
    * debajo de la bomba.
    */
    void *aux = tablero[fila][columna];
    tablero[fila][columna] = b;
    ((Bomba*) tablero[fila][columna])->tierra_debajo = aux;
    tipo[fila][columna] = 1;
    return;
}


void MostrarTablero(){
    /*
    * * * * * * * * *
    * Parametros:
    * - Ninguno
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * En el caso de que la tierra no sea 0, hace explotar la bomba
    * Muestra el tablero según lo que haya con la siguiente prioridad:
    *  - Bomba.
    *  - Tesoro.
    *  - Vida.
    */
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(tipo[i][j] == 0){
                if(((Tierra*) tablero[i][j])->vida == 0){
                    if(((Tierra*) tablero[i][j])->es_tesoro == 1){                   
                        printf("| * ");
                    } else {                       
                        printf("| %d ", ((Tierra*) tablero[i][j])->vida);
                    }
                } else {
                    printf("| %d ", ((Tierra*) tablero[i][j])->vida);
                }
            } else {
                printf("| o ");
            }
        }
        printf("|\n");
    }
    return;
}


void MostrarBombas(){
    /*
    * * * * * * * * *
    * Parametros:
    * - Ninguno
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * Muestra las bombas con sus caracteristicas con el 
    * formato entregado.
    */
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(tipo[i][j] == 1){
                printf("-------------------------------------\n");
                printf("Turnos para explotar: %d\n",((Bomba *)tablero[i][j])->contador_turnos);
                printf("Coordenadas: %d %d\n",i+1,j+1);
                void *comp = ExplosionX;
                if(comp == ((Bomba *)tablero[i][j])->explotar){
                    printf("forma explosion: ExplosionX\n");
                } else{
                    printf("forma explosion: ExplosionPunto\n");
                }
                printf("Vida de Tierra Debajo: %d\n",((Bomba*)tablero[i][j])->tierra_debajo->vida);
            }
        }
    }
    printf("-------------------------------------\n");
    return;
}


void VerTesoros(){
    /*
    * * * * * * * * *
    * Parametros:
    * - Ninguno
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * En el caso de que la tierra no sea 0, hace explotar la bomba
    * Muestra el tablero con todos los tesoros como RayosX teniendo
    * la siguiente prioridad:
    *  - Tesoros.
    *  - Bombas.
    *  - Vida.
    */
    printf(" >>> Tablero con todos los Tesoros <<<\n");
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(tipo[i][j] == 0){
                if(((Tierra*)tablero[i][j])->es_tesoro == 1){
                    printf("| * ");
                } else {
                    printf("| %d ", ((Tierra*) tablero[i][j])->vida);
                }
            } else {
                if(((Bomba *)tablero[i][j])->tierra_debajo->es_tesoro == 1){
                    printf("| * ");
                } else {
                    printf("| o ");
                }
            }
        }
        printf("|\n");
    }
    printf("\n---------------------------\n");
    return;
}


void BorrarTablero(){
    /*
    * * * * * * * * *
    * Parametros:
    * - Ninguno
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * Borra el tablero y también la matriz auxiliar que se creo
    * anteriormente.
    */
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(tipo[i][j] == 0){
                free(tablero[i][j]);    
            } else {
                BorrarBomba(i,j);
                free(tablero[i][j]);
            }
        }
        free(tablero[i]);
    }
    free(tablero);
    for(int i = 0; i < dimension; i++){
        free((void*)tipo[i]);
    }
    free(tipo);
    return;
}
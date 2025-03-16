#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"
#include <stdio.h>
#include <stdlib.h>


void TryExplotar(int fila, int columna){
    /*
    * * * * * * * * *
    * Parametros:
    * - int fila
    * - int columna
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * Descuenta un turno al contador de la bomba, y cuando
    * esta llega a 0, la hace explotar. 
    */
    ((Bomba*)tablero[fila][columna])->contador_turnos -= 1;
    if(((Bomba*)tablero[fila][columna])->contador_turnos == 0){
        ((Bomba*)tablero[fila][columna])->explotar(fila,columna);
    }
    return;
}

void BorrarBomba(int fila, int columna){
    /*
    * * * * * * * * *
    * Parametros:
    * - int fila
    * - int columna
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * Borra la bomba en las coordenadas dadas, pero antes le devuelve
    * a tablero la tierra que había debajo de la bomba.
    */
    void *aux = ((Bomba *)tablero[fila][columna])->tierra_debajo;
    free(tablero[fila][columna]);
    tablero[fila][columna] = aux;
    tipo[fila][columna] = 0;
    return;
}

void ExplosionPunto(int fila, int columna){
    /*
    * * * * * * * * *
    * Parametros:
    * - int fila
    * - int columna
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * En el caso de que la tierra no sea 0, hace explotar la bomba
    * y si encuentra un tesoro, los descuenta al contador de Tesoros 
    * totales y al terminar llama a la funcion que borrará la bomba
    * de la casilla.
    */
    if(((Bomba *)tablero[fila][columna])->tierra_debajo->vida != 0){
        ((Bomba *)tablero[fila][columna])->tierra_debajo->vida -= 3;
        if(((Bomba *)tablero[fila][columna])->tierra_debajo->vida <= 0){
            ((Bomba *)tablero[fila][columna])->tierra_debajo->vida = 0;
            if(((Bomba *)tablero[fila][columna])->tierra_debajo->es_tesoro == 1){
                Tesoros--;
            }
        }
    }
    BorrarBomba(fila, columna);
    return;
}

void ExplosionX(int fila, int columna){
    /*
    * * * * * * * * *
    * Parametros:
    * - int fila
    * - int columna
    * * * * * * * * *
    * return void
    * * * * * * * * *
    * En el caso de que la tierra debajo de cada casilla afectada, no
    * sea 0, entonces hará daño a la Tierra.
    * se divide en 4 casos:
    * - fila1 y columna1 : Esta representa la esquina superior izquierda
    * - fila1 y columna2 : Esta representa la esquina superior derecha 
    * - fila2 y columna1 : Esta representa la esquina inferior izquierda
    * - fila2 y columna2 : Esta representa la esquina inferior derecha
    * 
    * Si es que encuentra un tesoro en alguna de las casillas afectadas
    * las descuenta al contador de Tesoros totales  y al terminar llama
    * a la funcion que borrará la bomba de la casilla.
    */
    if(((Bomba *)tablero[fila][columna])->tierra_debajo->vida != 0){
        ((Bomba *)tablero[fila][columna])->tierra_debajo->vida -= 1;
        if(((Bomba *)tablero[fila][columna])->tierra_debajo->vida == 0){
            ((Bomba *)tablero[fila][columna])->tierra_debajo->vida = 0;
            if(((Bomba *)tablero[fila][columna])->tierra_debajo->es_tesoro == 1){
                Tesoros--;
            }
        }
    }
    int fila1, fila2, columna1, columna2;
    fila1 = (fila - 1) % dimension;
    fila2 = (fila + 1) % dimension;
    columna1 = (columna - 1) % dimension;
    columna2 = (columna + 1) % dimension;
    if(fila1 == -1){
        fila1 += dimension;
    }
    if(fila2 == -1){
        fila2 += dimension;
    }
    if(columna1 == -1){
        columna1 += dimension;
    }
    if(columna2 == -1){
        columna2 += dimension;
    }
    int filas[2] = {fila1, fila2};
    int columnas[2] = {columna1, columna2};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(tipo[filas[i]][columnas[j]] == 1){
                if(((Bomba *)tablero[filas[i]][columnas[j]])->tierra_debajo->vida != 0){
                    ((Bomba *)tablero[filas[i]][columnas[j]])->tierra_debajo->vida -= 1;
                    if(((Bomba *)tablero[filas[i]][columnas[j]])->tierra_debajo->vida == 0){
                        ((Bomba *)tablero[filas[i]][columnas[j]])->tierra_debajo->vida = 0;
                        if(((Bomba *)tablero[filas[i]][columnas[j]])->tierra_debajo->es_tesoro == 1){
                            Tesoros--;
                        }
                    }
                }
            } else {
                if(((Tierra *)tablero[filas[i]][columnas[j]])->vida != 0){
                    ((Tierra *)tablero[filas[i]][columnas[j]])->vida -= 1;
                    if(((Tierra *)tablero[filas[i]][columnas[j]])->vida == 0){
                        ((Tierra *)tablero[filas[i]][columnas[j]])->vida = 0;
                        if(((Tierra *)tablero[filas[i]][columnas[j]])->es_tesoro == 1){
                            Tesoros--;
                        }
                    }            
                }
            }    
        }
    }
    BorrarBomba(fila, columna);
    return;
}

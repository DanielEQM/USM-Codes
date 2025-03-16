#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tierra.h"
#include "Tablero.h"
#include "Bomba.h"

int main(int argc, char const *argv[])
{
    int d, option, fila, columna, explo;
    printf("¡Bienvenidos a a TreasureFinder!\n");
    printf("Indique el tamaño del tablero a jugar:\n(1) >>  7x7  <<\n(2) >> 10x10 <<\n(3) >> 12x12 <<\nOpcion Tamaño: ");
    scanf("%d", &d);
    printf("Generando tablero...\n¡Empezando!\n\n");
    switch (d) {
        case 1: d = 7; 
                break;
        case 2: d = 10;
                break;
        case 3: d = 12;
    }
    IniciarTablero(d);
    while(Tesoros != 0){ 
        printf("Tablero >> Turno %d <<\n",Turnos);   
        MostrarTablero();
        printf("\nSeleccione una de las siguientes acciones:\n");
        printf("[1] >>> Colocar Bomba\n[2] >>> Mostrar Bombas\n[3] >>> Mostrar Tesoros\nEscoja una opcion: ");
        scanf("%d",&option);
        if(option == 1){
            printf("\nIndique coordenadas de la bomba:\nFila: ");
            scanf("%d", &fila);
            printf("Columna: ");
            scanf("%d", &columna);
            printf("\nIndique forma en que explota la bomba:\n[1] >>> Punto\n[2] >>> ExplosionX\nTipo explosion: ");
            scanf("%d", &explo);
            Bomba *b = (Bomba *) malloc(sizeof(Bomba));
            switch (explo){
                case 1: b->explotar = ExplosionPunto;
                        b->contador_turnos = 1; 
                        break;
                case 2: b->explotar = ExplosionX;
                        b->contador_turnos = 3;
            }
            ColocarBomba(b, fila - 1, columna - 1);
            PasarTurno();
            Turnos++;
            printf("\n");
        } else if(option == 2) {
            printf("\n");
            MostrarBombas();
            printf("\n");
        } else if (option == 3){
            printf("\n");
            VerTesoros();
            printf("\n");
        }
    }
    printf("\nFELICIDADES, HAS ENCONTRADO TODOS LOS TESOROS\n\nTurnos necesitados: %d\nTablero final:\n", Turnos-1);
    MostrarTablero();
    BorrarTablero();
    return 0;
}
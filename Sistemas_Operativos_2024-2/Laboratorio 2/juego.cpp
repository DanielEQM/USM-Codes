#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <condition_variable>
#include "cartas.hpp"


void ia_juego(juego *tablero, int numJu, int id, mazos mazo){
    sem_post(semaphore);
    sleep(1);
    while(true){
        sem_wait(semaphore);

        // hubo algun ganador?
        if(ganador(tablero->cantCartasJugador)){
            sem_post(semaphore);
            break;
        }

        if(tablero->sig == numJu){
            cout << "--------------------------------------\n";
            printf("Jugador %d (id %d)\n", numJu, id);
            //cout << tablero->arriba.color << " " << tablero->arriba.tipo << "\n";
            cout << "\n";
            int skip = 1;

            if(tablero->arriba.tipo == R4 && tablero->toma == true){ // Tomas 4?
                cout << " Tomo 4 cartas\n";
                cout << "--------------------------------------\n";
                roba(tablero, mazo, 4, numJu);
                tablero->toma = false;
                tablero->sig = turnoJ(tablero->sig - 1, tablero->dir, skip);

            } else if(tablero->arriba.tipo == R2 && tablero->toma == true){ // Tomas 2?
                cout << " Tomo 2 cartas\n";
                cout << "--------------------------------------\n";
                roba(tablero, mazo, 2, numJu);
                tablero->toma = false;
                tablero->sig = turnoJ(tablero->sig - 1, tablero->dir, skip);

            } else {
                int x;
                int tiene;
                for(tiene = 0; tiene < mazo.num_cartas; tiene++){
                    if(mazo.mano[tiene].tipo == tablero->arriba.tipo) break;
                    else if(mazo.mano[tiene].color == tablero->arriba.color || mazo.mano[tiene].color == "SinColor") break;
                }

                if(tiene == mazo.num_cartas){
                    roba(tablero, mazo, 1, numJu);

                    if(verificarCarta(mazo.mano[tiene], tablero->arriba)){
                        cout << "La carta sacada del mazo no puede ser utilizada inmediatamente\n";
                        //imprimir_cartas_jugadores(mazo, id, numJu);
                        tablero->sig = turnoJ(tablero->sig - 1, tablero->dir, skip);
                        sem_post(semaphore);
                        continue;
                    }
                }
                //imprimir_cartas_jugadores(mazo, id, numJu);

                srand(time(NULL));
                swap(mazo.mano[tiene], mazo.mano[mazo.num_cartas - 1]);
                char* colores[4] = {(char*)"Rojo", (char*)"Azul", (char*)"Verde", (char*)"Amarillo"};

                if(mazo.mano[mazo.num_cartas - 1].color == "SinColor"){
                    tablero->arriba.color = colores[rand() % 4];
                    tablero->arriba.tipo = mazo.mano[mazo.num_cartas - 1].tipo;
                    if(tablero->arriba.tipo == R4) tablero->toma = true;
                }  
                else {
                    tablero->arriba = mazo.mano[mazo.num_cartas - 1];
                    if(tablero->arriba.tipo == R2) tablero->toma = true;
                    if(tablero->arriba.tipo == S) skip = 2;
                    if(tablero->arriba.tipo == CS){
                        if(tablero->dir == 'R') tablero->dir = 'L';
                        else tablero->dir = 'R';
                    }
                }
                cout << "La carta lanzada es: " << tablero->arriba.color << " " << tablero->arriba.tipo << "\n";
                cout << "--------------------------------------\n";
                tablero->descates.mano[tablero->descates.num_cartas] = mazo.mano[mazo.num_cartas - 1];
                tablero->descates.num_cartas++;
                mazo.num_cartas--;
                tablero->cantCartasJugador[numJu - 1] = mazo.num_cartas;
                tablero->sig = turnoJ(tablero->sig - 1, tablero->dir, skip);
            }
            //imprimir_cartas_jugadores(mazo, id, numJu);
        }
        sem_post(semaphore);
    }
}

/********** 
* función: ia_juego
* ********
* parámetros: juego *tablero, int numJu (numero jugador), int id (pid del proceso), mazos mazo
* ********
* descripción: Controla el flujo de juego de los otros jugadores, tomando la primera carta que coincida
* con el color o tipo de la primera carta de la pila de descarte.
*/

void nosotros(juego *tablero, int numJu, int id, mazos mazo){
    sem_post(semaphore);
    sleep(1);
    while(true){
        sem_wait(semaphore);

        // hubo algun ganador?
        if(ganador(tablero->cantCartasJugador)){
            sem_post(semaphore);
            break;
        }

        if(tablero->sig == numJu){
            cout << "--------------------------------------\n";
            printf("Jugador %d (id %d)\n", numJu, id);
            cout << tablero->arriba.color << " " << tablero->arriba.tipo << "\n";
            cout << "\n";
            int skip = 1;

            if(tablero->arriba.tipo == R4 && tablero->toma == true){ // Tomas 4?
                cout << " Tomo 4 cartas\n";
                cout << "--------------------------------------\n";
                roba(tablero, mazo, 4, numJu);
                tablero->toma = false;
                tablero->sig = turnoJ(tablero->sig - 1, tablero->dir, skip);

            } else if(tablero->arriba.tipo == R2 && tablero->toma == true){ // Tomas 2?
                cout << " Tomo 2 cartas\n";
                cout << "--------------------------------------\n";
                roba(tablero, mazo, 2, numJu);
                tablero->toma = false;
                tablero->sig = turnoJ(tablero->sig - 1, tablero->dir, skip);

            } else {
                cout << "--------------------------------------\n";
                int x;
                int tiene;

                for(tiene = 0; tiene < mazo.num_cartas; tiene++){
                    if(mazo.mano[tiene].tipo == tablero->arriba.tipo) break;
                    else if(mazo.mano[tiene].color == tablero->arriba.color || mazo.mano[tiene].color == "SinColor") break; 
                }

                if(tiene == mazo.num_cartas){
                    roba(tablero, mazo, 1, numJu);
                    cout << "La carta robada es: " << mazo.mano[tiene].color << " " << mazo.mano[tiene].tipo << "\n";

                    if(verificarCarta(mazo.mano[tiene], tablero->arriba)){
                        cout << "La carta sacada del mazo no puede ser utilizada inmediatamente\n";
                        imprimir_cartas_jugadores(mazo, id, numJu);
                        tablero->sig = turnoJ(tablero->sig - 1, tablero->dir, skip);
                        sem_post(semaphore);
                        continue;
                    }
                }

                imprimir_cartas_jugadores(mazo, id, numJu);
                cout << "Escoja una carta (del 1 al " << mazo.num_cartas << "): ";
                cin >> x;

                while(x <= 0 || x > mazo.num_cartas || verificarCarta(mazo.mano[x - 1], tablero->arriba)){
                    cout << "Escoja una carta correctamente (del 1 al " << mazo.num_cartas << "): ";
                    cin >> x;
                }

                // pone la carta.
                char* colores[4] = {(char*)"Rojo", (char*)"Azul", (char*)"Verde", (char*)"Amarillo"};
                int colour;
                swap(mazo.mano[x - 1], mazo.mano[mazo.num_cartas - 1]);

                if(mazo.mano[mazo.num_cartas - 1].color == "SinColor"){
                    cout << "Escoge el color:\n1. Rojo\n2. Azul\n3. Verde\n4. Amarillo\n";
                    cout << "Cual eliges: "; cin >> colour;

                    while(colour <= 0 || colour > 4){
                        cout << "Escoge uno correcto\n";
                        cout << "Cual eliges: "; cin >> colour;
                    }
                    tablero->arriba.color = colores[colour - 1];
                    tablero->arriba.tipo = mazo.mano[mazo.num_cartas - 1].tipo;
                    
                    if(tablero->arriba.tipo == R4) tablero->toma = true;
                } else{
                    tablero->arriba = mazo.mano[mazo.num_cartas - 1];
                    if(tablero->arriba.tipo == R2) tablero->toma = true;
                    if(tablero->arriba.tipo == S) skip = 2;
                    if(tablero->arriba.tipo == CS){
                        if(tablero->dir == 'R') tablero->dir = 'L';
                        else tablero->dir = 'R';
                    }
                }

                cout << "La carta lanzada es: " << tablero->arriba.color << " " << tablero->arriba.tipo << "\n";
                cout << "--------------------------------------\n";
                tablero->descates.mano[tablero->descates.num_cartas] = mazo.mano[mazo.num_cartas - 1];
                tablero->descates.num_cartas++;
                mazo.num_cartas--;
                tablero->cantCartasJugador[numJu - 1] = mazo.num_cartas;
                tablero->sig = turnoJ(tablero->sig - 1, tablero->dir, skip);
            }
            imprimir_cartas_jugadores(mazo, id, numJu);
        }
        sem_post(semaphore);
    }
}

/********** 
* función: nosotros 
* ********
* parámetros: juego *tablero, int numJu (numero jugador), int id (pid del proceso), mazos mazo
* ********
* descripción: Controla el flujo de juego del jugador principal, pidiendole que escoja la carta a jugar o el
* color a jugar en caso de que sea un comodín o un roba cuatro.
*/

int main(){
    semaphore = sem_open("sem",  O_CREAT | O_EXCL, 0644, 1);

    juego *tablero = (juego*) mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    int tam = inicializar_mazo(tablero->mazoMain.mano);
    tablero->mazoMain.num_cartas = tam;
    tablero->sig = 1;
    tablero->dir = 'R';
    int cont = 0;
    while(tablero->mazoMain.mano[tam - 1].color == "SinColor"){
        swap(tablero->mazoMain.mano[cont++], tablero->mazoMain.mano[tam - 1]);
    }
    tablero->descates.mano[0] = tablero->mazoMain.mano[tam - 1];
    tablero->descates.num_cartas++;
    tablero->mazoMain.num_cartas--;
    tablero->arriba = tablero->descates.mano[0];

    mazos mazoPL;
    //imprimir_mazo(tablero->mazoMain.mano, tablero->mazoMain.num_cartas);
    pid_t jugadoress[4];
    int numJ = 1;
    bool f = false;
    for(int i = 0; i < 4; i++){
        jugadoress[i] = fork();

        // revisa error
        if(jugadoress[i] == -1){
            perror("error DX\n");
            return(1);
        }

        if(jugadoress[i] == 0){
            f = true;
            break;
        }
        numJ++;
        sleep(0.1);
    }
    if(f){
        sem_wait(semaphore);
        int cant = 0;
        for(int j = tablero->mazoMain.num_cartas - 1; j > tablero->mazoMain.num_cartas - 8; j--){
            mazoPL.mano[cant] = tablero->mazoMain.mano[j];
            cant++;
            mazoPL.num_cartas++;
        }
        tablero->cantCartasJugador[numJ - 1] = cant;
        tablero->mazoMain.num_cartas -= cant;
        //imprimir_cartas_jugadores(mazoPL, getpid(), numJ);
        sem_post(semaphore);
        sleep(1);
        sem_wait(semaphore);
        if(numJ == 1){
            nosotros(tablero, numJ, getpid(), mazoPL);
        } else {
            ia_juego(tablero, numJ, getpid(), mazoPL);
        }
    } else {
        int x, status = 0;
        while ((x = wait(NULL)) > 0);

        //imprimir_mazo(s->mazo, s->sizeMazo);
        for(int i = 0; i < 4; i++){
            if(tablero->cantCartasJugador[i] == 0){
                cout << "¡El jugador " << i + 1 << " se ha quedado sin cartas! ¡Ha ganado!\n";
            }
        }
        int rc = munmap(tablero, 4096);
        assert(rc == 0);
    }
    sem_unlink("sem");
    sem_close(semaphore);
    sem_destroy(semaphore);
    return 0;
}

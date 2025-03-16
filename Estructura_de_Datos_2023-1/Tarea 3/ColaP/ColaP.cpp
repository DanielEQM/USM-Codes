#include "ColaP.hpp"

ColaP::ColaP(){
    server = new array[100];
    size = 0;
    create = 0;
}

/*****
* constructor tColaP
******
* Inicializa la cola de prioridad que se va a utilizar
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

ColaP::~ColaP(){
    delete[] server;
}

/*****
* destructor ~tColaP
******
* Borra la cola de prioridad
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/


void ColaP::insertColaP(array Pri){
    size++; create++;
    int min, x = size;
    server[size] = Pri;
    array z;
    while(x!=1 && server[x].priority < server[x/2].priority){
        z = server[x];
        server[x] = server[x/2];
        server[x/2] = z;
        x /= 2;
    }
    while(2*x+1 <= size && (server[x].priority > server[2*x].priority || server[x].priority > server[2*x+1].priority )){
        if(server[2*x].priority < server[2*x+1].priority){
            min = 2*x;
        } else {
            min = 2*x+1;
        }
        z = server[x];
        server[x] = server[min];
        server[min] = z;
        x = min;
    }
    if(2*x <= size && server[x].priority > server[2*x].priority){
        z = server[x];
        server[x] = server[2*x];
        server[2*x] = z;
    }
    return;
}


/*****
* void insertColaP
******
* se encarga de insertar item dentro de la cola de prioridad. Si el hijo añadido
tiene menor prioridad que el padre se intercambian
******
* Input:
* array pri : es el arreglo que se quiere agregar a la cola de prioridad
* .......
******
* Returns:
* nada
*****/

void ColaP::GET(int cant){
    array N[cant];
    if(size == 0){
        cout<< "0\n";
        return;
    }
    for(int i=0; i < cant; i++){
        if(size != 0){
            N[i] = server[1];
            server[1] = server[size];
            size--;
            int min, j = 1;
            array z;
            while(2*j+1 <= size && (server[j].priority > server[2*j].priority || server[j].priority > server[2*j+1].priority)){
                if(server[2*j].priority < server[2*j+1].priority){
                    min = 2*j;
                } else {
                    min = 2*j+1;
                }
                z = server[j];
                server[j] = server[min];
                server[min] = z;
                j = min;
            }
            if(2*j <= size && server[j].priority > server[2*j].priority){
                z = server[j];
                server[j] = server[2*j];
                server[2*j] = z;
            }
        }
    }
    cout << cant << " ";
    for(int i= 0; i < cant; i++){
        cout << N[i].ID <<" ";
    }
    cout << "\n";
    for(int i=0; i < cant; i++){
        cout << N[i].Instruction << "\n";
    }
    return;
}

/*****
* void GET
******
* obtiene la cantidad de elementos que se piden al usuario
******
* Input:
* int cant : cantidad de elementos a obtener
* .......
******
* Returns:
* nada
*****/

int ColaP::sizeColaP(){
    return size;
}

/*****
* int sizeColaP
******
* Te da el tamaño de la cola de prioridad
******
* Input:
* nada
* .......
******
* Returns:
* int, retorna el tamaño int de la cola de prioridad
*****/


int ColaP::total(){
    return create;
}

/*****
* void total
******
* entrega la cantidad de elementos que fueron ingresados a la
* cola de prioridad en total
******
* Input:
* nada
* .......
******
* Returns:
* int, retorna cantidad de elementos enviados
*****/


/*
void ColaP::imprimir(){
    // al descomentar se puede usar para imprimir los datos de la cola de prioridad, pero no es una función importante
    for(int i = 1; i < size; i++){
        cout << "pos; " << i << "info: " << server[i].ID << " " << server[i].priority <<" "<< server[i].Instruction << "\n";
    }
}*/
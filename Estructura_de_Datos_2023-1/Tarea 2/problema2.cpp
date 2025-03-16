#include <iostream>
#include <string>
#include "problema2.hpp"

using namespace std;

void ENCENDER(int x, tABB &arbol){
    arbol.insert(x);
}

/*****
* void ENCENDER
******
* Llama a la a la funcion insert con el objetivo de insertar el integer x
******
* Input:
* integer x : el numero x que se va a insertar en el arbol
  tABB &arbol: entrega la memoria del abb para poder modificarlo fuera de la funcion
* .......
******
* Returns:
* void
*****/

int CUANTOS_ENCENDER(int x, tABB &arbol){
    bool valor;
    int faro;
    valor = arbol.find(x);
    if(valor==1){
        return 0;
    }
    faro = arbol.lower_bound(x);
    if(faro != 0){
        return x - faro;
    }
    return x + 1;
}

/*****
* int CUANTOS_ENCENDER
******
* Entrega la cantidad de postes que estan apagados desde la posicion x hasta el poste encendido mas cercano y en
 caso de no haber un poste encendido devuelve la cantidad de postes apagados entre la posicion 0 y x.
******
* Input:
* integer x: indica la posicion desde la cual se comienza a contar el numero de postes apagados.
  tABB &arbol: entrega la memoria del abb para poder modificarlo fuera de la funcion.
* .......
******
* Returns:
* int, retorna el numero de postes apagados.
*****/

int PARAR_PROGRAMA(tABB &arbol){
    return arbol.size();
}

/*****
* int PARAR_PROGRAMA
******
* se encarga de detener el programa devolviendo la cantidad de postes encendidos
******
* Input:
* tABB &arbol: entrega la memoria del abb para poder modificarlo fuera de la funcion
* .......
******
* Returns:
* int, retorna el numero de postes encendidos
*****/

int main(){
    tABB arbol;
    int x;
    string faros = "";
    while(faros != "PARAR_PROGRAMA"){
        cin >> faros;
        if(faros == "ENCENDER"){
            cin >> x;
            ENCENDER(x, arbol);
        }
        if(faros == "CUANTOS_ENCENDER"){
            cin >> x;
            cout << CUANTOS_ENCENDER(x, arbol)<<"\n";
        }
    }
    cout<< PARAR_PROGRAMA(arbol)<<"\n";
    return 0;
}


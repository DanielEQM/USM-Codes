#include <iostream>
#include <string>
#include "Hashing.hpp"

using namespace std;

int h(tipoClave k) {
    int sum = 0;
    int pow_3 = 1;
    for(int i = 0; i < (int)k.length(); i++) {
        sum += ((int)(k[i] * pow_3) + k.length());
        pow_3 *= 3;
    }
    return sum;
}

/*****
* int h
******
* Se encarga de devolver una posicion dentro de la tabla hash en base a k
******
* Input:
* tipoClave k : nombre del usuario al cual se le va a hacer hashing
* .......
******
* Returns:
* int,  retorna una posicion aleatoria en formato int
*****/

int p(tipoClave k, int i) {
    return 3 * i * i + 11 * i + 1;
}

/*****
* int p
******
* Se encarga de calcular una nueva posicion para el usuario k
******
* Input:
* tipoClave k : nombre de usuario 
  int i: el numero total de colisiones
* .......
******
* Returns:
* int,  retorna el resultado del calculo 
*****/

void hashInsert(ranura* HT, tipoClave k, tipoInfo I, int size) {
    int inicio, i;
    int pos = inicio = h(k) % size;
    for (i = 1; HT[pos].User != VACIA && HT[pos].User != k; i++) {
        pos = (inicio + p(k, i)) % size; 
    }
    if (HT[pos].User == k){
        return;
    }else {
        HT[pos].User = k;
        HT[pos].Info = I;
        return; 
    }
}

/*****
* void hashInsert
******
* Se encarga de insertar al usuario k dentro de la nueva tabla hash
******
* Input:
* ranura* HT:  Puntero que apunta a la tabla hashing
  tipoClave k: Es el nombre de usuario
  tipoInfo I: Contraseña de la cuenta del usuario
  int size: Tamaño de la nueva tabla hashing
* .......
******
* Returns:
* void
*****/

ranura* Nueva(ranura HT[], int T){
    ranura* HT2 = new ranura[T];
    for(int i = 0; i < T; i++){
        HT2[i].User = VACIA;
    }
    for(int i = 0; i < T/2; i++){        
        if(HT[i].User != VACIA){
            hashInsert(HT2, HT[i].User, HT[i].Info, T);
        }
    }
    delete[] HT;
    return HT2;
}

/*****
* ranura* Nueva
******
* Crear una nueva tabla hash
******
* Input:
* ranura HT[]: antigua tabla hash
  int T: tamaño de la nueva tabla hash
* .......
******
* Returns:
* ranura*, puntero hacia la nueva tabla hash
*****/

Login::Login(){
    M = 32;
    HT = new ranura[M];
    size = 0;
    for(int i = 0; i < M; i++){
        HT[i].User = VACIA;
    }
}

/*****
* contructor Login
******
* inicializa la tabla hash
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

Login::~Login(){
    delete[] HT;
}

/*****
* destructor ~Login
******
* destruye la tabla hash
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

bool Login::crear_nuevo_usuario(string usuario, string clave){
    int inicio, i;
    int pos = inicio = h(usuario) % M;
    for(i = 1; HT[pos].User != VACIA && HT[pos].User != usuario; i++){
        pos = (inicio + p(usuario, i)) % M;
    }
    if(HT[pos].User == usuario){
        cout<<"El usuario ya se encuentra registrado\n";
        return false;
    }
    else{
        if(clave.length() < 8){
            cout<<"La clave debe tener al menos 8 caracteres\n";
            return false;
        } else{
            HT[pos].User = usuario;
            HT[pos].Info.Password = clave;
            size++;
            cout<<"Usuario registrado con exito\n";
            if((size/(float)M) > 0.7){
                M *= 2;
                HT = Nueva(HT, M);
            }
            return true;
        }
    }
    
}

/*****
* bool crear_nuevo_usuario
******
* Busca si el usuario ya existe y en caso de que no exista lo agrega a la tabla hash
******
* Input:
* string usuario: nombre de usuario solicitado
  string clave: contraseña del usuario
* .......
******
* Returns:
* bool, retorna false en caso de que ya exista el usuario y true en caso de que no exista
*****/

bool Login::iniciar_sesion(string usuario, string clave){
    int inicio, i;
    int pos = inicio = h(usuario) % M;
    for(i = 1; HT[pos].User != VACIA && HT[pos].User != usuario; i++){
        pos = (inicio + p(usuario, i)) % M;
    }
    if(HT[pos].User == usuario){
        if(HT[pos].Info.Password == clave){
            cout<<"Sesion iniciada con exito\n";
            return true;
        }
        else{
            cout<<"La clave ingresada no coincide\n";
            return false;
        }
    }
    else{
        cout<<"El usuario no se encuentra registrado\n";
        return false;
    }
}

/*****
* bool iniciar_sesion
******
* Busca al usuario solicitado dentro de la tabla hash y verifica si es que la clave ingresada es la correcta 
******
* Input:
* string usuario: nombre de usuario
  string clave: contraseña del usuario
* .......
******
* Returns:
* bool, retorna false en caso de que la clave no sea la correcta o que el usuario no se encuentre registrado
y retorna true en caso de que se logre iniciar sesion con exito
*****/

bool Login::cambiar_clave(string usuario, string clave){
    int inicio, i;
    int pos = inicio = h(usuario) % M;
    for(i = 1; HT[pos].User != VACIA && HT[pos].User != usuario; i++){
        pos = (inicio + p(usuario, i)) % M;
    }
    if(HT[pos].User == usuario){
        if(clave.length() < 8){
            cout<<"La clave debe tener al menos 8 caracteres\n";
            return false;
        }
        else{
            HT[pos].Info.Password = clave;
            cout<<"Clave actualizada con exito\n";
            return true;
        }
    }
    else{
        cout<<"El usuario no se encuentra registrado\n";
        return false;
    }
}

/*****
* bool cambiar_clave
******
* busca al usuario solicitado para cambiar su clave
******
* Input:
* string usuario: nombre de usuario 
  string clave: contraseña del usuario
* .......
******
* Returns:
* bool, retorna false en caso de que el usuario no exista o que la nueva clave no cumpla con los parametros requeridos
y retorna true cuando se logra actualizar la clave
*****/

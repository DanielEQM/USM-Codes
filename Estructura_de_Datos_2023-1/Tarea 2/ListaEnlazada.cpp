#include <iostream>
#include <fstream>
#include <string>
#include "problema1.hpp"

using namespace std;

listaEnlazada::listaEnlazada(){
    head=tail=curr=new nodo;
    listSize=pos=0;
}

/*****
* constructor listaEnlazada
******
* Entrega los valores iniciales con los que se crea un objeto tipo
listaEnlazada.
******
* Input:
* ninguno
******
* Returns:
* void
*****/

listaEnlazada::~listaEnlazada(){
    clear();
}

/*****
* destructor listaEnlazada
******
* Llama a la función clear tan pronto se tenga que eliminar un objeto
de la clase listaEnlazada.
******
* Input:
* ninguno
******
* Returns:
* void
*****/

unsigned int listaEnlazada::length(){
    return listSize;
}

/*****
* unsigned int lenght
******
* retorna el largo del objeto listaEnlazada a través de una variable privada.
******
* Input:
* ninguno
******
* Returns:
* unsigned int, retorna el largo de la lista.
*****/

void listaEnlazada::moveToStart(){
    curr=head;
    pos=0;
}

/*****
* void moveToStart
******
* Toma el puntero actual y lo dirige al principio de la lista, junto con
dejar la posición en cero.
******
* Input:
* ninguno
******
* Returns:
* void
*****/

void listaEnlazada::next(){
    if(curr==tail){
        return;
    }
    curr=curr->sig;
    pos++;
}

/*****
* void next
******
* Va al siguiente elemento de la lista, moviendoel curr una posición.
******
* Input:
* ninguno
******
* Returns:
* void
*****/

elemLista listaEnlazada::getValue(){
    return curr->sig->info;
}

/*****
* elemLista getValue
******
* entrega el valor almacenado en el nodo actual.
******
* Input:
* ninguno
******
* Returns:
* elemLista, elemento del nodo actual.
*****/

int listaEnlazada::insert(unsigned int posicion,elemLista n){
    unsigned int i;
    if(posicion<0||posicion>listSize){
        return -1;
    }
    moveToStart();
    for(i=0;i<posicion;i++){
        next();
    }
    nodo*aux=curr->sig;
    curr->sig=new nodo;
    curr->sig->info=n;
    curr->sig->sig=aux;
    if(curr==tail){
        tail=curr->sig;
    }
    listSize++;
    return pos;
}

/*****
* int insert
******
* Inserta un nodo en la posición entregada por parámetro, junto con el
nucleotido puesto como parámetro en el nodo.
******
* Input:
* unsigned int posicion: posicion a insertar el nuevo nodo.
* elemLista n: el nucleotido n a insertar como información del nuevo nodo.
******
* Returns:
* int, la posicion del objeto tipo listaEnlazada.
*****/

void listaEnlazada::erase(unsigned int posicion){
    unsigned int i;
    curr=head;
    pos=0;
    if(posicion<0||posicion>listSize){
        return;
    } 
    for(i=0;i<posicion;i++){
        next();
    }
    if(curr->sig==tail){
        tail=curr;
    } 
    nodo*aux=curr->sig;
    curr->sig=curr->sig->sig;
    delete[] aux;
    listSize--;
}

/*****
* void erase
******
* Borra el nodo en la posición ingresada como parámetro.
******
* Input:
* unsigned int posicion: posicion del nodo a borrar.
******
* Returns:
* void
*****/

void listaEnlazada::intercambiar(unsigned int posicion, elemLista n){
    if(posicion<0||posicion>listSize){
        return;
    } 
    curr=head;
    pos=0;
    for(unsigned int i=0;i<posicion;i++){
        next();
    }
    curr->sig->info=n;
}

/*****
* void intercambiar
******
* reemplaza el nucleotido del nodo en la posicion ingresada como parámetro
por el ingresado como parámetro (n).
******
* Input:
* unsigned int posicion: posicion del nodo a intercambiar el nucleotido.
* elemLista n: el nucleotido n a intercambiar.
******
* Returns:
* void
*****/

void listaEnlazada::clear(){
    curr=head;
    pos=0;
    nodo* aux;
    for(unsigned int i=0;i<listSize;i++){
        aux = curr->sig;
        curr->sig = curr->sig->sig;
        delete[] aux;
    }
    delete[] head;
    listSize=0;
} 

/*****
* void clear
******
* elimina la lista borrando sus nodos de izquierda a derecha (a excepción
de la cabeza que se borra al final).
******
* Input:
* ninguno
******
* Returns:
* void
*****/

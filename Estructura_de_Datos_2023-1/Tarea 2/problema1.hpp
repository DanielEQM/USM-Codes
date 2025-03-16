#ifndef PROBLEMA1_HPP
#define PROBLEMA1_HPP
#include <iostream>

using namespace std;

typedef char elemLista;

struct nodo{
    elemLista info;
    nodo* sig;
};

class listaEnlazada{
    private:
        nodo* head;
        nodo* tail;
        nodo* curr;
        unsigned int listSize;
        unsigned int pos;
    public:
        listaEnlazada(); 
        ~listaEnlazada(); 
        void clear(); 
        int insert(unsigned int posicion, elemLista n); 
        void erase(unsigned int posicion); 
        void intercambiar(unsigned int posicion, elemLista n); 
        void moveToStart(); 
        void next(); 
        unsigned int length();
        elemLista getValue(); 
};

#endif 
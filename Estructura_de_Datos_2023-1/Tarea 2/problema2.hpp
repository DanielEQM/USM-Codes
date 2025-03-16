#ifndef PROBLEMA2_HPP
#define PROBLEMA2_HPP
#include <iostream>

typedef int tElem;

struct tNodoArbolBin{
    tElem info;
    tNodoArbolBin* izq;
    tNodoArbolBin* der;
};

class tABB{
    private:
        tNodoArbolBin* raiz;
        int nElems;
    public:
        tABB();
        ~tABB();
        void clear();
        bool find(tElem item);
        void insert(tElem item);
        int size();
        int lower_bound(tElem item);
};

#endif
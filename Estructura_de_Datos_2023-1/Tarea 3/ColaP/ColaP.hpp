#ifndef COLAP_HPP
#define COLAP_HPP
#include <iostream>
#include <string>

using namespace std;

struct array{
    int priority;
    string ID;
    string Instruction;
};

class ColaP{
    private:
        array* server;
        int size;
        int create;
    public:
        ColaP();
        ~ColaP();
        void insertColaP(array Pri);
        void GET(int x);
        int sizeColaP();
        int total();
        void imprimir();
};

#endif 
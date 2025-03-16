#ifndef HASHING_HPP
#define HASHING_HPP
#include <iostream>
#include <string>
#define VACIA " "
using namespace std;

typedef string tipoClave;

struct tipoInfo {
    string Password;
};

struct ranura {
    tipoClave User;
    tipoInfo Info;
};

class Login{
    private:
        ranura* HT;
        int size;
        int M;
    public:
        Login();
        ~Login();
        bool iniciar_sesion(string usuario, string clave);
        bool crear_nuevo_usuario(string usuario, string clave);
        bool cambiar_clave(string usuario, string nueva_clave);
};

#endif 
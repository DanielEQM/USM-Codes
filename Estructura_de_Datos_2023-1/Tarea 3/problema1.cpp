#include <iostream>
#include <string>
#include "Hashing/Hashing.hpp"

using namespace std;

int main(){
    string operation = " ", user, password;
    Login Log;
    while(operation != "FINALIZAR"){
        cin >> operation;
        if(operation == "REGISTRAR"){
            cin >> user >> password;
            Log.crear_nuevo_usuario(user, password);
        }
        if(operation == "INICIAR_SESION"){
            cin >> user >> password;
            Log.iniciar_sesion(user, password);
        }
        if(operation == "ACTUALIZAR"){
            cin >> user >> password;
            Log.cambiar_clave(user, password);
        }
    }
    return 0;
}
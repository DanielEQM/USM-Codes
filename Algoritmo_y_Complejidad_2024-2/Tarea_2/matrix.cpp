#include <bits/stdc++.h>
using namespace std;

void base_case(){
    /*
    Crea casos de distintos costos.
    */
    ofstream salida;
    int costo;
    salida.open("dataCost/cost_replace.txt");
    cout << "costo sustituir: "; cin >> costo;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(i == j) salida << 0 << " ";
            else salida << costo << " ";
        }
        salida << "\n";
    }
    salida.close();
    cout << "costo eliminar: "; cin >> costo;
    salida.open("dataCost/cost_delete.txt");
    for(int i = 0; i < 26; i++){
        salida << costo << " ";
    }
    salida.close();
    cout << "costo insertar: "; cin >> costo;
    salida.open("dataCost/cost_insert.txt");
    for(int i = 0; i < 26; i++){
        salida << costo << " ";
    }
    salida.close();
    cout << "costo transponer: "; cin >> costo;
    salida.open("dataCost/cost_transpose.txt");
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(i == j) salida << 0 << " ";
            else salida << costo << " ";
        }
        salida << "\n";
    }
    salida.close();
}

int main(){
    base_case();
    return 0;
}
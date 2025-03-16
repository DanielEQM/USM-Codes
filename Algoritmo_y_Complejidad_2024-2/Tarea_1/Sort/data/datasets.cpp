#include <bits/stdc++.h>
using namespace std;


int main(){
    // Los elementos van de un rango de 0 a 99999

    ofstream salida;
    
    // Ordena inversamente los elementos (de mayor a menor)
    salida.open("data/ordenados_inversamente.txt");
    
    for(int i = 1; i < 8; i++){
        salida << setprecision(0) << fixed << pow(10, i) << "\n";
        vector<int> v(pow(10, i));
        for(int j = 0; j < pow(10, i); j++){
            v[j] = rand() % 100000;
        }
        sort(v.begin(),v.end(), greater<int>());
        for(int j = 0; j < pow(10, i); j++){
            salida << v[j] << " ";
        }
        salida << "\n";
    }
    salida.close();
    
    cout << "Listo primer archivo\n";
    
    // Ordena los datos ascendentemente (de menor a mayor)
    salida.open("data/parcialemente_ordenados.txt");
    
    for(int i = 1; i < 8; i++){
        salida << setprecision(0) << fixed << pow(10, i) << "\n";
        vector<int> v(pow(10, i));
        for(int j = 0; j < pow(10, i); j++){
            v[j] = rand() % 100000;
        }
        sort(v.begin(),v.end());
        for(int j = 0; j < pow(10, i); j++){
            salida << v[j] << " ";
        }
        salida << "\n";
    }
    salida.close();

    cout << "Listo segundo archivo\n";

    // Los datos estan completamente desordenados y aleatoriamente 
    // distribuidos.
    salida.open("data/desordenados1.txt");

    srand(time(0));

    for(int i = 1; i < 8; i++){
        salida << setprecision(0) << fixed << pow(10, i) << "\n";
        for(int j = 0; j < pow(10, i); j++){
            salida << rand() % 100000 << " ";
        }
        salida << "\n";
    }
    salida.close();

    cout << "Listo tercer archivo\n";
    
    return 0;
}
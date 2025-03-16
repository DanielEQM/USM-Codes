#ifndef AUXMATRIX_HPP
#define AUXMATRIX_HPP
#include <bits/stdc++.h>
using namespace std;


void createM(vector<vector<int> > &M, int fila, int columna){
    // Se crea la matriz.

    M.assign(fila, vector<int>(columna));
}


void getM(vector<vector<int> > &M, int fila, int columna){
    // Obtiene la matriz a traves de consola.

    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++){
            cin >> M[i][j];
        }
    }
}


void print(vector<vector<int> > &M, int fila, int columna, string name){
    // Genera un archivo .txt donde estaran las 
    // matrices resultantes de la multiplicación
    // de matrices.

    ofstream salida;
    salida.open(name, fstream::app);
    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++){
            salida << M[i][j] << " ";
        }
        salida << "\n";
    }
    salida << "----------------\n";
    salida.close();
}

#endif
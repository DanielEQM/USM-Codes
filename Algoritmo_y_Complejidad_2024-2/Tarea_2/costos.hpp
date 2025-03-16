#ifndef COSTOS_HPP
#define COSTOS_HPP
#include "funtion.hpp"

int costo_sub(char a, char b){
    //retorna costo de sustituir a por b.
    int costo;
    int x = a - 'a';
    int y = b - 'a';
    costo = cost_replace[x][y];
    return costo;
}

int costo_ins(char b){
    //retorna costo de insertar b.
    int costo;
    int x = b - 'a';
    costo = cost_insert[x];
    return costo;
}

int costo_del(char a){
    //retorna costo de eliminar a.
    int costo;
    int x = a - 'a';
    costo = cost_delete[x];
    return costo;
}

int costo_trans(char a, char b){
    //retorna costo de transponer a por b.
    int costo;
    int x = a - 'a';
    int y = b - 'a';
    costo = cost_transpose[x][y];
    return costo;
}

void initMatrix(vector <vector <int> > &matrix, string s1, string s2){
    //inicia matriz a rellenar con valores iniciales.
    for(int i = 1; i < matrix.size(); i++){
        matrix[i][0] = matrix[i-1][0] + costo_del(s1[i-1]);
    }
    for(int i = 1; i < matrix[0].size(); i++){
        matrix[0][i] = matrix[0][i-1] + costo_ins(s2[i-1]);
    }
}

void printMatrix(vector <vector <int> > matrix){
    //printea matriz para mostrar por pantalla
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

#endif
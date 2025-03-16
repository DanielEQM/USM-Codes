#include <bits/stdc++.h>
#include "auxMatrix.hpp"
using namespace std;


void multiply(vector<vector<int> > &M1, vector<vector<int> > &M2, vector<vector<int> > &R, int size1, int equal, int size2){
	/***********************************************
     * Parametros:
     * vector<vector<int> > &M1: Primera matriz la cual se va a multiplicar.
     * vector<vector<int> > &M2: Segunda matriz la cual se va a multiplicar.
     * vector<vector<int> > &R : Matriz donde estará el resultado de M1 x M2.
     * int size: tamaño de la matriz. 
     * *********************************************
     * Descripción:
     * Recorre los elementos de la fila de la matriz M1 y los multiplica por
     * las columnas de la matriz M2, el resultado de esto se guarda en la 
     * Matriz R.
    ***********************************************/
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            R[i][j] = 0;
            for(int k = 0; k < equal; k++){
                R[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}



int main(){

    int t, t1, t2;
    while(cin >> t){
        cin >> t1 >> t2;

        vector<vector<int> > M_1;
        vector<vector<int> > M_2;
        vector<vector<int> > M_R;
        createM(M_1, t, t1); createM(M_2, t1, t2); createM(M_R, t, t2);
        getM(M_1, t, t1); getM(M_2, t1, t2);

        auto start = chrono::high_resolution_clock::now();

        multiply(M_1, M_2, M_R, t, t1, t2);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << "Tiempo en segundos de (" << t << "x" << t1 << " * " << t1 << "x" << t2 << "): " << fixed << setprecision(5) << duration.count() << "\n";

        print(M_R, t, t2, "MulMatriz.txt");
    }
    return 0;
}
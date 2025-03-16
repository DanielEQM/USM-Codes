#include <bits/stdc++.h>
using namespace std;


void squareMatrix(){
    // genera matrices cuadradas de 2^4 hasta 2^11

    ofstream salida;
    salida.open("data/Matrices.txt");
    srand(time(0));

    for(int i = 4; i < 12; i++){

        int x = pow(2, i);

        salida << x << " " << x << " " << x << "\n";

        for(int k = 0; k < 2; k++){    
            for(int j = 0; j < x; j++){
                for(int z = 0; z < x; z++){
                    salida << rand() % 10 << " ";
                }
                salida << "\n";
            }
        }
    }
    salida.close();
}


void randomMatrix(){
    // Genera matrices de distintos tamaños que al momento
    // de ser obtenidos puedan ser multiplicables.

    ofstream salida;
    salida.open("data/MatricesR1.txt");
    srand(time(0));

    for(int i = 5; i < 5000; i *= 3){

        int size1 = rand() % i + 1,
            equal = rand() % i + 1,
            size2 = rand() % i + 1;

        salida << size1 << " " << equal << " " << size2 << "\n";

        for(int j = 0; j < size1; j++){
            for(int k = 0; k < equal; k++){
                salida << rand() % 10 << " ";
            }
            salida << "\n";
        }

        for(int j = 0; j < equal; j++){
            for(int k = 0; k < size2; k++){
                salida << rand() % 10 << " ";
            }
            salida << "\n";
        }
    } 
    salida.close();
}


int main(){
    
    //squareMatrix();
    randomMatrix();

    return 0;
}
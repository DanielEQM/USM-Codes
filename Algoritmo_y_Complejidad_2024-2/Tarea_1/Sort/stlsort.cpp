#include <bits/stdc++.h>
using namespace std;

void printArray(int A[], int const size){
	/***********************************************
     * Parametros:
     * int A[]: arreglo a imprimir.
     * int size: tamaño del arreglo. 
     * *********************************************
     * Descripción:
     * Crea un archivo donde estan los datos ordenados
    ***********************************************/
    ofstream salida;
    salida.open("stlsort.txt", fstream::app);
    salida << size << "\n";
	for (int i = 0; i < size; i++)
		salida << A[i] << " ";
	salida <<"\n-----------------\n";
    salida.close();
}


int main(){
    
	int n;
    while(cin >> n){
		int* arr = new int[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

		auto start = chrono::high_resolution_clock::now();

        sort(arr, arr + n);

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;

		cout << "Tiempo en segundos de "<< n << " elementos: " << fixed << setprecision(5) << duration.count() << "\n";

        printArray(arr, n);
		delete[] arr;
    }
    return 0;
}
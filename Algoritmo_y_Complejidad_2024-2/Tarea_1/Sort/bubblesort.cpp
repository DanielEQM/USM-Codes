#include <bits/stdc++.h>
using namespace std;
// El codigo esta sacado de la pagina de "geeks for geeks". 
// https://www.geeksforgeeks.org/bubble-sort-in-cpp/


void bubbleSort(int arr[], int n){
    /***********************************************
     * Parametros:
     * int arr[]: arreglo a ordenar.
     * int n: tamaño del arreglo. 
     * *********************************************
     * Descripción:
     * Revisa el elemento en el que se encuentra con
     * el siguiente elemento del arreglo y los compara
     * si es que es más pequeño que su sucesor, estos
     * se intercambian. Y esto lo repite por la cantidad
     * de elementos - 1 que tiene.
    ***********************************************/
    int i, j; 

    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]); 
} 


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
    salida.open("bubblesort.txt", fstream::app);
    salida << size << "\n";
	for (int i = 0; i < size; i++)
		salida << A[i] << " ";
	salida <<"\n-----------------\n";
    salida.close();
}

int main(){
    
	int n;
    while(cin >> n){
        // Despues de 10^6 datos se tarda mucho la ejecución por
        // lo que no se prueba.
        if(n == 10000000){
            break;
        }
        
		int* arr = new int[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

		auto start = chrono::high_resolution_clock::now();

        bubbleSort(arr, n);

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;

		cout << "Tiempo en segundos de "<< n << " elementos: " << fixed << setprecision(5) << duration.count() << "\n";

        printArray(arr, n);
		delete[] arr;
    }
    return 0;
}
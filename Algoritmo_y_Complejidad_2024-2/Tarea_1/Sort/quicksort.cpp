#include <bits/stdc++.h>
using namespace std;
// Este codigo esta sacado de la pagina Techie Delight y modificado para que sea más legible.
// https://www.techiedelight.com/es/quicksort/


int partition(int a[], int start, int end){
    /***********************************************
     * Parametros:
     * int a[]: arreglo a ordenar.
     * int start: Es la posición del elemento donde se comienza a ordenar.
     * int end: Es la posición del ultimo elemento donde se quiere ordenar.
     * *********************************************
     * Descripción:
     * Ordena el arreglo según el pivote, separando los elementos a la izquierda
     * menores al pivote y a la derecha mayores al pivote. finalizado el pivote se
     * posiciona donde separe los elementos y retorna dicha posición.
    ***********************************************/
   
    int pivot = a[end];
    int pIndex = start;
 
    // cada vez que encontramos un elemento menor o igual que el pivote, `pIndex`
    // se incrementa, y ese elemento se colocaría antes del pivote.
    for (int i = start; i < end; i++){
        if (a[i] <= pivot) {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    // intercambiar `pIndex` con pivote
    swap (a[pIndex], a[end]);
 
    // devuelve `pIndex` (índice del elemento pivote)
    return pIndex;
}


void quicksort(int a[], int start, int end){
    /***********************************************
     * Parametros:
     * int a[]: arreglo a ordenar.
     * int start: Es la posición del elemento donde se comienza a ordenar.
     * int end: Es la posición del ultimo elemento donde se quiere ordenar.
     * *********************************************
     * Descripción:
     * recorre recursivamente el arreglo. cuando este se ordena según el
     * pivote, se vuelve a evaluar pero esta vez siendo el ultimo elemento el pivote
     * y cuando termina ese proceso, el pivote + 1 pasa a ser la posición del primer
     * elemento a ordenar.
    ***********************************************/
    
    if (start >= end) {
        return;
    }
 
    // reorganizar los elementos a través del pivote
    int pivot = partition(a, start, end);
 
    // recurre en un subarray que contiene elementos que son menores que el pivote
    quicksort(a, start, pivot - 1);
 
    // se repite en el subarray que contiene elementos que son más que el pivote
    quicksort(a, pivot + 1, end);
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
    salida.open("quicksort.txt", fstream::app);
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

        quicksort(arr, 0, n - 1);

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;

		cout << "Tiempo en segundos de "<< n << " elementos: " << fixed << setprecision(5) << duration.count() << "\n";

        printArray(arr, n);
		delete[] arr;
    }
    return 0;
}
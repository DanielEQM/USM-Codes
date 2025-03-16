#include <bits/stdc++.h>
using namespace std;
// El codigo esta sacado de la pagina de "geeks for geeks" y modificado para que sea más legible. 
// https://www.geeksforgeeks.org/cpp-program-for-merge-sort/


void merge(int array[], int const left, int const mid, int const right){
    /***********************************************
     * Parametros:
     * int array[]: Es el arreglo que se quiere ordenar.
     * int cont left: Es la posición más a la izquierda de la cual se quiere partir a ordenar. 
     * int cont mid: Es la posición que esta entre la posición izquierda y la derecha que se quieren ordenar.
     * int cont right: Es la posición más a la izquierda de la cual se quiere terminar de ordenar.
     * *********************************************
     * Descripción:
     * Se crean dos arreglos (leftArray y rightArray) que tendrán los datos desde la posición izquierda (left) hasta
     * la posición central (mid) y de la posición central a la derecha (right) respectivamente.
     * Este algoritmo compara los elementos de ambos arreglos temporales y los ordena en el arreglo principal y los ordena 
     * hasta que revisa por completo alguno de los dos arreglos. Luego si quedan elementos en alguno de los arreglos, 
     * se agregan al final de la partición de arreglo principal que se analiza.
    ***********************************************/
	int const leftSize = mid - left + 1,
              rightSize = right - mid;

	int *leftArray = new int[leftSize],
		*rightArray = new int[rightSize];

	for (int i = 0; i < leftSize; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < rightSize; j++)
		rightArray[j] = array[mid + 1 + j];

	int indexLeftArray = 0, 
		indexRightArray = 0,
        indexArray = left; 

	// Compara los elementos de ambos arreglos temporales y los agrega en orden al arreglo principal.
	while (indexLeftArray < leftSize && indexRightArray < rightSize) {
		if (leftArray[indexLeftArray] <= rightArray[indexRightArray]) {
			array[indexArray] = 
			leftArray[indexLeftArray];
			indexLeftArray++;
		}
		else {
			array[indexArray] = 
			rightArray[indexRightArray];
			indexRightArray++;
		}
		indexArray++;
	}
	
	// Si quedan elementos en el arreglo izquierdo se agregan al final de la partición de arreglo principal.
	while (indexLeftArray < leftSize){
		array[indexArray] = 
		leftArray[indexLeftArray];
		indexLeftArray++;
		indexArray++;
	}

	// Si quedan elementos en el arreglo derecho se agregan al final de la partición de arreglo principal.
	while (indexRightArray < rightSize){
		array[indexArray] = 
		rightArray[indexRightArray];
		indexRightArray++;
		indexArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}


void mergeSort(int array[], int const begin, int const end){
	/***********************************************
     * Parametros:
     * int array[]: Es el arreglo que se quiere ordenar.
     * int cont begin: Es la posición donde comienza la partición del arreglo. 
     * int cont end: Es la posición donde termina la partición del arreglo.
     * *********************************************
     * Descripción:
     * Particiona el arreglo en dos recurrsivamente hasta que solo tenga un elemento.
     * Cuando tenga las dos particiones listas, las manda a la función marge para ordenarlo.
    ***********************************************/
	if (begin >= end)
		return; 

	int const mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
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
    salida.open("mergesort.txt", fstream::app);
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

        mergeSort(arr, 0, n - 1);

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;

		cout << "Tiempo en segundos de "<< n << " elementos: " << fixed << setprecision(5) << duration.count() << "\n";

        printArray(arr, n);

		delete[] arr;
    }
    return 0;
}
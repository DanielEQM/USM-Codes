#include "problema2.hpp"

using namespace std;

tABB::tABB(){
    raiz = NULL;
    nElems = 0;
}

/*****
* constructor tABB
******
* se encarga de crear un arbol
******
* Input:
* ninguno
* .......
******
* Returns:
* nada
*****/

tABB::~tABB(){
    clear();
}

/*****
* destructor tABB
******
* Llama a la a la funcion clear() tan pronto como sea llamada esta funcion.
******
* Input:
* ninguno
* .......
******
* Returns:
* nada
*****/

void clearHelp(tNodoArbolBin *nodo){
    if (nodo == NULL){
        return;
    }
    clearHelp(nodo->izq);
    clearHelp(nodo->der);
    delete[] nodo;
}

/*****
* void clearHelp
******
* se encarga de ir eliminando todos los nodos existentes dentro del arbol
******
* Input:
* tNodoArbolBin *nodo: unn puntero a los nodos del arbol binario
* .......
******
* Returns:
* void
*****/

void tABB::clear(){
    clearHelp(raiz);
    raiz = NULL;
    nElems = 0;
}

/*****
* void clear
******
* llama a la funcion clearHelp y luego le asgina el valor NULL a la raiz del ABB, aparte 
le asigna el valor 0 a la cantidad de elementos del arbol
******
* Input:
* ninguno
* .......
******
* Returns:
* void
*****/

bool findHelp(tNodoArbolBin *nodo, tElem item){
    if(nodo == NULL){
        return 0;
    }
    if(nodo->info == item){
        return 1;
    }
    if(item<nodo->info){
        return findHelp(nodo->izq, item);
    } else{
        return findHelp(nodo->der, item);
    }
}

/*****
* bool findHelp
******
* se encarga de buscar a traves de todo el arbol el valor item que se le mando.
******
* Input:
* tNodoArbolBin *nodo: puntero que apunta al nodo del arbol binario
  tElem item: es el item que se tiene que encontrar dentro del arbol binario
* .......
******
* Returns:
* bool, 0 es de que no encontro el item y 1 es que lo encontro.
*****/

bool tABB::find(tElem item){
    return findHelp(raiz, item);
}

/*****
* bool find
******
* llama a la funcion findHelp para asi retornar el booleano que devuelva esta funcion
******
* Input:
* tElem item: es el item que queremos encontrar
* .......
******
* Returns:
* bool, retorna 0 si no encontro el numero y retorna 1 si es que si lo encontro.
*****/

tNodoArbolBin* helpInsert(tNodoArbolBin *nodo, tElem item){
    if(nodo == NULL){
        nodo = new tNodoArbolBin;
        nodo->der = NULL;
        nodo->izq = NULL;
        nodo->info = item;
        return nodo;
    } else {
        if(item < nodo->info){
            nodo->izq = helpInsert(nodo->izq, item);
        } else if (item > nodo->info){
            nodo->der = helpInsert(nodo->der, item);
        }
    }
    return nodo;
}

/*****
* tNodoArbolBin* helpInsert
******
* se encarga de insertar el item solicitado en el arbol.
******
* Input:
* tNodoArbolBin *nodo: puntero que apunta a la raiz del arbol.
  tElem item: es el item que queremos insertar en el arbol.
* .......
******
* Returns:
* tNodoArbolBin*, retorna el nodo con los datos insertados.
*****/

void tABB::insert(tElem item){
    if(find(item) == 1){
        return;
    } else {
        raiz = helpInsert(raiz, item);
        nElems++;
    }
}

/*****
* void insert
******
* primero se encarga de ver si es que el item esta en el arbol y si es que esta entonces llama a la funcion 
 helpInsert para que esta ultima inserte el item.
******
* Input:
* tElem item: es el item que queremos insertar en el arbol
* .......
******
* Returns:
* void
*****/

int tABB::size(){
    return nElems;
}

/*****
* int size
******
* se encarga de de retornar la cantidad de elementos que hay en el arbol
******
* Input:
* ninguno
* .......
******
* Returns:
* int, retorna el numero de elementos que hay en el arbol.
*****/

void lower_Help(tNodoArbolBin *nodo, tElem item, int &x){
    if(nodo == NULL){
        return;
    }
    lower_Help(nodo->izq, item, x);
    if(nodo->info <= item){
        x = nodo->info;
    }
    lower_Help(nodo->der, item, x);
}

/*****
* void lower_Help
******
* se encarga de encontrar el primer numero que sea menor a x y que sea lo mas cercano posible a este
******
* Input:
* tNodoArbolBin*: crea un puntero hacia el nodo del arbol
  tElem item: es el numero al cual se le van a buscar numeros menores y cercanos a el
  int &x: la direccion de memoria de x
* .......
******
* Returns:
* void
*****/

int tABB::lower_bound(tElem item){
    int x = 0;
    lower_Help(raiz, item, x);
    return x;
}

/*****
* int lower_bound
******
* llama a la funcion lower_Help y le manda un integer x para que la funcion busque los numeros menores
 o igual a x
******
* Input:
* tElem item: es el numero al cual se le van a buscar numeros menores y cercanos a el
  int &x: la direccion de memoria de x
* .......
******
* Returns:
* int, retorna el numero que es igual o el más cercano al item.
*****/
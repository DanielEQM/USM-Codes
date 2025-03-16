#include <iostream>
#include <fstream>
#include <string>
#include "problema1.hpp"

using namespace std;

int main(){
    ifstream entrada;
    ofstream salida;
    int l,k,m,pos;
    elemLista n;
    string nucleotido,orden;
    salida.open("secuencias-reconstruidas.txt");
    entrada.open("secuencias-nucleotidos.txt");
    if (!entrada.is_open()) {
        cerr << "No se pudo abrir el archivo " << endl;
        return 1; 
    }
    entrada >> l;
    entrada >> nucleotido;
    entrada >> k;
    for(int j=0;j<k;j++){
        entrada >> m;
        listaEnlazada secnucl;
        for(int i=0;i<l;i++){ 
            secnucl.insert(i,nucleotido[i]);
        }
        for(int z=0;z<m;z++){
            entrada >> orden;
            if(orden=="INSERTAR"){
                entrada >> pos;
                entrada >> n;
                secnucl.insert(pos,n);
            }
            else if(orden=="BORRAR"){
                entrada >> pos;
                secnucl.erase(pos);
            }
            else if (orden=="INTERCAMBIAR"){
                entrada >> pos;
                entrada >> n;
                secnucl.intercambiar(pos,n);
            }
        }
        secnucl.moveToStart();
        int valor=secnucl.length();
        for(int i=0;i<valor;i++){
            char x = secnucl.getValue();
            salida << x;
            secnucl.next();
        }
        salida << "\n";
    }
    entrada.close();
    salida.close();
    return 0;
}
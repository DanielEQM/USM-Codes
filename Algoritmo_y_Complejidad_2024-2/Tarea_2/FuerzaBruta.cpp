#include "costos.hpp"

int costo = INT_MAX;

void fuerzaBruta(string s1, string s2, int valor){
    /*
    * Nombre: fuerzaBruta.
    * Parametros:
    *   * string s1: string a modificar.
    *   * string s2: string objetivo.
    *   * int valor: costo acumulado.
    * Descripción:
    *   Recorre recursivamente las palabras operación por operación hasta
    *   encontrar algún string vacio para ver el minimo.
    */
    if(s1.size() == 0){
        for(int i = 0; i < s2.size(); i++){
            valor += costo_ins(s2[i]);
        }
        costo = min(costo, valor);
    } else if(s2.size() == 0){
        for(int i = 0; i < s1.size(); i++){
            valor += costo_del(s1[i]);
        }
        costo = min(costo, valor);
    } else {
        fuerzaBruta(s1.substr(1), s2.substr(1), valor + costo_sub(s1[0], s2[0]));
        fuerzaBruta(s1, s2.substr(1), valor + costo_ins(s2[0]));
        fuerzaBruta(s1.substr(1), s2, valor + costo_del(s1[0]));
        
        if(s1.size() > 1 && s2.size() > 1){
            if(s1[1] == s2[0] && s1[0] == s2[1]){
                swap(s1[0], s1[1]);
                fuerzaBruta(s1.substr(2), s2.substr(2), valor + costo_trans(s1[1], s1[0]));
                swap(s1[0], s1[1]);
            }
        }
    }
}


int main(){
    Insert(); Delete(); Transpose(); Replace();
    string s[2];
    ifstream input;
    string caso;
    cout << "Numero del archivo input (1 al 10): "; cin >> caso;
    input.open("datasets/input"+caso+".txt");
    int cont = 0;
    while (getline(input, caso)){
        s[cont++] = caso;
    }
    input.close();
    cout << s[0] << " - " << s[1] +"\n";
    auto start = chrono::high_resolution_clock::now();
    fuerzaBruta(s[0], s[1], 0);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
	cout << "Tiempo en segundos de Distancia de Edición minima entre "+s[0]+" a "+s[1]+": " << fixed << setprecision(5) << duration.count() << "\n";
    cout << "Distancia minima es: " << costo << "\n";
    return 0;
}
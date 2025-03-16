#include "costos.hpp"

int edit_distance(string s1, string s2){
    /*
    * Nombre: edit_distance
    * Parametros:
    *   * string s1: string a modificar.
    *   * string s2: string objetivo.
    * Descripción:
    *   Una vez identificados los subproblemas, se crea una tabla
    *   donde se rellena con los valores minimos de ir comparando
    *   casilla por casilla, dando el optimo en la ultima de estas.
    */
    if(s1 == s2) return 0;
    else {
        vector <vector <int> > matrix(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        initMatrix(matrix, s1, s2);
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                int del = matrix[i-1][j] + costo_del(s1[i-1]),
                    sub = matrix[i-1][j-1] + costo_sub(s1[i-1], s2[j-1]),
                    ins = matrix[i][j-1] + costo_ins(s2[j-1]);

                matrix[i][j] = min(del, min(sub, ins));
                if(i > 1 && j > 1 && s1[i-1] == s2[j-2] && s1[i-2] == s2[j-1]){
                    matrix[i][j] = min(matrix[i][j], matrix[i-2][j-2] + costo_trans(s1[i-1], s1[i-2]));
                }
            }
        }
        
        //cout << "    ";
        //for(char s: s2) cout << s << " ";
        //cout << "\n";
        //for(int i = 0; i < matrix.size(); i++){
        //    if(i) cout << s1[i-1] << " "; else cout << "  ";
        //    for(int j = 0; j < matrix[0].size(); j++){
        //        cout << matrix[i][j] << " ";
        //    }
        //    cout << "\n";
        //}
        return matrix[matrix.size()-1][matrix[0].size()-1];
    }
}

int main(){
    Replace(); Insert(); Delete(); Transpose();
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
    int costo = edit_distance(s[0], s[1]);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
	cout << "Tiempo en segundos de Distancia de Edición minima entre "+s[0]+" a "+s[1]+": " << fixed << setprecision(5) << duration.count() << "\n";
    cout << "\nDistancia de Edición minima: " << costo << "\n";
    return 0;
}
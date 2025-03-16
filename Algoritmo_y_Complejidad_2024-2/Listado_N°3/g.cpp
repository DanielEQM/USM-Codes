#include <bits/stdc++.h>
using namespace std;

int cont;
bool f;
vector <string> colores;
vector <string> primero;
vector <string> aux;
vector <vector <string> > restr;

bool comprobar(int pos){
    for(int i = 0; i < restr.size(); i++){
        if(primero[pos] == restr[i][0]){
            if(primero[pos - 1] == restr[i][1]){
                return 0;
            }
        }
        if(primero[pos] == restr[i][1]){
            if(primero[pos - 1] == restr[i][0]){
                return 0;
            }
        }
    }
    return 1;
}


void perm(vector <int> v){
    if(primero.size() == colores.size()){
        if(comprobar(primero.size()-1)){
            if(f){
                aux = primero;
                f = 0;
            }
            cont++;
        }
    } else {
        for(int i = 0; i < colores.size(); i++){
            if(v[i] == 0){
                primero.push_back(colores[i]);
                if(primero.size() == 1){
                    v[i] = 1;
                    perm(v);
                    v[i] = 0;
                } else if (comprobar(primero.size()-1)){  
                    v[i] = 1;
                    perm(v);
                    v[i] = 0;
                }
                primero.pop_back();
            }
        }
    }
}


int main(){
    int n, m;
    string s, s1;
    vector <int> v;
    cin >> n;
    while(n--){
        cin >> m;

        v.clear();
        colores.clear();
        restr.clear();
        v.assign(m,0);
        cont = 0;
        f = 1;

        for(int i = 0; i < m; i++){
            cin >> s;
            colores.push_back(s);
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> s >> s1;
            restr.push_back({s, s1});
        }
        perm(v);
        cout << cont << "\n";
        for(int i = 0; i < aux.size(); i++){
            cout << aux[i] << " "; 
        }
        cout << "\n";
        /*
        for(int i = 0; i < restr.size(); i++){
            cout << restr[i][0] << " " << restr[i][1] << "\n";
        }
        */
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string c;

string veci(string x, string r, vector <int> b, int cont){
    if(cont == x.length() + 1){
        return r;
    } else{
        string aux = r, res = "";
        for(int i = 0; i < x.length(); i++){
            if(b[i] != 1){
                r += x[i];
                if(c.substr(0, cont) <= r.substr(0, cont)){
                    b[i] = 1;
                    res = veci(x, r, b, cont + 1);
                    if(res != c && res.length() == x.length()){
                        return res;
                    }
                    b[i] = 0;
                }
                r = aux;
            }
        }
    }
    return "0";
}

int main(){
    string x, resp = "";
    cin >> x;
    vector<int> si(x.length(), 0);
    c = x;
    sort(x.begin(), x.end());
    cout << veci(x, "", si, 1); 
    return 0;
}
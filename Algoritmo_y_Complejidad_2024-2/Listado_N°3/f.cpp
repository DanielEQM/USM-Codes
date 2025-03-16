#include <bits/stdc++.h>
using namespace std;

string decode(string z){
    string aux = "", neww = "";
    for(int i = 0; i < 8; i++){
        if(aux == "" && z[i] == '1'){
            neww += z[i];
            aux = neww[i];
        } else if(z[i] == '1'){
            if(aux == "1"){
                neww += '0';
            } else{
                neww += '1';
            }
            aux = neww[i];
        } else {
            if(aux == "1"){
                neww += '1';
            } else{
                neww += '0';
            }
            aux = neww[i];
        }
    }
    return neww;
}

string convert(int x){
    string z = "";
    while(x != 0){
        z += to_string(x % 2);
        x /= 2;
    }
    for(int i = z.length(); i < 8; i++){
        z += '0';
    }
    return z;
}

int main(){
    int n, b;
    cin >> n;
    while(n--){
        cin >> b;
        string z = decode(convert(b));
        int j = 0;
        for(int i = 0; i < 8; i++){
            if(z[i] == '1') j += pow(2, i);
        }
        cout << j << " ";
        j = 0;
    }
}
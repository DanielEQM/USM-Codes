#include <bits/stdc++.h>
using namespace std;

string a[4] = {"ABCD","EFGH","IJKL","MNO."};

int here(char x, int i, int j){
    for(int k = 0; k < 4; k++){
        for(int z = 0; z < 4; z++){
            if(a[k][z] == x){
                return abs(i-k) + abs(j-z);
            }
        }
    }
    return 0;
}

int main(){
    string  x;
    int z = 0;
    for(int i = 0; i < 4; i++){
        cin >> x;
        for(int j = 0; j < 4; j++){
            if(x[j] != '.'){
                if(x[j] != a[i][j]){
                    z += here(x[j], i, j);
                }
            }
        }
    }
    cout << z;
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main(){
    int t, n, x = 0, total = 0, cont = 0;
    string m;
    cin >> t >> n;
    int pila[n];
    while (cont < n){
        cin >> m;
        if(m == "undo"){
            cin >> m;
            x -= stoi(m);
        } else {
            pila[x] = stoi(m);
            x++;
        }
        cont++;
    }
    n = x;
    for(x = 0; x < n; x++){
        total += pila[x];
    }
    total %= t;
    if (total < 0){
        total = t + total; 
    }
    cout << total;
    return 0;
}
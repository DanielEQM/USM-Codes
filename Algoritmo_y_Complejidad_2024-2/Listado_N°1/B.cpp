#include <iostream>
using namespace std;

int main(){
    int n, i = 0, a = 0, v = 0, j = 0, l = 0;
    cin >> n;
    int h[n];
    while(cin >> h[i++]);
    v = h[0];
    for(i = 0;i < n;i++){
        if(v <= h[i]){
            if(a != 0 && j < a){
                j = a;
            }
            v = h[i];
        } else {
            if((v - h[i]) > a){
                a = v - h[i];
            }
        }
    }
    v = h[n-1];
    a = 0;
    for(i = n-1; 0 <= i; i--){
        if(v <= h[i]){
            if(a != 0 && l < a){
                l = a;
            }
            v = h[i];
        } else {
            if((v - h[i]) > a){
                a = v - h[i];
            }
        }
    }
    if(l > j){
        j = l;
    }
    cout << j;
    return 0;
}
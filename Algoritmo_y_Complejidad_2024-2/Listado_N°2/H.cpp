#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> v1, int low, int high, int elem){
    if (high >= low) {
        int c = low + (high - low) / 2;
        if(v1[c] == elem){
            return c;
        } else if (v1[c] < elem){
            return binary_search(v1, c+1, high, elem);
        } else {
            return binary_search(v1, low, c-1, elem);
        }
    }
    return -1;
}


int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector<int> l1(n), l2(n), r(n);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            l1[i] = x;
            r[i] = x;
        }
        for(int i = 0; i < n; i++){
            cin >> l2[i];
        }
        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());
        for(int i = 0; i < n; i++){
            int pos = binary_search(l1, 0, n-1, r[i]);
            cout << l2[pos] << "\n";
        }
        cout << "\n";
    }
    return 0;
}
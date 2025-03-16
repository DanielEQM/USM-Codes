#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll c, l, n;
    cin >> c;
    while(c--){
        cin >> l >> n;
        ll arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        auto p = lower_bound(arr, arr + n, l/2);
        if(l - arr[p - arr] > arr[p - arr - 1]){
            cout << l - arr[p - arr] << " ";
        } else {
            cout << arr[p - arr - 1] << " ";
        }
        if(arr[n-1] < l - arr[0]){
            cout << l - arr[0] << "\n";
        } else {
            cout << arr[n-1] << "\n";
        }
    }
    return 0;
}
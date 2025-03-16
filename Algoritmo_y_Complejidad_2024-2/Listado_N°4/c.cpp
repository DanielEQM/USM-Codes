#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll l, n, b, total = 0;
    cin >> l >> n >> b;
    vector <ll> arr;
    while(b--){
        ll x; cin >> x;
        arr.push_back(x);
    }
    if(arr.size() == 0){
        for(ll i = 6; i <= l - 6; i += n){
            total += 1;
        }
    } else {
        sort(arr.begin(), arr.end());
        for(ll i = 6; i < arr[0] - n; i += n){
            total += 1;
        }
        for(ll i = 0; i < arr.size() - 1; i++){
            for(ll j = arr[i] + n; j <= arr[i+1] - n; j += n){
                total += 1;
            }
        }
        for(ll i = arr[arr.size() - 1] + n; i <= l-6; i += n){
            total += 1;
        }
    }
    cout << total;
    return 0;
}
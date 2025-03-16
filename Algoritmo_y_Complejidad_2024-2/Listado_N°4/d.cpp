#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n, cont = 0;
    cin >> n;
    vector<ll> p(n);
    for(ll i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p.rbegin(), p.rend());
    for(ll i = 2; i < n; i += 3){
        cont += p[i];
    }
    cout << cont;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        b[i] += a[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0, pos = 0;
    for(int i = 0; i < n; i++){
        
        if(pos == n) break;
        while(b[pos] + m < a[i]) pos++;
        if(b[pos] <= a[i] && a[i] <= b[pos] + m){
            ans++; pos++;
        }
    }
    cout << ans;
    return 0;
}
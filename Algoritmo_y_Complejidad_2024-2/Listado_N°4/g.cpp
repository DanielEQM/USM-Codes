#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k, cont = 0;
    cin >> n >> m >> k;
    vector<int> plot(n);
    vector<int> Bplot(n, 0);
    vector<int> Chouse(m);
    vector<int> Shouse(k);
    for(int i = 0; i < n; i++) cin >> plot[i];
    for(int i = 0; i < m; i++) cin >> Chouse[i];
    for(int i = 0; i < k; i++) cin >> Shouse[i];
    sort(plot.begin(), plot.end());
    sort(Chouse.begin(), Chouse.end());
    sort(Shouse.begin(), Shouse.end());
    int s = 0;
    for(int i = 0; i < n; i++){
        if(!Bplot[i]){
            if(Chouse[s] < plot[i]){
                Bplot[i] = 1;
                cont++;
                s++;
            }
        }
        if(s == m) break;
    }
    s = 0;
    for(int i = 0; i < n; i++){
        if(!Bplot[i]){
            float hip = sqrt(2) * plot[i] ;
            if(Shouse[s] < hip){
                Bplot[i] = 1;
                cont++;
                s++;
            }
        }
        if(s == k) break;
    }
    cout << cont;
}
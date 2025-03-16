#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        vector<string> v(n);
        vector<string> r;
        for(int i = 0; i < n; i++) {cin >> v[i];}
        r.push_back(v[0]);

        for(int i = 1; i < n; i++){
            bool x = 1;
            for(int j = 0; j < r.size(); j++){
                if(v[i][0] < r[j][0]){
                    x = 0; 
                    r.insert(r.begin() + j, v[i]);
                    break;
                } else if (v[i][0] == r[j][0]){
                    if(v[i][1] < r[j][1]){
                        x = 0;
                        r.insert(r.begin() + j, v[i]);
                        break;
                    }
                }
            }
            if (x != 0){
                r.push_back(v[i]);
            }
        }

        for(int i = 0; i < r.size(); i++){
            cout << r[i] << "\n"; 
        }
        cout << "\n";
    }
    return 0;
}
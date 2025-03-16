#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin >> n;
    while(n--){
        cin >> k;
        int t = 0;
        vector<int> v(20,0), r;
        for(int i = 0; i < 20; i++) cin >> v[i];
        r.push_back(v[0]);

        for(int i = 1; i < 20; i++){
            bool x = 1;
            for(int j = 0; j < r.size(); j++){
                if(v[i] < r[j]){
                    x = 0;
                    t += r.size() - j; 
                    r.insert(r.begin() + j, v[i]);
                    break;
                }
            }
            if (x != 0){
                r.push_back(v[i]);
            }
        }
        cout << k << " " << t << "\n";
    }
    return 0;
}
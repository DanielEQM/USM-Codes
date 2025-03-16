#include <bits/stdc++.h>
using namespace std;

void split(vector<vector<string> > &v1, string s, int i){
    string m = "";
    for(char x: s){
        if(x == '-'){
            v1[i].push_back(m);
            m = "";
        } else {
            m += x;
        }
    }
    v1[i].push_back(m);

}

bool comparar(vector<vector<string> > &v1, int i, int j){
    int len;
    if(v1[i].size() < v1[j].size()){
        len = v1[i].size() - 1;
    } else {
        len = v1[j].size() - 1;
    }
    for(int k = 0; k < len; k++){
        if(v1[i][k] > v1[j][k]){
            return 0;
        } else if (v1[i][k] < v1[j][k]) {
            return 1;
        }
    }
    if(v1[i][v1[i].size()-1] < v1[j][v1[j].size()-1]){
        return 0;
    }
    return 1;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<vector<string> > c(n);
        string s, name;
        for(int i = 0; i < n; i++){
            cin >> name;
            cin >> s;
            split(c, s, i);
            cin >> s;
            reverse(c[i].begin(), c[i].end());
            for(int j = c[i].size(); j < 10; j++){
                c[i].push_back("middle");
            }
            c[i].push_back(name.erase(name.size()-1));
        }

        for(int i = 0; i < n - 1; i++){
            bool x = 0;
            for(int j = 0; j < n - i - 1; j++){
                if(comparar(c, j, j+1) != 0){
                    swap(c[j], c[j+1]);
                    x = 1;
                }
            }
            if(!x){
                break;
            }
        }
        for(int i = 0; i < n; i++){
            cout << c[i][c[i].size()-1] << "\n";
        }
        c.clear();
        cout << "==============================\n";
    }
    return 0;
}
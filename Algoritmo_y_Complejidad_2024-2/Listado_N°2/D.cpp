#include <bits/stdc++.h>
using namespace std;

void split(vector<string> &v, string n){
    string aux = "";
    for(char x: n){
        if(x == ' '){
            v.push_back(aux);
            aux = "";
        } else {
            aux += x;
        }
    }
    v.push_back(aux);
}


void my_sort(vector<vector<string> > &v, int pos){
    for(int i = 0; i < v.size() - 1; i++){
        bool x = 0;
        for(int j = 0; j < v.size() - i - 1; j++){
            if(v[j][pos] > v[j + 1][pos]){
                swap(v[j], v[j+1]);
                x = 1;
            }
        }
        if(!x){
            break;
        }
    }
}


int main(){
    string list, n;
    vector<string> s;
    int n1, n2;
    getline(cin, list);
    split(s, list);
    cin >> n1;
    vector<vector<string> > v(n1);
    for(int j = 0; j < n1; j++){
        for(int i = 0; i < s.size(); i++){
            cin >> n;
            v[j].push_back(n);
        }
    }
    cin >> n2;
    while(n2--){
        cin >> n;
        int pos;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == n){
                pos = i;
            } 
        }     
        my_sort(v, pos);
        for(int i = 0; i < s.size(); i++){
            cout << s[i] << " ";
        }
        cout << "\n";
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
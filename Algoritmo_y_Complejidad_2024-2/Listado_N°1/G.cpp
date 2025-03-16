#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    vector <string> vec;
    vector <string> l;
    int t = 0, t1 = 0;
    while(cin >> s){
        vec.insert(vec.begin() + t, s);
        t++;
    }
    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            if( i != j){
                s = vec[i] + vec[j];
                if(find(l.begin(), l.end(), s) == l.end()){
                    l.insert(l.begin() + t1, s);
                    t1++;
                }
            }
        }
    }
    sort(l.begin(), l.end());
    for(int i = 0; i < t1; i++){
        cout << l[i] << "\n";
    }
    return 0;
}
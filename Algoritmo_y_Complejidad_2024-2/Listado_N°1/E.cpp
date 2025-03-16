#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, m, x, s, c, r;
    string type, t;
    cin >> n;
    while(n--){
        cin >> m;
        vector <vector <int> > a, b;
        s = 0;
        while(m--){
            cin >> type >> x >> t >> t >> c;
            if(type == "buy"){
                b.push_back({c, x});
            } else {
                a.push_back({c, x});
            }
            sort(a.rbegin(), a.rend());
            sort(b.begin(), b.end());
            while((!b.empty() && !a.empty()) && (a[a.size()- 1][0] <= b[b.size()-1][0])){
                r = a[a.size()- 1][1] - b[b.size()-1][1];
                s = a[a.size()-1][0];
                if(r < 0){
                    b[b.size()-1][1] -= a[a.size()- 1][1];
                    a.pop_back();
                } else if( r > 0){
                    a[a.size()-1][1] -= b[b.size()-1][1];
                    b.pop_back();
                } else {
                    a.pop_back();
                    b.pop_back();
                }
            }
            if(a.empty()){
                cout << "- ";
            } else {
                cout << a[a.size() -1][0] << " ";
            }
            if(b.empty()){
                cout << "- ";
            } else {
                cout << b[b.size() -1][0] << " ";
            }
            if(s == 0){
                cout << "-\n";
            } else {
                cout << s << "\n";
            }
        }
    }
    return 0;
}
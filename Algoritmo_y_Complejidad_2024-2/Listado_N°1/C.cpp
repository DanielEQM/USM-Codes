#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    getline(cin,s);
    while(n--){
        getline(cin,s);
        list<char> c;
        list<char>::iterator it = c.begin();
        for (int i = 0; i < s.length(); i++){
            if(s[i] == '['){
                it = c.begin();
            }
            else if (s[i] == ']'){
                it = c.end();
            }
            else if (s[i] == '<'){
                if(it != c.begin() && !c.empty()){
                    auto it2 = it;
                    c.erase(--it2);
                }
            }
            else {
                c.insert(it, s[i]);
            }
        }
        for(char x : c){
            cout << x;
        }
        cout<<"\n";
    }
    return 0;
}
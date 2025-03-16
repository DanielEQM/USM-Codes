#include <bits/stdc++.h>
using namespace std;

string s;
long long int total;

bool tipo(char c, int tipo){
    int x;
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        x = 1;
    } else {
        x = 0;
    }
    if(x == tipo){
        return 1;
    } else {
        return 0;
    }
}

void dobra(int pos, int t, int cant, long long int algo){
    if(cant == 3) return;
    if(pos == s.length()){
        bool f = false;
        int contando = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'L'){
                f = true;
            }
            if(tipo(s[i], t)){
                contando++;
            } else {
                if(t == 0) t = 1;
                else t = 0;
                contando = 1;
            }
            if(contando == 3) break;
        }
        if(f && contando != 3){
            total += algo;
        }
    } else {
        int i;
        for(i = pos; i < s.length(); i++){
            if(s[i] == '_'){
                if(t == 1){
                    s[i] = 'L';
                    dobra(i + 1, 0, 1, algo);
                    //cout << s << " " << total << "\n";
                    s[i] = 'A';
                    dobra(i + 1, t, cant + 1, algo*5);
                    //cout << s << " " << total << "\n";
                    s[i] = 'B';
                    dobra(i + 1, 0, 1, algo*20);
                    //cout << s << " " << total << "\n";
                    s[i] = '_';
                } else {
                    s[i] = 'L';
                    dobra(i + 1, t, cant + 1, algo);
                    //cout << s << " " << total << "\n";
                    s[i] = 'A';
                    dobra(i + 1, 1, 1, algo*5);
                    //cout << s << " " << total << "\n";
                    s[i] = 'B';
                    dobra(i + 1, t, cant + 1, algo*20);
                    //cout << s << " " << total << "\n";
                    s[i] = '_';
                }
                return;
            } else {
                if(tipo(s[i], t)){
                    cant++;
                } else {
                    if(t == 0) t = 1;
                    else t = 0;
                    cant = 1;
                }
                if(cant == 3) break;
            }
        }
        if(i == s.length()) dobra(i, t, cant, algo);
    }
}



int main() {
    cin >> s;
    total = 0;
    dobra(0,0,0,1);
    cout << total;
    return 0;
}
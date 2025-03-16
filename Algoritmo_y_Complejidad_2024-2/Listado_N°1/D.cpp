#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, t;
    string s, s1, s2 = "";
    cin >> n;
    while(0 < n){
        bool f = 0;
        int head = 0, curr = 0, tail = 0;
        cin >> s >> t >> s1;
        int k[t];
        if(s1 != "[]"){
            for(char c : s1){
                if (c == ',' || c == ']'){
                    k[tail] = stoi(s2);
                    s2 = "";
                    tail++;
                } else if (c != '[') {
                    s2 += c;
                }
            }
        }
        for(char c : s){
            if(c == 'R'){
                if(curr == head){
                    curr = tail;
                } else {
                    curr = head;
                }
            } else {
                if((tail - head) == 0){
                    cout << "error\n";
                    f = 1;
                    break;
                }
                if(curr == head){
                    head++;
                    curr = head;
                } else {
                    tail--;
                    curr = tail;
                }
            }
        }
        if(f != 1){
            cout << "[";
            if (curr == head){
                for (curr = head; curr < tail - 1; curr++){
                    cout << k[curr] << ",";
                }
                if((tail - head) == 0){
                    cout << "]\n";
                } else {
                    cout << k[curr] << "]\n";
                } 
            } else {
                for (curr = tail - 1; curr > head; curr--){
                    cout << k[curr] << ",";
                }
                if((tail - head) == 0){
                    cout << "]\n";
                } else {
                    cout << k[curr] << "]\n";
                } 
            }
            n--;
        } else {
            n--;
        }
    }
    return 0;
}
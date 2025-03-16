#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> task(n), intervals(m);
    for(int i = 0; i < n; i++){
        cin >> task[i];
    }
    for(int i = 0; i < m; i++){
        cin >> intervals[i];
    }
    sort(task.begin(), task.end());
    sort(intervals.begin(), intervals.end());
    int cont = 0, pos = 0;
    for(int i = 0; i < m; i++){
        if(intervals[i] >= task[pos]){
            cont++; pos++;
        }
    }
    cout << cont;
    return 0;
}
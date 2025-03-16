#include <bits/stdc++.h>
using namespace std;

int binarySearch(int currHeight, int height[], int size) {
    int lower = 0;
    int upper = size;
    while (lower < upper) {
        int mid = (lower + upper) / 2;
        if(height[mid] == currHeight) return mid;
        if (height[mid] >= currHeight) upper = mid;
        else lower = mid+1;
    }
    return lower;
}


int main(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    // Es importante el tipo de dato, int se queda corto ante algunas respuestas.
    long long c, desp = 0;
    while(m--){
        cin >> c;
        int x = binarySearch(c, arr, n);
        desp += arr[x] - c;
    }
    cout << desp;
    return 0;
}
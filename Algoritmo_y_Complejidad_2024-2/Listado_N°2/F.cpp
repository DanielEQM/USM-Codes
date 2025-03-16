#include <bits/stdc++.h>
using namespace std;

int binarySearch(int currHeight, int height[], int size) {
    int lower = 0;
    int upper = size;
    while (lower < upper) {
        int mid = (lower + upper) / 2;
        if (height[mid] >= currHeight) upper = mid;
        else lower = mid+1;
    }
    return size - lower;
}


int main(){
    int n, h, e;
    cin >> n >> h;
    int tites[n/2];
    int mites[n/2];
    for(int i = 0; i < n; i++){
        cin >> e;
        if(i%2 == 0){
            tites[i/2] = e;
        } else {
            mites[i/2] = e;
        }
    }
    sort(tites, tites + n/2);
    sort(mites, mites + n/2);
    int min = n + 1, cont = 0;
    for(int i = 1; i <= h; i++){
        int floor = binarySearch(i, tites, n/2);
        int sky = binarySearch(h - i + 1, mites, n/2);
        if(min > (floor + sky)){
            min = floor + sky;
            cont = 1;
        } else if (min == (floor + sky)) {
            cont++;
        }
    }
    cout << min << " " << cont;
    return 0;
}
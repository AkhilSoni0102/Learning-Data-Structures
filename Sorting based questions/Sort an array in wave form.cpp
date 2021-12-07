#include<bits/stdc++.h>
using namespace std;
vector<int> waveFormArray(vector<int> &arr, int n) {
    int c = 0;
    for(int i = 0;i < n-1;i++){
        if(arr[i] < arr[i+1] && c == 0)
            swap(arr[i], arr[i+1]);
        else if(arr[i] > arr[i+1] && c == 1)
            swap(arr[i], arr[i+1]);
        if(c == 0)
            c++;
        else 
           	c--;
    }
    return arr;
}
#include<bits/stdc++.h>
using namespace std;
void sortHalfSorted(vector<int> &arr) {
    int j;
    for(int i = 0;i < arr.size()-1;i++){
        if(arr[i] > arr[i+1])
            j = i+1;
    }
    vector<int> v;
    int i = 0;
    int J = j;
    while(i < J && j < arr.size()){
        if(arr[i] <= arr[j]){
            v.push_back(arr[i]);
            i++;
        }
        else{
            v.push_back(arr[j]);
            j++;
        }
    }
    while(i < J){
        v.push_back(arr[i]);
        i++;
    }
    while(j < arr.size()){
        v.push_back(arr[j]);
        j++;
    }
    for(int i = 0;i < arr.size();i++)
        arr[i] = v[i];
}

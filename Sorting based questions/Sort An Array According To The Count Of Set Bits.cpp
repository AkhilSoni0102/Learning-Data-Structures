#include<bits/stdc++.h>
using namespace std;

int count(int N){
    int c = 0;
    while(N){
        N -= (N & (-N));
        c++;
    }
    return c;
}
void sortSetBitsCount(vector<int>& arr, int size)
{
    vector<vector<int>> v(33, vector<int>());
    for(int i = 0;i < size;i++)
        v[count(arr[i])].push_back(arr[i]);
    arr.clear();
    for(int i = 32;i >= 0;i--){
        for(int j = 0;j < v[i].size();j++)
            arr.push_back(v[i][j]);
    }
}
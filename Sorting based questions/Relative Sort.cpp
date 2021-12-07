#include<bits/stdc++.h>
using namespace std;
vector<int> relativeSorting(vector<int> &arr, vector<int> &brr, int N, int M)
{
    vector<int> res;
        unordered_map<int, int> umap;
        for(int i = 0;i < N;i++)
            umap[arr[i]]++;
        for(int i = 0;i < M;i++){
            while(umap[brr[i]]){
                res.push_back(brr[i]);
                umap[brr[i]]--;
            }
        }
        int m = res.size();
        for(int i = 0;i < N;i++)
            while(umap[arr[i]]){
                res.push_back(arr[i]);
                umap[arr[i]]--;
            }
        sort(res.begin() + m, res.end());
        return res;
}
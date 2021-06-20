#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, W;
    cin>>n>>W;
    int wt[n];
    int val[n];
    for(int i = 0;i < n;i++)
        cin>>wt[i];
    for(int i = 0;i < n;i++)
        cin>>val[i];
    int t[n+1][W+1];
    for(int i = 0;i < n+1;i++)
        t[i][0] = 0;
    for(int i = 0;i < W+1;i++)
        t[0][i] = 0;
    for(int i = 1;i < n+1;i++)
        for(int j = 1;j < W+1;j++)
            if(wt[i-1] <= j)
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]],t[i-1][j]);
            else 
                t[i][j] = t[i-1][j];
    cout << t[n][W];
}
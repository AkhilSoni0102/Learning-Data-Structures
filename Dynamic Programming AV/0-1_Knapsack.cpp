#include<bits/stdc++.h>
using namespace std;

int knapsack(int Weight[], int value[], int n, int W, int** DP){
    if(n == 0 || W <= 0)
        return 0;
    if(DP[n][W] != -1)
        return DP[n][W];
    int a = 0;
    if(Weight[0] <= W){
        DP[n-1][W - Weight[0]] = knapsack(Weight + 1, value + 1, n - 1, W - Weight[0], DP);
        a = value[0] + DP[n-1][W - Weight[0]];
    }
    DP[n-1][W] = knapsack(Weight + 1, value + 1, n - 1, W, DP);
    int b = DP[n-1][W];
    DP[n][W] = max(a, b);
    return DP[n][W];
}

int main(){
    int n, W;
    cin>>n>>W;
    int Weight[n];
    int value[n];
    for(int i = 0;i < n;i++){
        cin>>Weight[i];
    }
    for(int i = 0;i < n;i++){
        cin>>value[i];
    }
    int** DP = new int*[n+1];
    for(int i = 0;i < n+1;i++){
        DP[i] = new int[W+1];
        for(int j = 0;j < W+1;j++)
            DP[i][j] = -1;
    }
    cout << knapsack(Weight, value, n, W, DP);
}
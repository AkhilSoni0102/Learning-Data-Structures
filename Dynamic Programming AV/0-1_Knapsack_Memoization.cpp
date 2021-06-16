#include<bits/stdc++.h>
using namespace std;
int static DP[102][1002];
int knapsack(int Weight[], int value[], int n, int W){
    if(n == 0 || W == 0)
        return 0;
    if(DP[n][W] != -1)
        return DP[n][W];
    if(Weight[n-1] <= W)
        DP[n][W] = max(value[n-1] + knapsack(Weight, value, n-1, W - Weight[n-1]), knapsack(Weight, value, n-1, W));
    else
        DP[n][W] = knapsack(Weight, value, n-1, W);
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
    cout << knapsack(Weight, value, n, W);
}
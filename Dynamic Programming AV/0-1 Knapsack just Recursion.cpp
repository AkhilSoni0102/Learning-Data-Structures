#include<bits/stdc++.h>
using namespace std;

int knapsack(int Weight[], int value[], int n, int W){
    if(n == 0 || W == 0)
        return 0;
    if(Weight[n-1] <= W)
        return max(value[n-1] + knapsack(Weight, value, n-1, W - Weight[n-1]), knapsack(Weight, value, n-1, W));
    else
        return knapsack(Weight, value, n-1, W);
}

int main(){
    int n, W;
    cin>>n>>W;
    int Weight[n];
    int value[n];
    for(int i = 0;i < n;i++)
        cin>>Weight[i];
    for(int i = 0;i < n;i++)
        cin>>value[i];
    cout << knapsack(Weight, value, n, W);
}
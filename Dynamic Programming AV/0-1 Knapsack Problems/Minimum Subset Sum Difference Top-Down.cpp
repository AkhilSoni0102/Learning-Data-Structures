#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n];

    for(int i = 0;i < n;i++)
        cin>>A[i];
    int sum = 0;
    
    for(int i = 0;i < n;i++)
        sum += A[i];
    int t[n+1][sum+1];
    
    for(int i = 0;i < sum + 1; i++)
        t[0][i] = 0;
    for(int i = 0;i < n + 1; i++)
        t[i][0] = 1;
    
    for(int i = 1;i < n+1;i++)
        for(int j = 1;j < sum + 1;j++)
            if(A[i-1] <= j)
                t[i][j] = t[i-1][j-A[i-1]] || t[i-1][j];
            else 
                t[i][j] = t[i-1][j];
    int Min = INT_MAX;
    for(int i = (sum + 1)/2;i >= 0 ;i--){
        if(t[n][i]){
            cout << abs(sum - 2 * i);
            break;
        }
    }
}
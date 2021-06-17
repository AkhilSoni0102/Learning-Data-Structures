#include<bits/stdc++.h>
using namespace std;

bool Equal_Sum_Partition(int A[], int n, int sum1, int sum2){
    if(sum1 == sum2)
        return 1;
    if(sum1 < sum2)
        return 0;
    if(n == 0)
        return 0;
    for(int i = 0; i < n;i++)
        cout << A[i] << " ";
    cout << "sum1: " << sum1 << " sum2: " << sum2 << endl;
    if(A[n-1] <= sum1)
        return Equal_Sum_Partition(A, n-1, sum1 - A[n-1], sum2 + A[n-1]) || Equal_Sum_Partition(A, n-1, sum1, sum2);
    else 
        return Equal_Sum_Partition(A, n-1, sum1, sum2);
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin>>A[i];
    int sum = 0;
    for(int i = 0;i < n;i++)
        sum += A[i];
    cout << Equal_Sum_Partition(A, n, sum, 0);
    
}
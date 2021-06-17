#include<bits/stdc++.h>
using namespace std;

int MinSum(int A[], int n, int sum1, int sum2){
    if(sum1 == sum2)
        return 0;
    if(n == 0)
        return abs(sum1 - sum2);
    if(A[n-1] <= sum1){
        int a =  MinSum(A, n-1, sum1 - A[n-1], sum2 + A[n-1]);
        int b = MinSum(A, n-1, sum1, sum2);
        return min(b, a);
    }
    else {
        return MinSum(A, n-1, sum1, sum2);
    }
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i = 0; i < n;i++)
        cin>>A[i];
    int sum = 0;
    for(int i = 0;i < n;i++)
        sum += A[i];
    cout << MinSum(A, n, sum, 0);
}
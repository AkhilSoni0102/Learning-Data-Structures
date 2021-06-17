#include<bits/stdc++.h>
using namespace std;

int Count_Subsets(int A[], int n, int sum){
    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;
    if(A[n-1] <= sum)
        return Count_Subsets(A, n-1, sum - A[n-1]) + Count_Subsets(A, n-1, sum);
    else 
        return Count_Subsets(A, n-1, sum);
}

int main(){
    int n, sum;
    cin>>n>>sum;
    int A[n];
    for(int i = 0;i < n;i++)
        cin>>A[i];
    cout << Count_Subsets(A, n, sum);
}
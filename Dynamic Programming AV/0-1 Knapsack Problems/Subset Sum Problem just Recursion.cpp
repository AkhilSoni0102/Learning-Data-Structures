#include<bits/stdc++.h>
using namespace std;

int Subset_Sum(int arr[], int n, int sum){
    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;
    if(arr[n-1] <= sum)
        return Subset_Sum(arr, n-1, sum - arr[n-1]) || Subset_Sum(arr, n-1, sum);
    else 
        return Subset_Sum(arr, n-1, sum);
}

int main(){
    int n, sum;
    cin>>n>>sum;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin>>arr[i];
    cout << Subset_Sum(arr, n, sum);
}
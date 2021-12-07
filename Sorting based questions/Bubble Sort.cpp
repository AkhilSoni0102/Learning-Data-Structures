#include<bits/stdc++.h>
using namespace std;

void Bubble_Sort(int A[], int n){
    if(n == 0)
        return ;
    for(int i = 0;i < n-1;i++)
        for(int j = 0;j < n-i-1;j++)
            if(A[j] > A[j+1])
                swap(A[j], A[j+1]);
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0;i < n;i++)    
        cin >> A[i];
    Bubble_Sort(A, n);
    for(int i = 0;i < n;i++)
        cout << A[i] << " ";
}
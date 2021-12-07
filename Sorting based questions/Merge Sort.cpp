#include<bits/stdc++.h>
using namespace std;

void Merge(int A[], int i, int mid, int j){
    if(i == j)
        return ;
    int Copy[j-i+1];
    int m = 0;
    int I = i;
    int J = mid+1;
    while(I <= mid && J <= j){
        if(A[I] < A[J]){
            Copy[m] = A[I];
            I++;
            m++;
        }
        else{
            Copy[m] = A[J];
            J++;
            m++;
        }
    }
    while(I <= mid){
        Copy[m] = A[I];
        I++;
        m++;
    }
    while(J <= j){
        Copy[m] = A[J];
        J++;
        m++;
    }
    m--;
    while(m >= 0){
        A[j] = Copy[m];
        m--;
        j--;
    }
} 

void Merge_Sort(int A[], int i, int j){
    if(i == j)
        return ;
    int mid = (i+j)/2;
    Merge_Sort(A, i, mid);
    Merge_Sort(A, mid + 1, j);
    Merge(A, i, mid, j);
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0;i < n;i++)
        cin >> A[i];
    Merge_Sort(A, 0, n-1);
    for(int i = 0;i < n;i++)
        cout << A[i] <<  " ";
}
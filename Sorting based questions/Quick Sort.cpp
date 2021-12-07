#include<bits/stdc++.h>
using namespace std;

void Quick_Sort(int A[], int start, int end){
    if(start >= end)
        return ;
    int pivot = A[end];
    int pIndex = start;
    for(int i = start;i < end;i++){
        if(A[i] <= pivot){
            swap(A[i], A[pIndex]);
            pIndex++;
        }
    }
    swap(A[pIndex], A[end]);
    Quick_Sort(A, start, pIndex-1);
    Quick_Sort(A, pIndex+1, end);
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0;i < n;i++)
        cin >> A[i];
    Quick_Sort(A, 0, n-1);
    for(int i = 0;i < n;i++)
        cout << A[i] << " ";
}
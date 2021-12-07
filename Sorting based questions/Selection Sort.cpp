#include<bits/stdc++.h>
using namespace std;

void Selection_Sort_Recursion(int A[], int n){
    if(n == 0)
        return;
    int I = 0;
    for(int i = 0;i < n;i++)
        if(A[i] <= A[I])
            I = i;
    swap(A[I], A[0]);
    Selection_Sort_Recursion(A+1, n-1);
}

void Selection_Sort(int A[], int n){
    if(n == 0)
        return ;
    for(int i = 0;i < n;i++){
        int I = i;
        for(int j = i+1;j < n;j++)
            if(A[j] <= A[I])
                I = j;
        swap(A[I], A[i]);
    }
}
int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0;i < n;i++)
        cin >> A[i];
    Selection_Sort(A, n);
    for(int i = 0;i < n;i++)
        cout << A[i] << " ";
    cout << endl;
    Selection_Sort_Recursion(A, n);
    for(int i = 0;i < n;i++)
        cout << A[i] << " ";
}
#include<bits/stdc++.h>
using namespace std;
void Insertion_Sort(int A[], int n){
    if(n == 0)
        return;
    for(int i = 1;i < n;i++){
        int j = i-1;
        int cur = A[i];
        while(j >= 0 && A[j] > cur){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = cur;
    }
}
int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0;i < n;i++)
        cin >> A[i];
    Insertion_Sort(A, n);
    for(int i = 0;i < n;i++)
        cout << A[i] <<  " ";
}
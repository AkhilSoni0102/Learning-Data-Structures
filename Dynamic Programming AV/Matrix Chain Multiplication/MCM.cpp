#include<bits/stdc++.h>
using namespace std;

int MCM(int A[], int i, int j){
    if(i >= j)
        return 0;
    for(int k = i;k <= j;k++)
        min(MCM(A, i, k), MCM(A, k+1, j));
    
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0;i < N;i++)
        cin >> A[i];
    cout << MCM(A, 0, N-1);
}
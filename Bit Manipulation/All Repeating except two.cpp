#include<bits/stdc++.h>
using namespace std;
void ARET(int A[], int N){
    int Xor = 0;
    for(int i = 0;i < N;i++)
        Xor ^= A[i];
    int rmsb = (Xor & (-Xor));
    int x = 0;
    int y = 0;
    for(int i = 0;i < N;i++){
        if((A[i] & rmsb) == 0)
            x^=A[i];
        else    
            y ^= A[i];
    }
    cout << x << " " << y;
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i = 0;i < N ;i++)
        cin >> A[i];
    ARET(A, N);
}
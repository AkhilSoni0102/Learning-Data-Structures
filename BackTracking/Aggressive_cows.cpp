#include<bits/stdc++.h>
using namespace std;

void Aggressive(int* A, int n, int c, int start, int End){
    if(End >= Start)
        return ;
    int Mid = Start + (Start - End)/2;
    int C = c - 1;
    for(int i = 1; i < n;i++){
        if(A[i] - A[i-1] <= Mid)
            C--;
        if(C == 0)
            Aggressive(A, n, c, Mid+1, End);
    }
    Aggressive(A, n, c, Start, Mid - 1);
}

int main(){
    int n, c;
    cin>>n>>c;
    int* A = new int[n];
    for(int i = 0;i < n; i++)
        cin>>A[i];
    int Min = 0;
    int Max = A[n-1] - A[0];
    Aggressive(A, n, c, Min, Max); 
}
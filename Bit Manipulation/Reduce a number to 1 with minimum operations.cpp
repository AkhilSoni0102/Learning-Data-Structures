#include<bits/stdc++.h>
using namespace std;
int rmsb(int n){
    return (n & (-n));
}
int main(){
    int N;
    cin >> N;
    int c = 0;
    while(N > 1){
        if(N & 1){
            if(N+1 == rmsb(N+1) && N != 3)
                N++;
            else 
                N--;
        }
        else 
            N/=2;
        c++;
    }
    cout << c;
}
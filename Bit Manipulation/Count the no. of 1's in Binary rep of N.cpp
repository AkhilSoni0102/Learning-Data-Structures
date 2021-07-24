#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int c = 0;
    while(N > 0){
        c++;
        int rmsb = N & (-N);
        N = N - rmsb;
    }
    cout << c;
}
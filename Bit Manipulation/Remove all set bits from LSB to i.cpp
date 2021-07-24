#include<bits/stdc++.h>
using namespace std;


int main(){
    int N, i;
    while(cin >> N >> i){
        int a = ~((1 << (i+1)) - 1);
        int A = N & a;
        int b = (N >> (i+1)) << (i+1);
        cout << A << " " << b <<endl;
    }
}
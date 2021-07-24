#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    if((N & (N-1)) == 0)
        cout << "It is a power of 2";
    else 
        cout << "It is not a power of 2";
}
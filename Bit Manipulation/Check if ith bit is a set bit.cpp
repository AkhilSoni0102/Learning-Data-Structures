#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, i;
    cin >> N >> i;
    if((N & (1 << i)))
        cout << "It is a set bit";
    else 
        cout << "It is not a set bit";
}
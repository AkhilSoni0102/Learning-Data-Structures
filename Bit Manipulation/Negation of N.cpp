#include<bits/stdc++.h>
using namespace std;

// To convert a number from N to -N we take its 2's complement which is (~N + 1)
// Hence ~N = -N - 1;
// eg. ~2 = -2 - 2 = -3;

int main(){
    int N;
    cin >> N;
    int a = ~N;
    cout << a;
}
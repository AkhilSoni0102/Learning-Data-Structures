#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int A, int B){
    if(A == 0 || B == 0)
        return 0;
    if(a[A - 1] == b[B-1])
        return 1 + LCS(a, b, A-1, B-1);
    return max(LCS(a, b, A, B-1),LCS(a, b,A-1, B));
}

int main(){
    string a;
    string b;
    cin>>a;
    cin>>b;
    cout << LCS(a, b, a.length(), b.length());
}
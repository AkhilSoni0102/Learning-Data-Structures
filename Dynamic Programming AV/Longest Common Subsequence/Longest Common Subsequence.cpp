#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b){
    int A = a.length();
    int B = b.length();
    if(A == 0 || B == 0)
        return 0;
    if(a[A - 1] == b[B-1])
        return 1 + LCS(a.substr(0, A - 1), b.substr(0, B - 1));
    return LCS(a.substr(0, A - 1), b) || LCS(a, b.substr(0, B - 1));
}

int main(){
    string a;
    string b;
    cin>>a;
    cin>>b;
    cout << LCS(a, b);
}
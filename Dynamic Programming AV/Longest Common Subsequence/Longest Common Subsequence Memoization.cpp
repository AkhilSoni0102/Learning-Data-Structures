#include<bits/stdc++.h>
using namespace std;
int t[100][100];
int LCS(string a, string b, int A, int B){
    if(A == 0 || B == 0)
        return 0;
    if(t[A][B] != -1)
        return t[A][B];
    if(a[A - 1] == b[B-1]){
        t[A-1][B-1] = LCS(a, b, A-1, B-1);
        t[A][B] = 1 + t[A-1][B-1];
    }
    else{
        t[A-1][B] = LCS(a, b, A-1, B);
        t[A][B-1] = LCS(a, b, A, B-1);
        t[A][B] = max(t[A-1][B], t[A][B-1]);
    }
    return t[A][B];
}

int main(){
    string a;
    string b;
    cin>>a;
    cin>>b;
    memset(t, -1, sizeof(t));
    cout << LCS(a, b, a.length(), b.length());
}
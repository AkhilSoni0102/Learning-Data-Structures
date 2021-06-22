#include<bits/stdc++.h>
using namespace std;

string  Print_LCS(string A, string B, int a, int b){
    if(a == 0 || b == 0)
        return "";
    if(A[a-1] == B[b-1])
        return Print_LCS(A, B, a-1, b-1) + A[a-1];
    string left = Print_LCS(A, B, a, b-1);
    string right = Print_LCS(A, B, a-1, b);
    if(left.size() > right.size())
        return left;
    return right;
}

int main(){
    string a;
    string b;
    cin>>a>>b;
    cout << Print_LCS(a, b, a.length(), b.length());
}
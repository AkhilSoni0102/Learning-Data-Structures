#include<bits/stdc++.h>
using namespace std;
int main(){
    string A;
    cin>>A;
    string T = A;
    reverse(A.begin(), A.end());
    string B = A;;
    A = T;
    int a = A.length();
    int t[a+1][a+1];
    for(int i = 0;i < a+1;i++){
        t[i][0] = 0;
        t[0][i] = 0;
    }
    for(int i = 1;i < a+1;i++)
        for(int j = 1;j < a+1;j++)
            if(A[i-1] == B[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else 
                t[i][j] = max(t[i-1][j], t[i][j-1]);
    cout << t[a][a];
}
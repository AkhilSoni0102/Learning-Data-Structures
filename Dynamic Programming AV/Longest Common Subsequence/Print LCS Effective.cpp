#include<bits/stdc++.h>
using namespace std;
int main(){
    string A, B;
    cin>>A>>B;
    int a = A.length();
    int b = B.length();
    int t[a+1][b+1];
    for(int i = 0;i < a+1;i++)
        t[i][0] = 0;
    for(int j = 0;j < b+1;j++)  
        t[0][j] = 0;
    for(int i = 1;i < a+1;i++)
        for(int j = 1;j < b+1;j++)
            if(A[i-1] == B[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else 
                t[i][j] = max(t[i-1][j], t[i][j-1]);
    int i = a;
    int j = b;
    string ans = "";
    while(i > 0 && j > 0){
        if(A[i-1] == B[j-1])
            ans = A[i-1] + ans, i--, j--;
        else if(t[i-1][j] > t[i][j-1])  
            i--;
        else 
            j--;
    }
    cout << ans;
}
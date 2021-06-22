#include<bits/stdc++.h>
using namespace std;
int main(){
    string A;
    string B;
    cin>>A>>B;
    int a = A.length();
    int b = B.length();
    string t[a+1][b+1];
    for(int i = 0; i < a+1;i++)
        t[0][i] = "";
    for(int j = 0;j < b+1;j++)
        t[j][0] = "";
    for(int i = 1;i< a+1;i++)
        for(int j = 1;j < b+1;j++)
            if(A[i-1] == B[j-1])
                t[i][j] = t[i-1][j-1] + A[i-1];
            else if(t[i-1][j].size() > t[i][j-1].size())
                t[i][j] = t[i-1][j];
            else 
                t[i][j] = t[i][j-1];   
    for(int i = 1;i < a+1;i++){
        for(int j = 1;j < b+1;j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
}
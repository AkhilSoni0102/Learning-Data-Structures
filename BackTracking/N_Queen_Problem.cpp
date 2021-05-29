#include<bits/stdc++.h>
using namespace std;
/*
void BackTracking(vector<vector<int>> &A, int n, int r){
    if(r == n){
        cout<<"Queens: "<<endl;
        for(int i = 0; i < n;i++){
            for(int j = 0;j < n;j++)
                cout<<A[i][j]<<" ";
            cout<<endl;
        }
        return ;
    }
    for(int i = 0;i < n;i++)
        if(A[r][i] != -1){
            for(int j = i+1;j < n;j++)
                    A[r][j] = -1;
            for(int j = r+1;j < n;j++)
                    A[j][i] = -1;
            int a = r+1;
            int b = i+1;
            while(a < n && b < n){
                A[a][b] = -1;
                a++;
                b++;
            }
            a = r+1;
            b = i-1;
            while(a >= 0 && b >= 0 && a < n && b < n){
                A[a][b] = -1;
                a++;
                b--;
            }
            BackTracking(A, n, r+1);
            break;
        }

}*/

bool BackTracking(vector<vector<int>> & A, int n, int r){
    if(r == n){
        for(int i = 0;i < n;i++){
            for(int j = 0; j < n;j++)
                cout<<A[i][j]<<" ";
            cout<<endl;
        }
        return 1;
    }
    for(int i = 0;i < n;i++){
        if(A[r][i] == 0){
            for(int j = r+1;j < n;j++)
                    A[j][i]++;
            int a = r+1;
            int b = i-1;
            while(a < n && b < n && a >=0 && b >= 0){
                A[a][b]++;
                a++;
                b--;
            }
            a = r-1;
            b = i+1;
            while(a < n && b < n && a >=0 && b >= 0){
                A[a][b]++;
                a--;
                b++;
            }

            bool ans = BackTracking(A, n, r+1);
            
            for(int j = 0;j <= i;j++)
                A[r][j]++;
            for(int j = r+1;j < n;j++)
                    A[j][i]--;
            int a = r+1;
            int b = i-1;
            while(a < n && b < n && a >=0 && b >= 0){
                A[a][b]--;
                a++;
                b--;
            }
            a = r-1;
            b = i+1;
            while(a < n && b < n && a >=0 && b >= 0){
                A[a][b]--;
                a--;
                b++;
            if(i == n && ans){
                for(int j = 0;j < n;j++)
                    A[r][j]--;
            }
            }
        }
    }

}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> A(n,vector<int>(n,0));
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                A[i][j] = 0;
        for(int i = 0;i < n;i++){
            if(i != k)
                A[0][i] = -1;
        }
        BackTracking(A, n, 0);
    }
    
}
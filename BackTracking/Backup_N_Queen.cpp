#include<bits/stdc++.h>
using namespace std;

void BackTracking(int** A, int n, int r){
    if(r == n){
        cout<<"Queens: "<<endl;
        for(int i = 0; i < n;i++){
            for(int j = 0;j < n;j++)
                cout<<A[i][j]<<" ";
            cout<<endl;
        }
        cout<<"Queens: "<<endl;
        return ;
    }
    for(int i = 0;i < n;i++)
        if(A[r][i] != -1){
            for(int j = 0;j < n;j++)
                if(j != i)
                    A[r][j] = -1;
            for(int j = 0;j < n;j++)
                if(j != r)
                    A[j][i] = -1;
            int a = r+1;
            int b = i+1;
            while(a < n && b < n){
                A[a][b] = -1;
                a++;
                b++;
            }
            a = r-1;
            b = i-1;
            while(a >= 0 && b >=0){
                A[a][b] = -1;
                a--;
                b--;
            }
            a = r-1;
            b = i+1;
            while(a >= 0 && b >= 0 && a < n && b < n){
                A[a][b] = -1;
                a--;
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

}

int main(){
    int n;
    cin>>n;
    int** A = new int*[n];
    for(int i = 0;i < n;i++){
        A[i] = new int[n];
        for(int j = 0;j < n;j++)
            A[i][j] = 0;
    }
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
#include<bits/stdc++.h>
using namespace std;

bool Safe(int** A, int n, int r, int c){
    // checking the same column present only above current row "r"
    for(int i = 0;i < r;i++){
        if(A[i][c])
            return false;
    }
    // checking the primary diagonal present only above current row "r"
    for(int i = r, j = c; i >= 0 && j < n; i--, j++){
        if(A[i][j])
            return false;
    }
    // checking the secondary diagonal present only above current row "r"
    for(int i = r, j = c; i >= 0 && j >= 0; i--, j--){
        if(A[i][j])
            return false;
    }
    return true;
}

void N_Queens(int** A, int n, int r){
    if( r == n ){
        cout<< " Queens: " << endl;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++)
                cout<< A[i][j] << " " ;
            cout << endl;
        }
        return ;
    }
    for(int i = 0;i < n;i++){
        if(Safe(A, n, r, i)){
            A[r][i] = 1;
            N_Queens(A, n, r+1);
            A[r][i] = 0;
        }
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
    N_Queens(A, n, 0);
}
#include<bits/stdc++.h>
using namespace std;
void Rat_in_a_Maze(int** A, int n, int r, int c, int** solution){
    if(r >= n || r < 0 || c >= n  || c < 0)
        return;
    if(A[r][c] == 0 || solution[r][c] == 1)
        return ;
    if(r == n-1 && c == n-1){
        solution[r][c] = 1;
        cout << "Solution" << endl;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++)
                cout << solution[i][j] << " " ;
            cout << endl ;
        }
        solution[r][c] = 0;
        return ;
    }
    solution[r][c] = 1;
    Rat_in_a_Maze(A, n, r, c + 1, solution);
    Rat_in_a_Maze(A, n, r + 1, c, solution);
    Rat_in_a_Maze(A, n, r - 1, c, solution);
    Rat_in_a_Maze(A, n, r, c - 1, solution);
    solution[r][c] = 0;
}

int main(){
    int n;
    cin>>n;
    int** A = new int*[n];
    for(int i = 0;i < n;i++){
        A[i] = new int[n];
        for(int j = 0;j < n;j++)
            cin >> A[i][j] ;
    }
    int** solution = new int*[n];
    for(int i = 0;i < n;i++){
        solution[i] = new int[n];
        for(int j = 0;j < n;j++)
            solution[i][j] = 0;
    }
    Rat_in_a_Maze(A, n, 0, 0, solution);
}
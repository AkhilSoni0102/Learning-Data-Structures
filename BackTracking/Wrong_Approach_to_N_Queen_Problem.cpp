// In this approach this is what I did:
// 1. I created an array of size n*n and initialized all the elements as 0.
// 2. I called the function for the first row. 
// 3. I checked for all the columns of current row, whether it is possible to keep the queen or not. If possible, I changed 
//    the values of the cells to -1, present in: (let's say the current cell is (r,c) )
//       a) The current column(c)
//       b) The primary diagonal passing to the current (r,c).
//       c) The secondary diagonal passing through the current cell (r,c).
//    I have only "changed" the rows which were present "below" the current column.
// 4. Then I called the function for the next row: (r+1).
// ---------------------------------------------------------------------------------------------------------------------------
// Mistake:  This is the wrong appoach because I change the value of the cells which I have not visited yet. So, if I were to 
//           go back to take another path, I would have to delete the effect of the current cell on all the cells below the 
//           current row. which is not possible as all the cells present below the current row have contributions from all the
//           rows above the current row and the current row. So, if we just want to remove the effect of currrent row explicitly
//           we can not do it.
// ---------------------------------------------------------------------------------------------------------------------------
// Solution: If check the rows above the current row, i.e let's say we need to check whether it is safe to insert in the current
//           cell. We can check all the cells present in: 
//              a) current column 
//              b) The primary diagonal passing to the current (r,c).
//              c) The secondary diagonal passing through the current cell (r,c).
//           I have only "Checked" the rows which were present "above" the current column. Also, I didn't changed the values eihter.
//           This way I just need to change the current cell back to zero and I can take a step back and go to another path.

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
#include<bits/stdc++.h>
using namespace std;
#define N 4
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
            cout<<board[i][j];
		cout<<endl;
	}
}


bool isSafe(int board[N][N], int r, int c)
{
	int i, j;
	for (i = 0; i < c; i++)
		if (board[r][i])
			return false;
	for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;
	for (i = r, j = c; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;
	return true;
}
bool solveNQUtil(int board[N][N], int c)
{
	if (c >= N)
		return true;
	for (int i = 0; i < N; i++) {   
		if (isSafe(board, i, c)) {
			board[i][c] = 1;
			if (solveNQUtil(board, c + 1))
				return true;
			board[i][c] = 0;
		}
	}
	return false;
}
bool solveNQ()
{
	int board[N][N] = { { 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };
	if (solveNQUtil(board, 0) == false) {
		printf("Solution does not exist");
		return false;
	}
	printSolution(board);
	return true;
}
int main()
{
	solveNQ();
	return 0;
}
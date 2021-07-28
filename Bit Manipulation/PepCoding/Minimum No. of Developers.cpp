#include<bits/stdc++.h>
using namespace std;
 
int Knapsack(int A[], int E, int Limit, int Skill, vector<vector<int>> &dp){
    if(Skill == Limit)
        return 0;
    if(E == 0)
        return -1;
    if(dp[E][Skill] != -1)
	    return dp[E][Skill];
    int a = Knapsack(A, E-1, Limit, (Skill | A[E-1]), dp);
    int b = Knapsack(A, E-1, Limit, Skill, dp);
    int ans;
    if(a != -1 && b != -1)
        ans = min(1+a, b);
    else if(a==-1)
        ans = b;
    else if(b==-1)
        ans = a+1;
    else
        ans = -1;
    dp[E][Skill] = ans;
    return ans;
}
 
int main(){
    int N, E;
    cin >> N >> E;
    int A[E];
    string skill;
    for(int i = 0;i < E;i++){
        cin >> skill;
        A[i] = 0;
        for(int j = 0;j < skill.size();j++)
            A[i] += 1 << ((int)skill[j] - 97);
    }
    for(int i = 0;i < E;i++)
        cout << A[i] << " ";
    cout << endl;
    int Skill = 0;
    int Limit = (1 << N) - 1;
    cout << Limit << endl;
    vector<vector<int>> dp(E+1, vector<int>(Limit + 1, -1));
    Knapsack(A, E, Limit, Skill, dp);
    cout << dp[E][Skill];
}
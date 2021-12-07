#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int Max;
        int SecMax;
};
void BuildTree(vector<int> &A, vector<node> &T, int s, int e, int t){
    if(s == e){
        T[t] = {A[s], 0};
        return ;
    }
    int mid = (s+e)/2;
    BuildTree(A, T, s, mid, 2*t+1);
    BuildTree(A, T, mid+1, e, 2*t+2);
    T[t].Max = max(T[2*t + 1].Max, T[2*t + 2].Max);
    int l = 2*t+1;
    int r = 2*t+2;
    T[t].Max = max(T[l].Max, T[r].Max);
    T[t].SecMax = min(max(T[l].Max, T[r].SecMax), max(T[r].Max, T[l].SecMax)); 

}
int main(){
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 0;i < N;i++)
        cin >> A[i];
    vector<node> T(4*N, {0,0});
    BuildTree(A, T, 0, N-1, 0);
    for(int i = 0;i < T.size();i++)
        cout << T[i].Max << " " << T[i].SecMax << endl;
}
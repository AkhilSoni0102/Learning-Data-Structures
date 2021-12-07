#include<bits/stdc++.h>
using namespace std;
void BuildTree(vector<int> &A, vector<int> &T, int s, int e, int t){
    if(s == e){
        T[t] = A[s];
        return ;
    }
    int mid = (s+e)/2;
    BuildTree(A, T, s, mid, 2*t+1);
    BuildTree(A, T, mid+1, e, 2*t+2);
    T[t] = max({ T[2*t + 1], T[2*t + 2]});
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 0;i < N;i++)
        cin >> A[i];
    vector<int> T(4*N, 0);
    BuildTree(A, T, 0, N-1, 0);
}
// Given an array A. you need to perform the following two queries:
// 1. Assign A[i] = x
// 2. Print the sum of all the elements of the subarray from L to R.

#include<bits/stdc++.h>
using namespace std;
void BuildTree(vector<int> &A, vector<int> &T, int s, int e, int t){
    if(s == e){
        T[t] = A[s];
        return ;
    }
    int mid = (s + e)/2;
    BuildTree(A, T, s, mid, 2*t+1);
    BuildTree(A, T, mid + 1, e, 2*t+2);
    T[t] = T[2*t+1] + T[2*t+2];
}

void Update(vector<int>&A, vector<int> &T, int s, int e, int t, int I, int val){
    if(s == e){
        A[I] = val;
        T[t] = val;
        return ;
    }
    int mid = (s+e)/2;
    if(I > mid)
        Update(A, T, mid+1, e, 2*t+2, I, val);
    else 
        Update(A, T, s, mid, 2*t+1, I, val);
    T[t] = T[2*t+1] + T[2*t+2];
}
int Query(vector<int> &T, int s, int e, int t, int l, int r){
    if(r < s || l > e)
        return 0;
    if(s >= l && e <= r)
        return T[t];
    int mid = (s+e)/2;
    int a1 = Query(T, s, mid, 2*t+1, l, r);
    int a2 = Query(T, mid+1, e, 2*t+2, l, r);
    return a1 + a2;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 0;i < N;i++)
        A[i] = i+1;
    vector<int> T(4*N, 0);

    BuildTree(A, T, 0, N-1, 0);
    for(int i = 0;i < T.size();i++)
        cout << T[i] << " ";
    cout << endl;
    
    Update(A, T, 0, N-1, 0, 1, 3);
    for(int i = 0;i < T.size();i++)
        cout << T[i] << " ";
    cout << endl;
    
    cout << "Query:" << Query(T, 0, N-1, 0, 2, 5);
}
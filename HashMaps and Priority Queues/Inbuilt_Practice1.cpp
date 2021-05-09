// Given an array, return a vector containing unique elements from the array
#include<bits/stdc++.h>
using namespace std;

vector<int>* UniqueElements(int* A, int size){
    unordered_map<int, bool> present;
    vector<int>* v;
    for(int i = 0;i < size;i++){
        if(present.count(A[i]) > 0)
            continue;
        present[A[i]] = true;
        v->push_back(A[i]);      
    }
}

int main(){
    int N;
    cin>>N;
    int A[N];
    for(int i = 0;i < N; i++)
        cin>>A[i];
    vector<int>* v = UniqueElements(A, N);
    for(int i = 0;i < N; i++)
        cout<<v->at(i)<<" ";
}
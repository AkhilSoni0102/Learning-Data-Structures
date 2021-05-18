#include<bits/stdc++.h>
using namespace std;

bool HasPath(int** edges, int n, int s, int e, bool* visited){
    if(s == e)
        return true;
    visited[s] = true;
    for(int i = 0; i < n; i++){
        if(s == i)
            continue;
        if(edges[s][i] && !visited[i]){
            if(HasPath(edges,n, i, e, visited))
                return true;
        }
    }
    return false;
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    for(int i = 0;i < e;i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i = 0;i < n; i++)
        visited[i] = false;
    cout<<HasPath(edges, n, 0, 6, visited);
    
}
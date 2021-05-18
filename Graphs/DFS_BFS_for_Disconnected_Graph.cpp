#include<bits/stdc++.h>
using namespace std;

void DFS_Print(int** edges, int n, int sv, bool* visited){
    cout<<sv<<endl;
    visited[sv] = true;
    for(int i = 0;i < n; i++){
        if(sv == i)
            continue;
        if(edges[sv][i] == 1 && !visited[i]){
            DFS_Print(edges,n,i,visited);
        }
    }
}

void BFS_Print(int** edges, int n, int sv, bool* visited){
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    visited[sv] = true;
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front<<endl;
        for(int i = 0;i < n ;i++){
            if(front == i)
                continue;
            if(edges[front][i] && !visited[i]){
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int** edges, int n){
    bool* visited = new bool[n];
    for(int i = 0;i < n; i++)
        visited[i] = false;
    for(int i = 0;i < n; i++){
        if(!visited[i])
            DFS_Print(edges, n, i, visited);
    }
    delete [] visited;
}

void BFS(int** edges, int n){
    bool* visited = new bool[n];
    for(int i = 0;i < n; i++)
        visited[i] = false;
    for(int i = 0;i < n; i++){
        if(!visited[i])
            BFS_Print(edges, n, i, visited);
    }
    delete [] visited;
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
    cout<<"DFS: "<<endl;
    DFS(edges, n);
    cout<<"BFS: "<<endl;
    BFS(edges, n);
}
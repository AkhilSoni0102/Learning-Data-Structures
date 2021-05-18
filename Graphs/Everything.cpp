#include<bits/stdc++.h>
using namespace std;

void DFS_Print(int** edges, int n, int sv, bool* visited){
    cout<<sv<<endl;
    visited[sv] = true;
    for(int i = 0; i < n; i++){
        if(sv == i)
            continue;
        if(edges[sv][i] && !visited[i])
            DFS_Print(edges, n, i, visited);
    }
}
void BFS_Print(int** edges, int n, int sv, bool* visited){
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front<<endl;
        visited[front] = true;
        for(int i = 0;i < n;i++){
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
    for(int i = 0;i < n;i++)
        visited[i] = false;
    for(int i = 0;i < n;i++)
        if(!visited[i])
            DFS_Print(edges, n, i, visited);
}
void BFS(int** edges, int n){
    bool* visited = new bool[n];
    for(int i = 0;i < n;i++)
        visited[i] = false;
    for(int i = 0;i < n;i++)
        if(!visited[i])
            BFS_Print(edges, n, i, visited);
}

bool hasPath(int** edges, int n, int s, int e, bool* visited){
    if(s == e)
        return true;
    visited[s] = true;
    for(int i = 0; i < n;i++){
        if(s == i)
            continue;
        if(edges[s][i] && !visited[i]){
            if(hasPath(edges, n, i, e, visited))
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
    for(int i = 0;i < n;i++){
        edges[i] = new int[n];
        for(int j = 0;j < n;j++)
            edges[i][j] = 0;
    }
    for(int i = 0;i < e;i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i = 0;i < n;i++)
        visited[i] = false;
    cout<<"BFS_Print: "<<endl;
    BFS_Print(edges, n, 0, visited);

    for(int i = 0;i < n;i++)
        visited[i] = false;
    
    cout<<"DFS_Print: "<<endl;
    DFS_Print(edges, n, 0, visited);

    cout<<"DFS: "<<endl;
    DFS(edges, n);

    cout<<"BFS: "<<endl;
    BFS(edges, n);
    for(int i = 0;i < n;i++)
        visited[i] = false;
    cout<<"HasPath: "<<hasPath(edges, n, 0, 6, visited);

}
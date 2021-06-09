#include<bits/stdc++.h>
using namespace std;

void BFS_Print(int** edges, int n, int s){
    bool* visited = new bool[n];
    for(int i = 0; i < n;i++)
        visited[i] = false;
    queue<int> pendingNodes;
    pendingNodes.push(s);
    visited[s] = true;
    while(pendingNodes.size() != 0){
        int front = pendingNodes.front();
        pendingNodes.pop();
        cout << front << " "; 
        for(int i = 0; i < n;i++){
            if(edges[front][i] && !visited[i]){
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }    
    delete [] visited;
}

void DFS_Print(int** edges, int n, int s, bool* visited){
    visited[s] = true;
    cout << s << " ";
    for(int i = 0;i < n;i++)
        if(edges[s][i] && !visited[i])
            DFS_Print(edges, n, i, visited);
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
    for(int i = 0; i < e;i++){
        int f;
        int s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i = 0;i < n;i++)
        visited[i] = false;
    cout << "DFS Print: " << endl;
    DFS_Print(edges, n, 0, visited);
    cout << endl;
    cout << "BFS Print: " << endl;
    BFS_Print(edges, n, 0); 
}

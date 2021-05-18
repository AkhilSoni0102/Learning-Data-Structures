#include<bits/stdc++.h>
using namespace std;

void BFS(int** edges, int n, int sv){
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    visited[sv] = true;
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front<<endl;
        for(int i = 0;i < n; i++){
            if(front == i)
                continue;
            if(edges[front][i] == 1 && !visited[i]){
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
    delete [] visited;
}


void BFS_Print(int** edges, int n, int sv, bool* visited){
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    cout<<sv<<endl;
    visited[sv] = 1;
    while(pendingNodes.size() != 0){
        int front = pendingNodes.front();
        pendingNodes.pop();
        for(int i = 0; i < n; i++){
            if(front == i)
                continue;
            if(edges[front][i] == 1){
                if(!visited[i]){
                    cout<<i<<endl;
                    visited[i] = 1;
                    pendingNodes.push(i);
                }
            }
        }
}
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i = 0;i < n; i++){
        edges[i] = new int[n];
        for(int j = 0;j < n; j++)
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
        visited[i] = 0;

    BFS(edges, n, 0);


    cout<<"My way: "<<endl;
    BFS_Print(edges, n, 0, visited);
    
    
    delete [] visited;
    for(int i = 0;i < n; i++)
        delete [] edges[i];
    delete [] edges;
}
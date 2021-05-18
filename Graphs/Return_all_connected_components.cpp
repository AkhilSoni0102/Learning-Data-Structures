#include<bits/stdc++.h>
using namespace std;

vector<int>* BFS_return(int** edges, int n, int s, bool* visited){
    visited[s] = true;
    queue<int> pendingNodes;
    pendingNodes.push(s);
    vector<int>* v = new vector<int>();
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        v->push_back(front);
        for(int i = 0;i < n; i++){
            if(i == front)
                continue;
            if(edges[front][i] && !visited[i]){
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
    return v;
}

vector<vector<int>*>* return_all_connected_components(int** edges, int n){
    bool* visited = new bool[n];
    for(int i = 0;i < n;i++)
        visited[i] = false;
    vector<vector<int>* >* v = new vector<vector<int>*>();
    for(int i = 0;i < n; i++){
        if(!visited[i])
            v->push_back(BFS_return(edges, n, i, visited));
    }
    return v;
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i = 0;i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n;j++)   
            edges[i][j] = 0;
    }
    for(int i = 0;i < e;i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    vector<vector<int>*>* v = new vector<vector<int>*>();
    v = return_all_connected_components(edges, n);
    for(int i = 0;i < v->size();i++){
        for(int j = 0;j < v->at(i)->size();j++)
            cout<<v->at(i)->at(j)<<" ";
        cout<<endl;
    }
}
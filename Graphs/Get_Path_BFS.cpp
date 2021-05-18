#include<bits/stdc++.h>
using namespace std;

vector<int>* getPath(int** edges, int n, int s, int e, bool* visited){
    queue<int> pendingNodes;
    pendingNodes.push(s);
    visited[s] = true;
    unordered_map<int, int> umap;
    umap[s] = -1;
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        for(int i = 0;i < n;i++){
            if(front == i) 
                continue;
            if(edges[front][i] && !visited[i]){
                umap[i] = front;
                if(i == e){
                    vector<int>* v = new vector<int>();
                    int t = i;
                    while(t != s){
                        v->push_back(t);
                        t = umap[t];
                    }
                    v->push_back(s);
                    return v;
                }
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
    return NULL;
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i = 0; i < n;i++){
        edges[i] = new int[n];
        for(int j = 0;j < n;j++)
            edges[i][j] = 0;
    }
    for(int i = 0; i < e;i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i = 0;i < n;i++)
        visited[i] = false;
    vector<int>* v = new vector<int>();
    v = getPath(edges, n, 0, 6, visited);
    for(int i = 0; i < v->size();i++)
        cout<<v->at(i)<<" ";
}
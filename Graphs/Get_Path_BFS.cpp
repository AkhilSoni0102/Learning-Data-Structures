// Using Adjacency Matrix: 
#include<bits/stdc++.h>
using namespace std;

vector<int>* GetPathBFS(int** edges, int n, int s, int e, bool* visited){
    queue<int> pendingNodes;
    pendingNodes.push(s);
    unordered_map<int, int> parent;
    parent[s] = -1;
    while(pendingNodes.size() != 0){
        int front = pendingNodes.front();
        pendingNodes.pop();
        visited[front] = true;
        for(int i = 0;i < n;i++){
            if(front == i)
                continue;
            if(edges[front][i] && !visited[i]){
                parent[i] = front;
                visited[i] = true;
                pendingNodes.push(i);
                if(i == e){
                    vector<int>* v = new vector<int>();
                    int t = i;
                    while(t != -1){
                        v -> push_back(t);
                        t = parent[t];
                    }
                    return v;
                }
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
    for(int i = 0;i < n;i++){
        edges[i] = new int[n];
        for(int j = 0;j < n;j++)
            edges[i][j] = 0;
    }
    for(int i = 0;i < e;i++){
        int f;
        int s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    vector<int>* v = new vector<int>();
    bool* visited = new bool[n];
    for(int i = 0;i < n;i++)
        visited[i] = false;
    v = GetPathBFS(edges, n, 0, 6, visited);
    if(v != NULL)
        for(int i = 0;i < v -> size();i++)
            cout << v -> at(i) << " ";
    else   
        cout << "No Path Found! "<<endl;
}
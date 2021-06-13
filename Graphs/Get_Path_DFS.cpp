#include<bits/stdc++.h>
using namespace std;

vector<int>* GetPathDFS(int** edges, int n, int s, int e, bool* visited){
    if(s == e){
        vector<int>* v = new vector<int>();
        v->push_back(s);
        return v;
    }
    visited[s] = true;
    for(int i = 0;i < n;i++){
        if(s == i)
            continue;
        if(edges[s][i] && !visited[i]){
            vector<int>* v = new vector<int>();
            v = GetPathDFS(edges, n, i, e, visited);
            if(v != NULL){
                v -> push_back(s);
                return v;
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
    for(int i = 0; i < e;i++){
        int f;
        int s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    vector<int>* v = new vector<int>();
    bool* visited = new bool[n];
    for(int  i = 0;i < n;i++)
        visited[i] = false;
    v = GetPathDFS(edges, n, 0, 6, visited);
    for(int i = 0;i < v -> size();i++){
        cout << v -> at(i) << " " ;
    }
}



/*#include<bits/stdc++.h>
using namespace std;

vector<int>* getPath(int** edges, int n, int s, int e, bool* visited){
    if(s == e){
        vector<int>* v = new vector<int>();
        v->push_back(e);
        return v;
    }
    visited[s] = true;
    for(int i = 0;i < n;i++){
        if(s == i)
            continue;
        if(edges[s][i] && !visited[i]){
            vector<int>* v = new vector<int>();
            v = getPath(edges, n, i, e, visited);
            if(v != NULL){
                v->push_back(s);
                return v;
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
    for(int i = 0; i < n; i++)
        visited[i] = false;
    vector<int>* v = new vector<int>();
    v = getPath(edges, n, 0, 6, visited);
    for(int i = 0; i < v->size();i++){
        cout<<v->at(i)<<" ";
    }
}*/
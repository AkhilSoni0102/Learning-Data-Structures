#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** vertices = new int*[n];
    for(int i = 0;i < n;i++){
        vertices[i] = new int[n];
        for(int j = 0;j < n;j++){
            vertices[i][j] = 0;
        }
    }
    bool* visited = new bool[n];
    for(int i = 0;i < n;i++)
        visited[i] = false;
    for(int i = 0;o < e;i++)
    {
        int f, s;
        cin>>f>>s;
\      visited[f][s] = 1;
 \       visited[s][f] = 1;
\   }
\
\   cout<<"DFS Print: "<<endl;
\
}





/*#include<bits/stdc++.h>
using namespace std;

void DFS_Print(int** edges, int n, int s, bool* visited){
    cout<<s<<endl;
    visited[s] = true;
    for(int i = 0; i < n;i++){
        if(s == i)
            continue;
        if(edges[s][i] && !visited[i])
            DFS_Print(edges, n, i, visited);
    }
}

void BFS_Print(int** edges, int n, int s, bool* visited){
    visited[s] = true;
    queue<int> pendingNodes;
    pendingNodes.push(s);
    while(pendingNodes.size() != 0){
        int front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front<<endl;
        for(int i = 0;i < n;i++)
            if(edges[front][i] && !visited[i]){
                pendingNodes.push(i);
                visited[i] = true;
            }
    }
}

void DFS(int** edges, int n){
    bool* visited = new  bool[n];
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
    for(int i = 0;i < n;i++){
        if(edges[s][i] && !visited[i]){
            if(hasPath(edges, n, i, e, visited))
                return true;
        }
    }
    return false;
}

vector<int>* getPath_DFS(int** edges, int n, int s, int e, bool* visited){
    if(s == e){
        vector<int>* v = new vector<int>();
        v->push_back(e);
        return v;
    }
    visited[s] = true;
    for(int i = 0; i < n;i++){
        if(s == i)
            continue;
        if(edges[s][i] && !visited[i]){
            vector<int>* v = new vector<int>();
            v = getPath_DFS(edges, n, i, e, visited);
            if(v != NULL){
                v -> push_back(s);
                return v;
            }
        }
    }
    return NULL;
}

bool IsConnected(int** edges, int n, int s, int e){
    bool* visited = new bool[n];
    for(int i = 0;i < n;i++)
        visited[i] = false;
    DFS_Print(edges, n, 0, visited);
    for(int i = 0;i < n;i++)
        if(!visited[i])
            return false;
    return true;
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i = 0;i < n; i++){
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
    
    cout<<"DFS_Print: "<<endl;
    DFS_Print(edges, n, 0, visited);

    for(int i = 0;i < n;i++)
        visited[i] = false;

    cout<<"BFS_Print: "<<endl;
    BFS_Print(edges, n, 0, visited);
    
    cout<<"DFS: "<<endl;
    DFS(edges, n);

    cout<<"BFS: "<<endl;
    BFS(edges, n);

    for(int i = 0;i < n;i++)
        visited[i] = false;

    cout<<"hasPath from 0 to 6? "<<endl;
    cout<<hasPath(edges, n, 0, 6, visited)<<endl;

    vector<int>* v = new vector<int>();
    cout<<"GetPath_DFS: "<<endl;
    v = getPath_DFS(edges, n, 0, 6, visited);

    for(int i = 0;i < v->size();i++)
        cout<<v->at(i)<<" "; 
    cout<<endl;
    
    cout<<"isConnected 0, 6: "<<endl;
    cout<<IsConnected(edges, n, 0, 6)<<endl;
    

}

/*#include<bits/stdc++.h>
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
*/
#include<bits/stdc++.h>
using namespace std;

//Kruskal's Algorithm:
bool compare(int a[], int b[]){
    return a[2] < b[2];
}
int getParent(int v, int* parents){
    if(v == parents[v])
        return v;
    return getParent(parents[v],parents);
}
void Kruskals(int** edges, int n, int e){
    sort(edges, edges + e, compare);
    int* parents = new int[n];
    for(int i = 0;i < n;i++)
        parents[i] = i;
    int** ans = new int*[n-1];
    for(int i = 0;i < n-1;i++)
        ans[i] = new int[3];
    int count = 0;
    for(int i = 0;i < e;i++){
        int s = getParent(edges[i][0], parents);
        int e = getParent(edges[i][1], parents);
        if(s == e)
            continue;
        ans[count][0] = edges[i][0];
        ans[count][1] = edges[i][1];
        ans[count][2] = edges[i][2];
        count++;
        parents[s] = e; 
    }
    for(int i = 0;i < n-1;i++){
        if(ans[i][0] > ans[i][1])
            cout<<ans[i][1]<<" "<<ans[i][0]<<" "<<ans[i][2]<<endl;
        else
            cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }
}

//Prim's Algorithm:
void Prims(int** edges, int n){
    bool* visited = new bool[n];
    int* weights = new int[n];
    int* parents = new int[n];
    for(int i = 0;i < n;i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    weights[0] = 0;
    for(int j = 0;j < n;j++){
        int I = -1;
        for(int i = 0;i < n;i++)
            if((weights[i] < weights[I] || I == -1) && !visited[i])
                I = i;
        visited[I] = true;
        for(int i = 0;i < n;i++){
            if(!visited[i] && edges[I][i]){
                if(weights[i] > edges[I][i]){
                    weights[i] = edges[I][i];
                    parents[i] = I;
                }
            }
        }
    }
    for(int i = 1; i < n; i++){
        if(parents[i] < i)
            cout<< parents[i] << " " << i << " " << weights[i] << endl;
        else 
            cout<< i << " " << parents[i] << " " << weights[i] << endl;


    }
}

//Dijkstra Algorithm:
void Dijkstra(int** edges, int n, int s){
    bool* visited = new bool[n];
    int* dist = new int[n];
    for(int i = 0;i < n;i++){
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for(int j = 0; j < n; j++){
        int I = -1;
        for(int i = 0;i < n; i++){
            if(!visited[i] && (dist[i] < dist[I] || I == -1))
                I = i;
        }
        visited[I] = true;
        for(int i = 0;i < n;i++){
            if(edges[I][i] && !visited[i]){
                if(dist[i] > dist[I] + edges[I][i])
                    dist[i] = dist[I] + edges[I][i];
            }
        }
    }
    for(int i = 1;i < n;i++)
        cout<< 0 << " " << i << " " << dist[i] << endl;
}

//Optimized Prim's Algorithm: 
class PriorityQueue{
    public:
    vector<pair<int,int>> pq;

    bool Is_Empty(){
        return pq.size() == 0;
    }

    pair<int,int> Top(){
        if(!Is_Empty())
            return pq[0];
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    void Push(pair<int,int> p){
        pq.push_back(p);
        int CI = pq.size() - 1;
        while(CI > 0){
            int PI = (CI - 1)/2;
            if(pq[CI].second < pq[PI].second)
                swap(pq[CI], pq[PI]);
            else 
                break;
            CI = PI;
        }
    }

    void Pop(){
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int PI = 0;
        int LCI = 1;
        int RCI = 1;
        int MI = 0;
        while(LCI < pq.size() - 1){
            if(pq[LCI].second < pq[MI].second)
                MI = LCI;
            if(pq[RCI].second < pq[MI].second && RCI < pq.size() - 1)
                MI = RCI;
            if(MI == PI)
                break;
            swap(pq[MI], pq[PI]);
            PI = MI;
            LCI = 2 * PI + 1;
            RCI = 2 * PI + 2;
            MI = PI;
        }
    }

};

int main(){
    int n;
    int e;
    cin>>n>>e;
    unordered_map<int, vector<pair<int, int>>> edges;
    for(int i = 0;i < e;i++){
        int s;
        int e;
        int w;
        cin>>s>>e>>w;
        pair<int, int> p;
        p.first = e;
        p.second = w;
        if(edges.find(s) == edges.end()){
            vector<pair<int, int>> v;
            v.push_back(p);
            edges[s] = v;
        }
        else 
            edges[s].push_back(p);
    }
    bool* visited = new bool[n];
    int* parents = new int[n];
    int* weights = new int[n];
    for(int i = 0;i < n;i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    weights[0] = 0;
    PriorityQueue pq;
    pair<int,int> p;
    p.first = 0;
    p.second = 0;
    pq.Push(p);
    for(int i = 0;i < n;i++){
        pair<int,int> p = pq.Top();
        int I = p.first;
        visited[I] = true;
        pq.Pop();
        for(int i = 0;i < edges[I].size();i++){
            if(!visited[edges[I][i].first]){
                if(weights[edges[I][i].first] > edges[I][i].second)
                    weights[edges[I][i].first] = edges[I][i].second;
                    pq.Push(edges[I][i]);
                    parents[edges[I][i].first] = I;
            }
        }
    }
    cout<<"Prim's Algorithm: "<< endl;
    for(int i = 1;i < n;i++){
        if(parents[i] < i)
            cout << parents[i] << " " << i << " " << weights[i] << endl;
        else 
            cout << i << " " << parents[i] << " " << weights[i] << endl;
    }
    

}


/*
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
        int w;
        cin>>f>>s>>w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    cout<<"Prim's Algorithm: "<<endl;
    Prims(edges, n);

    cout<<"Dijkstra Algorithm: "<<endl;
    Dijkstra(edges, n, 0);
}*/
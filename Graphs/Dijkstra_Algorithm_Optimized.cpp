#include<bits/stdc++.h>
using namespace std;

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
    int* dist = new int[n];
    for(int i = 0;i < n;i++){
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
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
                if(dist[edges[I][i].first] > dist[I] + edges[I][i].second)
                    dist[edges[I][i].first] = dist[I] + edges[I][i].second;
                    pq.Push(edges[I][i]);
                    parents[edges[I][i].first] = I;
            }
        }
    }
    cout<<"Dijkstra's Algorithm: "<< endl;
    for(int i = 1;i < n;i++){
        if(parents[i] < i)
            cout << parents[i] << " " << i << " " << dist[i] << endl;
        else 
            cout << i << " " << parents[i] << " " << dist[i] << endl;
    }
    

}
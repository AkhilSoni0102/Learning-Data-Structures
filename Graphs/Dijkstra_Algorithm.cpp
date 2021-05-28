#include<bits/stdc++.h>
using namespace std;

void Dijkstra(int** edges, int n, int s){
    bool* visited = new bool[n];
    int* dist = new int[n];
    for(int i = 0; i < n;i++){
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    for(int j = 0;j < n;j++){
        int I = -1;
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                if(dist[i] < dist[I] || I == -1)
                    I = i;
            }
        }
        visited[I] = true;
        for(int i = 0;i < n;i++){
            if(edges[I][i] && !visited[i]){
                if(edges[I][i] + dist[I] < dist[i]){
                    dist[i] = edges[I][i] + dist[I];
                }
            }
        }
    }
    for(int i = 0;i < n;i++){
        cout<<dist[i]<<" ";
    }
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
        int w;
        cin>>f>>s>>w;
        edges[f][s] = w;
        edges[s][f] = w;
    }

    Dijkstra(edges, n, 0);
}
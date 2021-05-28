#include<bits/stdc++.h>
using namespace std;

void Prims(int** edges, int n){
    bool* visited = new bool[n];
    int* parents = new int[n];
    int* weight = new int[n];

    for(int i = 0;i < n;i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    parents[0] = -1;


    int count = 0;
    while(count != n-1){
        int MinW = INT_MAX;
        int I = 0;
        for(int i = 0;i < n;i++){
            if(MinW > weight[i] && !visited[i]){
                MinW = weight[i];
                I = i;
            }
        }
        visited[I] = true;
        for(int i = 0;i < n;i++){
            if(I == i)
                continue;
            if(edges[I][i] && !visited[i]){
                if(edges[I][i] && !visited[i]){
                    if(weight[i] > edges[I][i]){
                        weight[i] = edges[I][i];
                        parents[i] = I;
                    }
                }
            }
        }
        count++;
    }
    for(int i = 0;i < n;i++)
        cout<<weight[i]<<" ";

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
        int s;
        int e;
        int w;
        cin>>s>>e>>w;
        edges[s][e] = w;
        edges[e][s] = w;
    }
    Prims(edges,n);
    for(int i = 0;i<n;i++)
        delete [] edges[i];
    delete [] edges;
}
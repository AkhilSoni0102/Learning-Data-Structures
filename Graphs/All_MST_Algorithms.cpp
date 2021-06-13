#include<bits/stdc++.h>
using namespace std;

bool compare(int a[], int b[]){
    return a[2] < b[2];
}
void Kruskal(int** edges, int n, int e){
    sort(edges, edges + e, compare);
    int* parents = new int[n];
    for(int i = 0;i < n;i++)
        parents[i] = i;
    vector<vector<int>> v(n-1,{0,0,0});
    int m = 0;
    for(int i = 0;i < e;i++){
        int a = edges[i][0];
        int b = edges[i][1];
        while(a != parents[a])
            a = parents[a];
        while(b != parents[b])
            b = parents[b];
        if(a == b)
            continue;
        parents[b] = a;
        v[m][0] = edges[i][0];
        v[m][1] = edges[i][1];
        v[m][2] = edges[i][2];
        m++;
        if(m == n-1)
            break;
    }
    cout << "Ans: "<<endl;
    for(int i = 0;i < v.size();i++){
        cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
    }

}

void Prims(int** edges, int n, int e){
    int* parents = new int[n];
    int* weights = new int[n];
    bool* visited = new bool[n];
    for(int i = 0;i < n;i++){
        visited[i] = false;
        weights[i] =  INT_MAX;
    }
    weights[0] = 0;
    parents[0] = -1;

    for(int i = 0;i < n-1;i++){
        int I = -1;
        for(int i = 0;i < n;i++)
            if(!visited[i] && (weights[i] < weights[I] || I == -1))
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
    for(int i = 0; i < n;i++){
        cout << i << " " << parents[i] << " " << weights[i] << endl;
    }
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[e];
    for(int i = 0;i < e;i++)
        edges[i] = new int[3];
    for(int i = 0; i < e;i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    cout << "Kruskal's Algorithm: " << endl;
    Kruskal(edges, n, e);

    edges = new int*[n];
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
    cout << "Prim's Normal: " << endl;
    Prims(edges, n, e);
}
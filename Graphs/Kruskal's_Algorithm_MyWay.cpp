#include<bits/stdc++.h>
using namespace std;

void Kruskal(int** edges, int n, int e){
    int* parents = new int[n];
    for(int i = 0;i < n;i++)
        parents[i] = i;
    
    int** output = new int*[n-1];
    for(int i = 0;i < n-1;i++)
        output[i] = new int[3];
    int count = 0;
    for(int i = 0;i < e;i++){
        int s = edges[i][0];
        int e = edges[i][1];
        while(parents[s] != s)
            s = parents[s];
        while(parents[e] != e)
            e = parents[e];
        if(s == e)
            continue;
        output[count][0] = edges[i][0];
        output[count][1] = edges[i][1];
        output[count][2] = edges[i][2];
        count++;
        parents[s] = e;
        if(count == n-1)
            break;
    }
    for(int i = 0;i < n-1;i++)
        cout<<output[i][0]<<" "<<output[i][1]<<" "<<output[i][2]<<endl;
}



bool compare(int a[], int b[]){
    return a[2] < b[2];
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[e];
    for(int i = 0; i < e;i++){
        edges[i] = new int[3];
        for(int j = 0;j < 3;j++)
            cin>>edges[i][j];
    }
    sort(edges,edges + e, compare);
    cout<<"Kruskal's Algorithm: "<<endl;
    Kruskal(edges, n, e);
}




/*#include<bits/stdc++.h>
using namespace std;

bool compare(int a[], int b[]){
    return a[2] <= b[2];
}

vector<vector<int>>* MST(int** edges, int n,int e){
    sort(edges,edges+e,compare);
    int* parents = new int[n];
    for(int i = 0;i < n;i++)
        parents[i] = i;
    vector<vector<int>>* v = new vector<vector<int>>();
    vector<int> V;
    int count = 0;
    for(int i = 0;i < e;i++){
        int s = edges[i][0];
        int e = edges[i][1];
        int w = edges[i][2];
        while(s != parents[s])
            s = parents[s];
        while(e != parents[e])
            e = parents[e];
        if(s == e){
            continue;
        }
        V.push_back(edges[i][0]);
        V.push_back(edges[i][1]);
        V.push_back(edges[i][2]);
        parents[s] = e;
        count++;
        v->push_back(V);
        V.clear();
        if(count == n-1)
            break;
    }
    return v;
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[e];
    for(int i = 0;i < e;i++){
        edges[i] = new int[3];
        for(int j = 0;j < 3;j++)
            cin>>edges[i][j];
    }
    vector<vector<int>>* v = new vector<vector<int>>();
    v = MST(edges, n, e);
    cout<<"Final MST: "<<endl;
    for(int i = 0;i < v->size();i++)
        cout<<v->at(i)[0]<<" "<<v->at(i)[1]<<" "<<v->at(i)[2]<<endl; 

}*/
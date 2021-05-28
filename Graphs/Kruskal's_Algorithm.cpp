#include<bits/stdc++.h>
using namespace std;

class edges{
    public:
    int source;
    int dest;
    int weight;
};

bool compare(edges a, edges b){
    return a.weight < b.weight;
}

int findParent(int v, int* parents){
    if(v == parents[v])
        return v;
    return findParent(parents[v], parents);
}

void Kruskal(edges* input, int n, int e){
    int* parents = new int[n];
    for(int i = 0;i < n;i++)
        parents[i] = i;
    edges* output = new edges[n-1];
    sort(input, input + e, compare);
    int count = 0;
    int i = 0;
    while(count != n-1){
        edges currEdge = input[i];
        int sourceParent = findParent(input[i].source, parents);
        int destParent = findParent(input[i].dest, parents);
        if(sourceParent != destParent){
            output[count] = currEdge;
            count++;
            parents[sourceParent] = parents[destParent];
        }
        i++;
    }

    for(int i = 0;i < n-1;i++)
        if(output[i].source < output[i].dest)
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        else   
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
}

int main(){
    int n;
    int e;
    cin>>n>>e;
    edges* input = new edges[n];
    for(int i = 0;i < e;i++){
        cin>>input[i].source>>input[i].dest>>input[i].weight;
    }
    Kruskal(input, n, e);
}
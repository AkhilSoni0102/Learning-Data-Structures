#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr, int* tree, int s, int e, int treeNode){
    if(s == e){
        tree[treeNode] = arr[s];
        return ;
    }
    int mid = (s + e) / 2;
    buildTree(arr, tree, s, mid, 2*treeNode + 1 ) ;
    buildTree(arr, tree, mid + 1, e, 2*treeNode + 2);
    tree[treeNode] = tree[2*treeNode + 1 ]  + tree[2*treeNode + 2];
}
void updateTree(int* arr, int* tree, int start, int end, int treeNode, int idx, int value){
    if(start == end){
        arr[idx] = value;
        tree[treeNode] = value;
        return ;
    }
    int mid = (start + end) / 2;
    if(idx > mid)
        updateTree(arr, tree, mid+1, end, 2*treeNode + 2, idx, value);
    else 
        updateTree(arr, tree, start, mid, 2*treeNode + 1 ,  idx, value);
    tree[treeNode] = tree[2*treeNode + 1]  + tree[2*treeNode + 2];
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int * tree = new int[10];
    buildTree(arr, tree, 0, 4, 0);
    
    updateTree(arr, tree, 0, 4, 0, 2, 10);
    for(int i = 0;i < 10;i++)
        cout << tree[i] << " ";
}
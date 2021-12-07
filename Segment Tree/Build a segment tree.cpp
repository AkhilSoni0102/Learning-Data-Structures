#include<bits/stdc++.h>
using namespace std;
void buildTree(int* arr, int* tree, int s, int e, int treeNode){
    if(s == e){
        tree[treeNode] = arr[s];
        return ;
    }
    int mid = (s + e) / 2;
    buildTree(arr, tree, s, mid, 2*treeNode);
    buildTree(arr, tree, mid + 1, e, 2*treeNode+1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode + 1];
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int * tree = new int[18];
    buildTree(arr, tree, 0, 8, 1);
    for(int i = 1;i < 18;i++)
        cout << tree[i] << " ";
}
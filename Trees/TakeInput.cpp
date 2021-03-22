/*Tree having only one root node and two child node. */
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public: 
    T Data;
    vector<TreeNode<T>*> Children;

    TreeNode(T Data){
        this->Data = Data;
    }
};

TreeNode<int>* TakeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int N;
    cout<<"Enter the number of childeren of: "<<rootData<<endl;
    cin>>N;
    for(int i = 0; i<N;i++){
        TreeNode<int> *child = TakeInput();
        root->Children.push_back(child);
    }
    return root;
}

int main()
{
    
}
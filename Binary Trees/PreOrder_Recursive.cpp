#include<bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{
    public:
        int Data;
        vector<TreeNode<T>*> children;

        TreeNode(int Data){
            this -> Data = Data;
        }
        ~TreeNode(){
            for(int i = 0;i < children.size();i++)
                delete children;
            delete this;
        }
};
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter rootData: " << endl;
    cin >> rootData;
    if(rootData == -1)
        return NULL;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter the Number of Children of: " << front -> Data << endl;
        cin >> numChild;
        for(int i = 0;i < numChild;i++){
            cout << "Enter the " << i + 1 << "Child of: " << front -> Data << ": ";
            int ChildData;
            cin >> ChildData;
            if(ChildData != -1){
                TreeNode<int>* ChildNode = new TreeNode<int>(ChildData);
                front -> children.push_back(ChildNode);
                pendingNodes.push(ChildNode);
            }   
        }
    }
    return root;
}
void PrintLevelWise(TreeNode<int>* root){
    if(root == NULL)
        return ;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> Data << ": ";
        for(int i = 0;i < front -> children.size();i++){
            cout << front -> children[i] -> Data << " ";
            pendingNodes.push(front -> children[i]);
        }
        cout << endl;
    }
}
void PreOrderPrint(TreeNode<int>* root){
    if(root == NULL)
        return ;
    cout << root -> Data << " ";
    for(int i = 0;i < root -> children.size();i++)
        PreOrderPrint(root -> children[i]);
}
void PostOrderPrint(TreeNode<int>* root){
    if(root == NULL)
        return ;
    for(int i = 0;i < root -> children.size();i++)
        PostOrderPrint(root -> children[i]);
    cout << root -> Data << " " ;
}
int main(){
    TreeNode<int>* root = takeInputLevelWise();
    cout << "PreOrder: " << endl;
    PreOrderPrint(root);
    cout << "PostOrder:  " << endl;
    PostOrderPrint(root);
}
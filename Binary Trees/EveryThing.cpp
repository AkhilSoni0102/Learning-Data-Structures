#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    int Data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(int Data){
        this -> Data = Data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
        delete this;
    }
};
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter rootData: " << endl;
    cin >> rootData;
    if(rootData == -1)  
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the left child of " << front -> Data << ": ";
        int ChildData;
        cin >> ChildData;
        if(ChildData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(ChildData);
            front -> left = leftChild;
            pendingNodes.push(leftChild);
        }
        cout << endl;
        cout << "Enter the right Child of " << front -> Data << ": ";
        cin >> ChildData;
        if(ChildData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(ChildData);
            front -> right = rightChild;
            pendingNodes.push(rightChild);
        }
        cout << endl;
    }
    return root;
}
void PrintLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> Data << ": ";
        if(front -> left != NULL){
            cout << "L" << front -> left -> Data << " ";
            pendingNodes.push(front -> left);
        }
        if(front -> right != NULL){
            cout << "R" << front -> right -> Data << " ";
            pendingNodes.push(front -> right);
        }
        cout << endl;
    }
}
int Height_of_Tree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    return 1 + max(Height_of_Tree(root -> left), Height_of_Tree(root -> right));
}
int CountNode(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    return 1 + CountNode(root -> left) + CountNode(root -> right);
}
void PreOrderPrint_Recursive(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    cout << root -> Data << " ";
    PreOrderPrint_Recursive(root -> left);
    PreOrderPrint_Recursive(root -> right);
}
void MirrorBinaryTree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    BinaryTreeNode<int>* Temp;
    Temp = root -> left;
    root -> left = root -> right;
    root -> right = Temp;
    MirrorBinaryTree(root -> left); 
    MirrorBinaryTree(root -> right);
}
void PreOrderPrint_Iterative(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    stack<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* top = pendingNodes.top();
        pendingNodes.pop();
        cout << top -> Data << " ";
        if(top -> right != NULL)
            pendingNodes.push(top -> right);
        if(top -> left != NULL)
            pendingNodes.push(top -> left);
    }
    cout << endl;
}
void PostOrderPrint_Recursive(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    PostOrderPrint_Recursive(root -> left);
    PostOrderPrint_Recursive(root -> right);
    cout << root -> Data << " ";
}
void PostOrderPrint_Iterative(BinaryTreeNode<int>* root){

}
void Inorder_Recursive(BinaryTreeNode<int>* root){
    if(root == NULL)
        return ;
    Inorder_Recursive(root -> left);
    cout << root -> Data << " ";
    Inorder_Recursive(root -> right);
}
void Inorder_Iterative(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    stack<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.top();
        pendingNodes.pop();
        if(front -> left == NULL && front -> right == NULL){
            cout << front -> Data << " " ;
            if(pendingNodes.size() != 0){
                cout << pendingNodes.top() -> Data << " " ;
                pendingNodes.pop();
            }
            continue;
        }
        if(front -> right != NULL)
            pendingNodes.push(front -> right);
        pendingNodes.push(front);
        if(front -> left != NULL)
            pendingNodes.push(front -> left);
    } 
    
}
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    PrintLevelWise(root);
    cout << endl;
    cout << "Height of Tree: " << Height_of_Tree(root) << endl;
    cout << "Total Number of Nodes: " << CountNode(root) << endl;
    cout << "PreOrder Print Recursive: " << endl;
    PreOrderPrint_Recursive(root);
    cout << endl;
    cout << "PreOrder Print Iterative: " << endl;
    PreOrderPrint_Iterative(root);
    cout << "PostOrder Print Recursive: " << endl;
    PostOrderPrint_Recursive(root);
    cout << endl;
    cout << "Inorder Print Recursive: " << endl;
    Inorder_Recursive(root);
    cout << endl;
    cout << "Inorder Print Iterative: " << endl;
    Inorder_Iterative(root);
    cout << endl;

    
}
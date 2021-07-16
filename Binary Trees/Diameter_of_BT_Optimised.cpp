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

pair<int, int> Diameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> L = Diameter(root -> left);
    pair<int, int> R = Diameter(root -> right);
    int LH = L.first;
    int RH = R.first;
    int LD = L.second;
    int RD = R.second;
    int Height = max(LH, RH) + 1;
    int Dia = max(LH + RH, max(RD, LD));
    pair<int, int> p;
    p.first = Height;
    p.second = Dia;
    return p;
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    pair<int, int> Dia = Diameter(root);
    cout << Dia.first << " " << Dia.second;
}
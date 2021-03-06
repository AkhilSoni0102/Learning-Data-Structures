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
class Pair{
    public:
        int Min;
        int Max;
        int Height;
};
Pair Min_Max_Height(BinaryTreeNode<int>* root){
    if(root == NULL){
        Pair p;
        p.Min = INT_MAX;
        p.Max = INT_MIN;
        p.Height = 0;
        return p;
    }
    Pair L = Min_Max_Height(root -> left);
    Pair R = Min_Max_Height(root -> right);
    int LMin = L.Min;
    int RMin = R.Min;
    int LH = L.Height;
    int RH = R.Height;
    int LMax = L.Max;
    int RMax = R.Max;
    Pair p;
    p.Min = min(root -> Data, min(LMin, RMin));
    p.Max = max(root -> Data, max(RMax, LMax));
    p.Height = 1 + max(LH, RH);
    return p;
}
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    Pair P = Min_Max_Height(root);
    cout << "Min: " << P.Min << endl;
    cout << "Max: " << P.Max << endl;
    cout << "Height: " << P.Height;
}
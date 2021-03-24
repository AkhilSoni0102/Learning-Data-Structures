#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public: 
    T Data;
    vector<TreeNode<T>*> children;

    TreeNode(T Data){
        this -> Data = Data;
    }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter the root Data"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the Number of Children of: "<<front->Data<<endl;
        cin>>numChild;
        for(int i = 0;i < numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of: "<<front->Data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}


void PrintTreeLevelWise(TreeNode<int>* root){
    if(root == NULL)
        return;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->Data<<": ";
        for(int i = 0; i < front->children.size();i++){
            cout<<front->children[i]->Data<<" ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

int Sum_of_Nodes(TreeNode<int>* root){
    if(root == NULL)
        return 0;
    int ans = 0;
    ans += root->Data;
    for(int i = 0;i<root->children.size();i++){
        ans += Sum_of_Nodes(root->children[i]);
    }
    return ans;
}

int Count_of_Nodes(TreeNode<int>* root){
    if(root == NULL)
        return 0;
    int count = 1;
    for(int i = 0;i < root->children.size();i++){
        count += Count_of_Nodes(root->children[i]);
    }
    return count;
}

int Max_Data_Node(TreeNode<int>* root){
    if(root == NULL)
        return 0;
    int Max = root->Data;
    for(int i = 0;i < root->children.size();i++){
        Max = max(Max, Max_Data_Node(root->children[i]));
    }
    return Max;
}

int Find_Height(TreeNode<int>* root){
    if(root == NULL)
        return 0;
    int Height = 0;
    for(int i = 0;i < root->children.size();i++){
        Height = max(Height,Find_Height(root->children[i]));
    }
    return Height + 1;
}

int Count_Leaf_Nodes(TreeNode<int> * root){
    if(root == NULL)
        return 0;
    if(root->children.size() == 0)
        return 1;
    int count = 0;
    for(int i = 0;i<root->children.size();i++){
        count += Count_of_Nodes(root->children[i]);
    }
    return count;
}

void Print_At_Level_K(TreeNode<int>* root, int k){
    if(k == 0)
        cout<<root->Data<<" ";
    for(int i = 0;i < root->children.size();i++){
        Print_At_Level_K(root->children[i],k-1);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    PrintTreeLevelWise(root);
    cout<<endl;
    cout<<"The sum of Nodes: "<<Sum_of_Nodes(root)<<endl;
    cout<<"The Max Data: "<<Max_Data_Node(root)<<endl;
    cout<<"The Height of the Tree: "<<Find_Height(root)<<endl;
    cout<<"The total count of Nodes of the Tree: "<<Count_of_Nodes(root)<<endl;
    cout<<"The total count of Leaf Nodes of the Tree: "<<Count_Leaf_Nodes(root)<<endl;
    cout<<"All the Nodes at level 2 are: ";
    Print_At_Level_K(root,2);
}


/*#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public: 
    T Data;
    vector<TreeNode<T>*> children;

    TreeNode(T Data){
        this -> Data = Data;
    }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root Data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter the Number of Children of "<<front->Data<<endl;
        cin>>numChild;
        for(int i = 0;i < numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->Data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void PrintTreeLevelWise(TreeNode<int>* root){
    if(root == NULL)
        return;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->Data<<":";
        for(int i = 0;i < front->children.size();i++){
            cout<<front->children[i]->Data<<" ";
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

int Count_Nodes(TreeNode<int> *root){
    int ans = 1;
    for(int i = 0;i < root->children.size();i++){
        ans += Count_Nodes(root->children[i]);
    }
    return ans;
}

int Max_Data_Node(TreeNode<int>* root){
    int Max = root->Data;
    for(int i = 0;i < root->children.size();i++){
        Max = max(Max,Max_Data_Node(root->children[i]));
    }
    return Max;
}

int Sum_of_Nodes(TreeNode<int> * root){
    int sum = root->Data;
    for(int i = 0;i < root->children.size();i++){
        sum += Sum_of_Nodes(root->children[i]);
    }
    return sum;
}

int Find_Height(TreeNode<int> * root){
    if(root == NULL)
        return 0;
    int Height = 0;
    for(int i = 0;i < root->children.size();i++){
        Height = max(Height, Find_Height(root->children[i]));
    }
    return Height + 1;
}

int main(){
    TreeNode<int>*root = takeInputLevelWise();
    PrintTreeLevelWise(root);
    cout<<endl;
    cout<<"The Total Number of Node in the given tree are"<<Count_Nodes(root)<<endl;
    cout<<"The Max Data on the given Tree is: "<<Max_Data_Node(root)<<endl;
    cout<<"The sum of all the nodes in the given tree is: "<<Sum_of_Nodes(root)<<endl;
    cout<<"The Height of the Tree: "<<Find_Height(root)<<endl;
}
*/
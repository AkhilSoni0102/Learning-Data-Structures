#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
	public:
	T Data;
	BinaryTreeNode* right;
	BinaryTreeNode* left;
	
	BinaryTreeNode(T Data){
		this -> Data = Data;
		right = NULL;
		left = NULL;
	}
	
	~BinaryTreeNode(){
		delete left;
		delete right;
	}
};
class ThreePair{
	public:
	int Min;
	int Max;
	int Height;
	
	ThreePair(){
		Min = INT_MAX;
		Max = INT_MIN;
		Height = 0;
	}
};
	

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter the rootData: "<<endl;
	cin>>rootData;
	if(rootData == -1)
		return NULL;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int childData;
		cout<<"Enter the left Child of: "<<front->Data<<endl;
		cin>>childData;
		if(childData != -1){
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(childData);
			front->left = leftChild;
			pendingNodes.push(leftChild);
		}
		cout<<"Enter the right Child of: "<<front->Data<<endl;
		cin>>childData;
		if(childData != -1){
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(childData);
			front->right = rightChild;
			pendingNodes.push(rightChild);
		}
	}
	return root;
}

ThreePair Min_Max_Height(BinaryTreeNode<int>* root, int Node){
	if(root == NULL){
		ThreePair p;
		return p;
	}
	ThreePair leftAns = Min_Max_Height(root->left,Node);
	ThreePair rightAns = Min_Max_Height(root->right,Node);
	int l_Min = leftAns.Min;
	int l_Max = leftAns.Max;
	int l_Height = leftAns.Height;
	int r_Min = rightAns.Min;
	int r_Max = rightAns.Max;
	int r_Height = rightAns.Height;
	
	int Minimum = min(l_Min,min(r_Min,root->Data));
	int Maximum = max(l_Max,max(r_Max,root->Data));
	int Height = 1 + max(l_Height,r_Height);
	if(root->Data == Node){
		cout<<Minimum<<" "<<Maximum<<" "<<Height<<endl;
	}
	ThreePair p;
	p.Min = Minimum;
	p.Max = Maximum;
	p.Height = Height;
	return p;
}

int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	ThreePair p;
	p = Min_Max_Height(root,4);
	cout<<p.Min<<" "<<p.Max<<" "<<p.Height<<endl;
}

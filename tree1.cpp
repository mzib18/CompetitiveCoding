#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;
void printLevelWise(TreeNode<int>* root) {
    if(root==NULL)return;
   // cout<<root->data<<":";
    queue<TreeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty()){
        TreeNode<int>* front = pending.front();
        cout<<front->data<<":";
        pending.pop();int n=front->children.size();
        for(int i=0;i<n;i++){
            cout<<front->children[i]->data;
            if(i!=n-1)cout<<",";
            pending.push(front->children[i]);
        }
        cout<<endl;
    }
}
TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"enter root Data"<<endl;
	cin>>rootData;
	TreeNode<int>* root=new TreeNode<int>(rootData);
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter num of children of "<<front->data<<endl;
		int n;cin>>n;
		//cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
		for(int i=0;i<n;i++){
			cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
			int childData;
			cin>>childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}
TreeNode<int>* takeInput(){
	cout<<"Enter Data"<<endl;
	int rootData;cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	int n;
	cout<<"Enter num of children of "<<rootData<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		TreeNode<int>* child=takeInput();
		root->children.push_back(child);
	}
	return root;
}
void printTree(TreeNode<int>* root){
	if(root==NULL)return;
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
		cout<<root->children[i]->data<<",";
	cout<<endl;
	for (int i=0;i<root->children.size();i++)
		printTree(root->children[i]);
}
int numNodes(TreeNode<int>* root){
    if(root==NULL)return 0;
    int ans=1;
    for(int i=0;i<root->children.size();i++)ans+=numNodes(root->children[i]);
    return ans;
}
inline int getHeight(TreeNode<int>* root) {
    if(root==NULL)return 0;int maxSmall=0;
    for(int i=0;i<root->children.size();i++)maxSmall=max(getHeight(root->children[i]),maxSmall);
    return 1+maxSmall;
}
inline void printAtLevelK(TreeNode<int>* root,int k){
    if(root==NULL)return;
    if(k==0)cout<<root->data<<endl;
    for(int i=0;i<root->children.size();i++)printAtLevelK(root->children[i],k-1);
}
inline void preorder(TreeNode<int>* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)preorder(root->children[i]);
}
inline void printPostOrder(TreeNode<int> *root) {
  if (root == NULL)return;
  for(int i=0;i<root->children.size();i++)printPostOrder(root->children[i]);
  cout<<root->data<<" ";
}
int main(){
//	TreeNode<int>* root = new TreeNode<int>(1);
//	TreeNode<int>* node1 = new TreeNode<int>(2);
//	TreeNode<int>* node2 = new TreeNode<int>(3);
//	root->children.push_back(node1);
//	root->children.push_back(node2);
	TreeNode<int>* root= takeInputLevelWise();
	printLevelWise(root);
	//preorder(root);cout<<endl;
	//printPostOrder(root);cout<<endl;
	cout<<"Height Of Tree :"<<getHeight(root)<<endl;
	//printAtLevelK(root,3);
	//cout<<numNodes(root)<<endl;
	//to do delete the tree
	if(root!=NULL) delete root;
}

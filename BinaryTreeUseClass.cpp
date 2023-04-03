#include<iostream>
#include<queue>
#include<climits>
#include "BinaryTreeNode.h"
//#include "BinarySeachTree.h"
using namespace std;
void printBTree(BinaryTreeNode<int>* root){
    if(root==NULL)return;
    cout<<root->data<<": ";
    if(root->left)cout<<"L"<<root->left->data<<" ,";
    if(root->right)cout<<"R"<<root->right->data;
    cout<<endl;
    printBTree(root->left);
    printBTree(root->right);
}
BinaryTreeNode<int>* takeInput(){
    int rootData;cout<<" ENTER data "<<endl;
    cin>>rootData;
    if(rootData == -1)return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = takeInput();
    root->right = takeInput();
    return root;
}
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    if(rootData == -1)return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty()){
        BinaryTreeNode<int>* temp = pending.front();
        pending.pop();
        int leftChildData;
        cout<<"Enter the left child of "<<temp->data<<endl;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            temp->left = leftChild;pending.push(temp->left);
        }
        int rightChildData;
        cout<<"Enter the right child of "<<temp->data<<endl;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            temp->right = rightChild;pending.push(temp->right);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root) {
	if(root==NULL)return;
	queue<BinaryTreeNode<int>*>  pending;
	pending.push(root);
	while(!pending.empty()){
		BinaryTreeNode<int>* temp = pending.front();
		pending.pop();
		cout<<temp->data<<":";
		if(temp->left != NULL){
			cout<<"L:"<<temp->left->data<<",";
			pending.push(temp->left);
		}else{
                  cout << "L:" << "-1,";
        }
        if (temp->right != NULL) {
          cout << "R:" << temp->right->data << endl;
          pending.push(temp->right);
        } else {
          cout << "R:"<< "-1"<<endl;
        }
    }
}
inline void swap(BinaryTreeNode<int> *&a, BinaryTreeNode<int> *&b) {
  BinaryTreeNode<int> *temp = a;
  a = b;
  b = temp;
}
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if (!root) return;
    swap(root->left, root->right);
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
void inorder(BinaryTreeNode<int>* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
inline int height(BinaryTreeNode<int>* root) {
    if(root==NULL)return 0;
	return max(height(root->left),height(root->right))+1;
}
void preOrder(BinaryTreeNode<int> *root) {
	if(!root)return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

pair<bool, int> *checkBalanced(BinaryTreeNode<int> *root) {
  if (root == NULL)
          return new pair<bool, int>{true, 0};
        pair<bool, int> *left = checkBalanced(root->left);
        pair<bool, int> *right = checkBalanced(root->right);
        int height = 1+max(left->second,right->second);

	bool cond1  = (left->first and right->first) ? true : false;
	bool cond2 = (abs(left->second - right->second )<=1) ? true : false;
        return new pair<bool, int>{cond1 and cond2, height};
}
pair<int,int>* heightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL)return new pair<int,int>{0,0};
    pair<int,int>* leftAns = heightDiameter(root->left);
    pair<int,int>* rightAns = heightDiameter(root->right);
    int height = 1+max(leftAns->first,rightAns->first);
    int diameter = max(leftAns->first+rightAns->first,max(leftAns->second,rightAns->second));
    return new pair<int,int>{height,diameter};
}
inline int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL)return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
void postOrder(BinaryTreeNode<int> *root) {
	if(!root)return ;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}
void printLevelOrderWise(BinaryTreeNode<int> *root) {
    if(root==NULL)return;
	queue<BinaryTreeNode<int>*> pending;
	pending.push(root);pending.push(NULL);
	while(!pending.empty()){
				BinaryTreeNode<int>* temp = pending.front();
				pending.pop();
                                if (temp != NULL) {
                                  cout << temp->data << " ";
                                }else{
								   if(pending.empty()){
									   	break;
								   }else{
									   pending.push(NULL);cout<<endl;continue;
								   }
								}
                if(temp->left!=NULL){
					pending.push(temp->left);
				}
                if (temp->right != NULL) {
                  pending.push(temp->right);
                }
        }
}
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root==NULL)return root;
	if(root->left == NULL and root->right == NULL)return NULL;
	root->left = removeLeafNodes(root->left);
	root->right = removeLeafNodes(root->right);
	return root;
}
int maximum(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return INT_MIN;
  return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int>  *root) {
  if (root == NULL)
    return INT_MAX;
  return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return true;
  if (root->left and maximum(root->left) >= root->data)
    return false;
  if (root->right and minimum(root->right) <= root->data)
    return false;
  if (!isBST(root->left) || !isBST(root->right))
    return false;
  return true;
}
vector<int>* getRootToNode(BinaryTreeNode<int>* root,int x){
if(root == NULL)return NULL;
if(root->data == x){
    vector<int>* v = new vector<int>();
    v->push_back(root->data);
    return v;
}
 vector<int>* leftAns = getRootToNode(root->left,x);
 if(leftAns != NULL){
        leftAns->push_back(root->data);
        return leftAns;
 }
 vector<int>* rightAns = getRootToNode(root->right,x);
 if(rightAns != NULL){
        rightAns->push_back(root->data);
        return rightAns;
 }
 return NULL;
}

////2 1 3 1 1 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;*/
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);cout<<endl;
    inorder(root);cout<<endl;
    preOrder(root);cout<<endl;
    postOrder(root);cout<<endl;
    cout<<"Num Of Nodes in the Btree: "<<countNodes(root)<<endl;
    cout<<"Is Bst: "<<isBST(root)<<endl;
    /*vector<int>* path = getRootToNode(root,6);
    for(int i=0;i<path->size();i++){
        cout<<path->at(i)<<endl;
    }
    delete path;
    //cout<<"Height of Btree: "<<height(root)<<endl;
   // pair<bool,int>* answer = checkBalanced(root);
    //cout<<"Height of Btree: "<<answer->second<<endl;
    //cout<<"is BTree Balanced: "<<answer->first<<endl;
   /* BinaryTreeNode<int>* rootU = removeLeafNodes(root);
    printLevelOrderWise(rootU);cout<<endl;
    inorder(rootU);cout<<endl;
    preOrder(rootU);cout<<endl;
    postOrder(rootU);cout<<endl;
    cout<<"Num Of Nodes in the Btree: "<<countNodes(rootU)<<endl;*/
    delete root;

}

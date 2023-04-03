#include<iostream>
#include<queue>
#include<climits>
#include "BinaryTreeNode.h"
using namespace std;
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
int getLCAOfBTree(BinaryTreeNode <int>* root , int a, int b) {
    if(root==NULL)return -1;
	if(root->data == a || root->data == b)return root->data;
	int leftLCA = getLCAOfBTree(root->left,a,b);
	int rightLCA = getLCAOfBTree(root->right,a,b);
	if(leftLCA == -1 and rightLCA == -1)return -1;
	else if(leftLCA == -1)return rightLCA;
	else if(rightLCA == -1)return leftLCA;
	else return root->data;
}
int getLCAofBST(BinaryTreeNode<int>* root,int a,int b){
	if(root==NULL)return -1;
	if(root->data == a || root->data == b)return root->data;
	if(root->data < a){
		int rightLCA = getLCAofBST(root->right,a,b);
		if(rightLCA == -1)return -1;
		return rightLCA;
	}else if(root->data>b){
		int leftLCA = getLCAofBST(root->left,a,b);
		if(leftLCA == -1)return -1;
		return leftLCA;
	}else{
		int leftLCA = getLCAofBST(root->left,a,b);
		int rightLCA = getLCAofBST(root->right,a,b);
		if(leftLCA == -1 and rightLCA == -1)return -1;
		else if(leftLCA == -1)return rightLCA;
		else if(rightLCA == -1)return leftLCA;
		else return root->data;
	}
}
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    int a,b;
	if(val1 < val2){
		a=val1;b=val2;
	}else{
		a=val2;b=val1;
	}
	return getLCAofBST(root,a,b);
}
//2 1 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    cout<<getLCAOfBTree(root,4,9)<<endl;
}

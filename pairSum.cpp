#include<iostream>
#include<queue>
#include<climits>
#include "BinaryTreeNode.h"
using namespace std;
/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public :
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
bool search(BinaryTreeNode<int>* root,int x){
	if(root==NULL)return false;
        if (root->data == x) {
          root->data = INT_MIN;
          return true;
        }
    return search(root->left,x) || search(root->right,x);
}
void pairSumHelper(BinaryTreeNode<int>* root,int sum,BinaryTreeNode<int>* current){
	if(current==NULL)return;
	if(current->data != INT_MIN and current->data != (sum-current->data)){
		if(search(root,sum - current->data)){
			if(current->data < (sum-current->data)){
				cout<<current->data<<" "<<sum-current->data<<endl;
			}else{
                cout <<sum - current->data<<" "<<current->data<<endl;
            }
		}
	}
	pairSumHelper(root,sum,current->left);
	pairSumHelper(root,sum,current->right);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
	BinaryTreeNode<int>* current = root;
    pairSumHelper(root,sum,current);
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
void convertToArray(BinaryTreeNode<int>* root,vector<int> &output){
	if(root==NULL)return;
	output.push_back(root->data);
	convertToArray(root->left,output);
	convertToArray(root->right,output);
}
void pairSumBetter(BinaryTreeNode<int> *root, int sum) {
    vector<int> output;
	convertToArray(root,output);
	sort(output.begin(),output.end());
	int i=0;int j = (int)output.size()-1;
	while(i<j){
		if(output[i]+output[j] < sum){
			i++;
		}else if(output[i]+output[j] > sum){
			j--;
		}else{
			cout<<output[i]<<" "<<output[j]<<endl;
			i++;j--;
		}
	}
}
//2 1 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);cout<<endl;
    pairSumBetter(root,10);
}

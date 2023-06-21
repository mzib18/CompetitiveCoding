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
int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);

}

/**********************************************************

        Following is the Binary Tree Node class structure

        template <typename T>
        class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this->data = data;
                left = NULL;
                right = NULL;
        }
        };

***********************************************************/
#include "BinaryTreeNode.h"
#include <climits>
#include <iostream>
#include <queue>

using namespace std;
class BST {
  BinaryTreeNode<int> *root; // Define the data members
public:
  BST() { root = NULL; }
  ~BST() { delete root; }

private:
  void printBTree(BinaryTreeNode<int> *node) {
    if (node == NULL)
      return;
    cout << node->data << ":";
    if (node->left)
      cout << "L" << node->left->data << ",";
    if (node->right)
      cout << "R" << node->right->data;
    cout << endl;
    printBTree(node->left);
    printBTree(node->right);
  }
  bool hasData(int d, BinaryTreeNode<int> *node) {
    if (node == NULL)
      return false;
    if (node->data == d)
      return true;
    else if (node->data <= d)
      return hasData(d, node->left);
    else
      return hasData(d, node->right);
  }
  BinaryTreeNode<int> *insertData(int d, BinaryTreeNode<int> *node) {
    if (node == NULL) {
      BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(d);
      return newnode;
    }
    if (node->data >= d)
      node->left = insertData(d, node->left);
    else if (node->data < d)
      node->right = insertData(d, node->right);
    return node;
  }
  int minimum(BinaryTreeNode<int> *node) {
    if (node == NULL)
      return INT_MAX;
    return min(node->data, min(minimum(node->left), minimum(node->right)));
  }
  BinaryTreeNode<int> *deleteData(int d, BinaryTreeNode<int> *node) {
    if (node == NULL)
      return node;
    if (node->data == d) {
      if (node->left == NULL and node->right == NULL) {
        delete node;
        return NULL;
      } else if (node->left == NULL and node->right != NULL) {
        BinaryTreeNode<int> *temp = node->right;
        node->right = NULL;
        delete node;
        return temp;
      } else if (node->left != NULL and node->right == NULL) {
        BinaryTreeNode<int> *temp = node->left;
        node->left = NULL;
        delete node;
        return temp;
      } else {
        int minRight = minimum(node->right);
        node->data = minRight;
        node->right = deleteData(minRight, node->right);
        return node;
      }
    } else if (node->data >= d) {
      node->left = deleteData(d, node->left);
      return node;
    } else {
      node->right = deleteData(d, node->right);
      return node;
    }
  }

public:
  void remove(int data) {
    root = deleteData(data, root); // Implement the remove() function
  }

  void print() {
    printBTree(root); // Implement the print() function
  }

  void insert(int data) {
    root = insertData(data, root); // Implement the insert() function
  }

  bool search(int data) {
    return hasData(data, root); // Implement the search() function
  }
};

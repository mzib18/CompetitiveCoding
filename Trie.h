#include "TrieNode.h"
#include<string>
using namespace std;
class Trie{
private:
  TrieNode *root;
     bool searchWord(TrieNode *node, string word) {
      if (word.size() == 0) {
        if (node->isTerminal)return true;
        else return false;
      }
      int index = word[0] - 'a';
      TrieNode *child = node->children[index];
      if(child == NULL){
          return false;
      }else{
          return searchWord(child,word.substr(1));
      }
    }
  void insertWord(TrieNode* node,string word){
      if(word.size()==0){
        node->isTerminal = true;
        return;
    }
    int index = word[0] - 'a';
    TrieNode *child;
    if(node->children[index] != NULL){
        child = node->children[index];
    }else{
        child = new TrieNode(word[0]);
        node->children[index] = child;
    }
    insertWord(child,word.substr(1));
  }
  void removeWord(TrieNode* node,string word){
    if(word.size()==0){
        node->isTerminal = false;
        return ;
    }
    int index = word[0] - 'a';
    TrieNode *child;
    if(node->children[index] != NULL){
        child = node->children[index];
    }else{
        return;
    }
    removeWord(child,word.substr(1));
    if(child->isTerminal == false){
        for(int i = 0;i<26;i++){
            if(child->children[i] != NULL)return;
        }
    delete child;
    root->children[index] = NULL;
    }
  }
public:
  Trie(){
    root=new TrieNode('\0');
  }
  void insertWord(string word){
    insertWord(root,word);
  }
  bool searchWord(string word){
    return searchWord(root,word);
  }
  void removeWord(string word){
    removeWord(root,word);
  }
};

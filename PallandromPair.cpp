#include <iostream>
#include <string>
#include <vector>

using namespace std;
class TrieNode {
public:
  char data;
  TrieNode **children;
  bool isTerminal;
  bool isPalindrome;

  TrieNode(char data) {
    this->data = data;
    children = new TrieNode *[26];
    for (int i = 0; i < 26; i++)
      children[i] = NULL;
    isTerminal = false;
    isPalindrome = false;
  }
};
class Trie {
  TrieNode *root;

public:
  Trie() {
    root = new TrieNode('\0');
  }
  bool searchWord(TrieNode *node, string s, int si) {
    if ((node->isTerminal) and isStringPalindrome(s, si)) {
      return true;
    }
    if (si == s.length()) {
      if (node->isTerminal)
        return true;
      else if (node->isPalindrome)
        return true;
      else
        return false;
    }
    int index = s[si] - 'a';
    TrieNode *child = node->children[index];
    if (child == NULL) {
      return false;
    } else {
      if (child->isPalindrome)
        if (searchWord(child, s, si))
          return true;

        return searchWord(child, s, si + 1);
      }
  }
  void insertWord(TrieNode *node, string s, int si) {
    if (si == s.length()) {
      node->isTerminal = true;
      return;
    }
    node->isPalindrome = isStringPalindrome(s, si + 1);
    int index = s[si] - 'a';
    TrieNode *child;
    if (node->children[index] != NULL) {
      child = node->children[index];
    } else {
      child = new TrieNode(s[si]);
      node->children[index] = child;
    }
    // node->isPallandrome = isStringPallandrome(s,si-1);
    insertWord(child, s, si + 1);
  }
  bool isStringPalindrome(string s, int si) {
    int i = si;
    int j = s.length() - 1;
    while (i < j) {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
  bool isPalindromePair(vector<string> words) {
    for (int i = 0; i < words.size(); i++)
      if (isStringPalindrome(words[i],0))
        return true;

    for (int i = 0; i < words.size(); i++) {
      string s = words[i];
      string r = "";
      for (int j = 0; j < s.length(); j++) {
        r = s[j] + r;
      }
      insertWord(root, r, 0);
    }
    for (int i = 0; i < words.size(); i++) {
      string s = words[i];
            if(searchWord(root,s,0))
                return true;
    }
    return false;
  }
};

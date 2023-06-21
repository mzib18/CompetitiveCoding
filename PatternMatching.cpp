#include<string>
#include<vector>
using namespace std;
class SuffixTrieNode{
public:
    char data;
    SuffixTrieNode** children;
    SuffixTrieNode(char data){
        this->data = data;
        children = new SuffixTrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
    ~SuffixTrieNode(){
        for(int i=0;i<26;i++){
            delete children[i];
        }
        delete [] children;
    }
};
class SuffixTrie{
SuffixTrieNode* root;
public:
    int count;
    SuffixTrie(){
        this->count=0;
        root=new SuffixTrieNode('\0');
    }
private:
    void insertWord(SuffixTrieNode* root,string word){
       if(word.length()==0){
        return;
       }
       int index = word[0]-'a';
       SuffixTrieNode* child = root->children[index];
       if(child != NULL){
            insertWord(child,word.substr(1));
       }else{
            child = new SuffixTrieNode(word[0]);
            root->children[index]=child;
            insertWord(child,word.substr(1));
       }
       return;
    }
    bool searchWord(SuffixTrieNode* root,string word){
        if(word.length()==0)
            return true;
        int index = word[0]-'a';
        SuffixTrieNode* child = root->children[index];
        if(child != NULL){
                return searchWord(child,word.substr(1));
        }else{
                return false;
        }
    }
public:
    void insertWord(string word){
        insertWord(root,word);
        this->count++;
    }

    bool searchWord(string word){
        return searchWord(root,word);
    }
    bool patternMatching(vector<string> v,string pattern){
        for(int i=0;i<v.size();i++){
            string s = v[i];
            for(int i=0;i<s.length();i++){
                insertWord(s.substr(i));
            }
        }
        return searchWord(pattern);
    }
};


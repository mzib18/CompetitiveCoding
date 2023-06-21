#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;
class TrieNode {
   public:
    char data;
    unordered_map<char, TrieNode*> children;
    int penNum;

    TrieNode(char data,int penNum) {
        this->data = data;
        this->penNum = penNum;
    }
};

class Trie {


   public:
   TrieNode *root;
    Trie() {
        root = new TrieNode('\0',0);
    }

    void insertWord(TrieNode *root, string word,int penNO) {
        // Base case
        if (word.size() == 0) {
            return;
        }

        // Small calculation
        char ch = word[0];
        TrieNode *child;
        if (root->children.find(ch) != root->children.end()) {
            child = root->children[ch];
        } else {
            child = new TrieNode(ch,0);
            root->children[ch] = child;
        }
        // Set the pen number if it is not already set
        if (penNO != 0 && child->penNum == 0) {
            child->penNum = penNO;
        }

        // Recursive call
        insertWord(child, word.substr(1), penNO);
    }

    void insertWord(string word,int penNO){
        insertWord(root,word,penNO);
    }

    void searchWord(TrieNode* node, string s, vector<int>& ans, int pen) {
        if (s.size() == 0) return;

        char ch = s[0];
        if (node->children.find(ch) != node->children.end()) {
            TrieNode *child = node->children[ch];
            if (child->penNum != 0) {
                pen = child->penNum;
            }
            ans.push_back(pen);
            searchWord(child, s.substr(1), ans, pen);
        } else {
            searchWord(root, s.substr(1), ans, 0);
        }
    }

    void minpenChange(string s,vector<int>& ans){
        searchWord(root, s, ans, 0);
    }

    void patternMatching(string word,int pen) {
        for (int i = 0; i < word.length(); i++) {
            insertWord(word.substr(i), pen);
        }
    }

    ~Trie() {
        destroy(root);
    }

   private:
    void destroy(TrieNode* node) {
        if (node == NULL) {
            return;
        }
        for (auto it : node->children) {
            destroy(it.second);
        }
        delete node;
    }
};
signed main() {
    IOS;
    int T;
    cin >> T;
    Trie t;
    while (T--) {
        t.root = new TrieNode('\0', 0);
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 1; i <= k; i++) {
            string word;
            cin >> word;
            t.patternMatching(word, i);
        }
        vector<int> ans;
        t.minpenChange(s, ans);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}//t- O(N*K)

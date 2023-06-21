#include<bits/stdc++.h>
using namespace std;
class BinaryTreeNode{
public:
    pair<char,int> data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(pair<char,int> data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
struct comparator{
    bool operator()(const BinaryTreeNode *p1,const BinaryTreeNode *p2)const{
        return p1->data.second > p2->data.second;
    }
};

bool rootToLeafNodePath(BinaryTreeNode* root, char c, string& ans) {
    if (root == NULL) {
        return false;
    }
    if (root->data.first == c) {
        return true;
    }
    bool foundInLeft = rootToLeafNodePath(root->left, c, ans);
    if (foundInLeft) {
        ans = "0" + ans;
        return true;
    }
    bool foundInRight = rootToLeafNodePath(root->right, c, ans);
    if (foundInRight) {
        ans = "1" + ans;
        return true;
    }
    return false;
}
unordered_map<char,string> compressed(char *ch,int n){
        if(n==1){
          unordered_map<char,string> ans;
          ans[ch[0]]="0";
          return ans;
        }
        char freq[256]={0};
        for(int i=0;i<n;i++)freq[ch[i]]++;
        priority_queue<BinaryTreeNode*,vector<BinaryTreeNode*>,comparator> pq;
        vector<char> c;
        for(int i=0;i<256;i++){
            if(freq[i]>0){
                BinaryTreeNode* temp = new BinaryTreeNode({char(i),freq[i]});
                pq.push(temp);
                c.push_back(char(i));
            }
        }
        BinaryTreeNode* root;
        while(pq.size()>1){
                BinaryTreeNode* leftChild = pq.top();
                pq.pop();
                BinaryTreeNode* rightChild = pq.top();
                pq.pop();
                root = new BinaryTreeNode({'\0',leftChild->data.second + rightChild->data.second});
                root->left = leftChild;
                root->right = rightChild;
                pq.push(root);
        }
        unordered_map<char,string> mp;
        for(int i=0;i<c.size();i++){
            string path="";
            rootToLeafNodePath(root,c[i],path);
            mp[c[i]] = path;
        }
        delete root;
        return mp;
}

int main(){
    char ch[] = {'a','a','f','q','a','e','a','b','n','q','e','x','f','a','b','e','f','q'};
    int n = sizeof(ch)/sizeof(ch[0]);
    cout<<n<<endl;// 18
    cout<<ch<<endl;
    unordered_map<char,string> codes = compressed(ch,n);
    string s;
    for(int i=0;i<n;i++){
        s += codes[ch[i]];
    }
    auto it = codes.begin();
    unordered_map<string,char> decode;
    while(it!=codes.end()){
        decode.insert({it->second,it->first});
        ++it;
    }
    vector<bool> bits;

    for (char c : s) {
        if (c == '0') {
            bits.push_back(false); // Add a 0 bit
        } else{
            bits.push_back(true); // Add a 1 bit
        }
    }
    cout<<bits.size()<<endl;
    string sr="";
    string ans;
    for(int i=0;i<bits.size();i++){
        if(bits[i]==false){
            sr+= "0";
        }else{
            sr+= "1";
        }
        auto it1 = decode.find(sr);
        if(it1!=decode.end()){
            ans+=decode[sr];
            sr="";
        }
    }
    cout<<ans<<endl;
}

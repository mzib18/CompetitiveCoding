
 // Definition for a binary tree node.
  public class TreeNode {
     int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }
  }

class Solution {
    int helper(TreeNode* root,vector<int> &lst){
        if(root == NULL)return 0;
        int leftSum = helper(root->left,lst);
        int rightSum = helper(root->right,lst);
        int sum=root->val + leftSum + rightSum;
        lst.push_back(sum);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> lst;
        helper(root,lst);
        sort(lst.begin(),lst.end());
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<lst.size();i++){
            int c=0;
            int elem = lst[i];
            while(i<lst.size()-1 and lst[i]==lst[i+1]){
                i++;
                c++;
            }
            pq.push({c+1,elem});
        }
        vector<int> ans;
        if(!pq.empty()){
            int maxfreq = pq.top().first;
            while(!pq.empty() and pq.top().first == maxfreq){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};

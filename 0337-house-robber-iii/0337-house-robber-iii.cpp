/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int dfs(TreeNode* root,int can,map<pair<TreeNode*,int>,int>&mp){
    if(!root)return 0;
    if(mp.count({root,can}))return mp[{root,can}];
    int ans;
    if(can){
      int op1=root->val+dfs(root->left,0,mp)+dfs(root->right,0,mp);
      int op2=dfs(root->left,1,mp)+dfs(root->right,1,mp);
      ans=max(op1,op2);
    }
    else{
          ans=dfs(root->left,1,mp)+dfs(root->right,1,mp);
    }
    return mp[{root,can}]=ans;
}
    int rob(TreeNode* root) {
     map<pair<TreeNode*,int>,int>mp;
        return dfs(root,1,mp);
    }
};
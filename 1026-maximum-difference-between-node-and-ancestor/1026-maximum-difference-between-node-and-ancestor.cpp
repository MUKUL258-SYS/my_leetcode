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
int ans;
pair<int,int>dfs(TreeNode* root){
    if(!root)return {INT_MAX,INT_MIN};
    if(!root->left&&!root->right)return {root->val,root->val};
    pair<int,int>l=dfs(root->left);
    pair<int,int>r=dfs(root->right);
   // ans=max(ans,abs(root->val-l.first));
   //  ans=max(ans,abs(root->val-l.second));
     // ans=max(ans,abs(root->val-r.first));
      // ans=max(ans,abs(root->val-r.second));
     //  return {min(l.first,r.first),max(l.second,r.second)};
     int maxi=max(l.second,r.second);
     int mini=min(l.first,r.first);
     mini=min(mini,root->val);
     maxi=max(maxi,root->val);
     ans=max(ans,abs((root->val)-mini));
     ans=max(ans,abs((root->val)-maxi));
     return {mini,maxi};

}
    int maxAncestorDiff(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};
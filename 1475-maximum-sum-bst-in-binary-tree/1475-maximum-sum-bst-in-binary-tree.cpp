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
tuple<int,int,int>dfs(TreeNode* root,int &ans){
    if(!root)return {INT_MAX,INT_MIN,0};
    auto [leftmin,leftmax,lsum]=dfs(root->left,ans);
    auto [rightmin,rightmax,rsum]=dfs(root->right,ans);
    if(root->val>leftmax&&root->val<rightmin){
        ans=max(ans,root->val+lsum+rsum);
        return {min(root->val,leftmin),max(root->val,rightmax),root->val+lsum+rsum};
    }
    return {INT_MIN,INT_MAX,0};
}
    int maxSumBST(TreeNode* root) {
       int ans=0;
       dfs(root,ans);
       return ans; 
    }
};
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
int maxi;
int dfs(TreeNode* root){
    if(!root)return 0;
    int l=dfs(root->left);
    int r=dfs(root->right);
   int ans=1;
    if(root->left&&root->right){
          int v1=root->left->val;
          int v2=root->right->val;
          int v3=root->val;
          if((v3==v1)&&(v3==v2)){
            maxi=max(maxi,1+l+r);
          }

    }
    if(root->left){
          int v1=root->left->val;
          
          int v3=root->val;
          if(v1==v3){
            maxi=max(maxi,1+l);
            ans=max(ans,1+l);
          }
    }
    if(root->right){
           int v1=root->right->val;
          
          int v2=root->val;
          if(v1==v2){
            maxi=max(maxi,1+r);
            ans=max(ans,1+r);
          }
    }
    return ans;
}
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        maxi=0;
        maxi=max(maxi,dfs(root));
        return maxi-1;
    }
};
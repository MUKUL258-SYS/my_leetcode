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
TreeNode * dfs(TreeNode* root,int val){
   if(!root)return new TreeNode(val);
   if(root->val<val){
    TreeNode* r= new TreeNode(val);
    r->left=root;
    return r;
   }
   else {
    root->right=dfs(root->right,val);
    return root;
   }
   return NULL;
   

}
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        return dfs(root,val);
    }
};
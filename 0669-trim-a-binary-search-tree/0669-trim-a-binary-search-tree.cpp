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
TreeNode* dfs(TreeNode* root,int l,int h){
    if(!root)return NULL;
    int v=root->val;
    if(v<l){
        return dfs(root->right,l,h);
    }
    if(v>h)return dfs(root->left,l,h);
    TreeNode* left=dfs(root->left,l,h);
    TreeNode* right=dfs(root->right,l,h);
    root->left=left;
    root->right=right;
    return root;
}
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return dfs(root,low,high);
    }
};
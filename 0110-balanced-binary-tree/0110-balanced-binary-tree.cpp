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
bool ans;
int dfs(TreeNode* root){
    if(!root)return 0;
    int h1=dfs(root->left);
    int h2=dfs(root->right);
    if(abs(h1-h2)>1)ans=false;
    return 1+max(h1,h2);
}
    bool isBalanced(TreeNode* root) {
         ans=true;     
         dfs(root);
         return ans;
    }
};
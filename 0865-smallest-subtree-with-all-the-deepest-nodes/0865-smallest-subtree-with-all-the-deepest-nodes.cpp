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
pair<int,TreeNode*>dfs(TreeNode* root){
    if(!root)return {0,NULL};
pair<int,TreeNode*>l=dfs(root->left);
pair<int,TreeNode*>r=dfs(root->right);
if(l.first>r.first){
    return {l.first+1,l.second};
}
else if(r.first>l.first){
    return {r.first+1,r.second};
}
else {
    return {l.first+1,root};
}
return{0,NULL};
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
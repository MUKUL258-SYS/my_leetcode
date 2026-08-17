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
vector<int> dfs(TreeNode* root){
    if(!root)return {0,NULL};
    if(!root->left && !root->right)return {1,root->val};
    vector<int>l=dfs(root->left);
    vector<int>r=dfs(root->right);
    int maxi=root->val;
    int ans=l[0]+r[0];
    int a=l[1];
    int b=r[1];
    maxi=max(maxi,a);
    maxi=max(maxi,b);
    if(maxi==(root->val))ans++;
    return {ans,maxi};




}
    int countDominantNodes(TreeNode* root) {
        return dfs(root)[0];
    }
};
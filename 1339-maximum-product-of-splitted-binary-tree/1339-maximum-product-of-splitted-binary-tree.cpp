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
long long t=0;
long long maxi=0;
int mod=1e9+7;
void dfs2(TreeNode* root){
    if(!root)return ;
    t+=root->val;
    dfs2(root->left);
    dfs2(root->right);
}
long long dfs(TreeNode* root){
    if(!root){
       return 0;
    }
    long long sum=root->val;
    sum+=dfs(root->left);
    sum+=dfs(root->right);
    maxi=max(maxi,(sum*(t-sum)));
    return sum;
}

    int maxProduct(TreeNode* root) {
       // t=0;
       // maxi=0;
        dfs2(root);
        dfs(root);
        return maxi%mod;

    }
};
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
vector<int>v;
TreeNode* dfs2(int i,int j){
    if(i>j)return NULL;
    int mid=(i+j)/2;
    TreeNode* root=new TreeNode(v[mid]);
    root->left=dfs2(i,mid-1);
    root->right=dfs2(mid+1,j);
    return root;
}
void dfs(TreeNode* root){
    if(!root)return ;
   dfs(root->left);
   v.push_back(root->val);
   dfs(root->right);
}
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        int n=v.size();
        return dfs2(0,n-1);
    }
};
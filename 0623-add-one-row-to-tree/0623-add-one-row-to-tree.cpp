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
int val;
void dfs(TreeNode * root,int depth){
     if(!root)return ;
     if(depth==2){
        TreeNode* l= new TreeNode(val);
        TreeNode* r=new TreeNode(val);
        TreeNode* cl=root->left;
        TreeNode* cr=root->right;
        root->left=l;
        l->left=cl;
        root->right=r;
        r->right=cr;
        return ;

     }
dfs(root->left,depth-1);
dfs(root->right,depth-1);

     }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
             TreeNode* l= new TreeNode(val);
             l->left=root;
             return l;
        }
        this->val=val;
        dfs(root,depth);
        return root;
    }
};
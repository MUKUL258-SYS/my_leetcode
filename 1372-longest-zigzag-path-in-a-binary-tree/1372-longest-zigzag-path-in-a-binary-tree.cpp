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
int maxlen=0;
void dfs(TreeNode* root,bool isLeft,int len){
    if(!root){
        return ;
    }
    maxlen=max(maxlen,len);
    if(isLeft){
        dfs(root->right,false,len+1);
        dfs(root->left,true,1);
    }
    else{
        dfs(root->left,true,len+1);
        dfs(root->right,false,1);
    }
}
    int longestZigZag(TreeNode* root) {
        dfs(root->left,true,1);
        dfs(root->right,false,1);
        return maxlen;
    }
};
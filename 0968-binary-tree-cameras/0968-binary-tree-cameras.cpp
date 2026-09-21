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
int c;
//0-- uncovered(doesnot have cameras)
//1-- covered(does not need camers)
//2-- hascamera
int dfs(TreeNode* root){
   if(!root)return 1;
   int l=dfs(root->left);
   int r=dfs(root->right);

   if(l==0 || r==0){
    c++;
    return 2;
   }
   if(l==2 ||r==2){
    return 1;
   }
   return 0;
}
    int minCameraCover(TreeNode* root) {
      c=0;  
      int res=dfs(root);
      if(res==0)c++;
      return c;

    }
};
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
vector<TreeNode*>dfs(int s,int e){
   if(s>e)return {nullptr};
   vector<TreeNode*>res;
   for(int i=s;i<=e;i++){
    vector<TreeNode*>lt=dfs(s,i-1);
    vector<TreeNode*>rt=dfs(i+1,e);

    for(auto l:lt){
        for(auto r:rt){
            TreeNode* root=new TreeNode(i);
            root->left=l;
            root->right=r;
            res.push_back(root);
        }
    }
   // return res;
   }
   
    return res;
}
    vector<TreeNode*> generateTrees(int n) {
        return n ? dfs(1,n): vector<TreeNode*>();
    }
};
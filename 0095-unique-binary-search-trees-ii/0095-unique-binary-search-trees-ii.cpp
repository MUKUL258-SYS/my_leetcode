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
    if(s>e)return {NULL};
    vector<TreeNode*>v;
    for(int i=s;i<=e;i++){
        vector<TreeNode*>lc=dfs(s,i-1);
        vector<TreeNode*>rc=dfs(i+1,e);
        for(auto l:lc){
            for(auto r:rc){
                  TreeNode* root=new TreeNode(i);
                  root->left=l;
                  root->right=r;
                  v.push_back(root);
            }
        }
    }
    return v;
}
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
        
    }
};
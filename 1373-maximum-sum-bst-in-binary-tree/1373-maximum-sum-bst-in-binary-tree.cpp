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
int ans;
vector<int>dfs(TreeNode* root){
    //if(!root)return {};
    if(!root){
        return {INT_MAX,INT_MIN,0};
    }
    
    auto l=dfs(root->left);
    auto r=dfs(root->right);
    int val=root->val;
    if(val<r[0] && val>l[1]){
        ans=max(ans,val+l[2]+r[2]);

        return {min(l[0],val),max(val,r[1]),val+l[2]+r[2]};
    }

    return {INT_MIN,INT_MAX,0};
   
}
    int maxSumBST(TreeNode* root) {
        ans=0;
        auto val=dfs(root);
    
       //return  val[2]<0?0:val[2];
       return ans;
    }
};
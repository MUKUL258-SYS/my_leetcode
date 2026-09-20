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
vector<int>ans;
int maxi;
int dfs(TreeNode* root){
    if(!root)return 0;
    return 1+dfs(root->left)+dfs(root->right);
}
void ltor(TreeNode * root,int depth){
  if(!root)return;
  ans[root->val]=max(ans[root->val],maxi);
   maxi=max(maxi,depth);
  ltor(root->left,depth+1);
  ltor(root->right,depth+1);
  //maxi=max(maxi,depth);

}
void rtol(TreeNode * root,int depth){
  if(!root)return;
  ans[root->val]=max(ans[root->val],maxi);
   maxi=max(maxi,depth);
  rtol(root->right,depth+1);
 rtol(root->left,depth+1);
 // maxi=max(maxi,depth);

}
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
         maxi=0;
        int n=dfs(root);
         //ans.resize(100005,0);
         ans.resize(n+1,0);
            rtol(root,0);
          //   for(auto i:ans)cout<<i<<" ";
            maxi=0;
            ltor(root,0);
            vector<int>res;
          //  for(auto i:ans)cout<<i<<" ";
          //  cout<<endl;
            for(auto q:queries){
               res.push_back(ans[q]);
            }
            return res;

    }
};
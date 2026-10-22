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
string mini;
void dfs(TreeNode * root,string &s){
    if(!root)return ;
        s.push_back('a'+root->val);
    if(!root->left && !root->right){
      reverse(s.begin(),s.end());
      if(mini=="")mini=s;
      else if(s<mini){
        mini=s;
      }
      //mini=min(mini,s);
      reverse(s.begin(),s.end());
    }
   // s.push_back('a'+root->val);
    dfs(root->left,s);
    dfs(root->right,s);
    s.pop_back();

}
    string smallestFromLeaf(TreeNode* root) {
        string t="";
        mini="";
        dfs(root,t);
        return mini;
    }
};
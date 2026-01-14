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
void preorder(TreeNode* root){
    if(!root)return ;
    preorder(root->left);
    v.push_back(root->val);
    preorder(root->right);
}
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>res;
        preorder(root);
        int n=v.size();
        for(auto i:queries){
            auto itr=lower_bound(v.begin(),v.end(),i);
            if(itr!=v.end()&&*itr==i){
                res.push_back({i,i});
            }
            else if(itr==v.end()){
                res.push_back({*(itr-1),-1});
            }
            else if(itr==v.begin()){
                res.push_back({-1,*(itr)});
            }
            else{
                res.push_back({*(itr-1),*(itr)});
            }
        }
        return res;
    }
};
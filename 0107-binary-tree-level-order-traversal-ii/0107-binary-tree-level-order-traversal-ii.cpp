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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
       vector<vector<int>>res;
       //if(q.size()==0)return {{}};
       //res.push_back({root->val});
        while(!q.empty()){
            int sz=q.size();
            vector<int>v;
            while(sz--){
               auto f=q.front();
               q.pop();
               v.push_back(f->val);
               if(f->left)q.push(f->left);
               if(f->right)q.push(f->right);

            }
            res.push_back(v);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
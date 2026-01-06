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
int res;
int d;
vector<int>dfs(TreeNode* root){
    if(!root)return {0};
    if((root->left==NULL)&&(root->right==NULL))return {1};
    vector<int>l=dfs(root->left);
    vector<int>r=dfs(root->right);
    for(auto i:l){
        for(auto j:r){
            if(i>0&&j>0){
            if(i+j<=d)res++;
            }
        }
    }
    
    vector<int>v;
    for(auto i:l){
      if(i>0&&i<d)v.push_back(i+1);
    }
    for(auto i:r){
       if(i>0&&i<d)v.push_back(i+1);
    }
    return v;
}
    int countPairs(TreeNode* root, int distance) {
        res=0;
        d=distance;
        dfs(root);
        return res;
    }
};
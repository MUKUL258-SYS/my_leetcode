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
unordered_map<int,int>mp;
int dfs(TreeNode* root){
    if(!root){
        return 0;
    }
    int ans=root->val;
    ans+=dfs(root->right);
    ans+=dfs(root->left);
     mp[ans]++;
     return ans;


}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        int maxi=0;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        vector<int>v;
        for(auto i:mp){
            if(i.second==maxi)v.push_back(i.first);
        }
        return v;
    }
};
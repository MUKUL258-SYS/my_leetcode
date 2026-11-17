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
vector<vector<int>>adj;
void dfs(TreeNode* root){
    if(!root)return ;
    if(root->left){
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val);
    }
    if(root->right){
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
    }
    dfs(root->left);
    dfs(root->right);
}
    int amountOfTime(TreeNode* root, int start) {
         adj.resize(100005);
         dfs(root);
         queue<int>q;
         q.push(start);
         vector<bool>vis(100005,false);
         vis[start]=true;
         int t=-1;
         while(!q.empty()){
             //auto f=q.front();
            // q.pop();
            int sz=q.size();
            while(sz--){
auto f=q.front();
             q.pop();
              for(auto i:adj[f]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
              }
            }
            t++;
         }
         return t;
    }
};
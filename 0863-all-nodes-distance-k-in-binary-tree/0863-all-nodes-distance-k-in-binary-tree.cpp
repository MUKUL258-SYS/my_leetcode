/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<vector<int>>v;
vector<int> bfs(int s,int k){
    if(k==0)return {s};
    queue<int>q;
    q.push(s);
    //vis[s]=1;
    vector<int>vis(505,0);
     vis[s]=1;
    int l=0;
    vector<int>res;
    
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
         auto i=q.front();
         q.pop();
         for(auto nei:v[i]){
            if(vis[nei]==0){
                q.push(nei);
                vis[nei]=1;
            }
         }
        }
        if(l==k-1){
         //   cout<<"yes"<<endl;
      while(!q.empty())res.push_back(q.front()),q.pop();
      return res;
        }
        l++;
    }
    return res;
}
void dfs(TreeNode* root){
 if(!root)return ;
  if(root->left){
    v[root->val].push_back(root->left->val);
    v[root->left->val].push_back(root->val);
  }
  if(root->right){
    v[root->val].push_back(root->right->val);
    v[root->right->val].push_back(root->val);
  }
  dfs(root->left);
  dfs(root->right);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        v.resize(505);
        dfs(root);
      /*  for(int i=0;i<505;i++){
           // cout<<i<<" ";
            for(int j=0;j<v[i].size();j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
    return bfs(target->val,k);
    }
};
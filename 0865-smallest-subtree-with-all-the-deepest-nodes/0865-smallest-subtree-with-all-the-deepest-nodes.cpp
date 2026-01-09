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
TreeNode* lca(TreeNode* p,TreeNode* q,TreeNode* root){
    if(!root)return NULL;
    if(root==p)return root;
    if(root==q)return root;
    TreeNode* l=lca(p,q,root->left);
    TreeNode* r=lca(p,q,root->right);
    //if(root==p)return root;
    //if(root==q)return root;
    if(l&&r){
         return root;
    }
    if(l)return l;
    if(r)return r;
    return NULL;

}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*>q;
        unordered_map<int,vector<TreeNode*>>mp;
        q.push(root);
        int l=0;
        while(!q.empty()){
            int sz=q.size();
                while(sz--){
                auto m=q.front();
               mp[l].push_back(m);
               q.pop();
               if(m->left)q.push(m->left);
               if(m->right)q.push(m->right);
            }
            l++;
        }
        /*for(auto i:mp){
            for(auto j:i.second)cout<<j<<" ";
            cout<<endl;
        }
        */
        vector<TreeNode*>v=mp[l-1];
        TreeNode* t=v[0];
        for(int i=1;i<v.size();i++){
           t=lca(t,v[i],root);
        }
        return t;
    }
};
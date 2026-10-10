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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int l=0;
        while(!q.empty()){
              int s=q.size();
              vector<int>v;
              while(s--){
                 auto f=q.front();
                 int value=f->val;
                 if(l%2==0 && value%2 ==0 )return false;
                 if(l%2==1 && value%2 ==1 )return false;
                 v.push_back(value);
                 q.pop();
                 if(f->left)q.push(f->left);
                 if(f->right)q.push(f->right);
              }
              vector<int>t=v;
              set<int>st(v.begin(),v.end());
              if(st.size()!=v.size())return false;
              
              if(l%2==0){
                sort(t.begin(),t.end());
                if(t!=v)return false;
              }
              else {
                sort(t.begin(),t.end(),greater<int>());
                if(t!=v)return false;
              }
              l++;

        }
        return true;
    }
};
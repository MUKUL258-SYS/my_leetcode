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
vector<int>vp;
pair<int,int>dfs(TreeNode* root){
   if(!root){
    return {0,0};
   }
   pair<int,int>p1=dfs(root->left);
   pair<int,int>p2=dfs(root->right);
   int h1=p1.first;
   int n1=p1.second;
   int h2=p2.first;
   int n2=p2.second;
   if(n1==n2&&h1==h2){
        if((n1&(n1+1))==0)vp.push_back(1+2*n1);
   }
   return {1+max(h1,h2),1+n1+n2};
}
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(vp.begin(),vp.end(),greater<int>());
        for(auto i:vp)cout<<i<<" ";
        cout<<endl;
        if(vp.size()>=k)return vp[k-1];
        return -1;
    }
};
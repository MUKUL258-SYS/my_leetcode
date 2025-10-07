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
class CBTInserter {
public:
queue<TreeNode*>q;
TreeNode* r;
    CBTInserter(TreeNode* root) {
        r=root;
        queue<TreeNode*>t;
        t.push(root);
        while(!t.empty()){
            TreeNode* f=t.front();
            t.pop();
            if(f->left==NULL || f->right==NULL){
               q.push(f);
            }
            
            if(f->left){
                t.push(f->left);
            }
            if(f->right){
                t.push(f->right);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* f=q.front();
        TreeNode* n=new TreeNode(val);
        if(f->left==NULL){
           f->left=n;
           q.push(n);
        }
       else if(f->right==NULL){
            q.pop();
            f->right=n;
            q.push(n);
        }

        return f->val;
    }
    
    TreeNode* get_root() {
        return r;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
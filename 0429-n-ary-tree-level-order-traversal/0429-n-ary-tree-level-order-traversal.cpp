/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>res;
        while(!q.empty()){
            int sz=q.size();
           // q.pop();
            vector<int>v;
            while(sz--){
                Node* f=q.front();
                q.pop();
               v.push_back(f->val);
               for(auto child:f->children){
                     q.push(child);
               }
            }
            res.push_back(v);

        }
        return res;
    }
};
class Solution {
public:
vector<vector<int>>gr;
vector<vector<int>>res;
int n;
void dfs(int node,vector<int>&ans){
    if(node+1==n){
        ans.push_back(node);
        res.push_back(ans);
        ans.pop_back();
        return ;
    }
    ans.push_back(node);
    for(auto nei:gr[node]){
        dfs(nei,ans);
    }
    ans.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       gr=graph;
       n=graph.size();
       vector<int>v;
       dfs(0,v);
            return res;
    }
};
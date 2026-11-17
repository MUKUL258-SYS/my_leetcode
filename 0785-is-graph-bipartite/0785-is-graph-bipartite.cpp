class Solution {
public:
vector<vector<int>>adj;
bool dfs(int node,int c,vector<int>&color){
    color[node]=c;
    for(auto nei:adj[node]){
        if(color[nei]==-1 && dfs(nei,1-c,color))return true;
       else if(color[node]==color[nei])return true;
    }
    return false;
}
    bool isBipartite(vector<vector<int>>& graph) {
        adj=graph;
        int n=adj.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && dfs(i,0,color))return false;
        }
        return true;
    }
};
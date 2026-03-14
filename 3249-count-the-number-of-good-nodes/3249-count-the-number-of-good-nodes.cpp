class Solution {
public:
int cnt;
int dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
    
    set<int>s;
    int ans=1;
    vis[node]=true;
    for(auto nei:adj[node]){
        if(vis[nei])continue;
        int sz=dfs(nei,adj,vis);
        ans+=sz;
        s.insert(sz);
    }
    if(s.size()<=1)cnt++;

    return ans;
}
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
         cnt=0;
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0,adj,vis);
     return cnt;
    }
};
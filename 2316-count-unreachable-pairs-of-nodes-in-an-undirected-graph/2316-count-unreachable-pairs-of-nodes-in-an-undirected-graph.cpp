class Solution {
public:
long long dfs(vector<vector<int>>&adj,int node,vector<bool>&vis){
    vis[node]=true;
    long long ans=1;
    for(auto nei:adj[node]){
        if(!vis[nei]){
            ans+=dfs(adj,nei,vis);
        }
    }
    return ans;

}
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0;
        vector<vector<int>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<long long>v;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                v.push_back(dfs(adj,i,vis));
            }
        }
        long long presum=v[0];
        for(int i=1;i<v.size();i++){
            ans+=(presum*v[i]);
            presum+=v[i];

        }
        return ans;
    }
};
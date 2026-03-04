class Solution {
public:
unordered_map<int,int>mp;
vector<vector<int>>adj;
int cnt;
void dfs(int node,vector<int>&vis){
      vis[node]=1;
    cnt++;
      for(auto nei:adj[node]){
        if(mp[nei]>0)continue;
        if(vis[nei]==0){
            dfs(nei,vis);
        }
      }
}
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        adj.resize(n);
        vector<int>vis(n,0);
        cnt=0;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(auto i:restricted){
            mp[i]++;
        }
        dfs(0,vis);
        return cnt;
        
    }
};
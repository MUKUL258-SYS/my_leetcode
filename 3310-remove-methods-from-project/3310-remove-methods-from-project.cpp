class Solution {
public:
void dfs(int node,vector<bool>&vis,vector<vector<int>>&adj,vector<int>&vp){
    vis[node]=true;
    vp.push_back(node);
    for(auto nei:adj[node]){
        if(!vis[nei]){
            dfs(nei,vis,adj,vp);
        }
    }
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>>adj(n);
        vector<vector<int>>rev_adj(n);
        for(auto i:inv){
            adj[i[0]].push_back(i[1]);
            rev_adj[i[1]].push_back(i[0]);
        }
        vector<bool>vis(n,false);
        vector<int>vp;
        dfs(k,vis,adj,vp);
        vector<int>v;
      set<int>s;
      for(int i=0;i<n;i++){
        s.insert(i);
       v.push_back(i);
      }
   
        vector<int>res;
        bool f=true;
        for(auto i:vp){
            if(!vis[i])return v;
             for(auto j:rev_adj[i]){
            if(!vis[j])return v;
            s.erase(j);
        }
        s.erase(i);
        }
        
        s.erase(k);
        v.clear();
        for(auto i:s)v.push_back(i);
        return v;
        
    }
};
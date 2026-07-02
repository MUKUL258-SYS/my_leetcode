class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
      vector<int>indegree(n,0);
      vector<set<int>>adj(n);
      for(auto i:roads){
        int u=i[0];
        int v=i[1];
        adj[u].insert(v);
        adj[v].insert(u);
      }
      int maxi=0;
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
         int ans=adj[i].size()+adj[j].size();
         if(adj[i].contains(j))ans--;
         maxi=max(maxi,ans);
        }
      }
      return maxi;
     
 
    
    }
};
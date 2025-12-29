class Solution {
public:
void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int &res){
    vis[node]=1;
    res++;
    for(auto nei:adj[node]){
        if(!vis[nei])dfs(nei,vis,adj,res);
    }
}
    int makeConnected(int n, vector<vector<int>>& c) {
        int m=c.size();
      int cnt=0;
      vector<vector<int>>adj(n);
      int t=0;
      for(auto i:c){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
        t++;
      }
      vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        int res=0;
       if(!vis[i]){
        dfs(i,vis,adj,res);
        t-=(res-1);
        cnt++;
       }
    }
    return t>=cnt-1?cnt-1:-1;
    }
};
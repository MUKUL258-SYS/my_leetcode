class Solution {
public:
int n;
int dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
   //vector<bool>vis(n,false);
vis[node]=true;
int ans=1;
for(auto i:adj[node]){
    if(i!=node&&!vis[i]){
        ans+=dfs(i,adj,vis);
    }
}
return ans;
}
long long helper(int x1,int y1,int x2,int y2){
    return  (1ll*(x1-x2)*(x1-x2)+1ll*(y1-y2)*(y1-y2));
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
              long long dist=helper(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1]);
              int r=bombs[i][2];
              if(dist<=(1ll*r*r)){
                adj[i].push_back(j);
              }
            }
        }
        ///simply apply dfs on all the fucking nodes
        int maxi=0;
        for(int i=0;i<n;i++){
             vector<bool>vis(n,false);
         maxi=max(maxi,dfs(i,adj,vis));
        }
        return maxi;
    }
};
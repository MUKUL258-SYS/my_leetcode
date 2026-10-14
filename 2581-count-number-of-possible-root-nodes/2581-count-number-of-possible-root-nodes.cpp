class Solution {
public:
vector<vector<int>>adj;
map<pair<int,int>,bool>mp;
int res,k;
int dfs(int node,vector<bool>&vis){
    vis[node]=true;
    int ans=0;
    for(auto nei:adj[node]){
        if(vis[nei])continue;
     ans+=(mp[{node,nei}]+dfs(nei,vis));
    }
    return ans;
}

void dfs2(int node,vector<bool>&vis,int ans){
    if(ans>=k){
        res++;
      ////  return ;
    }
    vis[node]=true;
    for(auto nei:adj[node]){
        if(vis[nei])continue;
       // ans-=mp[{node,nei}];
       // ans+=mp[{nei,node}];
        dfs2(nei,vis,ans-mp[{node,nei}]+mp[{nei,node}]);
    }
}
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
              int n=edges.size();
              adj.resize(n+1);
              this->k=k;
              res=0;
              for(auto i:edges){
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(i[0]);
              }
              for(auto i:guesses){
                   mp[{i[0],i[1]}]=true;
              }
              vector<bool>vis(n+1,false);
              int ans=dfs(0,vis);
              vis.assign(n+1,false);
                dfs2(0,vis,ans);
          return res;
    }
};
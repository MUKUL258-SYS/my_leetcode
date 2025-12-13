class Solution {
public:
int nodes,k;
void dfs(int u,vector<vector<pair<int,int>>>&adj,vector<int>&vis,int t){
     vis[u]=1;
     for(auto &i:adj[u]){
        int nei=i.first;

        int time=i.second;
        if(!vis[nei]&&time>t){
            dfs(nei,adj,vis,t);
        }
     }
}
bool helper(int time,vector<vector<pair<int,int>>>adj){
    int components=0;
    vector<int>vis(nodes,0);
    for(int i=0;i<nodes;i++){
        if(!vis[i]){
             components++;
            dfs(i,adj,vis,time);
           // components++;
        }
    }
    return components>=k;
}
    int minTime(int n, vector<vector<int>>& edges, int k) {
      nodes=n;
      this->k=k;
      vector<vector<pair<int,int>>>adj(n);
      int high=0;
      int low=0;
      for(auto i:edges){
     int u=i[0];
     int v=i[1];
     int t=i[2];
     adj[u].push_back({v,t});
     adj[v].push_back({u,t});
     high=max(high,t);
      }
      while(low<=high){
        int mid=(low+high)/2;
        if(helper(mid,adj)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
      }
      return low;
    }
};
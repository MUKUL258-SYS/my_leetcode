class Solution {
public:

//int node1,node2;
vector<vector<int>>adj;
void dfs(int node,vector<bool>&vis,int d,unordered_map<int,int>&dis){
    vis[node]=true;
  dis[node]=d;
    for(auto nei:adj[node]){
        if(!vis[nei]){
            dfs(nei,vis,d+1,dis);

        }
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
       // this->node1=node1;
       // this->node2=node;
      int n=edges.size();
      adj.resize(n);
      for(int i=0;i<n;i++){
        if(edges[i]==-1){
          //  adj[i].push_back(i);
            continue;
        }
        adj[i].push_back(edges[i]);
      }
      unordered_map<int,int>dis1,dis2;
      vector<bool>vis(n,false);
      dfs(node1,vis,0,dis1);
      vis.assign(n,false);
      dfs(node2,vis,0,dis2);
      int mini=INT_MAX;
      int ans=-1;
      for(auto i:dis1){
        int node=i.first;
          if(dis2.find(node)!=dis2.end()){
             int dist=max(i.second,dis2[node]);
             if(dist<mini){
                mini=dist;
                ans=i.first;
             }
             else if(dist==mini && node<ans){
                      mini=dist;
                      ans=node;
             }
            
          }
      }
      return ans;

    }
};
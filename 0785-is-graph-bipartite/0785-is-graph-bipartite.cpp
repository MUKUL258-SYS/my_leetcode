class Solution {
public:
vector<vector<int>>adj;
bool dfs(int node,int c,vector<int>&color){
    color[node]=c;
  for(auto nei:adj[node]){
    if(color[nei]==-1 &&!dfs(nei,1-c,color))return false;
    else if(color[node]==color[nei])return false;
  }
  return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
int n=graph.size();
        //   return dfs()
      adj=graph;
        vector<int>c(n,-1);
        for(int i=0;i<n;i++){
            if(c[i]==-1 && !dfs(i,0,c))return false;
        }
        return true;
    }
};
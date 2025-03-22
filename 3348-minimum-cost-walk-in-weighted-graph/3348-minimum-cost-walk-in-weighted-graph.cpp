class Solution {
public:
vector<int>parent,vis,cost;
vector<vector<vector<int>>>adj;
void dfs(int node,int p){
    vis[node]=1;
    parent[node]=p;
    //cost[p]=cost[p]&(adj[node][1]);
    for(auto &x:adj[node]){
        int child=x[0];
        int weight=x[1];
   cost[p] &=weight;
        if(!vis[child]){
            dfs(child,p);
        }
    }
}
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        cost.resize(n,INT_MAX);
        parent.resize(n);
        vis.resize(n,0);
        adj.resize(n);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        int p=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
               dfs(i,p);
               p++;
            }
        }
        vector<int>ans;
        for(auto i:query){
            if(parent[i[0]]==parent[i[1]]){
               ans.push_back(cost[parent[i[0]]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
class Solution {
public:
long long res=0;
vector<vector<int>>adj;
long long dfs(int node,int parent,vector<int>&cost){
    long long cnt=0;
    long long maxi=0;
    long long maxi_cnt=0;
    for(auto nei:adj[node]){
        if(nei!=parent){
         long long value=dfs(nei,node,cost);
         if(value>maxi){
            maxi=value;
            maxi_cnt=1;
         }   
         else if(value==maxi){
            maxi_cnt++;
         }
         cnt++;
        }
    }
    res+=cnt-maxi_cnt;
    return cost[node]+maxi;
}
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        adj.resize(n,{});
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0,-1,cost);
        return res;
    }
};
class Solution {
public:
unordered_map<int,int>mp;
vector<long long>dp;
vector<vector<int>>adj;
long long dfs(int node){
   if(adj[node].size()==0){
    return mp[node];
   }
    long long mini=LLONG_MAX;
    long long maxi=LLONG_MIN;
    for(auto nei:adj[node]){
        long long v=dfs(nei);
        mini=min(mini,v);
        maxi=max(maxi,v);


    }
    return mp[node]+((2ll*maxi)-mini);
   // dp[node]=mp[node]+1ll*((2ll*maxi)-mini);

}
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& b) {
        //int m=b.size();
        for(int i=0;i<n;i++){
             mp[i]=b[i];
        }
        adj.resize(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
        }
      return dfs(0);
      
    }
};
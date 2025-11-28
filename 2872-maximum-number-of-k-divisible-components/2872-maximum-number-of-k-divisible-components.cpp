class Solution { 
public:
vector<vector<int>>adj;
long long ans=0,K;
long long dfs(int node,int parent,vector<int>&values){
    long long sum=values[node];
    for(auto nei:adj[node]){
        if(nei!=parent){
            sum+=dfs(nei,node,values);

        }
    }
    if(sum%K==0){
        ans++;
        return 0;
    }
    return sum;

}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
     adj.assign(n,{});
     K=k;
     for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
     }
       dfs(0,-1,values);
      return ans;  
        
    }
};
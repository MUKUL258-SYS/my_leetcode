class Solution {
public:
vector<vector<int>>dp;
int n;
int solver(int mask){
    int nodes=0;
    int edges=0;
    int maxdist=0;
  for(int i=0;i<n;i++){
    if((mask&(1<<i))==0)continue;
    nodes++;
    for(int j=i+1;j<n;j++){
           if((mask&(1<<j))==0)continue;
           if(dp[i][j]==1)
           edges++;
           maxdist=max(maxdist,dp[i][j]);
        

    }
  }
  if((edges+1) == nodes)return maxdist;
  return 0;
}
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
    dp.resize(n,vector<int>(n,INT_MAX));
    this->n=n;
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        dp[u-1][v-1]=1;
        dp[v-1][u-1]=1;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][k]==INT_MAX||dp[j][k]==INT_MAX)continue;
                dp[i][j]=dp[j][i]=min({dp[i][j],dp[j][i],dp[i][k]+dp[j][k]});
            }
        }
    }
    vector<int>res(n-1,0);
for(int i=0;i<(1<<n);i++){
    int ans=solver(i);
    if(ans>0){
       res[ans-1]++;
    }
}
return res;
    }
};
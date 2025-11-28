class Solution {
public:
vector<vector<vector<int>>>dp;
vector<vector<int>>grid;
int mod=1e9+7;
int n,m,k;
int dfs(int i,int j,int rem){
    if(i>=n||j>=m)return 0;
      rem=(rem+grid[i][j])%k;
      if(i==n-1&&j==m-1){
        if(rem==0)return 1;
        return 0;
      }
      if(dp[i][j][rem]!=-1)return dp[i][j][rem];
      int ans=0;
      ans+=dfs(i+1,j,rem);
      ans+=dfs(i,j+1,rem);
      ans=ans%mod;
   return dp[i][j][rem]=ans%mod;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        this->k=k;
  this->grid=grid;
       dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+5,-1)));
      return dfs(0,0,0); 
    }
};
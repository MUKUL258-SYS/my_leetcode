class Solution {
public:
vector<vector<int>>grid;
vector<vector<bool>>vis;
int dp[51][51][2510];
int n;
int dfs(int i,int j,int t){
      if(i<0||j<0||i>=n||j>=n||vis[i][j])return INT_MAX;
      if(i==n-1&&j==n-1)return t+max(0,grid[i][j]-t);
      if(dp[i][j][t]!=-1)return dp[i][j][t];
      int ans=INT_MAX;
      vis[i][j]=true;
      ans=min(ans,dfs(i+1,j,t+max(0,grid[i][j]-t)));
       ans=min(ans,dfs(i,j+1,t+max(0,grid[i][j]-t)));
        ans=min(ans,dfs(i-1,j,t+max(0,grid[i][j]-t)));
         ans=min(ans,dfs(i,j-1,t+max(0,grid[i][j]-t)));
         vis[i][j]=false;
         return dp[i][j][t]=ans;
      
}
    int swimInWater(vector<vector<int>>& grid) {
        this->grid=grid;
         n=grid.size();
        memset(dp,-1,sizeof(dp));
        vis.resize(n+5,vector<bool>(n+5,false));
        return dfs(0,0,0);
    }
};
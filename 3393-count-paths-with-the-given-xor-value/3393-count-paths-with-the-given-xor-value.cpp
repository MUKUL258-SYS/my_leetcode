class Solution {
public:
int k;
int n,m;
int mod=1e9+7;
//vector<vector<int>>grid;
int dp[400][400][20];
int dfs(int i,int j,int x,vector<vector<int>>&grid){
    if(i==n-1 && j==m-1){
        if(x==k)return 1;
        return 0;
    }
    if(i<0||i>=n||j<0||j>=m)return 0;
    if(dp[i][j][x]!=-1)return dp[i][j][x];
    int ans=0;
    if(i+1<n){
        ans=(ans+dfs(i+1,j,grid[i+1][j]^x,grid))%mod;
    }
    if(j+1<m){
        ans=(ans+dfs(i,j+1,grid[i][j+1]^x,grid))%mod;
    }
    return dp[i][j][x]=ans%mod;
}
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        //this->grid=grid;
      //  memset(dp,-1,sizeof(dp));
      for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            for(int kl=0;kl<20;kl++)dp[i][j][kl]=-1;
        }
      }
        this->k=k;
        return dfs(0,0,grid[0][0],grid);
    }
};
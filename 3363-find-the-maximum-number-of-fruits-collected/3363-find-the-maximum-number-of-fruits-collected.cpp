class Solution {
public:
int n;
vector<vector<int>>grid;
int dfs2(int i,int j,vector<vector<int>>&dp){
    if(i==n-1&&j==n-1)return 0;
     if(i>=n||j>=n ||i<=j||i<0)return -1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    //vis[i][j]=true;
   int ans=0;
      ans=max(ans,dfs2(i+1,j+1,dp));
      ans=max(ans,dfs2(i,j+1,dp));
      ans=max(ans,dfs2(i-1,j+1,dp));
      return dp[i][j]=ans+grid[i][j];
}
int dfs1(int i,int j,vector<vector<int>>&dp){
    if(i==n-1&&j==n-1)return 0;
    if (i >= n || j >= n || j <= i || j < 0) return -1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    //vis[i][j]=true;
   int ans=0;
      ans=max(ans,dfs1(i+1,j-1,dp));
      ans=max(ans,dfs1(i+1,j+1,dp));
      ans=max(ans,dfs1(i+1,j,dp));
      return dp[i][j]=ans+grid[i][j];
}
    int maxCollectedFruits(vector<vector<int>>& grid) {
        this->grid=grid;
        n=grid.size();
        int sum=grid[n-1][n-1];
        int i=n-2;
        int j=n-2;
      //  set<pair<int,int>>s;
      vector<vector<int>>vis(n,vector<int>(n,false));
       vector<vector<int>>dp(n,vector<int>(n,-1));
     dp[n-1][n-1]=grid[n-1][n-1];
        while(i>=0&&j>=0){
             // cout<<i<<" "<<j<<endl;
            sum+=grid[i][j];
            //s.insert({i,j});
            vis[i][j]=true;
            dp[i][j]=grid[i][j]+dp[i+1][j+1];
            i--;
            j--;
            
        }
     sum+=dfs1(0,n-1,dp);
     sum+=dfs2(n-1,0,dp);
     return sum;
       
    }
};
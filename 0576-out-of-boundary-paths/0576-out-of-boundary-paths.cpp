class Solution {
public:
int n,m;
long long dp[100][100][100];
long long mod=1e9+7;
long long dfs(int i,int j,int moves){
   if(i<0||j<0||i>=n||j>=m)return 1;
   if(moves<=0)return 0;
   if(dp[i][j][moves]!=-1)return dp[i][j][moves];
   long long ans=0;
 ans=(ans+dfs(i+1,j,moves-1))%mod;
 ans=(ans+dfs(i,j+1,moves-1))%mod;
 ans=(ans+dfs(i-1,j,moves-1))%mod;
 ans=(ans+dfs(i,j-1,moves-1))%mod;
 return dp[i][j][moves]=ans;
}
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        this->n=n;
        this->m=m;
        memset(dp,-1,sizeof(dp));
        return dfs(startRow,startColumn,maxMove);
    }
};
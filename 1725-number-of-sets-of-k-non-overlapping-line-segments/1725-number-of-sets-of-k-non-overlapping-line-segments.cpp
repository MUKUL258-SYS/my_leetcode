class Solution {
public:
int mod=1e9+7;
int dp[1111][1111];
int dfs(int n,int k){
    if(k>=n)return 0;
    if(k<=0)return 1;
    if(dp[n][k]!=-1)return dp[n][k];
    dp[n][k]=dfs(n-1,k)%mod;
    for(int i=1;i<n;i++){
        dp[n][k]=(dp[n][k]+dfs(n-i,k-1))%mod;;
    }
    return dp[n][k];
}
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<n;i++){
            dp[i][i-1]=1;
        }
        return dfs(n,k);
    }
};
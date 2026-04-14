class Solution {
public:
static const int MOD=1e9+7;
int dp[4002][1002];
int offset=1000;
int dfs(int curr,int end,int k){
    if(k==0){
        if(curr==end)
        return 1;
        return 0;
    }
    if(dp[curr+offset][k]!=-1)return dp[curr+offset][k];
    int ans=0;
    ans=(ans+dfs(curr+1,end,k-1))%MOD;
    ans=(ans+dfs(curr-1,end,k-1))%MOD;
    return dp[curr+offset][k]=ans%MOD;

}
    int numberOfWays(int s, int e, int k) {
        for(int i=0;i<4002;i++){
            for(int j=0;j<1002;j++){
                dp[i][j]=-1;
            }
        }
        return dfs(s,e,k);
    }
};
class Solution {
public:
int limit;
int mod=1e9+7;
int dp[201][201][2];
int dfs(int z,int o,int last){
    if(o==0&&z==0){
        return 1;
    }
    if(dp[z][o][last]!=-1)return dp[z][o][last];
    long long ans=0;
    if(last==1){
        for(int i=1;i<=min(z,limit);i++){
           ans=(ans+dfs(z-i,o,0))%mod;
        }
    }
    else{
        for(int i=1;i<=min(o,limit);i++){
            ans=(ans+dfs(z,o-i,1))%mod;
        }
    }
    return dp[z][o][last]=ans;
}
    int numberOfStableArrays(int zero, int one, int limit) {
        this->limit=limit;
           memset(dp,-1,sizeof(dp));
           return (dfs(zero,one,0)+dfs(zero,one,1))%mod;
    }
};
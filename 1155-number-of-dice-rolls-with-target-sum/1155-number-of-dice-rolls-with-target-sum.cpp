class Solution {
public:
int k;
  int mod=1e9+7;
  int dp[31][1002];
long long dfs(int n,int target){
    if(n==0){
        if(target==0)
        return 1;
    return 0;
    }
    if(n<0||target<0){
        return 0;
    }
    if(dp[n][target]!=-1)return dp[n][target];
    long long ans=0;
    for(int i=1;i<=k;i++){
      ans=(ans+dfs(n-1,target-i))%mod;
    }
    return dp[n][target]=ans;
}
    int numRollsToTarget(int n, int k, int target) {
      //  int mod=1e9+7;
        this->k=k;
        int ans=0;
        for(int i=0;i<31;i++){
            for(int j=0;j<1002;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=1;i<=k;i++){
         ans=(ans+dfs(n-1,target-i))%mod;
        }
        return ans;
    }
};
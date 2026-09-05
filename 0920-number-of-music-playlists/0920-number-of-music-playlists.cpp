class Solution {
public:
int g;
int mod;
int n,k;
int dp[105][105];
int dfs(int used,int len){
    if(len==g){
        if(used==n)
        return 1;
    return 0;
    }
    if(dp[used][len]!=-1)return dp[used][len];
    int op1=(1ll*(n-used)*dfs(used+1,len+1))%mod;
    int op2=(1ll*max(0,used-k)*dfs(used,len+1))%mod;
    return dp[used][len]=(op1+op2)%mod;
}
    int numMusicPlaylists(int n, int goal, int k) {
   g=goal;
   mod=1e9+7;
   this->n=n;
   this->k=k;
   memset(dp,-1,sizeof(dp));
  return dfs(0,0);
        
    }
};
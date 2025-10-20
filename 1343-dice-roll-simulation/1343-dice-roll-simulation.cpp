class Solution {
public:
vector<int>v;
int mod=1e9+7;
int dp[5005][8][20];
int dfs(int n,int last_digit,int freq){
  if(n<=0)return 1;
  if(dp[n][last_digit][freq]!=-1)return dp[n][last_digit][freq];
  int ans=0;
  for(int j=1;j<7;j++){
    /*if((j==last_digit)&&(freq<v[last_digit-1])){
       ans=(ans+dfs(n-1,j,freq+1))%mod;
    }
    else ans=(ans+dfs(n-1,j,1))%mod;
    */
    if(j!=last_digit||freq<v[last_digit-1]){
        ans+=dfs(n-1,j,(j==last_digit)?freq+1:1);
        ans%=mod;
    }
  }
return dp[n][last_digit][freq]=ans;
}
    int dieSimulator(int n, vector<int>& rollMax) {
        v=rollMax;
        memset(dp,-1,sizeof(dp));
        return dfs(n,6,0);
    }
};
class Solution {
public:
vector<vector<vector<int>>>dp;
int n;
int mod=1e9+7;
int dfs(int ind,int p1,int p2){
    if(ind==n)return 1;
    int ans=0;
    if(dp[ind][p1][p2]!=-1)return dp[ind][p1][p2];
    for(int i=1;i<=6;i++){
        if(p1!=i&&p2!=i&&(p1==0||__gcd(i,p1)==1)){
          ans=(ans+dfs(ind+1,i,p1))%mod;
        }
    }
    return dp[ind][p1][p2]=ans;
}
    int distinctSequences(int n) {
        this->n=n;
        dp.resize(n+1,vector<vector<int>>(7,vector<int>(7,-1)));
        return dfs(0,0,0);
    }
};
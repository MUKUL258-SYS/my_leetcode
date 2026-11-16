class Solution {
public:
int m,n;
int minProfit;
vector<int>p,g;
int mod=1e9+7;
int dp[101][101][101];
int dfs(int i,int profit,int num){

    if(i>=m){
        if(profit >= minProfit && num<=n){
            return 1;
        }
        return 0;
    }
    if(dp[i][profit][num]!=-1)return dp[i][profit][num];
    long long ans=dfs(i+1,profit,num);
    if(num+g[i] <= n)
    ans+=dfs(i+1,min(minProfit,profit+p[i]),num+g[i]);
    //int op2=dfs(i+1,profit,num);
    return dp[i][profit][num]=ans%mod;
}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        m=group.size();
        this->minProfit=minProfit;
        this->n=n;
      p=profit;
      g=group;
     /* for(int i=0;i<=m;i++){
        for(int j=0;j<= minProfit;j++){
            for(int k=0;k<=n;k++){
                dp[i][j][k]=-1;
            }
        }
      }*/
      memset(dp,-1,sizeof(dp));
        return dfs(0,0,0);
    }
};
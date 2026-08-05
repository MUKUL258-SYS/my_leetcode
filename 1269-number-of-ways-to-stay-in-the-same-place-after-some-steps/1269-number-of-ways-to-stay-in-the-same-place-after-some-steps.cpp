class Solution {
public:
int n;
int steps;
int mod=1e9+7;
vector<vector<long long>>dp;
int dfs(int i,int s){
    if(i>=n ||i<0 || s>steps)return 0;
   if(s==steps){
    if(i==0)return 1;
    return 0;
   }
    if(dp[i][s]!=-1)return dp[i][s];
    int op1=dfs(i+1,s+1);
    int op2=dfs(i-1,s+1);
    int op3=dfs(i,s+1);
    return dp[i][s]=(1ll*op1+op2+op3)%mod;
}
    int numWays(int steps, int arrLen) {
        n=min(arrLen,steps+1);
        this->steps=steps;
    dp.assign(n+1,vector<long long>(steps+1,-1));
        return dfs(0,0);
    }
};
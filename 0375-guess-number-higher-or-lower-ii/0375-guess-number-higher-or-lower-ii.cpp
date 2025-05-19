class Solution {
public:
int dfs(vector<vector<int>>&dp,int l,int r){
    if(l>=r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int ans=INT_MAX;
    for(int i=l;i<=r;i++){
   ans=min(ans,i+max(dfs(dp,l,i-1),dfs(dp,i+1,r)));
    }
    return dp[l][r]=ans;
}
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+5,vector<int>(n+5,-1));
        return dfs(dp,1,n);
    }
};
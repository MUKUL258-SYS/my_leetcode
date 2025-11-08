class Solution {
public:
int dp[6000][4];
int dfs(int ind,int b,vector<int>&prices){
    if(ind>=prices.size()){
        return 0;

    }
    if(dp[ind][b]!=-1)return dp[ind][b];
    int ans=0;
    if(b){
        ans=max(-prices[ind]+dfs(ind+1,0,prices),dfs(ind+1,1,prices));
    }
    else{
        ans=max(prices[ind]+dfs(ind+2,1,prices),dfs(ind+1,0,prices));
    }
    return dp[ind][b]=ans;
}
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,1,prices);
    }
};
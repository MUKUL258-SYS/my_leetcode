class Solution {
public:
int solver(int n,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int mini=INT_MAX;
    for(int i=1;i*i<=n;i++){
        int cnt=1+solver(n-(i*i),dp);
        mini=min(mini,cnt);
    }
    return dp[n]=mini;
}
    int numSquares(int n) {
        vector<int>dp(n+5,-1);
        return solver(n,dp);
    }
};
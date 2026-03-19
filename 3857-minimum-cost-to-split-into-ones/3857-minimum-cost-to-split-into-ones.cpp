class Solution {
public:
vector<int>dp;
int dfs(int n){
    if(n==1||n==2)return n-1;
    if(dp[n]!=-1)return dp[n];
    int cost=INT_MAX;
for(int i=1;i<n;i++){
    cost =min(cost,i*(n-i)+dfs(i)+dfs(n-i));
}
    return dp[n]=cost;
}
    int minCost(int n) {
        dp.resize(n+1,-1);
        return dfs(n);
    }
};
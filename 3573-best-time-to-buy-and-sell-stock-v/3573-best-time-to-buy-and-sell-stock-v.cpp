class Solution {
public:
vector<int>v;
int k;
long long dp[1002][501][3];
long long dfs(int i,int t,int hold){
    int n=v.size();
    if(i==n){
        if(hold==0)return 0;
        return LLONG_MIN/2;
    }
    if(dp[i][t][hold]!=-1)return dp[i][t][hold];
    long long ans=dfs(i+1,t,hold);
    if(hold==0){
        ans=max(ans,v[i]+dfs(i+1,t,1));
        ans=max(ans,-v[i]+dfs(i+1,t,2));
    }
    else if(hold==1&&t<k){
        ans=max(ans,-v[i]+dfs(i+1,t+1,0));
    }
    else if(hold==2&&t<k){
        ans=max(ans,v[i]+dfs(i+1,t+1,0));
    }
    return dp[i][t][hold]=ans;
}
    long long maximumProfit(vector<int>& prices, int k) {
        v=prices;
        this->k=k;
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,0);
    }
};
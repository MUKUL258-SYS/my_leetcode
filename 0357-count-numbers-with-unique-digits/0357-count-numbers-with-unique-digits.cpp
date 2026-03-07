class Solution {
public:
int n;
vector<vector<int>>dp;
int dfs(int mask,int len){
    if(len==n)return 0;
    int ans=0;
    if(dp[mask][len]!=-1)return dp[mask][len];
    for(int i=0;i<=9;i++){
        if(len==0&&i==0)continue;
        if(mask&(1<<i))continue;
        ans+=(1+dfs(mask|(1<<i),len+1));
    }
    return dp[mask][len]=ans;
}
    int countNumbersWithUniqueDigits(int n) {
        dp.resize(1030,vector<int>(10,-1));
        this->n=n;
        return 1+dfs(0,0);
    }
};
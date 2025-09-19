class Solution {
public:
vector<int>v;
int dp[555][555];
int dfs(int idx,int i){
    if(idx>=v.size())return 0;
    if(dp[idx][i]!=-1)return dp[idx][i];
    int inc=v[idx]*i+dfs(idx+1,i+1);
    int exc=dfs(idx+1,i);
    return dp[idx][i]=max(inc,exc);
}
    int maxSatisfaction(vector<int>& satisfaction) {
        v=satisfaction;
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return dfs(0,1);
    }
};
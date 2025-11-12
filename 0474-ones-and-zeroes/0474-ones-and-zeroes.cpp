class Solution {
public:
vector<string>v;
int dp[700][105][105];
int dfs(int i,int m,int n){
    if(i>=v.size())return 0;
    if(m<=0&&n<=0)return 0;
    if(dp[i][m][n]!=-1)return dp[i][m][n];
    int exc=dfs(i+1,m,n);
    int cnt0=0;
    int cnt1=0;
    int inc=0;
    for(auto j:v[i]){
        if(j=='0')cnt0++;
        else cnt1++;
    }

    if(cnt1<=n&&cnt0<=m)inc=1+dfs(i+1,m-cnt0,n-cnt1);
    return dp[i][m][n]=max(inc,exc);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
       v=strs;
       memset(dp,-1,sizeof(dp));
       return dfs(0,m,n);
    }
};
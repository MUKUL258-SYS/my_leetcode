class Solution {
public:
int m,n;
int dp[105][105];
int dfs(int i,int j){
    if(i==m-1 && j==n-1)return 1;
    if(i<0 ||i>=m || j<0 ||j>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int a=dfs(i+1,j);
    int b=dfs(i,j+1);
    return dp[i][j]=a+b;
}
    int uniquePaths(int m, int n) {
        this->m=m;
        this->n=n;
        memset(dp,-1,sizeof(dp));
        return dfs(0,0);
    }
};
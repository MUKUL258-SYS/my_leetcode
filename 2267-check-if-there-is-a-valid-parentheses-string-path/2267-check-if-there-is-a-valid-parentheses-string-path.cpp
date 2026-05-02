class Solution {
public:
int dp[100][100][205];
int n,m;
vector<vector<char>>grid;
bool dfs(int i,int j,int k){
    if(i>=n||j>=m)return false;
    if(grid[i][j]=='(')k++;
    else k--;
    if(k<0)return false;
    if(i==n-1&&j==m-1)return k==0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    return dp[i][j][k]=dfs(i+1,j,k)||dfs(i,j+1,k);
}
    bool hasValidPath(vector<vector<char>>& grid) {
        this->grid=grid;
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
      return  dfs(0,0,0);
    }
};
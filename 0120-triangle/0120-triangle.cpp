class Solution {
public:
vector<vector<int>>v;
int dp[205][205];
int maxi=100005;
int dfs(int row,int col){
    if(row>=v.size())return 0;
    if(dp[row][col]!=maxi)return dp[row][col];
    return dp[row][col]=v[row][col]+min(dfs(row+1,col),dfs(row+1,col+1));
}
    int minimumTotal(vector<vector<int>>& triangle) {
      v=triangle;
     // memset(dp,maxi,sizeof(dp));
     for (int i = 0; i < 205; i++)
            for (int j = 0; j < 205; j++)
        dp[i][j] = maxi;

      return dfs(0,0);
    }
};
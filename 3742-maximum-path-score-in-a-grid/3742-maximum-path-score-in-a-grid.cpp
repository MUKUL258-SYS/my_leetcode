class Solution {
public:
vector<vector<int>>grid;
int n,m;
int dfs(int i,int j,vector<vector<vector<int>>>&dp,int c,int k){
    if(i==n||j==m)return INT_MIN;
    if(dp[i][j][c]!=-1)return dp[i][j][c];
    int ac=0;
    int as=0;
    if(grid[i][j]==1){
        ac+=1;
        as+=1;
    }
    else if(grid[i][j]==2){
        ac+=1;
        as+=2;
    }
    if(c+ac>k)return dp[i][j][c]=INT_MIN;
    if(i==n-1&&j==m-1)return dp[i][j][c]=as;
    int left=dfs(i+1,j,dp,c+ac,k);
    int right=dfs(i,j+1,dp,c+ac,k);
    int maxi=max(left,right);
    if(maxi==INT_MIN)return dp[i][j][c]=INT_MIN;
    return dp[i][j][c]=as+maxi;
}
    int maxPathScore(vector<vector<int>>& grid2, int k) {
        n=grid2.size();
        m=grid2[0].size();
       grid=grid2;
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+5,-1)));
           int ans=dfs(0,0,dp,0,k);
           if(ans==INT_MIN)return -1;
           return ans;
    }
};
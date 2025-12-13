class Solution {
public:
int n,m;
int dp[500][500][4];
vector<vector<int>>grid;
int mod=1e9+7;
int dfs(int x,int y,int dir){
    if(x>=n||y>=m){
        return 0;
    }
    if(x==n-1&&y==m-1)return 1;
    if(dp[x][y][dir+1]!=-1)return dp[x][y][dir+1];
    int ans=0;
    if(grid[x][y]==0){
        ans=(ans+dfs(x+1,y,-1))%mod;
        ans=(ans+dfs(x,y+1,1))%mod;
    }
    else{
        if(dir==-1){
            ans=(ans+dfs(x,y+1,1))%mod;
        }
        else{
            ans=(ans+dfs(x+1,y,-1))%mod;
        }
    }

    return dp[x][y][dir+1]=ans%mod;
}
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        this->grid=grid;
        return dfs(0,0,0);
    }
};
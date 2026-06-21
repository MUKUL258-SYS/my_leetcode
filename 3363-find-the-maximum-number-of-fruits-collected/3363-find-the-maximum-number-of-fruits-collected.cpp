class Solution {
public:
int n;
vector<vector<int>>v;
bool helper(int x,int y,vector<vector<int>>&vis){
    if(x==y)return false;
    if(x<0||x>=n||y<0||y>=n||vis[x][y])return false;
    return true;
}
int dfs(int x,int y,vector<vector<int>>&dp){
    if(x==n-1 && y==n-1)return 0;
    if(y<0||y>=n||x>=y)return -1e9;
    if(dp[x][y]!=-1)return dp[x][y];
   int cost=v[x][y];
   int a=dfs(x+1,y,dp);
   int b=dfs(x+1,y-1,dp);
   int c=dfs(x+1,y+1,dp);
   return dp[x][y]=cost+max({a,b,c});

}
int dfs2(int x,int y,vector<vector<int>>&dp){
if(x==n-1 && y==n-1)return 0;
   if(x<0||x>=n||y>=x)return -1e9;
    if(dp[x][y]!=-1)return dp[x][y];
   int cost=v[x][y];
  
   int a=dfs2(x+1,y+1,dp);
   int b=dfs2(x,y+1,dp);
   int c=dfs2(x-1,y+1,dp);
   return dp[x][y]=cost+max({a,b,c});

}
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        v=fruits;
        int cost=0;
        for(int i=0;i<n;i++){
            cost+=fruits[i][i];
        }
        vector<vector<int>>dp1(n,vector<int>(n,-1));
         cost+=dfs(0,n-1,dp1);
          vector<vector<int>>dp2(n,vector<int>(n,-1));
        int vx=dfs2(n-1,0,dp2);
        return cost+vx;
    }
};
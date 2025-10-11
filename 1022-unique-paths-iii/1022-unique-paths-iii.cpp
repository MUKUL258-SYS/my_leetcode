class Solution {
public:
//vector<vector<int>>dp;
int c;
int dfs(int i,int j,vector<vector<int>>&grid,int cnt){
    int n=grid.size();
    int m=grid[0].size();
    if(i>=n||i<0||j>=m||j<0||grid[i][j]==-1)return 0;
    if(grid[i][j]==2){
        if(cnt==c)return 1;
        else return 0;
    }
    int ans=0;
    int old_value=grid[i][j];
   grid[i][j]=-1;
   ans+=dfs(i+1,j,grid,cnt+1);
   ans+=dfs(i,j+1,grid,cnt+1);
   ans+=dfs(i-1,j,grid,cnt+1);
   ans+=dfs(i,j-1,grid,cnt+1);
   grid[i][j]=old_value;
   return ans;

}
    int uniquePathsIII(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       c=0;
      // vector<vector<int>>dp(n,vector<int>(m,-1));
       int sx,sy;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(grid[i][j]==1){
            sx=i;
            sy=j;
            c++;
           }
           else if(grid[i][j]==0)c++;
        }
       }
        return dfs(sx,sy,grid,0);
    }
};
class Solution {
public:
int color;
 int org_color;
vector<int>dx={0,1,0,-1};
vector<int>dy={1,0,-1,0};
void dfs(int r,int c,vector<vector<bool>>&vis,vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    if(r>=n||r<0||c>=m||c<0||vis[r][c]||grid[r][c]!=org_color)return ;
   // int org_color=grid[r][c];
    vis[r][c]=true;
  // if(r==0||c==0||r==(n-1)||c==(m-1))
    grid[r][c]=color;
    for(int k=0;k<4;k++){
        int nr=r+dx[k];
        int nc=c+dy[k];
       dfs(nr,nc,vis,grid);
    }

}
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size();
        int m=grid[0].size();
        this->color=color;
        org_color=grid[row][col];
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        dfs(row,col,vis,grid);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0&&i+1<n&&j-1>=0&&j+1<m){
                    if(vis[i][j]&&vis[i-1][j]&&vis[i+1][j]&&vis[i][j-1]&&vis[i][j+1])grid[i][j]=org_color;
                }
            }
        }
        return grid;
    }
};
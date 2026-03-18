class Solution {
public:
vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
vector<vector<int>>grid;
long long dfs(int x,int y,vector<vector<int>>&vis){
    if(x<0||x>=n||y<0||y>=m||!grid[x][y]||vis[x][y])return 0;
    vis[x][y]=1;
    long long ans=grid[x][y];
    for(int k=0;k<4;k++){
        int nx=dirs[k][0]+x;
        int ny=dirs[k][1]+y;
        ans+=dfs(nx,ny,vis);
    }
    return ans;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        this->grid=grid;
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
       /* for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              grid[i][j]=grid[i][j]%k;

             }
        }*/
        int cnt=0,components=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]&&(!vis[i][j])){
                    components++;
                    long long v=dfs(i,j,vis);
                    if((v%k)==0){
                       cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
bool helper(int x,int y,vector<vector<int>>&grid,vector<vector<bool>>&vis){
    int n=grid.size();
    int m=grid[0].size();
    if(x<0||y<0||x>=n||y>=m||grid[x][y]==2)return false;
    return true;
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
       vector<vector<int>>grid(m,vector<int>(n,0));
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(auto i:guards){
            grid[i[0]][i[1]]=2;
        }
        for(auto i:walls){
            grid[i[0]][i[1]]=2;
        }
      
        vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
        for(auto i:guards){
            int sx=i[0];
            int sy=i[1];
            vis[sx][sy]=true;
            for(auto j:dirs){
              int nx=sx+j[0];
              int ny=sy+j[1];
              while(helper(nx,ny,grid,vis)){
                 grid[nx][ny]=1;
            nx+=j[0];
            ny+=j[1];
              }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
                if(grid[i][j]==0)cnt++;
            }
            cout<<endl;
        }
        return cnt;
        

    }
};
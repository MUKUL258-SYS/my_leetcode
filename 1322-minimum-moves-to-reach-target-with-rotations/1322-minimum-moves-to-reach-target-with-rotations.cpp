class Solution {
public:
int vis[101][101][2];
    int minimumMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<vector<int>>q;
        q.push({0,0,0,0});
        memset(vis,0,sizeof(vis));
        vis[0][0][0]=1;
        while(!q.empty()){
            int d=q.front()[0];
            int x=q.front()[1];
            int y=q.front()[2];
            int dir=q.front()[3];
            q.pop();
            if(dir==0 && x==n-1 && y==n-2)return d;
            if(dir==0){
                if(y+2<n&&grid[x][y+2]==0&&vis[x][y+1][0]==0){
                    q.push({d+1,x,y+1,0});
                    vis[x][y+1][0]=1;
                }
                if(x+1<n&&y+1<n&&grid[x+1][y]==0&&grid[x+1][y+1]==0&&vis[x+1][y][0]==0){
                    q.push({d+1,x+1,y,0});
                    vis[x+1][y][0]=1;
                }
                if(x+1<n&&y+1<n&&grid[x+1][y]==0&&grid[x+1][y+1]==0&&vis[x][y][1]==0){
                    q.push({d+1,x,y,1});
                    vis[x][y][1]=1;
                }
            }
            else{
                 if(x+2<n&&grid[x+2][y]==0&&vis[x+1][y][1]==0){
                    q.push({d+1,x+1,y,1});
                    vis[x+1][y][1]=1;
                }
                if(x+1<n&&y+1<n&&grid[x][y+1]==0&&grid[x+1][y+1]==0&&vis[x][y+1][1]==0){
                    q.push({d+1,x,y+1,1});
                    vis[x][y+1][1]=1;
                }
                if(x+1<n&&y+1<n&&grid[x][y+1]==0&&grid[x+1][y+1]==0&&vis[x][y][0]==0){
                    q.push({d+1,x,y,0});
                    vis[x][y][0]=1;
                }
            }

        }
        return -1;
    }
};
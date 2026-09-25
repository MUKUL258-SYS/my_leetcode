class Solution {
public:
int helper(vector<vector<int>>grid,int  n,int m){
    int islands=0;
    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0)continue;
            queue<pair<int,int>>q;
            grid[i][j]=0;
            islands++;
            q.push({i,j});
            while(!q.empty()){
                auto [x,y]=q.front();q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx<0 || nx>=n ||ny<0 ||ny>=m ||grid[nx][ny]==0)continue;
                    grid[nx][ny]=0;
                    q.push({nx,ny});
                }
            }
        }
    }
    return islands;
}
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int num=helper(grid,n,m);
        if(num!=1)return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    int num=helper(grid,n,m);
                    if(num!=1)return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};
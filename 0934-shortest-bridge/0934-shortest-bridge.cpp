class Solution {
public:
vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
int n;
queue<pair<int,int>>q;
void dfs(int i,int j,vector<vector<int>>&grid){
    grid[i][j]=2;
    q.push({i,j});
    for(int k=0;k<4;k++){
        int ni=i+dirs[k][0];
        int nj=j+dirs[k][1];
        if(ni>=0&&ni<n&&nj>=0&&nj<n&&grid[ni][nj]==1){
            dfs(ni,nj,grid);
        }
    }
}
    int shortestBridge(vector<vector<int>>& grid) {
         n=grid.size();
        int si,sj;
     bool f=true;
        for(int i=0;i<n&&f;i++){
            for(int j=0;j<n&&f;j++){
                if(grid[i][j]){
                    dfs(i,j,grid);
                    f=false;
                }
            }
        }
     
        int steps=0;
        while(!q.empty()){
              int sz=q.size();
              while(sz--){
                auto f=q.front();
                int i=f.first;
                int j=f.second;
                q.pop();
               // if(grid[i][j]==1)return steps;
                 for(int k=0;k<4;k++){
        int ni=i+dirs[k][0];
        int nj=j+dirs[k][1];
        if(ni>=0&&ni<n&&nj>=0&&nj<n){
                  if(grid[ni][nj]==2)continue;
                  if(grid[ni][nj]==1)return steps;
                q.push({ni,nj});
                grid[ni][nj]=2;
        }
    }
              }
              steps++;
        }
        return steps;
    }
};
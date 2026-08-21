class Solution {
public:
int n,m;
vector<vector<int>>dirs={{0,1},{1,0},{-1,0},{0,-1}};
void dfs(int i,int j,vector<vector<char>>&grid){
    if(i<0 ||i>=n ||j<0 ||j>=m || grid[i][j]=='0')return ;
     grid[i][j]='0';
     for(auto k:dirs){
        int ni=i+k[0];
        int nj=j+k[1];
        dfs(ni,nj,grid);
     }

}
    int numIslands(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(grid[i][j]=='1'){
                cnt+=1;
                dfs(i,j,grid);
              }
            }
        }
        return cnt;
    }
};
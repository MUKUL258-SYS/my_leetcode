class Solution {
public:
vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
bool checker(int i,int j){
    if(i<0||i>=n||j<0||j>=m)return true;
    return false;
}
bool dfs(char color,int pi,int pj,int si,int sj,vector<vector<char>>&grid){
    //if(grid[si][sj]==-color)return true;
grid[si][sj]=-color;
for(auto dir:dirs){
    int ni=si+dir[0];
    int nj=sj+dir[1];
    if(checker(ni,nj)||(ni==pi && nj==pj))continue;
    if(grid[ni][nj]==-color)return true;
    if(grid[ni][nj]==color){
        if(dfs(color,si,sj,ni,nj,grid))return true;
    }
}
return false;
   
}
    bool containsCycle(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]<0)continue;
                if(dfs(grid[i][j],-1,-1,i,j,grid))return true;
            }
        }
        return false;
    }
};
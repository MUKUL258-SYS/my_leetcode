class Solution {
public:
int n;
vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
bool safe(int x,int y){
    return (x>=0&&x<3*n&&y>=0&&y<3*n);
}
void dfs(int i,int j,vector<vector<int>>&grid){
   grid[i][j]=1;
   for(auto dir:dirs){
    int ni=i+dir[0];
    int nj=j+dir[1];
    if(safe(ni,nj)&&grid[ni][nj]==0)dfs(ni,nj,grid);
   }
}
    int regionsBySlashes(vector<string>& grid) {
         n=grid.size();
        int cnt=0;
        vector<vector<int>>arr(3*n,vector<int>(3*n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    arr[3*i+2][3*j+0]=1;
                    arr[3*i+1][3*j+1]=1;
                    arr[3*i+0][3*j+2]=1;
                }
                else if(grid[i][j]=='\\'){
                    arr[3*i+0][3*j+0]=1;
                    arr[3*i+1][3*j+1]=1;
                    arr[3*i+2][3*j+2]=1;
                }
            }
        }
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if(arr[i][j]==0){
                    dfs(i,j,arr);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
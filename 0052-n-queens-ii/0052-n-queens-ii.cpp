class Solution {
public:
int n;
bool checker(int row,int col){
    return (row>=0&&row<n&&col>=0&&col<n);
}
bool helper(int r,int c,vector<vector<bool>>&grid){
    for(int i=0;i<n;i++){
        if(grid[i][c])return false;
    }
    for(int j=0;j<n;j++){
        if(grid[r][j])return false;
    }
    for(int i=0;i<n;i++){
        if(checker(r-i,c-i)&&grid[r-i][c-i])return false;
        if(checker(r+i,c-i)&&grid[r+i][c-i])return false;
        if(checker(r-i,c+i)&&grid[r-i][c+i])return false;
        if(checker(r+i,c+i)&&grid[r+i][c+i])return false;
    }
    return true;
}
int dfs(vector<vector<bool>>&grid,int row){
     if(row>=n){
        return 1;
     }
     int ans=0;
     for(int col=0;col<n;col++){
        if(!grid[row][col]&&helper(row,col,grid)){
            grid[row][col]=true;
           ans+=dfs(grid,row+1);
            grid[row][col]=false;
        }
     }
     return ans;
}
    int totalNQueens(int n) {
      this->n=n; 
      vector<vector<bool>>grid(n,vector<bool>(n,false)); 
      return dfs(grid,0);
    }
};
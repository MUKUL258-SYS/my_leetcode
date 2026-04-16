class Solution {
public:
//vector<vector<int>>grid;
int n,m;
bool dfs(int i,int j,vector<vector<int>>&grid){
    if(i==n-1 && j==m-1){
      return true;
    }
    if(i>=n||i<0||j>=m||j<0||grid[i][j]==0)return false;
    bool ans=false;
    grid[i][j]=0;
    ans=ans||dfs(i+1,j,grid);
    ans=ans||dfs(i,j+1,grid);
    return ans;

}
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        //if(grid=={{1,1}})return false;
        //this->grid=grid;
        //vector<vector<int>>v={{1,1}};
        //if(v==grid)return false;
        n=grid.size();
        m=grid[0].size();
        //vector<vector<bool>>vis(n,vector<bool>(m,false));
        /*int ans=dfs(0,0,grid);
        cout<<ans<<endl;
        if(ans>1)return false;
        return true;
        */
         if(!dfs(0,0,grid))return true;
         grid[0][0]=1;
         if(!dfs(0,0,grid))return true;
         return false;
    }
};
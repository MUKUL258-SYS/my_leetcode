class Solution {
public:
int helper(vector<vector<int>>grid){
    int n=grid.size();
    int m=grid[0].size();
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<m-1;j++){
            if(grid[i][j]&&grid[i-1][j]){
            grid[i][j]=min(grid[i-1][j-1],grid[i-1][j+1])+1;
            ans+=(grid[i][j]-1);
            }
        }
    }
    return ans;

}
    int countPyramids(vector<vector<int>>& grid) {
        int ans=helper(grid);
        reverse(grid.begin(),grid.end());
        ans+=helper(grid);
        return ans;
    }
};
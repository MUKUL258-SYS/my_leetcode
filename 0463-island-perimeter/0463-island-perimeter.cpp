class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
      //  int cnt=0;
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int s=4;
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int ni=dirs[k][0]+i;
                        int nj=dirs[k][1]+j;
                        if(ni>=0&&nj>=0&&ni<n&&nj<m&&grid[ni][nj]==1)s--;
                    }
                    cnt+=s;
                }
            }
        }
        return cnt;
    }
};
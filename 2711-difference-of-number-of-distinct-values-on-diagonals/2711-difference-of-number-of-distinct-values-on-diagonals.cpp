class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sx=i-1;
                int sy=j-1;
                unordered_set<int>s1;
                unordered_set<int>s2;
                while(sx>=0&&sy>=0){
          s1.insert(grid[sx][sy]);
          sx--;
          sy--;
                }
                sx=i+1;
                sy=j+1;
                while(sx<n&&sy<m){
                    s2.insert(grid[sx][sy]);
                    sx++;
                    sy++;
                }
v[i][j]=abs((int)s1.size()-(int)s2.size());
            
            }
        }
        return v;
    }
};
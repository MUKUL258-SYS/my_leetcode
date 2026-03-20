class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ox(m,0);
        vector<int>oy(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int cntx=0;
            int cnty=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X')cntx++;
                else if(grid[i][j]=='Y')cnty++;
                ox[j]+=cntx;
                oy[j]+=cnty;
                if(ox[j]==oy[j]&&ox[j]>0)ans++;
            }
        }
        return ans;
    }
};
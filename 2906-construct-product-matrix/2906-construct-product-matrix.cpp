class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vp(n,vector<int>(m,1));
        int mod=12345;
        long long suffix=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
              vp[i][j]=suffix;
              suffix=(suffix*grid[i][j])%mod;
            }
        }
   long long prefix=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
           vp[i][j]=(prefix*vp[i][j])%mod;
           //vp[i][j]=(prefix*grid[i][j])%mod;
           prefix=(prefix*grid[i][j])%mod;
            }
        }
        return vp;

    }
};
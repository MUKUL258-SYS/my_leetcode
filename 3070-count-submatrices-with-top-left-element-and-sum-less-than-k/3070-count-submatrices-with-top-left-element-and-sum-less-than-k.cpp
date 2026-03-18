class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>mat=grid;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            int v1=i-1>=0?mat[i-1][j]:0;
            int v2=j-1>=0?mat[i][j-1]:0;
            int v3=(i-1>=0&&j-1>=0)?mat[i-1][j-1]:0;
            mat[i][j]=grid[i][j]+v1+v2-v3;

          }
        }
       /* for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
        */
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(mat[i][j]<=k)cnt++;
            }
        }
        return cnt;

    }
};
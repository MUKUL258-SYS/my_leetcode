class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>row,col;
        
        row=grid;
        col=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    row[i][j]=0;
                    col[i][j]=0;
                }
                else{
                  row[i][j]=(j>0)?1+row[i][j-1]:1;
                  col[i][j]=(i>0)?1+col[i-1][j]:1;
                }
            }
        }
        int mini=min(m,n);
        for(int l=mini;l>=1;l--){
        for(int i=0;i+l<=n;i++){
            for(int j=0;j+l<=m;j++){
                 int v1=row[i][j+l-1];
                 int v2=row[i+l-1][j+l-1];
                 int v3=col[i+l-1][j+l-1];
                 int v4=col[i+l-1][j];
                 if(v1>=l && v2>=l && v3>=l && v4>=l){
                    return l*l;
                 }
                
            }
        }
       // return 0;
        }
         return 0;
    }
};
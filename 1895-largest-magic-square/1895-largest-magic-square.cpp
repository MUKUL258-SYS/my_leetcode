class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>row(m,vector<int>(n,0));
        vector<vector<int>>col(m,vector<int>(n,0));
        vector<vector<int>>d1(m,vector<int>(n,0));
        vector<vector<int>>d2(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i][j]=grid[i][j]+(j?row[i][j-1]:0);
                col[i][j]=grid[i][j]+(i?col[i-1][j]:0);
             d1[i][j]=grid[i][j]+(i&&j?d1[i-1][j-1]:0);
          d2[i][j]=grid[i][j]+(i&&j+1<n?d2[i-1][j+1]:0);
            }
        }
        int ans=1;
        for(int k=min(m,n);k>=2;k--){
            for(int i=0;i+k<=m;i++){
                for(int j=0;j+k<=n;j++){
                    bool ok=true;
int sum=row[i][j+k-1]-(j?row[i][j-1]:0);
for(int x=i;x<i+k;x++){
    int s=row[x][j+k-1]-(j?row[x][j-1]:0);
    if(sum!=s){
        ok=false;
       break;
    }
}
if(!ok)continue;
for(int y=j;y<j+k;y++){
    int s=col[i+k-1][y]-(i?col[i-1][y]:0);
    if(sum!=s){
        ok=false;
       break;
    }
}
if(!ok)continue;
int s1=d1[i+k-1][j+k-1]-(i&&j?d1[i-1][j-1]:0);
int s2=d2[i+k-1][j]-(i&&j+k<n?d2[i-1][j+k]:0);
if(s1==sum&&s2==sum)return k;
                }
            }
        }
        return 1;
    }
};
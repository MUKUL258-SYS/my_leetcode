class Solution {
public:
vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<int>t;
        for(int i=1;i<=9;i++){
            t.insert(i);
        }
        vector<vector<int>>h,v;
        h=grid;
        v=grid;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                h[i][j]+=h[i][j-1];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                v[i][j]+=v[i-1][j];
            }
        }
        int ans=0;

        for(int i=1;i<n-1;i++){
         //   set<int>s;
            for(int j=1;j<m-1;j++){
                 set<int>s;
                s.insert(grid[i][j]);
                for(int k=0;k<8;k++){
                   int ni=i+dirs[k][0];
                   int nj=j+dirs[k][1];
                   s.insert(grid[ni][nj]);
                }
                if(s==t){
                  //  for(auto i:s)cout<<i<<endl;
                    set<int>l;
                   l.insert(grid[i-1][j-1]+grid[i+1][j+1]+grid[i][j]);
                   l.insert(grid[i-1][j+1]+grid[i+1][j-1]+grid[i][j]);   
                   l.insert(h[i-1][j+1]-(j-2>=0?h[i-1][j-2]:0));
                    l.insert(h[i][j+1]-(j-2>=0?h[i][j-2]:0));
                     l.insert(h[i+1][j+1]-(j-2>=0?h[i+1][j-2]:0));
                     l.insert(v[i+1][j-1]-(i-2>=0?v[i-2][j-1]:0));
                      l.insert(v[i+1][j]-(i-2>=0?v[i-2][j]:0));
                       l.insert(v[i+1][j+1]-(i-2>=0?v[i-2][j+1]:0));
                       if(l.size()==1){
                        //cout<<i<<" "<<j<<endl;
                        ans++;
                       }
                }
            }
        }
        return ans;
    }
};
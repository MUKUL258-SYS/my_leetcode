class Solution {
public:
long long dp_min[16][16];
long long dp_max[16][16];
vector<vector<int>>grid;
int mod=1e9+7;
int n,m;
pair<long long,long long>dfs(int i,int j){
    
    if(i==n-1&&j==m-1){
return {grid[i][j],grid[i][j]};
    }
    if(dp_min[i][j]!=2e18)return {dp_min[i][j],dp_max[i][j]};
    long long curr_min=2e18;
    long long curr_max=-2e18;
    if(i+1<n){
        auto res=dfs(i+1,j);
        long long choices[]={(res.first*grid[i][j]),(res.second*grid[i][j])};
        for(auto v:choices){
            curr_min=min(curr_min,v);
            curr_max=max(curr_max,v);
        }
    }
    if(j+1<m){
        auto res=dfs(i,j+1);
        long long choices[]={(res.first*grid[i][j]),(res.second*grid[i][j])};
        for(auto v:choices){
            curr_min=min(curr_min,v);
            curr_max=max(curr_max,v);
        }
    }
    dp_min[i][j]=curr_min;
    dp_max[i][j]=curr_max;
    return {curr_min,curr_max};

}
    int maxProductPath(vector<vector<int>>& grid) {
        //memset(dp_min,-2e18,sizeof(dp_min));
       // memset(dp_max,-2e18,sizeof(dp_max));
       this->grid=grid;
        n=grid.size();
        m=grid[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp_min[i][j]=2e18;
            dp_max[i][j]=-2e18;
        }
       }
       auto v=dfs(0,0);
       return v.second<0?-1:v.second%mod;

    }
};
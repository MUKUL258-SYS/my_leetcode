class Solution {
public:
int n,m;
bool checker(int x,int y){
  if(x>=0&&x<n&&y>=0&&y<m)return true;
  return false;
}
    int minimumObstacles(vector<vector<int>>& grid) {
       n=grid.size();
        m=grid[0].size();
      // priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
      deque<pair<int,int>>pq;
     pq.push_back({0,0});
    // dp[0][0]=0;
       vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
       dp[0][0]=0;
       vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
       while(!pq.empty()){
        auto [x,y]=pq.front();
        pq.pop_front();
        if(x==n-1 && y==m-1)break;
        for(auto dir:dirs){
            int nx=dir[0]+x;
            int ny=dir[1]+y;
            if(checker(nx,ny)){
                int new_dist=grid[nx][ny]+dp[x][y];
                if(new_dist<dp[nx][ny]){
                    dp[nx][ny]=new_dist;
                    if(grid[nx][ny]==0){
                        pq.push_front({nx,ny});
                    }
                    else{
                        pq.push_back({nx,ny});
                    }
                }
            }
        }
       }
      
       return dp[n-1][m-1];

    }
};
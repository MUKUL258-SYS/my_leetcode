class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        vector<vector<int>>dirs={{-1,0},{0,1},{1,0},{0,-1}};
        using T=tuple<int,int,int,int>;
        priority_queue<T,vector<T>,greater<>>pq;
        pq.emplace(0,0,0,0);
        while(!pq.empty()){
               auto[time,i,j,nextMoveTime]=pq.top();
               pq.pop();
               if(time>=dp[i][j])continue;
               dp[i][j]=time;
               if(i== n-1 && j==m-1)return time;
               for(auto &d :dirs){
                int x=i+d[0],y=j+d[1];
                if(x>=0&&y>=0&&x<n&&y<m){
                    int wait = moveTime[x][y];
                    int future=nextMoveTime==1?2:1;
                    int nextTime=wait>time?wait+future:time+future;
                    if(nextTime<dp[x][y]){
                        pq.emplace(nextTime,x,y,future);
                    }
                }
               }
        }
        return -1;
    }
};
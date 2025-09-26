class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1&&c==m-1)return diff;
            for(int k=0;k<4;k++){
                int nr=r+dirs[k][0];
                int nc=c+dirs[k][1];
                if(nr>=0&&nr<n&&nc>=0&&nc<m){
                    int new_diff=max(abs(heights[nr][nc]-heights[r][c]),diff);
                    if(new_diff<dist[nr][nc]){
                        dist[nr][nc]=new_diff;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};
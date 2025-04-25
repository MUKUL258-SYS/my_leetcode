class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
         int n=arr.size();
         vector<int>dist(n,INT_MAX);
         int j=0;
         for(auto i:arr){
            int m_dist=abs(start[0]-i[0])+abs(start[1]-i[1])+i[4];
            pq.push({m_dist,j});
            j++;
         }
         int ans=abs(start[0]-target[0])+abs(start[1]-target[1]);
         while(!pq.empty()){
            int r=arr[pq.top().second][2];
            int c=arr[pq.top().second][3];
            int id=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            ans=min(ans,d+abs(target[0]-r)+abs(target[1]-c));
            for(int i=0;i<n;i++){
                int m_dist=abs(arr[i][0]-r)+abs(arr[i][1]-c)+arr[i][4];
                if(d+m_dist<dist[i]){
                    dist[i]=d+m_dist;
                    pq.push({dist[i],i});
                }
            }
         }
         return ans;

    }
};
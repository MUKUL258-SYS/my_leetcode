class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int ans=0;
        int k=ladders;
        for(int i=1;i<n;i++){
          if(heights[i]<=heights[i-1])continue;
          pq.push(heights[i]-heights[i-1]);
          if(pq.size()>k){
            bricks-=pq.top();
            pq.pop();
          }
          if(bricks<0)return i-1;

        }
        return n-1;
    }
};
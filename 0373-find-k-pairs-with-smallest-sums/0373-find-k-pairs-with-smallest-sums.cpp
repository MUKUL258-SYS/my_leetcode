class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        int n=nums1.size();
        int m=nums2.size();
        pq.push({nums1[0]+nums2[0],0,0});
        vector<vector<int>>res;
        //vis[{0,0}]=1;
        map<pair<int,int>,int>vis;
         vis[{0,0}]=1;
        while(k--&&pq.size()){
            auto v=pq.top();
            pq.pop();
            int i=v[1];
            int j=v[2];
            res.push_back({nums1[i],nums2[j]});
            if(i+1<n&&vis[{i+1,j}]==0){
                pq.push({nums1[i+1]+nums2[j],i+1,j});
                 vis[{i+1,j}]=1;
            }
            if(j+1<m&&vis[{i,j+1}]==0){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
            vis[{i,j+1}]=1;
            }
        }
        return res;
    }
};
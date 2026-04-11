class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
int n=nums1.size();
int m=nums2.size();
        vector<vector<int>>res;
        pq.push({nums1[0]+nums2[0],0,0});
        set<pair<int,int>>vis;
        vis.insert({0,0});
        while(k--&&pq.size()){
            auto v=pq.top();
            int i=v[1];
            int j=v[2];
        res.push_back({nums1[i],nums2[j]});
            pq.pop();
            if(i+1<n && !vis.count({i+1,j})){
                pq.push({nums1[i+1]+nums2[j],i+1,j});
                vis.insert({i+1,j});
            }
            if(j+1<m && !vis.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
                vis.insert({i,j+1});
            }

        }
        return res;
    }
};
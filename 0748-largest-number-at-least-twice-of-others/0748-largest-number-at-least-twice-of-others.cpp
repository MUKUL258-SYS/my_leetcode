class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<pair<int,int>>vp;
        int n=nums.size();
        for(int i=0;i<n;i++){
          vp.push_back({nums[i],i});
        }
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        if(vp[0].first>=(2*vp[1].first))return vp[0].second;
        return -1;

    }
};
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto i:nums)mp[i]++;
        return mp[nums[n/2]]==1;
    }
};
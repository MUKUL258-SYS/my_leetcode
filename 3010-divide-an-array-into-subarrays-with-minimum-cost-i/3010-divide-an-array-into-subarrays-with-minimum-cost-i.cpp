class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        for(int i=1;i<n;i++)v.push_back(nums[i]);
        sort(v.begin(),v.end());
        return nums[0]+v[0]+v[1];
    }
};
class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int prev=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[prev]||(i==n-1)){
                ans+=(1ll*(i-prev)*nums[prev]);
                prev=i;
            }
        }
        return ans;
    }
};
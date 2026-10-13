class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(auto &i:nums){
            if(i<0)i=-1*i;
        }
        sort(nums.begin(),nums.end(),greater<int>());
        int stop_idx=n/2;
        if(n%2 == 0)stop_idx--;
        for(int i=0;i<n;i++){
            long long x=1ll*nums[i]*nums[i];
            if(i<=stop_idx)ans+=x;
            else ans-=x;
        }
        return ans;
    }
};
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long ans=0;
        unordered_map<int,int>suff,pre;
        int mod=1e9+7;
        for(auto i:nums)suff[i]++;
        int n=nums.size();
        for(int i=0;i<n;i++){
            suff[nums[i]]--;
            int mid=nums[i];
          ans=(ans+(1ll*pre[2*mid]*suff[2*mid])%mod)%mod;
          pre[nums[i]]++;
        }
        return ans;

    }
};
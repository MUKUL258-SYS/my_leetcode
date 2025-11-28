class Solution {
public:
using ll=long long;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll>v(k,LLONG_MAX);
        ll prefix=0;
        ll ans=LLONG_MIN;
        v[0]=0;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int mod_index=(i+1)%k;
            if(v[mod_index]!=LLONG_MAX){
                ans=max(ans,prefix-v[mod_index]);
            }
            v[mod_index]=min(v[mod_index],prefix);

        }
        return ans;
    }
};
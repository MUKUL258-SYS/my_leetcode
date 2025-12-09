class Solution {
public:
using ll=long long;
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        ll lmax=nums[0];
        ll lmin=nums[0];
       ll res=max(nums[m-1]*lmin,nums[m-1]*lmax);
        for(int i=m;i<n;i++){
          ll r=1LL*nums[i];
          lmax=max(lmax,1ll*nums[i-m+1]);
          lmin=min(lmin,1ll*nums[i-m+1]);
          res=max({res,lmax*r,lmin*r});
        }
        return res;
    }
};
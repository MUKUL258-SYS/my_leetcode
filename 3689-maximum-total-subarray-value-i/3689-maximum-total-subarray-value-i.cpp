class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        vector<int>pre_max(n),post_max(n),pre_min(n),post_min(n);
        pre_max[0]=nums[0];
        pre_min[0]=nums[0];
        post_max[n-1]=nums.back();
        post_min[n-1]=nums.back();
        for(int i=1;i<n;i++){
            pre_max[i]=max(pre_max[i-1],nums[i]);
            pre_min[i]=min(pre_max[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            post_max[i]=max(post_max[i+1],nums[i]);
            post_min[i]=min(post_min[i+1],nums[i]);
        }
      //  long long ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,1ll*k*(pre_max[i]-post_min[i]));
            ans=max(ans,1ll*k*(post_max[i]-pre_min[i]));
        }
        return ans;

    }
};
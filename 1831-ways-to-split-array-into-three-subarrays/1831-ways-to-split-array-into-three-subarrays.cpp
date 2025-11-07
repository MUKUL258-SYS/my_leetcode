class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            int low=lower_bound(pre.begin()+i+1,pre.end(),2*pre[i])-pre.begin();
            int upper=upper_bound(pre.begin()+i+1,pre.begin()+n-1,pre[i]+(pre[n-1]-pre[i])/2)-pre.begin();
            ans+=max(0,upper-low);
            ans%=mod;
        }
        return ans;
    }
};
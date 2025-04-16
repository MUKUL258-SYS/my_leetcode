class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=0;
        int n=nums.size();
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i]=nums[i]+mp.rbegin()->first;
            mp[dp[i]]++;
            if(i>=k){
                mp[dp[i-k]]--;
                if(mp[dp[i-k]]==0)mp.erase(dp[i-k]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
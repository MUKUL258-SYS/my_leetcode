class Solution {
public:
unordered_map<int,int>dp;
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            dp[nums[i]+1]=max(dp[nums[i]+1],dp[nums[i]]+1);
            dp[nums[i]]=max(dp[nums[i]],dp[nums[i]-1]+1);
        }
        int maxi=0;
        for(auto i:dp){
            maxi=max(maxi,i.second);
        }
        return maxi;
    }
};
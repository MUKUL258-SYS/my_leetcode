class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>parent(n,-1);
        vector<int>dp(n,1);
        int l=0;
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
             if(nums[i]%nums[j] == 0){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
              }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                l=i;
            }

        }
        vector<int>v;
        while(l!=-1){
                v.push_back(nums[l]);
                l=parent[l];
        }
        return v;
    }
};
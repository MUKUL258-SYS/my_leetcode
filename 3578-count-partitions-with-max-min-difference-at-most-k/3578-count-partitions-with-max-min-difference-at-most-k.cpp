class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        multiset<int>ms;
        int n=nums.size();
        vector<int>dp(n+1),pre(n+1);
        int MOD=1e9+7;
        dp[0]=1;
        pre[0]=1;
        int j=0;
        for(int i=1;i<=n;i++){
            ms.insert(nums[i-1]);
            while(*(ms.rbegin())-*(ms.begin())>k){
                ms.erase(ms.find(nums[j]));
                j++;
            }
          dp[i]=(pre[i-1]-((j-1>=0?pre[j-1]:0))+MOD)%MOD;
          pre[i]=(pre[i-1]+dp[i])%MOD;
          
        }
        return dp[n];
    }
};
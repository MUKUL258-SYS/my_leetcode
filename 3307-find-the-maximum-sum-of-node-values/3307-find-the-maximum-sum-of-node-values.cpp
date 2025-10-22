class Solution {
public:
int n;
int k;
vector<int>nums;
long long dp[20009][5];
long long dfs(int idx,int even){
   if(idx==n){
    if(even==1){
        return 0;
    }
    return LLONG_MIN;
   }
   if(dp[idx][even]!=-1)return dp[idx][even];
   long long inc=(nums[idx]^k)+dfs(idx+1,!even);
   long long exc=nums[idx]+dfs(idx+1,even);
   return dp[idx][even]=max(inc,exc);
}
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
n=nums.size();
this->k=k;
this->nums=nums;
memset(dp,-1,sizeof(dp));
return dfs(0,1);
    }
};
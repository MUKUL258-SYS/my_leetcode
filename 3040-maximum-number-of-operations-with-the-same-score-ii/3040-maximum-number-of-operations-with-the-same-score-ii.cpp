class Solution {
public:
int dp[2005][2005];
int n;
vector<int>nums;
int dfs(int s,int e,int prev_sum){
    if(s>=e)return 0;
    if(dp[s][e]!=-1)return dp[s][e];
    int ans=0;
    if(nums[s]+nums[e]==prev_sum){
     ans=max(ans,1+dfs(s+1,e-1,prev_sum));
    }
    if(s+1<n&&(nums[s]+nums[s+1])==prev_sum){
        ans=max(ans,1+dfs(s+2,e,prev_sum));
    }
    if(e-1>=0&&(nums[e]+nums[e-1])==prev_sum){
        ans=max(ans,1+dfs(s,e-2,prev_sum));
    }
    return dp[s][e]=ans;
}
    int maxOperations(vector<int>& nums) {
         n=nums.size();
    memset(dp,-1,sizeof(dp));
    this->nums=nums;
    int ans=0;
    ans=max(ans,dfs(2,n-1,nums[0]+nums[1]));
    ans=max(ans,dfs(1,n-2,nums[0]+nums[n-1]));
    ans=max(ans,dfs(0,n-3,nums[n-1]+nums[n-2]));
    return ans+1;
    }
};
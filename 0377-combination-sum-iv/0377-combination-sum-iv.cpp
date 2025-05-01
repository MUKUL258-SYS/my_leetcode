class Solution {
public:
int n;
vector<int>dp;
vector<int>nums;
int dfs(int target){
    if(target<0)return 0;
    if(target==0)return 1;
    if(dp[target]!=-1)return dp[target];
    dp[target]=0;
    for(int i=0;i<n;i++){
       if(nums[i]<=target) 
      dp[target]+=dfs(target-nums[i]);
    }
    return dp[target];
}
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        this->nums=nums;
        dp.resize(target+5,-1);
        return dfs(target);
    }
};
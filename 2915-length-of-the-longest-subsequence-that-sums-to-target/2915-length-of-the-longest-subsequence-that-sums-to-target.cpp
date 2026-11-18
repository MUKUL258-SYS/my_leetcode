class Solution {
public:
int n;
vector<int>nums;
int dp[1005][1005];
int dfs(int i,int target){
    if(target<0)return INT_MIN;
    if(i>=n){
        if(target==0)return 0;
        return INT_MIN;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int op1=dfs(i+1,target);
    int op2=dfs(i+1,target-nums[i]);
    if(op2!=INT_MIN)op2++;
    return dp[i][target]=max(op1,op2);
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        n=nums.size();
        this->nums=nums;
         memset(dp,-1,sizeof(dp));
        int res=dfs(0,target);
      //  memset(dp,-1,sizeof(dp));
        if(res==INT_MIN)return -1;
        return res;
    }
};
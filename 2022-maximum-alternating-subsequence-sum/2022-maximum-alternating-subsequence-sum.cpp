class Solution {
public:
vector<int>nums;
vector<vector<long long>>dp;
long long dfs(int idx,bool flag){
    int n=nums.size();
   if(idx>=n)return 0;
   if(dp[idx][flag]!=-1)return dp[idx][flag];
   long long inc=0,exc=0;
   exc=dfs(idx+1,flag);
   if(flag){
     inc=nums[idx]+dfs(idx+1,!flag);
   }
   else{
    inc=-nums[idx]+dfs(idx+1,!flag);
   }
   return dp[idx][flag]=max(inc,exc);
}
    long long maxAlternatingSum(vector<int>& nums) {
        this->nums=nums;
        int n=nums.size();
        dp.resize(n+5,vector<long long>(2,-1));
        return dfs(0,true);
    }
};
class Solution {
public:
int t,n;
vector<int>nums;

int dfs(int k,int curr_sum,int mask,vector<int>&dp){
    if(k==0){
        return mask== (1<<n)-1;
    }
    if(dp[mask]!=-1)return dp[mask];
    if(curr_sum==t){
        return dp[mask]=dfs(k-1,0,mask,dp);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(curr_sum+nums[i]<=t){
        if((mask&(1<<i))==0){
          int newmask=mask|(1<<i);
          ans=ans||dfs(k,curr_sum+nums[i],newmask,dp);
          newmask^=(1<<i);
         if(ans){
            return dp[mask]=ans;
         }
     }
  }
}
return dp[mask]=ans;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        this->nums=nums;
   long long sum=0;
    n=nums.size();
   for(auto i:nums)sum+=i;
   if(sum%k)return false;
   t=sum/k;
   vector<int>dp(1<<n,-1);
   return dfs(k,0,0,dp);
    }
};
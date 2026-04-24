class Solution {
public:
int t;
vector<int>nums;
int dfs(int k,vector<int>&dp,int mask,int curr){
    int n=nums.size();
    if(k==0){
        return mask+1==(1<<n);
    }
    if(curr==t){
        return dfs(k-1,dp,mask,0);
    }
    if(dp[mask]!=-1)return dp[mask];
int  ans=0;
    for(int i=0;i<n;i++){
      if(curr+nums[i]<=t){
        if((mask&(1<<i))==0){
            mask|=(1<<i);
            ans=ans||dfs(k,dp,mask,curr+nums[i]);
            if(ans){
                return dp[mask];
            }
            mask^=(1<<i);

        }
      }  
    }
    return dp[mask]=ans;

}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
       int sum=0;
       int n=nums.size();
       this->nums=nums;
       for(auto i:nums){
        sum+=i;
       } 
       if(sum%k)return false;
      t=sum/k;
      vector<int>dp(1<<n,-1);
    return dfs(k,dp,0,0);

    }
};
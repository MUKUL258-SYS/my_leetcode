class Solution {
public:
int dp[14][1<<14];
int mod=1e9+7;
int n;
int dfs(int prev,int mask,vector<int>&nums){
    if(mask==(1<<n)-1){
        return 1;
    }
    if(prev!=-1&&dp[prev][mask]!=-1)return dp[prev][mask];
    int ans=0;
    for(int i=0;i<n;i++){
        if((mask&(1<<i)))continue;
        int v1,v2;
       if(prev>=0)v1=nums[i]%nums[prev];
       if(prev>=0)v2=nums[prev]%nums[i];
    if(prev==-1||v1==0||v2==0){
     ans=(ans+dfs(i,mask|(1<<i),nums))%mod;;
    }
       
    }
    if(prev!=-1)dp[prev][mask]=ans;
    return ans;

}
    int specialPerm(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return dfs(-1,0,nums);
    }
};
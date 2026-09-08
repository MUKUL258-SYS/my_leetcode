class Solution {
public:
int n;
int dp[1<<16][16];
static const int mod=1e9+7;
vector<int>nums;
int dfs(int mask,int prev){
    if(mask==((1<<n)-1)){
        return 1;
    }
    if(dp[mask][prev]!=-1)return dp[mask][prev];
    int ans=0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i))continue;
        if((nums[i]%nums[prev]==0)||(nums[prev]%nums[i]==0)){
            int newmask=mask;
            ans=(ans+dfs(newmask|(1<<i),i))%mod;
        }
    }
    return  dp[mask][prev]=ans;
}
    int specialPerm(vector<int>& nums) {
        n=nums.size();
        this->nums=nums;
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+dfs((1<<i),i))%mod;
        }
        //return dfs(0,0);
         return ans;
    }
};
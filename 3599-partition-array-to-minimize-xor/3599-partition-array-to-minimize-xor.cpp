class Solution {
public:
vector<int>pref;
int dp[251][251];
    int minXor(vector<int>& nums, int k) {
        int n=nums.size();
        pref.resize(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)pref[i]=pref[i-1]^nums[i];
        memset(dp,-1,sizeof(dp));
        return helper(nums,n-1,k);
    }
    int helper(vector<int>&nums,int i,int k){
        if(k==1){
            return pref[i];
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int ans=INT_MAX;
        for(int len=1;len<=(i+2-k);len++){
          int val=max(pref[i-len]^pref[i],helper(nums,i-len,k-1));
          ans=min(ans,val);
        }
        return dp[i][k]=ans;
    }
};
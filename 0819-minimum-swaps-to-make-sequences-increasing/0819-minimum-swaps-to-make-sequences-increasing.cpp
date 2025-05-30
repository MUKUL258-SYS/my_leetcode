class Solution {
public:
int dp[100005][2];
int n;
int dfs(vector<int>&nums1,vector<int>&nums2,int i,int prev1,int prev2,bool swap){
    if(i==n)return 0;
    if(dp[i][swap]!=-1)return dp[i][swap];
    int ans=INT_MAX;
    if(nums1[i]>prev1&&nums2[i]>prev2){
        ans=min(ans,dfs(nums1,nums2,i+1,nums1[i],nums2[i],false));
    }
    if(nums1[i]>prev2&&nums2[i]>prev1){
    ans=min(ans,1+dfs(nums1,nums2,i+1,nums2[i],nums1[i],true));
   }
   return dp[i][swap]=ans;
}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        memset(dp,-1,sizeof(dp));
        return dfs(nums1,nums2,0,-1,-1,false);
    }
};
class Solution {
public:
int n,m;
vector<int>nums1;
vector<int>nums2;
int dp[1005][1005];
int ans;
int dfs(int i,int j){
    if(i>=n||j>=m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    
if(nums1[i]==nums2[j]){
    dp[i][j]=1+dfs(i+1,j+1);
}
else dp[i][j]=0;
  dfs(i+1,j);
  dfs(i,j+1);
ans=max(ans,dp[i][j]);
    return  dp[i][j];

}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        ans=0;
         n=nums1.size();
         m=nums2.size();
         this->nums1=nums1;
         this->nums2=nums2;
         for(int i=0;i<1005;i++){
            for(int j=0;j<1005;j++){
                dp[i][j]=-1;
            }
         }
         dfs(0,0);
        return ans;

    }
};

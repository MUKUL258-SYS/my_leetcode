class Solution {
public:
int n,m;
int dp[550][550];
int dfs(int i,int j,vector<int>&nums1,vector<int>&nums2){
   if(i>=n||j>=m)return 0;
   if(dp[i][j]!=-1)return dp[i][j]; 
   int op1=(nums1[i]*nums2[j])+dfs(i+1,j+1,nums1,nums2);
   int op2=dfs(i+1,j+1,nums1,nums2);
   int op3=dfs(i+1,j,nums1,nums2);
   int op4=dfs(i,j+1,nums1,nums2);
   return dp[i][j]=max({op1,op3,op4});
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        memset(dp,-1,sizeof(dp));

        int ans=dfs(0,0,nums1,nums2);
        if(ans==0){
             int v1=*max_element(nums1.begin(),nums1.end());
             int v2=*max_element(nums2.begin(),nums2.end());
             int v3=*min_element(nums1.begin(),nums1.end());
             int v4=*min_element(nums2.begin(),nums2.end());
             ans=max(v1*v4,v2*v3);

        }
        return ans;
    }
};
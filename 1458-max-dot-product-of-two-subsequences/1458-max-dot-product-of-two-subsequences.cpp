class Solution {
public:
int n,m;
vector<vector<int>>dp;
 const int NEG_INF = -1e9;
int dfs(int i,int j,vector<int>&nums1,vector<int>&nums2){
   if(i>=n||j>=m)return NEG_INF;
   if(dp[i][j]!=INT_MIN)return dp[i][j]; 
   int op1=(nums1[i]*nums2[j])+dfs(i+1,j+1,nums1,nums2);
   int op2=nums1[i]*nums2[j];
   int op3=dfs(i+1,j,nums1,nums2);
   int op4=dfs(i,j+1,nums1,nums2);
   return dp[i][j]=max({op1,op2,op3,op4});
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
       // memset(dp,INT_MIN,sizeof(dp));
   dp.resize(n+5,vector<int>(m+5,INT_MIN));
        return dfs(0,0,nums1,nums2);
        
    }
};
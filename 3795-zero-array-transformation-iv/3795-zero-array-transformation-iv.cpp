class Solution {
public:
//vector<vector<int>>dp;
int dfs(int i,int target,int k,vector<vector<int>>&queries,vector<vector<int>>&dp){
    if(target==0)return k;
    if(target<0||k>=queries.size())return queries.size()+1;
    if(dp[target][k]!=-1)return dp[target][k];
    //skip
    int res=dfs(i,target,k+1,queries,dp);
    if(i>=queries[k][0]&&i<=queries[k][1]){
        res=min(res,dfs(i,target-queries[k][2],k+1,queries,dp));
    }
    return dp[target][k]=res;
}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<vector<int>>dp(nums[i]+5,vector<int>(queries.size()+5,-1));
          ans=max(ans,dfs(i,nums[i],0,queries,dp));
          //if(ans>queries.size())ans=-1;
        }
         if(ans>queries.size())ans=-1;
        return ans;
    }
};
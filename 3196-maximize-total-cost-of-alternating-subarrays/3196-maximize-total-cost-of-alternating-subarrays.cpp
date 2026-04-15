class Solution {
public:
vector<int>nums;
//vector<vector<long long>>dp;
long long dp[100005][5];
long long dfs(int idx,int ongoing){
    int n=nums.size();
    if(idx==n){
        return 0;
    }
if(dp[idx][ongoing+1]!=-1e18)return dp[idx][ongoing+1];
    long long op1=nums[idx]+dfs(idx+1,0);
    long long op2=-1e18;
    if(ongoing!=-1){
        if(ongoing==0){
            op2=-1*nums[idx]+dfs(idx+1,1);
        }
        else{
            op2=nums[idx]+dfs(idx+1,0);
        }
    }
    return dp[idx][ongoing+1]=max(op1,op2);
}
    long long maximumTotalCost(vector<int>& nums) {
        this->nums=nums;
        int n=nums.size();
       // dp.resize(n+5,vector<long long>(3,-1));
       //memset(dp,-1e18,sizeof(dp));
       for(int i = 0; i < 100005; i++){
    for(int j = 0; j < 5; j++){
        dp[i][j] = -1e18;
    }
}
        return dfs(0,-1);

    }
};
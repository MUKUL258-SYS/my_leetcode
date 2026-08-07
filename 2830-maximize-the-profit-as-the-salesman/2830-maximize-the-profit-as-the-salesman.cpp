class Solution {
public:
int m;
vector<int>dp;
vector<vector<int>>nums;
int dfs(int i){
  if(i>=m){
    return 0;
  }
  if(dp[i]!=-1)return dp[i];
  int op1=dfs(i+1);
  int op2=0;
  auto ni=upper_bound(nums.begin(),nums.end(),vector<int>{nums[i][1],INT_MAX,INT_MAX})-nums.begin();
  
 op2=nums[i][2]+dfs(ni);
 return dp[i]=max(op1,op2);
}
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
    
        m=offers.size();
        dp.resize(m+1,-1);
        nums=offers;
        return dfs(0);
    }
};
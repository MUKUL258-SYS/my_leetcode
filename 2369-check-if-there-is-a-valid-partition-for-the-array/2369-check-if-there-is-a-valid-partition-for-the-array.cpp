class Solution {
public:
int n;
vector<int>nums;
int dp[100009];
bool dfs(int i){
    if(i>=n)return true;
    if(dp[i]!=-1)return dp[i];
    bool ans=false;
    bool res=false;
    if(i+1<n){
        if(nums[i]==nums[i+1]){
          // bool a=true;
         res=res||dfs(i+2);
        }
        if(i+2<n){
            if((nums[i]==nums[i+1]) && (nums[i+1]==nums[i+2])){
                res=res||dfs(i+3);
            }
            if(nums[i+2]-nums[i+1]==1 && nums[i+1]-nums[i]==1){
                res=res||dfs(i+3);
            }
        }
    }
    return dp[i]=res;

}

    bool validPartition(vector<int>& nums) {
      n=nums.size(); 
      this->nums=nums;
      memset(dp,-1,sizeof(dp));
      return dfs(0);  
    }
};
class Solution {
public:
vector<int>nums;
int dp[1005][1005];
int dfs(int i,int diff){
    int n=nums.size();
    if(i>=n){
        return 0;
    }
    if(dp[i][diff+501]!=-1)return dp[i][diff+501];
    int op2=0;
    int op1=0;
    if(diff == -501){
      //  int op1=1+dfs(i+1,nums[i]);
       // int op2=dfs(i+1,diff);
        op1=dfs(i+1,diff);
     //  int op2=0;
       for(int j=i+1;j<n;j++){
         op2=max(op2,1+dfs(j,nums[j]-nums[i]));
       }
    }else{
       //  op1=dfs(i+1,diff);
       // int op2=0;
        for(int j=i+1;j<n;j++){
            if((nums[j]-nums[i]) == diff)
            op2=max(op2,1+dfs(j,diff));
        }
    }
    return dp[i][diff+501]=max({op1,op2,1});
}
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        this->nums=nums;
      //  memset(dp,-1,sizeof(dp));
      for(int i=0;i<1005;i++){
        for(int j=0;j<1005;j++){
            dp[i][j]=-1;
        }
      }
         return dfs(0,-501);
    }
};
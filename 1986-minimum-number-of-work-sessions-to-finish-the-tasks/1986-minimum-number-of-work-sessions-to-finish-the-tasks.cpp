class Solution {
public:
int n;
int st;
vector<int>nums;
int dp[1<<14][1000];
int dfs(int mask,int curr){
   if(mask == (1<<n)-1)return 0;
   if(dp[mask][curr]!=-1)return dp[mask][curr];
   int mini=INT_MAX;
   for(int i=0;i<n;i++){
    if(!(mask&(1<<i))){
      int newmask=mask|(1<<i);
      if(curr+nums[i]<=st){
        mini=min(mini,dfs(newmask,curr+nums[i]));
      }
      else{
        mini=min(mini,1+dfs(newmask,nums[i]));
      }
    }
  // return  dp[mask][curr]=mini;
   }
    return  dp[mask][curr]=mini;
}
    int minSessions(vector<int>& tasks, int sessionTime) {
      n=tasks.size();  
      st=sessionTime;
      nums=tasks;
      memset(dp, -1, sizeof(dp));
      sort(nums.begin(),nums.end());
     
      return dfs(0,0)+1;
    }
};
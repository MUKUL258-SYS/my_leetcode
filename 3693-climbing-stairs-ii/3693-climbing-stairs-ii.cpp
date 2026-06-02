class Solution {
public:
vector<int>arr;
vector<int>dp;
int dfs(int prev){
    int n=arr.size();
    if(prev == n-1){
        return 0;
    }
    if(dp[prev+1]!=-1)return dp[prev+1];
int mini=INT_MAX;
for(int i=prev+1;i<=min(prev+3,n-1);i++){
    int c=i-prev;
    int sub=dfs(i);
    if(sub!=INT_MAX){
   mini=min(mini,(c*c)+arr[i]+sub);
    }
}
return dp[prev+1]=mini;


}
    int climbStairs(int n, vector<int>& costs) {
        arr=costs;
        dp.resize(n+5,-1);
     return dfs(-1);   
    }
};
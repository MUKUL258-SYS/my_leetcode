class Solution {
public:
int n;
 vector<pair<int,int>>v;
/*int dfs(int prev,int curr){
 if(curr>=n)return 0;
 int take=0;
 int notake=0;
 if(prev==-1){
    take=v[curr].second+dfs(prev+1,curr+1);
    notake=dfs(prev+1,curr+1);
 }
 else{

    if(v[curr].second>=v[prev].second)take=v[curr].second+dfs(curr,curr+1);
      notake=dfs(prev,curr+1);
 }
return max(take,notake);
}
*/
int dp[1005][1005];
int dfs(int prev, int curr) {
    if (curr >= n) return 0;
    if (dp[prev + 1][curr] != -1) return dp[prev + 1][curr];

    int take = 0, notake = 0;
    if (prev == -1 || v[curr].second >= v[prev].second)
        take = v[curr].second + dfs(curr, curr + 1);

    notake = dfs(prev, curr + 1);

    return dp[prev + 1][curr] = max(take, notake);
}

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
   //   vector<pair<int,int>>v;
   memset(dp,-1,sizeof(dp));
       n=scores.size();
      for(int i=0;i<n;i++){
        v.push_back({ages[i],scores[i]});
      }  
      sort(v.begin(),v.end());
return dfs(-1,0);
    }
};
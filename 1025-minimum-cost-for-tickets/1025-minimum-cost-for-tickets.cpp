class Solution {
public:
int n;
vector<int>dp;
int dfs(vector<int>&days,vector<int>&costs,int si){
    if(si>=n)return 0;
    if(dp[si]!=-1)return dp[si];
    int c1=costs[0]+dfs(days,costs,si+1);
    int i;
    for(i=si;i<n&&days[i]<days[si]+7;i++);
    int c2=costs[1]+dfs(days,costs,i);
    for(i=si;i<n&&days[i]<days[si]+30;i++);
    int c3=costs[2]+dfs(days,costs,i);
    return  dp[si]=min({c1,c2,c3});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      n=days.size();
      dp.resize(400,-1);
        return dfs(days,costs,0);
    }
};
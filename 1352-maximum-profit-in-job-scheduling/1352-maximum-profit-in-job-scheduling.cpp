class Solution {
public:
vector<vector<int>>vp;
vector<int>start;
vector<int>dp;
int dfs(int i){
    if(i>=start.size())return 0;
    if(dp[i]!=-1)return dp[i];
    int index=lower_bound(start.begin(),start.end(),vp[i][1])-start.begin();
    int take=vp[i][2]+dfs(index);
    int nottake=dfs(i+1);
    return dp[i]=max(take,nottake);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        start=startTime;
        int n=startTime.size();
        dp.resize(n,-1);
        for(int i=0;i<n;i++){
            vp.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(vp.begin(),vp.end());
        sort(start.begin(),start.end());
        return dfs(0);
    }
};
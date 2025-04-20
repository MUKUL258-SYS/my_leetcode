class Solution {
public:
int dp[1005][1005];
int dfs(int curr_idx,int prev_idx,vector<pair<int,int>>&vp){
    if(curr_idx>=vp.size())return 0;
    if(dp[curr_idx][prev_idx+1]!=-1)return dp[curr_idx][prev_idx+1];
    int pick=0;
    if(prev_idx==-1||vp[curr_idx].second>=vp[prev_idx].second){
    pick=vp[curr_idx].second+dfs(curr_idx+1,curr_idx,vp);
    }
    int notpick=dfs(curr_idx+1,prev_idx,vp);
    return dp[curr_idx][prev_idx+1]=max(pick,notpick);

}
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<pair<int,int>>vp;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            vp.push_back({ages[i],scores[i]});
        }
        sort(vp.begin(),vp.end());
         return dfs(0,-1,vp);
    }
};
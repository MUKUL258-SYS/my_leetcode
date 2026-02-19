class Solution {
public:
int n;
vector<int>time;
vector<int>v;
int dfs(int pos,int k,int currTime,vector<vector<vector<int>>>&dp){
    if(pos==n-1){
        if(k==0)return 0;
        return INT_MAX;
    }
    if(dp[pos][k][currTime]!=-1)return dp[pos][k][currTime];
    int res=dfs(pos+1,k,time[pos+1],dp);
    int ans=INT_MAX;
    if(res!=INT_MAX){
        ans=min(ans,(v[pos+1]-v[pos])*currTime+res);
    }
    int timesum=time[pos+1];
    int ops=0;
    for(int i=pos+2;i<=min(n-1,pos+k+1);i++){
        timesum+=time[i];
        ops++;
        int res=dfs(i,k-ops,timesum,dp);
        if(res!=INT_MAX){
            ans=min(ans,(v[i]-v[pos])*currTime+res);
        }
    }
    return dp[pos][k][currTime]=ans;

}
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        this->n=n;
        int sum=0;
        this->time=time;
        v=position;
        for(auto i:time)sum+=i;
        vector<vector<vector<int>>>dp(n+5,vector<vector<int>>(k+1,vector<int>(sum+5,-1)));
        return dfs(0,k,time[0],dp);
    }
};
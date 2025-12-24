class Solution {
public:
int dp[50][50];
long long dfs(vector<int>&a,int s,int e){
    if(s>=e)return 0;
    if(dp[s][e]!=-1)return dp[s][e];
    long long ans=LLONG_MAX;
    for(int i=s;i<e;i++){
        long long v1=*max_element(a.begin()+s,a.begin()+i+1);
        long long v2=*max_element(a.begin()+i+1,a.begin()+e+1);
        long long res1=dfs(a,s,i);
        long long res2=dfs(a,i+1,e);

             ans=min(ans,(v1*v2)+res1+res2);
    }
    return dp[s][e]=ans;
}
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return dfs(arr,0,arr.size()-1);
    }
};
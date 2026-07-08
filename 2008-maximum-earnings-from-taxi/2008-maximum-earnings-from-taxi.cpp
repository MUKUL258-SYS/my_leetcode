class Solution {
public:
vector<vector<int>>arr;
vector<long long>dp;
int m;
long long dfs(int i){
if(i>=m){
    return 0;
}
long long op1=0;
long long op2=0;
//if(dp[i][last]!=-1)return dp[i][last];
if(dp[i]!=-1)return dp[i];
long long dt=arr[i][1];
long long st=arr[i][0];
long long tip=arr[i][2];
auto idx=lower_bound(arr.begin(),arr.end(),dt,
[&](const vector<int>&row,long long value){
    return row[0]<value;
});
op1=dt-st+tip+dfs(idx-arr.begin());
op2=dfs(i+1);
return dp[i]=max(op1,op2);

}
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        arr=rides;
        m=arr.size();
        sort(arr.begin(),arr.end());
        //dp.resize(m+1,vector<long long>(n+1,-1));
        dp.resize(m+1,-1);
        return dfs(0);
    }
};
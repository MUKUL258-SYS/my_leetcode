/*class Solution {
public:
//vector<int>v;
//unordered_map<string,long long>mp;
long long dp[2001][4000];
long long  dfs(int i,long long sum,vector<int>&v){
    int n=v.size();
    if(i>=n){

        return sum;
    }
    if(dp[i][sum]!=-1)return dp[i][sum];
   //string str=to_string(i)+"@"+to_string(sum);
   //if(mp[str]>0)return mp[str];
   //if(mp.find(str)!=mp.end())return mp[str];
   long long ans=0;
    ans=max(ans,dfs(i+1,sum,v));
    if(v[i]>sum)
    ans=max(ans,dfs(i+1,sum+v[i],v));
    return dp[i][sum]=ans;

   

}
    int maxTotalReward(vector<int>& vp) {
      //  v=vp;
     // vp.erase(unique(vp.begin(),vp.end()),vp.end());
    // set<int>s;
     //for(auto i:vp)s.insert(i);

    //    sort(vp.begin(),vp.end());
        //v=vp;
       // vector<int>v;
       // for(auto i:s)v.push_back(i);
       set<int> s(vp.begin(), vp.end());
        vector<int> nums(s.begin(), s.end());
        memset(dp,-1,sizeof(dp));
   return dfs(0,0,nums);
    }
};
*/
class Solution {
public:
    int ans;
    int solve(int i,int n,int r,vector<int>&v,vector<vector<int>>&dp) {
        if(i==n) {
            return r;
        }
        if(dp[i][r]!=-1)
            return dp[i][r];
        int include=r;
        if(v[i]>r) {
            include=solve(i+1,n,r+v[i],v,dp);
        }
        int exclude=solve(i+1,n,r,v,dp);
        return dp[i][r]=max(include,exclude);
    }
    int maxTotalReward(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        vector<vector<int>>dp(2001,vector<int>(4001,-1));
        ans=solve(0,n,0,v,dp);
        return ans;
    }
};
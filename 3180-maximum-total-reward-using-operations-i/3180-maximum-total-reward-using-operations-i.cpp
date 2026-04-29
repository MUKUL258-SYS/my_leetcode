class Solution {
public:
//vector<int>v;
//unordered_map<string,long long>mp;
//long long dp[2001][4000];
vector<vector<int>>dp;
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
       // memset(dp,-1,sizeof(dp));
       dp.resize(2001,vector<int>(4000,-1));
   return dfs(0,0,nums);
    }
};

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int mod=1e9+7;
      long long ans=0;
      unordered_map<int,int>mp;
      for(auto i:points){
        mp[i[1]]++;
      }
      long long edgeSum=0;
      for(auto i:mp){
        long long edges=(i.second*1ll*(i.second-1))/2;
        ans=(ans+(edges*edgeSum)%mod)%mod;
        edgeSum+=edges;
      }
      return ans;
    }
};
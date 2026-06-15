class Solution {
public:
int mod;
long long power(long long  base,long long exp){
    long long res=1;
    base=base%mod;
    while(exp>0){
       if(exp%2){
        res=(res*base)%mod;
       }
      // res=(res*res)%mod;
      base=(base*base)%mod;
       exp/=2;
    }
    return res;
}
    int countWays(vector<vector<int>>&v) {
        mod=1e9+7;
        int n=v.size();
        sort(v.begin(),v.end());
        vector<vector<int>>res;
        res.push_back(v[0]);
        for(int i=1;i<n;i++){
            vector<int>vp=res.back();
            if(v[i][0]>vp[1]){
                res.push_back(v[i]);
            }
            else{
                int mini=vp[0];
                mini=min(mini,v[i][0]);
                int maxi=vp[1];
                maxi=max(maxi,v[i][1]);
                res.pop_back();
                res.push_back({mini,maxi});
            }
        }
        return (int)power(2,1ll*res.size())%mod;
    }
};
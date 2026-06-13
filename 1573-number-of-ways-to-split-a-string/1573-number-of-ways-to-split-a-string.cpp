class Solution {
public:
    int numWays(string s) {
        int cnt1=0;
        int mod=1e9+7;
        int n=s.size();
        for(auto i:s){
            if(i=='1')cnt1++;
        }
        if((cnt1)%3)return 0;
        if(cnt1==0){
          //  return (1ll*(n-1)*(n-2))/2;
          return (1LL * (n - 1) * (n - 2) / 2) % mod;
        } 
        int k=cnt1/3;
        int cnt=0;
        int l=1;
        int r=1;
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt++;
            if(cnt==k){
                if(s[i]=='0')l++;
            }
            if(cnt==(2*k)){
                if(s[i]=='0')r++;
            }
        }
        return (1ll*l*r)%mod;
    }
};
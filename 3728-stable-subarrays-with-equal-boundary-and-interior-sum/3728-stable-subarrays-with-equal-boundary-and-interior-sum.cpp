class Solution {
public:
using ll=long long;
    long long countStableSubarrays(vector<int>& c) {
        unordered_map<ll,unordered_map<ll,ll>>mp;
        int n=c.size();
        vector<ll>pre(n,0);
        pre[0]=c[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+1LL*c[i];
        }
    ll ans=0;
    for(ll r=2;r<n;r++){
        ll l=r-2;
        mp[c[l]][pre[l]]++;
    ll v=c[r];
    ll vc=pre[r-1]-v;
        if(mp.count(v)){
            ans+=(mp[v][vc]);
        }
    } 
    return ans; 
        
        
     }
};
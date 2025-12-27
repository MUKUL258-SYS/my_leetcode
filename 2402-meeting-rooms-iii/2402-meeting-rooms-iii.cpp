class Solution {
public:
using ll=long long;
using pi=pair<long long,long long>;
    int mostBooked(int n, vector<vector<int>>&m) {
        sort(m.begin(),m.end());
        vector<int>res(n,0);
        priority_queue<ll,vector<ll>,greater<ll>>ready;
        priority_queue<pi,vector<pi>,greater<pi>>used;
        for(int i=0;i<n;i++){
              ready.push(1ll*i);
        }
        for(auto i:m){
            ll s=1ll*i[0];
            ll e=1ll*i[1];
            while(!used.empty()&&used.top().first<=s){
                  ll r=used.top().second;
                 used.pop();
                 ready.push(r);
            }
            ll r;
            if(ready.size()){
                  r=ready.top();
                  ready.pop();
                  used.push({e,r});
            }
            else{
               auto p=used.top();
               used.pop();
               r=p.second;
               ll t=p.first;
               used.push({t+(e-s),r});
            }
            res[r]++;
        }
        ll maxi=-1;
        int ans;
        for(int i=0;i<n;i++){
    if(res[i]>maxi){
        maxi=res[i];
        ans=i;
    }
        }
        return ans;
    }
};
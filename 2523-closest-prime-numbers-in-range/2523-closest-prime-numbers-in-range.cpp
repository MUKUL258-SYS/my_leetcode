class Solution {
public:
vector<int>vp;
void seive(int maxi){
    vector<bool>vis(maxi+1,true);
    vis[1]=false;
    vis[0]=false;
    for(int i=2;i<=maxi;i++){
      if(!vis[i])continue;
      for(int j=2*i;j<=maxi;j+=i){
        vis[j]=false;
      }
    }

    for(int i=0;i<=maxi;i++){
        if(vis[i])vp.push_back(i);
    }
}
    vector<int> closestPrimes(int left, int right) {
        seive(right);
        int idx=lower_bound(vp.begin(),vp.end(),left)-vp.begin();
        int n=vp.size();
        int diff=INT_MAX;
        vector<int>res;
        for(int i=idx+1;i<n;i++){
              if(vp[i]-vp[i-1]<diff){
                diff=vp[i]-vp[i-1];
                res={vp[i-1],vp[i]};
              }
        }
        if(diff==INT_MAX)res={-1,-1};
        return res;
    }
};
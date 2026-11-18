class Solution {
public:
unordered_map<int,int>mp;
vector<bool> helper(int n){
    vector<bool>vis(n+1,false);
    vis[0]=true;
    vis[1]=true;
    for(int i=2;i*i<=n;i++){
        if(vis[i])continue;
        for(int j=i*i;j<=n;j+=i){
            vis[j]=true;
        }
    }
    return vis;
  
}
    vector<vector<int>> findPrimePairs(int n) {
       vector<bool>vp=helper(n);
        vector<vector<int>>res;
        for(int i=2;i<=(n/2);i++){
            if(!vp[i] && !vp[n-i])res.push_back({i,n-i});
        }
        return res;
    }
};
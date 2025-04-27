class Solution {
public:
#define ll long long
ll bfs(vector<vector<int>>&adj,vector<ll>&path,int n){
    unordered_set<ll>ss(path.begin(),path.end());
      ll ans=INT_MIN;
    for(auto i:path){
        ll len=0;
        vector<bool>vis(n,false);
        queue<ll>q;
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                ll front=q.front();
                q.pop();
                for(auto nei:adj[front]){
                    if(ss.find(nei)!=ss.end()&&!vis[nei]){
                        q.push(nei);
                        vis[nei]=true;
                    }
                }
            }
            len++;
        }
        ll cnt=0;
        for(auto i:vis)if(i)cnt++;
        if(cnt!=path.size())return -1;
        ans=max(ans,len-1);
    }
    return ans;
}
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        vector<int>ans(n-1,0);
        for(auto &x:edges){
            adj[x[0]-1].push_back(x[1]-1);
            adj[x[1]-1].push_back(x[0]-1);
        }
        for(ll mask=0;mask<(1LL<<n);mask++){
            vector<ll>path;
            for(ll j=0;j<n;j++){
                if(mask&(1LL<<j)){
                    path.push_back(j);
                }
            }
            if(path.size()<=1){
                continue;
            }
            ll max_size=bfs(adj,path,n);
            cout<<max_size<<endl;
            if(max_size!=-1)ans[max_size-1]++;
        }
        return ans;
    }
};

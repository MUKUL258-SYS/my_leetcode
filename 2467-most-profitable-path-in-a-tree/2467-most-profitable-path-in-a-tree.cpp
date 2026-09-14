class Solution {
public:
vector<vector<int>>adj;
bool dfs(int src,int time ,unordered_map<int,int>&path,vector<bool>& vis){
    vis[src]=true;
    path[src]=time;
    if(src==0)return true;
    for(auto nei:adj[src]){
        if(!vis[nei]){
            if(dfs(nei,time+1,path,vis))return true;
        }
    }
    path.erase(src);
    return false;
}
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n=edges.size();
    adj.resize(n+5);
    for(auto e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    queue<vector<int>>q;
    int ans=INT_MIN;
    vector<bool>vis(n,false);
    unordered_map<int,int>mp;
    dfs(bob,0,mp,vis);
    vis.assign(n,false);
   // vis[0]=true;
    q.push({0,0,0});
    while(!q.empty()){
        auto f=q.front();
        int node=f[0];
        int time=f[1];
        int inc=f[2];
        q.pop();
        vis[node]=true;
        if(mp.find(node)==mp.end()){
            inc+=amount[node];
        }
        else{
            if(time<mp[node]){
                inc+=amount[node];
            }
            else if(time==mp[node]){
                inc+=(amount[node]/2);
            }
        }
        if(adj[node].size()==1 && node!=0 )
        ans=max(ans,inc);
        
        for(auto nei:adj[node]){
            if(!vis[nei]){
                q.push({nei,time+1,inc});
            }
        }
    }
    return ans;
    
        
    }
};
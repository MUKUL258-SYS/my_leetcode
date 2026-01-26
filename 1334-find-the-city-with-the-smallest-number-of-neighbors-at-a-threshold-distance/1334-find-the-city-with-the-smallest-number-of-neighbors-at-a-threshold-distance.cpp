class Solution {
public:
int d;
int n;
vector<vector<pair<int,int>>>adj;
/*int bfs(int node){
    queue<pair<int,int>>q;
    q.push({node,0});
    vector<int>vis(n,false);
    vis[node]=true;
    int cnt=0;
    while(!q.empty()){
auto f=q.front();
int dist=f.second;
int node=f.first;
if(dist<=d)cnt++;
else continue;
q.pop();
for(auto i:adj[node]){
    auto {nei,w}=i;
    if(!vis[nei]){
        vis[nei]=true;
        q.push({nei,dist+w});
    }
}
    }
    return cnt;
    
}
*/
int bfs(int node){
    int cnt=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,node});
    vector<int>dist(n,INT_MAX);
    dist[node]=0;
    while(!pq.empty()){
        auto [cd,u]=pq.top();
        pq.pop();
       
        if(cd>dist[u])continue;
        if(cd>d)break;
        cnt++;
        for(auto [v,w]:adj[u]){
            if(dist[u]+w<dist[v]){
             dist[v]=w+dist[u];
             pq.push({dist[v],v});
            }
        }
        

    }
    return cnt-1;
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        this->n=n;
   d=distanceThreshold;
   adj.resize(n);
   
   for(auto i:edges){
     adj[i[0]].push_back({i[1],i[2]});
     adj[i[1]].push_back({i[0],i[2]});
   }
   int mini=INT_MAX;
   //int maxi=INT_MIN;
   int ans;
        for(int i=0;i<n;i++){
           int v=bfs(i);
           if(v<mini){
            mini=v;
            ans=i;
           }
           else if(v==mini){
             ans=max(ans,i);
           }
        }
        return ans;
    }
};
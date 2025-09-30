class Solution {
public:
long long k;
bool dijkstra(int s,int e,int mid,vector<vector<pair<int,int>>>&adj){
   int n=adj.size();
   vector<long long>dist(n,LLONG_MAX);
   dist[s]=0;
   priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>pq;
   pq.emplace(0,s);
   while(!pq.empty()){
   auto [d,node]=pq.top();
    pq.pop();
    if(d>dist[node])continue;
    if(node==e)return true;
    for(auto &[v,w]:adj[node]){
        long long total_d=w+d;
        if(w<mid)continue;
        if(total_d>k)continue;
        if(total_d<dist[v]){
            dist[v]=total_d;
            pq.emplace(dist[v],v);
        }
    }
   }
   return false;
}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        this->k=k;
        vector<vector<pair<int,int>>>adj(n);
        int maxi=-1;
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            if(online[u]&&online[v]){
                adj[u].push_back({v,w});
                maxi=max(maxi,w);
            }
        }
        int s=0;
        int e=maxi;
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(dijkstra(0,n-1,mid,adj)){
                ans=max(ans,mid);
              s=mid+1;
            }
            else e=mid-1;
        }
        return ans;

    }
};
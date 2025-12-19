class Solution {
public:
#define pi pair<int,int>
int bfs(vector<vector<pi>>&adj,int n){
    
    vector<int>dis(n,1e9);
    priority_queue<pi,vector<pi>,greater<pi>>pq;
 dis[0]=0;
 pq.push({0,0});
    while(!pq.empty()){
        auto p=pq.top();
        int dist=p.first;
        int node=p.second;
        pq.pop();
        if(node==n-1)return dis[node];
        if(dist>dis[node])continue;
        for(auto i:adj[node]){
           // if(vis[nei])continue;
           int nei=i.first;
           int d=i.second;
            if(d+dis[node]<dis[nei]){
                dis[nei]=d+dis[node];
                pq.push({dis[nei],nei});
            }
        }

    }
    return dis[n-1];
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pi>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back({i+1,1});
        }
        vector<int>res;
        for(auto i:queries){
            adj[i[0]].push_back({i[1],1});
            res.push_back(bfs(adj,n));
        }
        return res;
    }
};
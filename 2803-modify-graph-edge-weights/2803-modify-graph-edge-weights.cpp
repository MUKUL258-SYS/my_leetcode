class Solution {
public:
vector<vector<pair<int,int>>>adj;
int dijkstra(int s,int d,vector<vector<pair<int,int>>>&adj){
    int n=adj.size();
    vector<int>dist(n,INT_MAX);
    dist[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto [dt,node]=pq.top();
        pq.pop();
        for(auto [nei,d]:adj[node]){
            if(dist[node]+d<dist[nei]){
                dist[nei]=dist[node]+d;
                pq.push({dist[nei],nei});
            }
        }
       
    }
    return dist[d];
}
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int s, int d, int target) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:edges){
            if(i[2]==-1)continue;
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        int dis=dijkstra(s,d,adj);
        if(dis<target){
            return {};
        }
        else if(dis==target){
            for(auto &i:edges){
                if(i[2]==-1)i[2]=1e9;
            }
            return edges;
        }
        else{
               for(auto &i:edges){
                if(i[2]==-1){
                    i[2]=1;
                adj[i[0]].push_back({i[1],1});
                adj[i[1]].push_back({i[0],1});
                int dist=dijkstra(s,d,adj);
                if(dist<=target){
                    i[2]+=(target-dist);
                    for(auto &j:edges){
                        if(j[2]==-1){
                            j[2]=1e9;
                        }
                    }
                    return edges;
                }
                }
               }
               //return edges;
        }
        return {};
    }
};
class Solution {
public:
int minmax( vector<vector<pair<int,int>>>&gr,int n,int src,int des,int ban_u,int ban_v){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n,1e9);
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();
        if(u==des)return d;
        for(auto &[v,w]:gr[u]){
            if((u==ban_u&&v==ban_v)||(v==ban_u&&u==ban_v))continue;
            int dis=max(d,w);
            if(dis<dist[v]){
                dist[v]=dis;
                pq.push({dist[v],v});
            }
        }
    }
    return 1e9;
}
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<vector<pair<int,int>>>gr(n);
        for(auto i:edges){
            gr[i[0]].push_back({i[1],i[2]});
            gr[i[1]].push_back({i[0],i[2]});
        }
        vector<vector<int>>ans(2);
        int k=0;
        for(auto i:edges){
            int w=i[2];
            int u=i[0];
            int v=i[1];
            int wt=minmax(gr,n,u,v,u,v);
            if(w<wt){
                ans[0].push_back(k);
            }
            else if(w==wt){
                ans[1].push_back(k);
            }
            k++;
        }
        return ans;

    }
};
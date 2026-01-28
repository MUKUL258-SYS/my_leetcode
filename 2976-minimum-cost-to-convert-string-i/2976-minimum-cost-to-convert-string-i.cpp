class Solution {
public:
vector<vector<pair<int,int>>>adj;
vector<long long> bfs(int node){
    vector<long long>dist(26,LLONG_MAX);
    dist[node]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,node});
    while(!pq.empty()){
        auto [wt,u]=pq.top();
        pq.pop();
        for(auto [v,w]:adj[u]){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }

    }
    return dist;
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        int m=26;
        adj.resize(m);
        for(int i=0;i<n;i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        vector<vector<long long>>vp;
        for(char ch='a';ch<='z';ch++){
           vp.push_back(bfs(ch-'a'));
        }
        long long res=0;
        n=source.size();
        for(int i=0;i<n;i++){
            if(source[i]==target[i])continue;
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(vp[u][v]==LLONG_MAX)return -1;
            res+=vp[u][v];
        }
        return res;
    }
};
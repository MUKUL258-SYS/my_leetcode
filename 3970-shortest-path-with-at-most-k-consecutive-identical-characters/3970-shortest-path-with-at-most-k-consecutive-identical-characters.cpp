class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<long long>>dist(n,vector<long long>(k+1,LLONG_MAX));
         priority_queue<
               vector<long long>,
               vector<vector<long long>>,
        greater<vector<long long>>>pq;
    vector<vector<pair<int,int>>>adj(n);
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        int w=i[2];
        adj[u].push_back({v,w});
    }
    pq.push({0,0,k});
    dist[0][k]=0;
    while(!pq.empty()){
        int d=pq.top()[0];
        int node=pq.top()[1];
        int rem=pq.top()[2];
        pq.pop();
        if(d>dist[node][rem])continue;
        for(auto j:adj[node]){
            int nei=j.first;
            int w=j.second;
            if(labels[node]==labels[nei]){
                if(rem<=1)continue;
                if(dist[nei][rem-1]>d+w){
                   dist[nei][rem-1]=d+w;
                   pq.push({dist[nei][rem-1],nei,rem-1});

                }
            }
            else{
                 if(dist[nei][k]>d+w){
                   dist[nei][k]=d+w;
                   pq.push({dist[nei][k],nei,k});

                }
            }
        }
    }
    long long mini=LLONG_MAX;
    for(int i=1;i<=k;i++){
        mini=min(mini,dist[n-1][i]);
    }
    if(mini==LLONG_MAX)return -1;
    return mini;

    }
};
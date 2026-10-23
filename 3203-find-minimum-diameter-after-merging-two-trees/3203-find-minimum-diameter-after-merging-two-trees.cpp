class Solution {
public:
pair<int,int> bfs(vector<vector<int>>&adj,int node){
    int n=adj.size();
    vector<int>dist(n,-1);
    dist[node]=0;
    queue<int>q;
    int farthest;
    q.push(node);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        farthest=f;
        for(auto nei:adj[f]){
            if(dist[nei]==-1){
                dist[nei]=1+dist[f];
                q.push(nei);
            }
        }
    }
    return {farthest,dist[farthest]};
}
    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2){
         vector<vector<int>>adj1,adj2;
         int n=e1.size();
         int m=e2.size();
         adj1.resize(n+1);
         adj2.resize(m+1);
         for(auto i:e1){
            adj1[i[0]].push_back(i[1]);
             adj1[i[1]].push_back(i[0]);
         }
          for(auto i:e2){
            adj2[i[0]].push_back(i[1]);
             adj2[i[1]].push_back(i[0]);
         }
        auto p1=bfs(adj1,0);
        auto d1=bfs(adj1,p1.first);
        auto p2=bfs(adj2,0);
        auto d2=bfs(adj2,p2.first);
        int a=d1.second;
        int b=d2.second;
        return max({a,b,(a+1)/2 + (b+1)/2 +1});
    }
};
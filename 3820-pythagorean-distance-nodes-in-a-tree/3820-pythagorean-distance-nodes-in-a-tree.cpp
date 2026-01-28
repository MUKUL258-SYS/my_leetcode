class Solution {
public:
//vector<int>d1,d2,d3;
int n;
vector<long long> bfs(int node,vector<vector<int>>&adj){
      queue<int>q;
     // dist.resize(n,INT_MAX);
     vector<long long>dist(n,LLONG_MAX);
      q.push(node);
      dist[node]=0;
      while(!q.empty()){
        auto f=q.front();
        q.pop();
        for(auto i:adj[f]){
            if(dist[i]==LLONG_MAX){
                dist[i]=dist[f]+1;
                q.push(i);
            }
        }
      }
      return dist;
      
}
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
     this->n=n;    
     vector<vector<int>>adj(n);
     for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
     }

     vector<long long>d1=bfs(x,adj);
     vector<long long>d2=bfs(y,adj);
     vector<long long>d3=bfs(z,adj);
     int cnt=0;
     for(int i=0;i<n;i++){
        long long v1=d1[i];
        long long v2=d2[i];
        long long v3=d3[i];
        if(v1==LLONG_MAX||v2==LLONG_MAX||v3==LLONG_MAX)continue;
        vector<long long>v={v1,v2,v3};
        sort(v.begin(),v.end());
      v1=v[0]*v[0]+v[1]*v[1];
      v2=v[2]*v[2];
     cnt+=(v1==v2?1:0);
     }
     return cnt;
    }
};
class Graph {
public:
vector<vector<pair<int,int>>>adj;
int n;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        this->n=n;
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];
         //   vector<int>temp={v,w};
            adj[u].push_back({v,w});
        }
    }
    
    void addEdge(vector<int> edge){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node1});
        dist[node1]=0;
        while(!pq.empty()){
             auto [d,node]=pq.top();
              pq.pop();
              if(d>dist[node])continue;
              for(auto &i:adj[node]){
                int nei=i.first;
                int w=i.second;
               if(dist[nei]>d+w){
                dist[nei]=d+w;
                pq.push({dist[nei],nei});
               }
              }
        }
        return dist[node2]==INT_MAX?-1:dist[node2];

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
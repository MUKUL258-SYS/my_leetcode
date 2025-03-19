class Solution {
public:
vector<vector<int>>adj;
vector<int>color;
int n;
int bfs(vector<int>&comp) {
    int maxDepth=0;
    for(auto &node:comp){
    queue<int> q;
    q.push(node);
    //int maxDepth=0;
    vector<int>depth(n+6,-1);
    depth[node] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto nei : adj[curr]) {
            if (depth[nei]==-1) { // Not visited
                depth[nei] = depth[curr] + 1;
                maxDepth = max(maxDepth, depth[nei]);
                q.push(nei);
            }
        }
    }

    }
    return maxDepth+1;
}

bool dfs(int node,int col,vector<int>&component){
    color[node]=col;
    component.push_back(node);
    for(auto nei:adj[node]){
        if(color[nei]==-1){
            if(!dfs(nei,!col,component))return false;
        }
        else if(color[nei]==col)return false;
    }
    return true;
}
    int magnificentSets(int n, vector<vector<int>>& edges) {
        //vector<vector<int>>adj(n+6);
        this->n=n;
        adj.resize(n+6);
        color.assign(n+6,-1);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<int>>components;
        
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                components.emplace_back();
                if(!dfs(i,0,components.back()))return -1;
            }
        }
        int total=0;
        for(auto &comp:components){
            total+=bfs(comp);
        }
        return total;

    }
};
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
       vector<vector<int>>adj(n+1);
       for(auto i:d){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
       }
       vector<int>color(n+1,-1); 
       for(int i=1;i<=n;i++){
        if(color[i]!=-1)continue;
        queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nei:adj[node]){
                if(color[nei]==-1){
                    color[nei]=1-color[node];
                    q.push(nei);
                }
                else if(color[nei]==color[node]){
                    return false;
                }
            }

        }
       }
       return true;
    }
};
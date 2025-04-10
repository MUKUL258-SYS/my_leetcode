class Solution {
public:
int res;
int maxTime;
vector<vector<pair<int,int>>>adj;
vector<int>values;
void dfs(int node,int score,int time,vector<int>&vis){
     if(time>maxTime)return;

     if(!vis[node])score+=values[node];

     vis[node]++;

     if(node==0)res=max(res,score);

     for(auto nei:adj[node]){
       // time+=nei.second;
        dfs(nei.first,score,time+nei.second,vis);
     }

     vis[node]--;
}
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        res=values[0];

        int n=values.size();
        adj.resize(n);
        this->maxTime=maxTime;
        this->values=values;

        for(auto i:edges){
          adj[i[0]].push_back({i[1],i[2]});
          adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>vis(n,0);
        dfs(0,0,0,vis);
        return res;
    }
};
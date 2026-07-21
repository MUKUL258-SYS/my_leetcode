class Solution {
public:
int ss;
void dfs(int parent,int node,int dis,int & cnt, vector<vector<pair<int,int>>>&adj){
    if(dis%ss==0)cnt++;
    for(auto [nei,wt]:adj[node]){
        if(parent!=nei){
            dfs(node,nei,dis+wt,cnt,adj);
        }
    }
}
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n=edges.size();
        vector<vector<pair<int,int>>>adj(n+1);
        ss=signalSpeed;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
       vector<int>res(n+1,0);
       for(int i=0;i<=n;i++){
        vector<int>temp;
        long long sum=0;
       // int cnt=0;
        for(auto [nei,wt]:adj[i]){
             int cnt=0;
            dfs(i,nei,wt,cnt,adj);
            temp.push_back(cnt);
            sum+=cnt;
        }
        int value=0;
        for(auto i:temp){
            value+=(i*(sum-i));
        }
        res[i]=value/2;



       }
       return res;

    }
};
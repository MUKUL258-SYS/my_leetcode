class Solution {
public:
vector<vector<int>>adj;
long long n,ans;
int seats;
long long dfs(int node,vector<bool>&vis){
    vis[node]=true;
    long long cnt=1;
    //if(node==0)cnt--;
    for(auto nei:adj[node]){
        if(!vis[nei]){
            cnt+=dfs(nei,vis);
        }
    }
    int x=cnt/seats;
    if(cnt%seats)x++;
   if(node!=0)ans+=x;
    return cnt;

}
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
         n=roads.size();
         this->seats=seats;
         ans=0;
        adj.resize(n+1);
        vector<bool>vis(n+1,false);
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
         dfs(0,vis);
         return ans;
    }
};
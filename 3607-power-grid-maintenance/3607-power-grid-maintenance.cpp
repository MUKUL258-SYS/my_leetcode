class Solution {
public:
vector<int>root;
vector<set<int>>v;
void dfs(int i0,int i,vector<vector<int>>&adj,vector<int>&vis){
    root[i]=i0;
    vis[i]=1;
    v[i0].insert(i);
    for(auto nei:adj[i]){
        if(vis[nei]==0){
            dfs(i0,nei,adj,vis);
        }
    }
}
    vector<int> processQueries(int c, vector<vector<int>>& co, vector<vector<int>>& queries) {
        root.resize(c+5);
        v.resize(c+5);
         vector<vector<int>>adj(c+1);
         for(auto i:co){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
         }
         vector<int>vis(c+1,0);
         for(int i=1;i<=c;i++){
            if(vis[i]==0){
                vis[i]=1;
                dfs(i,i,adj,vis);
            }
         }
         vector<int>ans;
         for(auto i:queries){
            int x=i[0];
            int y=i[1];
            auto& comp=v[root[y]];
            if(x==2){
                 comp.erase(y);
            }
            else{
                if(comp.empty())ans.push_back(-1);
                else if(comp.count(y))ans.push_back(y);
                else{
                    ans.push_back(*comp.begin());
                }
            }
         }
         return ans;

    }
};
class Solution {
public:
vector<vector<pair<int,int>>>gr;
int mod=1e9+7;
 void dfs(int node,vector<bool>&vis,vector<int>&v){
    vis[node]=true;
    for(auto &[nei,weight]:gr[node]){
        if(!vis[nei]){
            v[nei]=(1LL*v[node]*weight)%mod;
            dfs(nei,vis,v);
        }
    }
}
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n=conversions.size();
        gr.resize(n+1);
        vector<bool>vis(n+1,false);
        vector<int>v(n+1,1);
        for(auto i:conversions){
                gr[i[0]].push_back({i[1],i[2]});
        }
        dfs(0,vis,v);
       return v;
    }
};
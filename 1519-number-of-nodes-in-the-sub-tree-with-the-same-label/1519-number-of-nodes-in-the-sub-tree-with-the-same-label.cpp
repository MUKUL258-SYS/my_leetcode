class Solution {
public:
vector<vector<int>>adj;
string l;
vector<int>ans;
vector<int>dfs(int node,int parent){
   vector<int>vp(26,0);
   for(auto nei:adj[node]){
    if(nei==parent)continue;
    vector<int>v=dfs(nei,node);
    for(int i=0;i<26;i++){
        vp[i]+=v[i];
    }
   }
   vp[l[node]-'a']++;
   ans[node]= vp[l[node]-'a'];
  // cout<<node<<endl;
  // for(auto i:vp)cout<<i<<" ";
  // cout<<endl;
   return vp;
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        ans.resize(n,0);
        l=labels;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0,-1);
        return ans;

    }
};
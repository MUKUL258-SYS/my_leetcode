class Solution {
public:
int n;
vector<int>ans;
vector<vector<int>>adj;
string s;
void dfs(int node,vector<int>last,vector<int>&parent){
    int i=s[node]-'a';
    if(last[i]!=-1)parent[node]=last[i];
    last[i]=node;
    for(auto m:adj[node])dfs(m,last,parent);
    if(parent[node] >=0)ans[parent[node]]+=ans[node];
}
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
      n=parent.size();
    //  this->parent=parent;
      this->s=s;
   ans.resize(n,1);
   adj.resize(n);
   //last.resize(n,-1);
   for(int i=1;i<n;i++)adj[parent[i]].push_back(i);
   vector<int>last(26,-1);
   dfs(0,last,parent);
   return ans;

    }
};
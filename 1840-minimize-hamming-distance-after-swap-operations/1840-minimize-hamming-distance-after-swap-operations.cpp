class Solution {
public:
vector<vector<int>>adj;
vector<int>temp;
vector<bool>vis;
int n;
int find(vector<int>&temp,vector<int>&source,vector<int>&target){
    unordered_map<int,int>mp;
    for(auto i:temp){
        mp[source[i]]++;
        mp[target[i]]--;
    }
    int res=0;
    for(auto i:mp){
        res+=abs(i.second);
    }
    return res/2;
}
void dfs(int node){
    vis[node]=true;
    for(auto nei:adj[node]){
        if(!vis[nei]){
            temp.push_back(nei);
            dfs(nei);
        }
    }
}
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& arr) {
      n=source.size();
      adj.resize(n);  
     // temp.resize(n);
      vis.resize(n);
      for(auto i:arr){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
      }
      int res=0;
      for(int i=0;i<n;i++){
        if(vis[i])continue;
        temp.clear();
        temp.push_back(i);
        dfs(i);
        res+=find(temp,target,source);

      }
      return res;
    }
};
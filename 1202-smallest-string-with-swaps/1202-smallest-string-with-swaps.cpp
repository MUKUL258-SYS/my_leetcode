class Solution {
public:
string s;
void dfs(int node,vector<bool>&vis,vector<int>&v,vector<vector<int>>&adj){
    vis[node]=true;
    v.push_back(node);
    for(auto nei:adj[node]){
        if(!vis[nei]){
              dfs(nei,vis,v,adj);
        }
    }
}
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
       int n=s.size();
       this->s=s;
        vector<vector<int>>adj(n);
        for(auto i:pairs){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>vis(n,false);
        string ans="";
      //  string t="";
        for(int i=0;i<n;i++){
            if(!vis[i]){
                 vector<int>v;
                dfs(i,vis,v,adj);
                sort(v.begin(),v.end());
                vector<char>vp;
                for(auto i:v){
                    vp.push_back(s[i]);
                }
                sort(vp.begin(),vp.end());
               int k=0;
               for(auto i:v){
                s[i]=vp[k++];
               }
            }
        }
        return s;
    }
};
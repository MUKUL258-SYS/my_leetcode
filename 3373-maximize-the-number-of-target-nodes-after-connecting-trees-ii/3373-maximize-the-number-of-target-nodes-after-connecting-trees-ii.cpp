class Solution {
public:
vector<vector<int>>built(vector<vector<int>>&edges){
    int n=edges.size();
    vector<vector<int>>adj(n+1);
    for(auto &i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    return adj;
}
void dfs(vector<vector<int>>&adj,int u,int parent,vector<int>&color,int &even,int &odd){
    if(color[u]==0)even++;
    else odd++;
    for(auto i:adj[u]){
        if(i!=parent){
            color[i]=color[u]^1;
            dfs(adj,i,u,color,even,odd);
        }
    }
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

       auto adjA=built(edges1);
       auto adjB=built(edges2);
       //int n=edges1.size();
       //int m=edges2.size();
       int n=adjA.size();
       int m=adjB.size();
       vector<int>v1(n,-1);
       vector<int>v2(m,-1);
       v1[0]=0;
       v2[0]=0;
       int e1=0,e2=0,o1=0,o2=0;
    
       dfs(adjA,0,-1,v1,e1,o1);
       dfs(adjB,0,-1,v2,e2,o2);
       vector<int>v;
       for(auto i:v1){
        cout<<i<<" ";
       }
       for(auto i:v1){
    if(i==0){
        v.push_back(e1+max(e2,o2));
    }
    else{
        v.push_back(o1+max(e2,o2));
    }
       }
       return v;
       
    }
};
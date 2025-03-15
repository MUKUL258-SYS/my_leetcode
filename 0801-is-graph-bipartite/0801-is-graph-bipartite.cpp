class Solution {
public:
bool dfs(int node,vector<int>& color,vector<vector<int>>&gr,int col){
    color[node]=col;
    for(auto nei:gr[node]){
        if(color[nei]==-1){
            if(!dfs(nei,color,gr,!col))return false;
        }
        else if(color[nei]==col)return false;
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,color,graph,0))return false;
            }
        }
        return true;
    }
};
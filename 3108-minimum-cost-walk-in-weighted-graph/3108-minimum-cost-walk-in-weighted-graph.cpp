class Solution {
public:
//vector<int>cost;
int find(int i,vector<int>&parent){
    if(parent[i]==i)return i;
    return parent[i]=find(parent[i],parent);
}
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int>cost(n,-1);
        vector<int>parent(n);
        std::iota(parent.begin(),parent.end(),0);
        for(auto &m:edges){
            int u=m[0];
            int v=m[1];
            int w=m[2];
            int ru=find(u,parent);
            int rv=find(v,parent);
            if(ru != rv){
                parent[ru]=rv;
                cost[rv]=cost[ru]&cost[rv]&w;
            }
            else{
                cost[rv]=cost[rv]&w;
            }
        }
        vector<int>vp;
        for(auto &m:query){
            int u=m[0];
            int v=m[1];
            
            if(u==v)vp.push_back(0);
            else if(find(u,parent)!=find(v,parent)){
                vp.push_back(-1);
            }
            else{
                vp.push_back(cost[find(v,parent)]);
            }
        }
        return vp;

    }
};
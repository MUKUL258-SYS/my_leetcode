class DSU{
    private:
    vector<int>parent;
    vector<int>rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.assign(n,1);
        std::iota(parent.begin(),parent.end(),0);
    }
    int find(int i){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i]);
    }
    bool unite(int i,int j){
        int rooti=find(i);
        int rootj=find(j);
        if(rooti != rootj){
            if(rank[rooti]<rank[rootj]){
                std::swap(rooti,rootj);
            }
            parent[rootj]=rooti;
            if(rank[rooti]==rank[rootj]){
                rank[rooti]++;
            }
            return true;
        }
        return false;
    }
};
class Solution {
public:
/*class DSU(int n){
    vector<int>parent(n);
    vector<int>rank(n);
    DSU(){
        parent.resize(n);
        rank.assign(n,1);
        std::iota(parent.begin(),parent.end(),0);
    }
    int find(int i){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i]);
    }
    bool unite(int i,int j){
        int rooti=find(i);
        int rootj=find(j);
        if(rooti != rootj){
            if(rank[rooti]<root[rootj]){
                std::swap(rooti,rootj);
            }
            parent[rootj]=rooti;
            if(rank[rooti]==rank[rootj]){
                rank[rooti]++;
            }
            return true;
        }
        return false;
    }
};
*/
int mst(int n,vector<vector<int>>& edges,int forceedge=-1,int tempedge=-1){
    DSU dsu(n);
      int cnt_edges=0;
      int min_weight=0;
      if(forceedge!=-1){
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            int id=e[3];
            if(id ==forceedge){
                 //cnt_edges=1;
                 if(dsu.unite(u,v)){
                      cnt_edges=1;
                 min_weight+=w;
                 //break;
                 }
                 break;

            }
        }
        
      }
      for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            int id=e[3];
            if(id== tempedge || id== forceedge){
                continue;
            }
            //cnt_edges++;
                if(dsu.unite(u,v)){
                 min_weight+=w;
                   cnt_edges++;
                // break;
                }
      }
      if(cnt_edges==(n-1))return min_weight;
      return INT_MAX;

}
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>>newEdges;
        /*sort(newEdges.begin(), newEdges.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
});
*/
int m=edges.size();
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
      newEdges.push_back({u,v,w,i});
        }
        sort(newEdges.begin(), newEdges.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
});
        int baseweight=mst(n,newEdges,-1,-1);
        vector<int>critical,pcritical;
   
        for(int i=0;i<m;i++){
            if(mst(n,newEdges,-1,i)>baseweight){
                critical.push_back(i);
            }
            else if(mst(n,newEdges,i,-1) == baseweight){
                pcritical.push_back(i);
            }
        }
        return {critical,pcritical};
    }
};
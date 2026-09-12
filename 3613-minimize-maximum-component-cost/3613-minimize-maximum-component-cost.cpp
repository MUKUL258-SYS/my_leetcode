class DSU{
  public:
  std::vector<int>parent;
  DSU(int n):parent(n){
   std::iota(parent.begin(),parent.end(),0);
  }
  int find(int n){
    if(parent[n]==n)return n;
    return parent[n]=find(parent[n]);
  }
  bool unite(int a,int b){
    int pa=find(a);
    int pb=find(b);
    if(pa!=pb){
          parent[pa]=pb;
    return true;
    }
    return false;
  }

};
class Solution {
public:

    int minCost(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        sort(edges.begin(),edges.end(),[](const vector<int> &v1,const vector<int> &v2){
           return v1[2]<v2[2];
        });
       int c=n;
       int maxi=0;
        for(auto e:edges){
          if(dsu.unite(e[0],e[1])){
            //union(e[0],e[1]);
            maxi=max(maxi,e[2]);
            c--;
          }
          if(c==k){
            return maxi;
          }
        }
        return 0;


    }
};
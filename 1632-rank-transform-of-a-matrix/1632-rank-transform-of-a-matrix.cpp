class Dsu {
private:
    vector<int>parent;
public:
    Dsu(int n){
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    
    int find(int x){
        if(parent[x] != x)parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)return;
        parent[y]=x;
    }
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();
       map<int,vector<pair<int,int>>>mp;
         vector<vector<int>>ans(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           // DSU dsu(n+m);
           mp[mat[i][j]].push_back({i,j});

        }
       } 
          vector<int>rowMaxRank(n), colMaxRank(m);
       for(auto p:mp){
        Dsu dsu(n+m);
        for(auto [row,col]:p.second){
           dsu.unite(row,col+n);
        }
        unordered_map<int,int>rootRank;
        for(auto [row,col]:p.second){
            int root=dsu.find(row);
            rootRank[root]=max(rootRank[root],max(rowMaxRank[row],colMaxRank[col])+1);
        }
        for(auto [row,col]:p.second){
             int root=dsu.find(row);
             int rank=rootRank[root];
             ans[row][col]=rowMaxRank[row]=colMaxRank[col]=rank;
        }
       } 
       return ans;    
    }
};
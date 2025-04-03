class DSU{
    public:
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    bool Union(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py)return false;
        if(rank[px]<rank[py]){
            rank[py]+=rank[px];
            parent[px]=parent[py];
        }
        else{
            rank[px]+=rank[py];
            parent[py]=parent[px];
        }
        return true;
    }
};
class Solution {
public:

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m=queries.size();
        DSU dsu(n);
        vector<bool>vp(m,false);
        int l=edgeList.size();
        for(int i=0;i<m;i++)queries[i].push_back(i);
        int i=0;
        sort(queries.begin(),queries.end(),[&](auto const &a,auto const &b){       return a[2]<b[2];

        });
        sort(edgeList.begin(),edgeList.end(),[&](auto const &a,auto const&b){
           return a[2]<b[2];
        });
        for(auto j:queries){
            while(i<l&&edgeList[i][2]<j[2]){
            int a=edgeList[i][0];
            int b=edgeList[i][1];
                dsu.Union(a,b);
                i++;
            }
            if(dsu.find(j[0])==dsu.find(j[1])){
                vp[j[3]]=true;
            }
            
        }
        return vp;
    }
};
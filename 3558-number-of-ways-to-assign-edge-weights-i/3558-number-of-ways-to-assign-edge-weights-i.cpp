class Solution {
public:
int mod=1e9+7;
vector<vector<int>>adj;
int dfs(int node,int parent){
    int maxi=0;
    for(auto nei:adj[node]){
        if(nei!=parent)
        maxi=max(maxi,(1+dfs(nei,node)));
    }
    return maxi;
}
long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
      //  vector<vector<int>>adj(n+1);
      adj.resize(n+1);
        for(auto &i:edges){
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(i[0]);
        }
        int value=dfs(1,-1);
       // value-=1;
        return power(2*(1ll),(1ll)*(value-1));

    }
};
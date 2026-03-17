class Solution {
public:
int find_parent(vector<int>&parent,int node){
    if(parent[node]==node)return node;
    return parent[node]=find_parent(parent,parent[node]);
}
void unionSet(vector<int>&parent,vector<int>&rank,int u,int v){
    if(rank[u]<rank[v]){
        parent[u]=v;
        rank[v]++;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<accounts.size();i++){
            auto account=accounts[i];
            for(int j=1;j<account.size();j++){
                  if(mp.find(account[j])==mp.end()){
                    mp[account[j]]=i;
                  }
                  else{
                    int u=mp[account[j]];
                    int v=i;
                    u=find_parent(parent,u);
                    v=find_parent(parent,v);
                    if(u!=v){
                        unionSet(parent,rank,u,v);
                    }
                  }
            }
        }
        unordered_map<int,set<string>>m;
        for(auto [str,node]:mp){
            node=find_parent(parent,node);
            m[node].insert(str);
        }
        vector<vector<string>>res;
        for(int i=0;i<n;i++){
            vector<string>temp;
            if(parent[i]==i){
                  temp.push_back(accounts[i][0]);
                  for(auto j:m[i]){
                    temp.push_back(j);
                  }
                  res.push_back(temp);
            }
        }
        return res;
    }
};
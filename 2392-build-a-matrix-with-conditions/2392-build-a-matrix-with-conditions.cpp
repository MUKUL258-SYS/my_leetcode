class Solution {
public:
////vector<vector<int>>adj1;
//vector<vector<int>>adj2;
int k;
vector<int> topo(vector<vector<int>>&edges){
  //  int cnt=0;
    queue<int>q;
    vector<vector<int>>adj(k+1);
    vector<int>indegree(k+1,0);
    for(auto i:edges){
       adj[i[0]].push_back(i[1]);
        indegree[i[1]]++;
    }
    for(int i=1;i<=k;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    vector<int>v;
    //v.reserve(k);
    while(!q.empty()){
        int f=q.front();
        q.pop();
          cnt++;
          v.push_back(f);
          for(auto nei:adj[f]){
            indegree[nei]--;
            if(indegree[nei]==0)q.push(nei);
          }
    }
    if(cnt !=k)return {};
    return v;
}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
      this->k=k;
       
       vector<vector<int>>res(k,vector<int>(k,0));
       
        vector<int>v1=topo(r);
        vector<int>v2=topo(c);
        if(v1.empty()|| v2.empty())return {};
        vector<int>posx(k+1),posy(k+1);
        for(int i=0;i<k;i++){
            posx[v1[i]]=i;
        }
        for(int i=0;i<k;i++){
            posy[v2[i]]=i;
        }
        for(int i=1;i<=k;i++){
            res[posx[i]][posy[i]]=i;
        }
        return res;
    }
};
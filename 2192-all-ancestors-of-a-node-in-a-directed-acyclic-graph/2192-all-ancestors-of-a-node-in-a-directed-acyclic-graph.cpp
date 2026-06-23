class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>res(n);
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto i:edges){
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
        auto node=q.front();
        //cout<<node<<endl;
        q.pop();
        for(auto nei:adj[node]){
           // res[nei].push_back(node);
            //vector<int>t=res[node];
            set<int>s=res[node];
            //for(auto j:t)res[nei].push_back(j);
            for(auto itr=s.begin();itr!=s.end();itr++){
                res[nei].insert(*itr);
            }
            //res[nei].push_back(node);
            res[nei].insert(node);
            indegree[nei]--;
            if(indegree[nei]==0)q.push(nei);
        }
    }
    vector<vector<int>>v(n);
    for(int i=0;i<n;i++){
        set<int>s=res[i];
        for(auto itr=s.begin();itr!=s.end();itr++)
        v[i].push_back(*itr);
    }
  return v;
    

    }
};
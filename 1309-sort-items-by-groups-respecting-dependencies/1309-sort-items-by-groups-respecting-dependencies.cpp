class Solution {
public:
vector<int> topoSort(unordered_map<int,vector<int>>adj,vector<int>indegree){
      queue<int>q;
      for(int i=0;i<adj.size();i++){
        if(indegree[i]==0)q.push(i);
      }
      vector<int>res;
      while(!q.empty()){
        int f=q.front();
        res.push_back(f);
        q.pop();
        for(auto nei:adj[f]){
            indegree[nei]--;
            if(indegree[nei]==0){
                q.push(nei);
            }
        }
      }
      return res.size()==adj.size()?res:vector<int>();
}
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i]==-1)group[i]=m++;
        }
        //step1 make item graph and itemindegree
        unordered_map<int,vector<int>>itemGraph;
        vector<int>itemindegree(n,0);
        for(int i=0;i<n;i++){
            itemGraph[i]=vector<int>();
        }
        unordered_map<int,vector<int>>groupGraph;
        vector<int>groupindegree(m,0);
        for(int i=0;i<m;i++){
            groupGraph[i]=vector<int>();
        }
        for(int i=0;i<n;i++){
            for(int prev:beforeItems[i]){
                itemGraph[prev].push_back(i);
                itemindegree[i]++;
                if(group[i]!=group[prev]){
                    int previtemgroup=group[prev];
                    int curritemgroup=group[i];
                    groupGraph[previtemgroup].push_back(curritemgroup);
                    groupindegree[curritemgroup]++;
                }
            }
        }
        vector<int>itemorder=topoSort(itemGraph,itemindegree);
        vector<int>grouporder=topoSort(groupGraph,groupindegree);
        unordered_map<int,vector<int>>grouptoitem;
        for(auto &item:itemorder){
            int itemgroup=group[item];
            grouptoitem[itemgroup].push_back(item);
        }
        vector<int>res;
        for(auto i:grouporder){
            res.insert(res.end(),grouptoitem[i].begin(),grouptoitem[i].end());
        }
           return res;
    }
};
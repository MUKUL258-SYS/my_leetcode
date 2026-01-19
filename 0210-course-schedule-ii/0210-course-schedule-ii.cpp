class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& prereq) {
    //    return {};
        vector<vector<int>>adj(num);
        vector<int>indegree(num,0);
        for(auto i:prereq){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int>q;
        /*for(auto i:indegree){
            if(i==0)q.pu
        }
        */
        vector<int>v;
        vector<bool>vis(num,false);
        for(int i=0;i<num;i++){
            if(indegree[i]==0){q.push(i);
           // v.push_back(i);
            //vis[i]=true;
            }
        }
        while(!q.empty()){
  int sz=q.size();
  while(sz--){
    int f=q.front();
    v.push_back(f);
    q.pop();
    for(auto nei:adj[f]){
        indegree[nei]--;
        if(indegree[nei]==0){
            q.push(nei);
           // vis[nei]=true;
        }
    }

  }
        }
  
       // return v.size()==num?v:{};
       if(v.size()!=num)return {};
       return v;
    }
};
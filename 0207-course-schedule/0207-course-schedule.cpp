class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int n=numCourses;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto i:prereq){
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        queue<int>q;
        /*for(auto i:indegree){
            if(i==0){
                q.push(i);
            }
        }
        */
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }

        vector<bool>vis(n,false);
        while(!q.empty()){
           int node=q.front();
           q.pop();
           vis[node]=true;
           for(auto nei:adj[node]){
            if(vis[nei])continue;
            indegree[nei]--;
            if(indegree[nei]==0){
                q.push(nei);
            }
           }
        }
        for(auto i:vis){
            if(i==false)return false;
        }
        return true;
    }
};
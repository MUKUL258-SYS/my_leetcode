class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        vector<vector<bool>>vp(n,vector<bool>(n,false));
        vector<int>indegree(n+1,0);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto next:adj[node]){
                vp[node][next]=true;
                for(int i=0;i<n;i++){
                    if(vp[i][node])vp[i][next]=true;
                }
                indegree[next]--;
                if(indegree[next]==0)q.push(next);
            }            
        }
        int m=queries.size();
        vector<bool>ans(m,false);
        int k=0;
        for(auto i:queries){
           if(vp[i[0]][i[1]])ans[k]=true;
           k++;
        }
        return ans;


    }
};
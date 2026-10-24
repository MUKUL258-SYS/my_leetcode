class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ings, vector<string>& s) {
        vector<string>res;
        int n=r.size();
        //vector<int>indegree(n,0);
        unordered_map<string,int>indegree;
        map<string,vector<string>>adj;
        for(int i=0;i<n;i++){
            for(auto j=0;j<ings[i].size();j++){
                adj[ings[i][j]].push_back(r[i]);
            }
            indegree[r[i]]=ings[i].size();
        }
        queue<string>q;
       // unordered_map<string,bool>vis;
        for(auto i:s){
            if(indegree[i]==0){
                  q.push(i);
            }
        }
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            for(auto nei:adj[f]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                    res.push_back(nei);
                }
            }
        }
        return res;
    }

};
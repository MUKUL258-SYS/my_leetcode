class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+5);
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        //queue<pair<int,int>>q;
        queue<int>q;
        int mini=INT_MAX;
        q.push(1);
        vector<bool>vis(n+1,false);
        vis[1]=true;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            //mini=min(mini,wt);
            //if(node==n)break;
        for(auto nei:adj[node]){
            int neiv=nei.first;
            int neiw=nei.second;
            mini=min(mini,neiw);
            if(!vis[neiv]){
                q.push(neiv);
                vis[neiv]=true;
            }
        }
        }
        return mini;

    }
};
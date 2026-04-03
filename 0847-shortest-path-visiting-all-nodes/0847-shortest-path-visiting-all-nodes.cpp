class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1)return 0;
        int maxi=(1<<n)-1;
        vector<vector<bool>>vis(n,vector<bool>(1<<n,false));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.emplace(i,mask,0);
            vis[i][mask]=true;
        }
        while(!q.empty()){
            auto [node,mask,dist]=q.front();
            q.pop();
            if(mask==maxi)return dist;
            for(auto nei:graph[node]){
               int newmask=mask|(1<<nei);
               if(!vis[nei][newmask]){
                q.emplace(nei,newmask,dist+1);
                vis[nei][newmask]=true;
               }
            }
        }
        return -1;

    }
};
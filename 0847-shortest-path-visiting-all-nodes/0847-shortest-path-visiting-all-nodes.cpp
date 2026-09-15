class Solution {
public:
    int shortestPathLength(vector<vector<int>>& gr) {
         int n=gr.size();
        vector<vector<bool>>vis(n,vector<bool>(1<<n,false));
        //int n=gr.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            q.push({i,(1<<i)});
            vis[i][1<<i]=true;
        }
        
        int steps=0;
        int target=(1<<n)-1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            auto [node,mask]=q.front();
            q.pop();
            if(mask==target)return steps;
           
            for(auto nei:gr[node]){
                int newmask=mask|(1<<nei);
                if(!vis[nei][newmask]){
                    vis[nei][newmask]=true;
                    q.push({nei,newmask});
                }
            }
        }
            steps++;
        }
        return 0;

    }
};
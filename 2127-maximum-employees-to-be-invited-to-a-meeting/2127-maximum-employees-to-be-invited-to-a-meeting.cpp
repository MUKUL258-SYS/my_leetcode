class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n=fav.size();
        vector<int>indegree(n,0),depth(n,1);
        for(int i=0;i<n;i++)indegree[fav[i]]++;
        queue<int>q;
        for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
        while(!q.empty()){
            int curr=q.front();q.pop();
            int nxt=fav[curr];
            depth[nxt]=max(depth[nxt],depth[curr]+1);
            if(--indegree[nxt] ==0)q.push(nxt);

        }
        int maxcycle=0;
        int twocycle=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)continue;
            int curr=i;
            int len=0;
            while(indegree[curr]!=0){
                indegree[curr]=0;
            len++;
            curr=fav[curr];
            }
            if(len==2){
              twocycle+=(depth[i]+depth[fav[i]]);
            }
            else{
                maxcycle=max(maxcycle,len);
            }
        }
        return max(maxcycle,twocycle);
    }
};
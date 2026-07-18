class Solution {
public:
unordered_map<int,int>mp;
int dfs(int node,vector<vector<int>>&adj,int parent){
    int ans=1;
    for(auto nei:adj[node]){
        if(nei!=parent){
            ans+=dfs(nei,adj,node);
        }
    }
    return mp[node]=ans;
}
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
        }
       dfs(0,adj,-1);
       //return 0;
     /*  for(auto i:mp){
        cout<<i.first<<" "<<i.second<<endl;
       }*/
       cout<<endl;
       cout<<endl;
       unordered_map<int,long long>mp2;
    
       for(int i=0;i<n;i++){
        int nodes=n-1;

         if(adj[i].size()==2){
            if(i==0){
                mp2[i]=(1ll*mp[adj[i][0]]*mp[adj[i][1]]);
                continue;
            }
            nodes-=(mp[adj[i][0]]);
            nodes-=(mp[adj[i][1]]);
            //nodes-=1;
            mp2[i]=1ll*nodes*(mp[adj[i][0]])*(mp[adj[i][1]]);

         }
         else if(adj[i].size()==1){
            if(i==0){
                   mp2[i]=(mp[adj[i][0]]);
                continue;
            }
            nodes-=mp[adj[i][0]];
            mp2[i]=1ll*nodes*mp[adj[i][0]];
         }
         else{

              mp2[i]=1ll*nodes;
         }
       }
       /*for(auto i:mp2){
        cout<<i.first<<" "<<i.second<<endl;
       }*/
       //return 0;
       long long maxi=0;
       for(auto i:mp2){
        maxi=max(maxi,i.second);
       }
      int cnt=0;
      for(auto i:mp2){
        if(i.second==maxi)cnt++;
      }
      
       return cnt;
    }
};
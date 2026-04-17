class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        queue<int>q;
        vector<int>inorder(n+1,0);
        vector<vector<int>>adj(n+1);
        for(auto i:relations){
            adj[i[0]].push_back(i[1]);
            inorder[i[1]]++;
        }
         vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            if(inorder[i]==0){
                q.push(i);
                dp[i]=time[i-1];
            }
        }

        while(!q.empty()){
           int node=q.front();
           q.pop();
          
           for(auto nei:adj[node]){
              inorder[nei]--;
              dp[nei]=max(dp[nei],dp[node]+time[nei-1]);
              if(inorder[nei]==0){
                q.push(nei);
              }
           }
        }
        int maxi=0;
        for(auto i:dp){
            //cout<<i<<endl;
             maxi=max(maxi,i);
        }
        return maxi;
    }
};
class Solution {
public:
vector<vector<int>>adj;
void dfs(int node,unordered_set<int>&vis,int mask){
  
   vis.insert(node);
    for(auto nei:adj[node]){
        if((mask&(1<<nei))&&!vis.count(nei)){
            dfs(nei,vis,mask);
        }
    }
}
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        adj.resize(n);
        vector<bool>vis(n,false);
       for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
       }
        
        int cnt=0;
        for(int mask=1;mask<(1<<n);mask++){
            vector<int>temp;
            long long sum=0;
            for(int j=0;j<n;j++){
                if(mask&(1<<j)){
                    temp.push_back(j);
                    sum+=nums[j];
                }
            }
         // if(helper(temp,nums))cnt++;
         unordered_set<int>s;
         //vector<int>t;
          dfs(temp[0],s,mask);

          if((s.size()!=temp.size())||(sum%2))continue;
          cnt++;
        }
        return cnt;
    }
};

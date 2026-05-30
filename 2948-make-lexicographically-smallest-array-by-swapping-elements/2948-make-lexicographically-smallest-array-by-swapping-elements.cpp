class Solution {
public:
unordered_map<int,vector<int>>adj;
int k;
void dfs(int node,vector<int>&t,vector<bool>&vis){
    vis[node]=true;
    t.push_back(node);
    for(auto nei:adj[node]){
        if(!vis[nei]){
          dfs(nei,t,vis);
        }
    }
}
//unordered_map<int,vector<int>>adj;
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>vp;
        k=limit;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vp.push_back({nums[i],i});
        }

        sort(vp.begin(),vp.end());
       for(int i=1;i<n;i++){
        int v1=vp[i].first;
        int v2=vp[i-1].first;
        int idx1=vp[i].second;
        int idx2=vp[i-1].second;
        if((v1-v2)<=k){
            adj[idx1].push_back(idx2);
            adj[idx2].push_back(idx1);
        }
       }
       vector<bool>vis(n,false);
       for(int i=0;i<n;i++){
        if(vis[i])continue;
        vector<int>t;
         
        dfs(i,t,vis);
        vector<int>temp;
        for(auto i:t){
           // cout<<i<<endl;
            temp.push_back(nums[i]);
        }
     //   cout<<endl;
        sort(t.begin(),t.end());
        sort(temp.begin(),temp.end());
       for(int i=0;i<t.size();i++){
        nums[t[i]]=temp[i];
       }

       }
       return nums;
    }
};
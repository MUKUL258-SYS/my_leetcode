class Solution {
public:
vector<int>nums;
vector<vector<int>>adj;
void dfs(int node,vector<bool>&vis,int &odd,int &even,vector<int>&temp){
    if(node%2==0)even++;
    else odd++;
    vis[node]=true;
    temp.push_back(nums[node]);
   for(auto nei:adj[node]){
    if(!vis[nei]){
        dfs(nei,vis,odd,even,temp);
    }
   }
}
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n=nums.size();
        adj.resize(n);
        this->nums=nums;
        for(auto i:swaps){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>vis(n,false);
        long long ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int odd=0;
                int even=0;
                vector<int>v;
                dfs(i,vis,odd,even,v);
                sort(v.begin(),v.end());
                //for(auto i:v)cout<<i<<" ";
                //cout<<endl;
                for(int i=0;i<odd;i++){
                 ans+=(-1ll*v[i]);
                }
                for(int i=odd;i<v.size();i++){
                    ans+=(1ll*v[i]);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
vector<int>arr;
bool helper(int i,vector<bool>&vis){
    int n=vis.size();
    if(i<0||i>=n||vis[i])return false;
    return true;
}
bool dfs(int i,vector<bool>&vis){
    if(arr[i]==0)return true;
    vis[i]=true;
    bool ans=false;
    if(helper(i+arr[i],vis))ans=ans||dfs(i+arr[i],vis);
    if(helper(i-arr[i],vis))ans=ans||dfs(i-arr[i],vis);
    return ans;
}
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        this->arr=arr;
        vector<bool>vis(n,false);
        return dfs(start,vis);
    }
};
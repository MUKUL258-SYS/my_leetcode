class Solution {
public:
int ans;
int dfs(int i,vector<int>&cost){
    if(i>=cost.size())return 0;
    int a=dfs(2*i+1,cost);
    int b=dfs(2*i+2,cost);
    ans+=abs(a-b);
    return cost[i]+max(a,b);
}
    int minIncrements(int n, vector<int>& cost) {
        ans=0;
         dfs(0,cost);
         return ans;
    }
};
class Solution {
public:
int n;
vector<vector<int>>dp;
static bool comp(vector<int>&v1,vector<int>&v2){
    if(v1[0]==v2[0]){
        if(v1[1]==v2[1]){
            return v1[2]<v2[2];
        }else{
            return v1[1]<v2[1];
        }
    }
    return v1[0]<v2[0];
}
int dfs(int idx,vector<vector<int>>&cuboids,int prev){
    if(idx>=n)return 0;
    int maxi=-1;
    if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
    if(prev==-1||cuboids[idx][0]>=cuboids[prev][0]&&cuboids[idx][1]>=cuboids[prev][1]&&cuboids[idx][2]>=cuboids[prev][2]){
        maxi=max(maxi,(int)cuboids[idx][2]+dfs(idx+1,cuboids,idx));
    }
    maxi=max(maxi,dfs(idx+1,cuboids,prev));
    return dp[idx][prev+1]=maxi;
}
    int maxHeight(vector<vector<int>>& cuboids) {
         n=cuboids.size();
         dp.resize(n+5,vector<int>(n+5,-1));
        for(int i=0;i<n;i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end(),comp);
      return dfs(0,cuboids,-1);
    }
};
class Solution {
public:
vector<vector<int>>vp,dp;
int n;
int dfs(int i,int k){
    if(i>=n||k<=0)return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    int op1=dfs(i+1,k);
    int maxi=0;
    int c=0;
    for(int j=0;j<min((int)vp[i].size(),k);j++){
         c+=vp[i][j];
        maxi=max(maxi,c+dfs(i+1,k-1-j));
    }
    return dp[i][k]=max(maxi,op1);
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        dp.resize(n+5,vector<int>(k+5,-1));
        vp=piles;
        return dfs(0,k);
    }
};
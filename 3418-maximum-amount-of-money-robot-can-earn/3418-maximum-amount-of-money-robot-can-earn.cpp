class Solution {
public:
int n,m;
vector<vector<int>>coins;
int dp[505][505][3];
int mini=-1e7;
int dfs(int i,int j,int cnt){
    if(i==n-1&&j==m-1){
       if(coins[i][j]<0){
        if(cnt>0)return 0;
        }
       return coins[i][j];
    }
    if(i>=n||j>=m)return mini;
    if(dp[i][j][cnt]!=mini)return dp[i][j][cnt];
    int ans=0;
    if(coins[i][j]>0){
    ans=coins[i][j]+max(dfs(i+1,j,cnt),dfs(i,j+1,cnt));
    }
    else{
        if(cnt>0){
            ans=max(dfs(i+1,j,cnt-1),dfs(i,j+1,cnt-1));
            ans=max(ans,coins[i][j]+max(dfs(i+1,j,cnt),dfs(i,j+1,cnt)));
        }
        else{
           ans=coins[i][j]+max(dfs(i+1,j,cnt),dfs(i,j+1,cnt)); 
        }
    }
    return dp[i][j][cnt]=ans;

}
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        this->coins=coins;
        //memset(dp,mini,sizeof(dp));
        for(int i=0;i<505;i++){
            for(int j=0;j<505;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=mini;
                }
            }
        }
        return dfs(0,0,2);

    }
};
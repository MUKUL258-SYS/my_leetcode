class Solution {
public:
int amt;
vector<int>coins;
vector<vector<int>>dp;
int dfs(int s,int i){
    if(s<0||i>=coins.size())return 0;
    if(s==0)return 1;
    if(dp[s][i]!=-1)return dp[s][i];
    int take=dfs(s-coins[i],i);
    //int take2=dfs(s+coins[i],i+1);
    int notake=dfs(s,i+1);
    return    dp[s][i]=take+notake;
}
    int change(int amount, vector<int>& coins) {
        amt=amount;
        this->coins=coins;
        int n=coins.size();
        dp.resize(amt+5,vector<int>(n+5,-1));
        return dfs(amt,0);
    }
};
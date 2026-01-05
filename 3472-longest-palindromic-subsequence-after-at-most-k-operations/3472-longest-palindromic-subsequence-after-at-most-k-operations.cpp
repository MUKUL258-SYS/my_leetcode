class Solution {
public:
string s;
int dp[205][205][205];
int dfs(int i,int j,int k){
    if(i>j){
        return 0;
    }
    if(i==j)return 1;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int c1=abs(s[i]-s[j]);
    int c2=26-abs(s[i]-s[j]);
    int mini=min(c1,c2);
    int op1=0;
    if(k>=mini)op1=2+dfs(i+1,j-1,k-mini);
    int op2=dfs(i+1,j,k);
    int op3=dfs(i,j-1,k);
    return dp[i][j][k]=max({op1,op2,op3});
    
}
    int longestPalindromicSubsequence(string s, int k) {
        this->s=s;
        memset(dp,-1,sizeof(dp));
        return dfs(0,s.size()-1,k);
    }
};
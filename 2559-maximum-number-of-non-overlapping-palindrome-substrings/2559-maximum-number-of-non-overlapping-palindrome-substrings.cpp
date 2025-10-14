class Solution {
public:
int dp[2001][2001];
int n,k;
string s;
bool isPal(int i,int j){
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
int dfs(int i,int j){
    if(i>=n||j>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(isPal(i,j)){
        return dp[i][j]=max(dfs(i,j+1),max(dfs(i+1,j+1),1+dfs(j+1,j+k)));
    }
    return dp[i][j]=max(dfs(i,j+1),dfs(i+1,j+1));
}
    int maxPalindromes(string s, int k) {
      n=s.size();  
      if(k==1)return n;
      this->s=s;
      this->k=k;
      memset(dp,-1,sizeof(dp));
      return dfs(0,k-1);
    }
};
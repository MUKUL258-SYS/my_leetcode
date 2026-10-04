class Solution {
public:
int n;
string s;
vector<vector<int>>dp;
bool dfs(int i,int balance){
    if(i>=n){
        return balance==0?true:false;
    }
    if(balance<0)return false;
    if(dp[i][balance]!=-1)return dp[i][balance];
    if(s[i]=='('){
        return dfs(i+1,balance+1);
    }
    else if(s[i]==')'){
        return dfs(i+1,balance-1);
    }
    bool op1=dfs(i+1,balance+1);
    bool op2=dfs(i+1,balance-1);
    bool op3=dfs(i+1,balance);
    return dp[i][balance]=op1||op2||op3;
}
    bool checkValidString(string s) {
      n=s.size();
      this->s=s;
      int m=105;
      dp.resize(n,vector<int>(m,-1));
      return dfs(0,0);
    }
};
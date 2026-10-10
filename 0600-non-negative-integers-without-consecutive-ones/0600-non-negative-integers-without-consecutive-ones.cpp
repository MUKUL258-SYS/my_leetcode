class Solution {
public:
int d;
//vector<vector<int>>dp;
string s;
int dp[32][2][2];
int dfs(int i,int last,int tight){
if(i==s.size())return 1;
if(dp[i][last][tight]!=-1)return dp[i][last][tight];
int lb=0,ans=0;
int ub=tight?s[i]-'0':1;
for(int j=lb;j<=ub;j++){
    if(last && j)continue;
      ans+=dfs(i+1,j,(tight&&(j==ub)));
}
return dp[i][last][tight]=ans;
}
    int findIntegers(int n) {
      s=bitset<32>(n).to_string();
     //dp.resize(d+2,vector<int>(3,-1));
     //dp[0][0]=0;
     memset(dp,-1,sizeof(dp));
     return dfs(0,0,1);
    }
};
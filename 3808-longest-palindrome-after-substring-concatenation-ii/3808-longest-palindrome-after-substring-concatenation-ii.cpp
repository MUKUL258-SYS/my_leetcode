class Solution {
public:
vector<int>sp,tp;
int dp[1001][1001][3];
int n,m;
bool is_palindrome(string &s,int i,int j){
    while(i<=j){
        if(s[i++]!=s[j--])return false;
    }
    return true;
}
vector<int>pre_comp(string &s){
    int n=s.size();
    vector<int>res(n,0);
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(is_palindrome(s,i,j)){
               res[i]=(j-i+1);
               break;
            }
        }
    }
    return res;
}
int dfs(int i,int j,string &s,string &t,int f){
    if(i>=n&&j>=m)return 0;
    if(i>=n)return tp[j];
    if(j>=m)return sp[i];
    if(dp[i][j][f]!=-1)return dp[i][j][f];
    int res=max(sp[i],tp[j]);
    if(s[i]==t[j]){
        res=max(res,2+dfs(i+1,j+1,s,t,0));
    }
    if(f==2){
        res=max(res,dfs(i+1,j,s,t,2));
        res=max(res,dfs(i,j+1,s,t,2));
    }
    return dp[i][j][f]=res;
}
    int longestPalindrome(string s, string t) {
        reverse(t.begin(),t.end());
        n=s.size();
        m=t.size();
   sp=pre_comp(s);
   tp=pre_comp(t);
   memset(dp,-1,sizeof(dp));
  return dfs(0,0,s,t,2);

    }
};
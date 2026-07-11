class Solution {
public:
vector<int>dp;
int mod;
int dfs(int i,string &s){
    int n=s.size();
    if(i>=n)return 1;
    if(dp[i]!=-1)return dp[i];
    int ans=0;
    int num=s[i]-'0';
    ans=(ans+dfs(i+1,s))%mod;
   if(num==7 || num==9){
     if(i+1<n && s[i+1]==s[i]){
        ans=(ans+dfs(i+2,s))%mod;
        if(i+2<n && s[i+2]==s[i]){
            ans=(ans+dfs(i+3,s))%mod;
            if(i+3<n && s[i+3]==s[i]){
                ans=(ans+dfs(i+4,s))%mod;
            }
        }
     }
     
   }
   else{
         if(i+1<n && s[i+1]==s[i]){
            ans=(ans+dfs(i+2,s))%mod;
           if(i+2<n && s[i+2]==s[i]){
            ans=(ans+dfs(i+3,s))%mod;
        }
     }
   }
   return dp[i]=ans%mod;
}
    int countTexts(string pressedKeys) {
        int n=pressedKeys.size();
        dp.resize(n+3,-1);
        mod=1e9+7;
        return dfs(0,pressedKeys);
    }
};
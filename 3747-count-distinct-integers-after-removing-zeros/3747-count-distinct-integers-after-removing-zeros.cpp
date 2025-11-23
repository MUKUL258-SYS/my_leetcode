class Solution {
public:
long long dp[20][2][2];
long long dfs(int pos, string & s,int tight,int leading){
    int n=s.size();
    if(pos==n){
        return leading?0:1;
    }
    if(dp[pos][tight][leading]!=-1)return dp[pos][tight][leading];
    long long ans=0;
    int maxDigit=tight?(s[pos]-'0'):9;
    for(int d=0;d<=maxDigit;d++){
        int nextTight=(tight&&d==maxDigit);
       if(leading){
        if(d==0)ans+=dfs(pos+1,s,nextTight,1);
        else ans+=dfs(pos+1,s,nextTight,0);
       }
       else{
          if(d==0)continue;
          ans+=dfs(pos+1,s,nextTight,0);
       }
    }
    return dp[pos][tight][leading]=ans;
}
    long long countDistinct(long long n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return dfs(0,s,1,1);
    }
};
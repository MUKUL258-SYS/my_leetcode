class Solution {
public:
string s;
int k;
int dfs(int prev,int curr){
   if(curr>=s.size())return 0;
   int ans;
   if(prev==-1){
    ans=1+dfs(prev+1,curr+1);
   }
   else{
    int inc=0,exc=0;
    int diff=abs(s[curr]-s[prev]);
    if(diff<=k){
    inc=1+dfs(curr,curr+1);
    }
    exc=dfs(prev,curr+1);
    ans=max(exc,inc);
   }
   return ans;
}
    int longestIdealString(string s, int k) {
        this->k=k;
        this->s=s;
       // return dfs(-1,0);
       int dp[150]={0},maxLen=0;
       for(char c:s){
        for(int i=c-k;i<=c+k;i++){
            if(i>='a'&&i<='z'){
                dp[c]=max(dp[c],dp[i]);
            }
        }
        maxLen=max(maxLen,++dp[c]);
       }
       return maxLen;
    }
};
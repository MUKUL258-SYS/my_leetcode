class Solution {
public:
vector<int>dp;
int dfs(int idx,string &s){
    int n=s.size();
    if(idx==n)return 0;
    if(dp[idx]!=-1)return dp[idx];
    int freq[26]={0};
    int unique=0;
    int maxi=0,ans=INT_MAX;
    for(int i=idx;i<n;i++){
        if(freq[s[i]-'a']==0)unique++;
        freq[s[i]-'a']++;
        int len=i-idx+1;
         maxi=max(maxi,freq[s[i]-'a']);
         if((maxi*unique)==len){
          ans=min(ans,1+dfs(i+1,s));
         }
    }
    return dp[idx]=ans;

}
    int minimumSubstringsInPartition(string s) {
        dp.resize(s.size()+5,-1);
        return dfs(0,s);
    }
};
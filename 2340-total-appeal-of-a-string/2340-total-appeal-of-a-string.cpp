class Solution {
public:
    long long appealSum(string s) {
      long long ans=0;
        unordered_map<char,int>mp;
        int n=s.size();
        vector<int>dp(n+1);
        for(char ch='a';ch<='z';ch++)mp[ch]=-1;
       // long long ans=0;
        for(int i=0;i<n;i++){
          dp[i+1]=dp[i]+i-mp[s[i]];
          ans+=dp[i+1];
          mp[s[i]]=i;
        }
        return ans;
    }
};
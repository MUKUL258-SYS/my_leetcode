class Solution {
public:
bool checker(string s,string t){
    int n=s.size();
    int m=t.size();
    if(n!=m)return false;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i])cnt++;
    }
    return cnt==1;
}
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        if(n==1)return words;
        vector<int>dp(n+1,1);
         vector<int>prev(n+1,-1);
         int maxi=1;
         int maxprev=0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(groups[i]!=groups[j]){
                    bool b=checker(words[i],words[j]);
                    if(b){
                        if(1+dp[j]>dp[i]){
                            prev[i]=j;
                            dp[i]=1+dp[j];
                            if(dp[i]>maxi){
                                maxi=dp[i];
                                maxprev=i;
                            }
                        }
                        
                    }
                }
            }
        }
        vector<string>res;
        res.push_back(words[maxprev]);
        while(prev[maxprev]!=-1){
           res.push_back(words[prev[maxprev]]);
           maxprev=prev[maxprev];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
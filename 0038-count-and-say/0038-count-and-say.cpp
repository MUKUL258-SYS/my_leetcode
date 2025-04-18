class Solution {
public:
unordered_map<int,string>dp;
string dfs(int n){
    if(n==1)return "1";
    if(n==2)return "11";
    if(dp.find(n)!=dp.end())return dp[n];
    string s=dfs(n-1);
    string res="";
    int l=1;
    int i;
    for(i=1;i<s.size();i++){
          if(s[i]==s[i-1]){
            l++;
          }
          else{
            res+=to_string(l);
            res+=s[i-1];
            l=1;
          }
    }
    int m=s.size();
    if(s[m-1]==s[m-2]){
         res+=to_string(l);
         res+=s[m-1];

      }
          else{
            res+="1";
            res+=s[m-1];
          }
     return dp[n]=res;

}
    string countAndSay(int n) {
         return dfs(n);
    }
};
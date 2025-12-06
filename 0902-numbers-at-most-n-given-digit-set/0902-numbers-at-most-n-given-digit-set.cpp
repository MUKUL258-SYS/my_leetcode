class Solution {
public:
int dp[11][2][2];
string s;
vector<int>v;
int dfs(int n,bool tight,bool isLeading){
    if(n==0){
        return 1;
    }
    if(dp[n][tight][isLeading]!=-1)return dp[n][tight][isLeading];
    int ub=tight?(s[s.size()-n]-'0'):9;
    int ans=0;
    if(isLeading){
    ans+=dfs(n-1,0,1);
    }
    for(auto d:v){
        if(d<=ub)
        ans+=dfs(n-1,tight&&(d==ub),0);
    }
    return dp[n][tight][isLeading]=ans;
}
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp,-1,sizeof(dp));
        for(auto i:digits){
            v.push_back(stoi(i));
        }
        s=to_string(n);
        return dfs(s.size(),1,1)-1;

    }
};
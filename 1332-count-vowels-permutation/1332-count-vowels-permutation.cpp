class Solution {
public:
int n;
int mod=1e9+7;
vector<vector<long long>>dp;
long long dfs(int i,char ch){
    if(i==n)return 1;
    if(dp[i][ch-'a']!=-1)return dp[i][ch-'a'];
    long long cnt=0;
    if(ch=='a'){
       cnt=(cnt+dfs(i+1,'e'))%mod;
    }
    else if(ch=='e'){
        cnt=(cnt+dfs(i+1,'a'))%mod;
        cnt=(cnt+dfs(i+1,'i'))%mod;
    }
    else if(ch=='i'){
        cnt=(cnt+dfs(i+1,'a'))%mod;
        cnt=(cnt+dfs(i+1,'e'))%mod;
        cnt=(cnt+dfs(i+1,'o'))%mod;
        cnt=(cnt+dfs(i+1,'u'))%mod;
    }
    else if(ch=='o'){
        cnt=(cnt+dfs(i+1,'i'))%mod;
        cnt=(cnt+dfs(i+1,'u'))%mod;
    }
    else if(ch=='u'){
        cnt=(cnt+dfs(i+1,'a'))%mod;
    }
    return dp[i][ch-'a']=cnt%mod;
}
    int countVowelPermutation(int n) {
        this->n=n;
        dp.resize(n+9,vector<long long>(30,-1));
        return (dfs(1,'a')+dfs(1,'e')+dfs(1,'i')+dfs(1,'o')+dfs(1,'u'))%mod;
    }
};
class Solution {
public:
long long mod=1e9+7;
long long K,Goal,N;
//vector<vector<long long>>dp;
long long dp[108][108];
long long dfs(long long currlen,long long usedsong){
     if(currlen==Goal){
        return usedsong==N;
     }
     if(dp[currlen][usedsong]!=-1)return dp[currlen][usedsong];
     long long newsongplay=(dfs(currlen+1,usedsong+1)*(N-usedsong))%mod;
     long long oldsongplay=(dfs(currlen+1,usedsong)*max(0LL,usedsong-K))%mod;
     return dp[currlen][usedsong]=(newsongplay+oldsongplay)%mod;
}
    int numMusicPlaylists(int n, int goal, int k) {
        K=k;
        Goal=goal;
        N=n;
        memset(dp,-1,sizeof(dp));
        //dp.resize(Goal+5,vector<long long>(N+5,-1));
        return dfs(0,0);
    }
};
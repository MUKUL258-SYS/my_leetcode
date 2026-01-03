class Solution {
public:
int dp[5005][5][5][5];
int n;
int mod=1e9+7;
int dfs(int i,int prev1,int prev2,int prev3){
    if(i>=n)return 1;
    if(dp[i][prev1][prev2][prev3]!=-1)return dp[i][prev1][prev2][prev3];
    int ans=0;
    for(int curr1=1;curr1<=3;curr1++){
        if(curr1==prev1)continue;
        for(int curr2=1;curr2<=3;curr2++){
            if(curr2==prev2||curr2==curr1)continue;
            for(int curr3=1;curr3<=3;curr3++){
                if(curr3==prev3||curr3==curr2)continue;
                ans=(ans+dfs(i+1,curr1,curr2,curr3))%mod;
            }
        }
    }
    return dp[i][prev1][prev2][prev3]=ans%mod;
}
    int numOfWays(int n) {
        this->n=n;
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,0,0);
    }
};
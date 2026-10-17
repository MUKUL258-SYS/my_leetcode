class Solution {
public:
using ll=long long ;
    long long maximumSum(vector<int>& A, int m, int l, int r) {
        ll n=A.size(),inf=1e12;
        vector<ll>pre(n);
        pre[0]=A[0];
        for(int i=1;i<n;i++){
           pre[i]=pre[i-1]+A[i];
        }
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-inf));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=1;j<=m;j++){
            multiset<ll>ms;
            //dp[i][j]=dp[i+1][j];
            for(int i=n-1;i>=0;i--){
                 dp[i][j]=dp[i+1][j];
                int add=i+l-1;
                int rem=i+r;
                if(add<n)ms.insert(pre[add]+dp[add+1][j-1]);
                if(rem<n)ms.erase(ms.find(pre[rem]+dp[rem+1][j-1]));
                if(!ms.empty()){
                    ll best =*ms.rbegin();
                    if(i-1>=0)best-=pre[i-1];
                    dp[i][j]=max(dp[i][j],best);
                }
            }
        }
        ll ans=-inf;
        for(int j=1;j<=m;j++){
            ans=max(ans,dp[0][j]);
        }
        return ans;
    }
};
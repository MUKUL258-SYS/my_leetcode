class Solution {
public:
unordered_map<int,int>dp;
int dfs(int n){
    if(n==0)return 0;
    if(dp.count(n))return dp[n];
    if((n&(n-1))==0)return dp[n]=1;
    long long p=1;
    while(p<n)p=p*2;
    int add=1+dfs(p-n);
    int sub=1+dfs(n-(p>>1));
    return dp[n]=min(add,sub);
}
    int minOperations(int n) {
        return dfs(n);
    }
};
class Solution {
    private:
    long long pow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = result * base % mod;
            }
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }
public:
int mod;
vector<long long>fact,infact;
long long ncr(int n,int r){
if(n>=r)return (fact[n]* infact[n-r]%mod *infact[r]%mod);
return 0;
}
    int minMaxSums(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        mod=1e9+7;
        int n=nums.size();
        fact.resize(n+1,1);
        infact.resize(n+1,1);
        for(int i=1;i<=n;i++){
            fact[i]=(fact[i-1]*i)%mod;
            infact[i]=pow(fact[i],mod-2,mod);
        }
        long long ans=0;
        for(int l=1;l<=k;l++){
        for(int i=0;i<n;i++){
            ans=(ans+ncr(n-i-1,l-1) * nums[i] %mod) % mod;
            ans=(ans+ncr(i,l-1) * nums[i] % mod) % mod;
        }
        }
        return ans;
    }
};
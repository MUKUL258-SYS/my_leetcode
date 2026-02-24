class Solution {
public:
long long mod=1e9+7;
long long modPow(long long base,long long exp){
    long long res=1;
    while(exp){
        if(exp&1)res=(res*base)%mod;
        base=(base*base)%mod;
        exp>>=1;
    }
    return res%mod;
}
    int countGoodNumbers(long long n) {
        long long pow1=(n+1)/2;
        long long pow2=n/2;
        return (int)((modPow(5,pow1)*modPow(4,pow2))%mod);
    }
};
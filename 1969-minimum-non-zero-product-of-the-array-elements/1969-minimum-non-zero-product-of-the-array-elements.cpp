class Solution {
public:
long long mod;
long long power(long long a,long long b){
    //long long ans=1;
    long long res=1;
    //b=b%mod;
    a=a%mod;
    while(b>0){
        if(b&1)res=(res*a)%mod;
        //res=(res*res)%mod;
        //b=(b*b)%mod;
        a=(a*a)%mod;
        b>>=1;
        
    }
    return res;
}
    int minNonZeroProduct(int p) {
        if(p==1)return 1;
        if(p==2)return 6;
        long long ans=(1LL<<p)-1;
        long long b=ans-1;
        long long exp=ans/2;
        mod=1e9+7;
        long long res=power(b,exp);
        return (((ans%mod)*(__int128)res)%mod);
        
    }
};

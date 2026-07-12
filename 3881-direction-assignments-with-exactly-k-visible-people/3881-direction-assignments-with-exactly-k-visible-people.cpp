class Solution {
public:
static const long long mod=1e9+7;
vector<long long>fact;
vector<long long>infact;
int n;
 static const  int maxi=1e5;
long long power(long long a,long long b,long long mod){
    long long res=1;
    a %= mod;
    while(b>0){
      if(b&1)res=(res*a)%mod;
      a=(a*a)%mod;
      b>>=1;

    }
    return res;
}
void precompute(){
    fact.resize(maxi,1);
    infact.resize(maxi,1);
    
    for(int i=1;i<maxi;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    infact[maxi-1]=power(fact[maxi-1],mod-2,mod);
    for(int i=maxi-2;i>=0;i--){
        infact[i]=(infact[i+1]*(i+1))%mod;
    }
}
long long ncr(int n,int r){
  if (r < 0 || r > n) return 0;
  //  return ((fact[n]%mod)*((infact[n-r]%mod)*(infact[r]%mod))%mod)%mod;
  return fact[n] * infact[r] % mod * infact[n - r] % mod;
    
}
    int countVisiblePeople(int n, int pos, int k) {
        precompute();
       // int maxi=1e5+1;
        this->n=n;
        int n1=pos;
        int n2=n-pos;
        int mini=min({n1,n2,k});
         return (ncr(n-1,k)*2)%mod;
    }
};

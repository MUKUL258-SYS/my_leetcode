class Solution {
public:
    int concatenatedBinary(int n){
        long long ans=0;
        const int mod=1e9+7;
        long long len=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0)len++;
            ans=((ans<<len)%mod+i)%mod;
        }
        return ans;
    }
};


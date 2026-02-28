class Solution {
public:
int mod=1e9+7;
    int concatenatedBinary(int n) {
        long long sum=1;
        for(int i=2;i<=n;i++){
            int bits=floor(log2(i))+1;
           // cout<<bits<<endl;
            int value=1<<bits;
            sum=(sum*value)%mod;
            sum=(sum+i)%mod;
        }
        return sum%mod;
    }
};
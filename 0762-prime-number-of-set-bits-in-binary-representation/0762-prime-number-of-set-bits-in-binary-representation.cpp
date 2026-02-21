class Solution {
public:
vector<int>helper(int n){
    vector<bool>isPrime(n+5,true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(isPrime[i])ans.push_back(i);
    }
    return ans;
}
    int countPrimeSetBits(int left, int right) {
        vector<int>v=helper(right+5);;
        unordered_map<int,int>mp;
        int cnt=0;
        for(auto i:v)mp[i]++;
        for(int i=left;i<=right;i++){
            int bits=__builtin_popcount(i);
            if(mp[bits]>0)cnt++;
        }
        return cnt;
    }
};
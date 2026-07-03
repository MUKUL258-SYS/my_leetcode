class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int>arr(26,0);
        for(auto i:s)arr[i-'a']++;
        int mod=1e9+7;
        while(t--){
            vector<int>temp(26,0);
            for(int i=0;i<26;i++){
                if(arr[i]==0)continue;
                if(i==25){
                    temp[0]=(temp[0]+arr[i])%mod;
                    temp[1]=(temp[1]+arr[i])%mod;
                }
                else temp[i+1]=(arr[i]+temp[i+1])%mod;
            }
            arr=temp;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+arr[i])%mod;
        }
        return ans;
    }
};
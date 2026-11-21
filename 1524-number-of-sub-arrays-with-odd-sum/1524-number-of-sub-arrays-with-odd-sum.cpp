class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int  n =arr.size();
        int evencnt=1;
        int mod=1e9+7;
        int oddcnt=0;
        long long sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
         sum+=arr[i];
         if(sum%2 ==0){
           ans=(ans+oddcnt)%mod;
           evencnt++;

         }
         else{
            ans=(ans+evencnt)%mod;
            oddcnt++;
         }
        }
        return ans;
    }
};
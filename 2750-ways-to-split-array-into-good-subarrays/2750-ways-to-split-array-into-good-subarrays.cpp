class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
          int i=0;
          int mod=1e9+7;
          int n=nums.size();
          while(i<n){
            if(nums[i]==0)i++;
            else break;
          }
          if(i>=n)return 0;
          long long cnt=0;
          long long ans=1;
          for(;i<n;i++){
             if(nums[i]==0)cnt++;
             else{
                cnt++;
                  ans=(ans*cnt)%mod;
                  cnt=0;
             }
          }
          return ans;

    }
};
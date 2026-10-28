class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        for(auto &i:nums){
            i=i%k;
        }
       int len=1;
       int ans=1;
       int sum=nums[0];
        for(int i=1;i<n;i++){
              //sum+=nums[i];
            if(nums[i]==nums[i-1]){
                 sum+=nums[i];
                 len++;
                  if((sum-nums[i])%k ==0){
                     ans=max(ans,len);
                  }

            }else{
                len=1;
                sum=nums[i];
            }
         //   sum+=nums[i];

        }
        return ans;

    }
};
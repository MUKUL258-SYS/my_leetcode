class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        for(auto i:nums)sum+=i;
        int k=n/2;
        long long curr_sum=0;
        for(int i=0;i<k;i++)curr_sum+=nums[i];
        int cnt=0;
        for(int i=0;i<n;i++){
         long long rem=sum-curr_sum;
         if(rem<curr_sum)cnt++;
          curr_sum-=nums[i];
          curr_sum+=(nums[(i+k)%n]);
        }
        return cnt;
    }
};
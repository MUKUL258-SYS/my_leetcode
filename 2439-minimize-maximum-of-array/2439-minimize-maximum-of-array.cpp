class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans=nums[0];
        int n=nums.size();
        long long sum=nums[0];
        for(int i=1;i<n;i++){
            sum+=(nums[i]);
          long long avg=ceil(sum/((1.0)*(i+1)));
        ans=max(ans,avg);
        }
        return (int)ans;
    }
};
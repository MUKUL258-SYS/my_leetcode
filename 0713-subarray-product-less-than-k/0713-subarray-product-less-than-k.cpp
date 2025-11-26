class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        long long product=1;
        long long ans=0;
        while(j<n){
            product=product*nums[j];
           while(i<=j&&product>=k){
                 product=product/nums[i];
                 i++;
           }
           ans+=(j-i+1);
           j++;
        }
        return ans;
    }
};
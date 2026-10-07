class Solution {
public:

    int maxSubarrays(vector<int>& nums) {
      int   mini=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            mini=mini&nums[i];
        }
        if(mini)return 1;
      int cnt = 0;
        int current_and = -1; // -1 has all bits set to 1

        for (int num : nums) {
            current_and &= num;
            
            // Increment as soon as current subarray reaches 0
            if (current_and == 0) {
                cnt++;
                current_and = -1; // Reset for the next subarray
            }
        }
        return cnt;
    }
};
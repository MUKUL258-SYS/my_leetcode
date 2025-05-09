class Solution {
public:
    int minMoves(vector<int>& nums) {
         int n=nums.size();
         int mini=nums[0];
         int sum=0;
         for(auto i:nums){
            sum+=i;
            mini=min(mini,i);
         }

         return sum-(mini*n);
    }
};
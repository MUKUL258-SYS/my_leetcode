class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            sum+=nums[i];
        }
        return sum-(1ll*(n-1)*nums[0]);
    }
};
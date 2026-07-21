class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        auto itr=lower_bound(nums.begin(),nums.end(),k)-nums.begin();
        return itr;


    }
};
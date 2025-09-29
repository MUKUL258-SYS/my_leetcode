class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int x=0;
        for(auto i:nums)x=x^i;
        return x;
    }
};
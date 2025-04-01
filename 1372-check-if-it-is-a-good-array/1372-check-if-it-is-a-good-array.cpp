class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int a=nums[0];
        for(auto i:nums){
            a=__gcd(a,i);
        }
        return a==1;
    }
};
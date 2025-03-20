class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n=nums.size();
        int x=0;
       for(auto i:nums)x=x^i;
       if(x==0||n%2==0)return true;
       return false;
    }
};
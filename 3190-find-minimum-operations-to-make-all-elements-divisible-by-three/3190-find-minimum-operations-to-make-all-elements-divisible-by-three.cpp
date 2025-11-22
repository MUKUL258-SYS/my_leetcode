class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        for(auto &i:nums){
            i=i%3;
        }
        int res=0;
        for(auto i:nums){
            res+=min(i,3-i);
        }
        return res;
    }
};
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt=0;
        for(auto i:nums){
            if(i%2 == 0){
                cnt++;
            }
        }
        return cnt>=2;
    }
};
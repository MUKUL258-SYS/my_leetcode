class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>v;
        for(auto i:nums){
            if(i==2){
                v.push_back(-1);
                continue;
            }
            int n=i+1;
            int lsb=(n&(-n));
            v.push_back(i-(lsb/2));

        }
        return v;
    }
};
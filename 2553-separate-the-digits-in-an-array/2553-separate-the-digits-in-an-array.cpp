class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>v;
        for(auto i:nums){
            vector<int>vp;
            while(i){
               vp.push_back(i%10);
               i/=10;
            }
            reverse(vp.begin(),vp.end());
            for(auto i:vp)v.push_back(i);
        }
        return v;
    }
};
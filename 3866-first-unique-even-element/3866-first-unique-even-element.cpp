class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:nums){
            if(i%2)continue;
            if(mp[i]==1)return i;
        }
        return -1;
    }
};
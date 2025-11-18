class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            if(i==k)continue;
            mp[i]++;
            if(i<k)return -1;
        }
        return mp.size();
        
    }
};
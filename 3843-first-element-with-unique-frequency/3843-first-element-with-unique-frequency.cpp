class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;

        }
        unordered_map<int,int>freq;
        for(auto i:mp){
            freq[i.second]++;
        }
        for(auto i:nums){
            int times=mp[i];
            if(freq[times]==1)return i;
        }
        return -1;
    }
};
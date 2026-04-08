class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k)return false;
        int maxi=n/k;
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        for(auto i:mp){
            if(i.second>maxi)return false;
        }
        return true;
    }
};
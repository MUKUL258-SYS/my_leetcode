class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        long long n=nums.size();
        vector<int>v;
        int k=floor(n/3.0);
        for(auto i:m){
            if(i.second>k)v.push_back(i.first);
        }
        return v;
    }
};
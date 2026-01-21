class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
       // return 0;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=target[i])mp[nums[i]]++;
        }
        return mp.size();
        
    }
};
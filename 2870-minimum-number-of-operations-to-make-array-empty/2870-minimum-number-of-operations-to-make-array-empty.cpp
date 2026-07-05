class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int cnt=0;
        for(auto i:mp){
            int freq=i.second;
            if((freq) == 1){
                return -1;
            }
            else {
              cnt+=ceil(freq/3.0);
            }
        }
        return cnt;
    }
};
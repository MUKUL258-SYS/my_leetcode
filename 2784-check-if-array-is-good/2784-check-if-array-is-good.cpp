class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int maxi=0;
        for(auto i:nums){
            maxi=max(maxi,i);
            mp[i]++;
        }
        for(int i=1;i<maxi;i++){
            if(mp[i]!=1)return false;
        }
        if(mp[maxi]!=2)return false;
        return true;
        
    }
};
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        map<pair<int,int>,int>mp;
        for(int i=0;i+1<n;i++){
        if(nums[i]!=nums[i+1]){
            if(nums[i]<nums[i+1])mp[{nums[i],nums[i+1]}]++;
            else mp[{nums[i+1],nums[i]}]++;
        }
        }
        int ans=0;
        for(int i=0;i+1<n;i++){
            if(nums[i]==nums[i+1])ans++;
        }
        int maxi=0;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        return ans+maxi;
        
    }
};
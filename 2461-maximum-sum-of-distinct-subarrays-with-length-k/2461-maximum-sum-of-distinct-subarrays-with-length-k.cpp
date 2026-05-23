class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi=0;
        long long sum=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()==k)maxi=max(maxi,sum);
        for(int i=1;i+k<=n;i++){
            mp[nums[i-1]]--;
            if(mp[nums[i-1]]==0)mp.erase(nums[i-1]);
            
            sum-=nums[i-1];
            mp[nums[i+k-1]]++;
            sum+=nums[i+k-1];
          if(mp.size()==k)maxi=max(maxi,sum);
        }
        return maxi;
    }
};
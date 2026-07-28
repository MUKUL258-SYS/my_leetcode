class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        for(auto i:nums)maxi=max(maxi,i);
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=maxi)continue;
            int cnt=0;
            int j=i;
          while(j<n && nums[j]==maxi){
            cnt++;
            j++;
          }
          i=j-1;
         // maxi=max(maxi,cnt);
         ans=max(ans,cnt);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n=nums.size();
      map<int,int>mp;
      for(int i=0;i<k;i++){
        mp[nums[i]]++;
      }  
      vector<int>v;
      v.push_back(mp.rbegin()->first);
      for(int i=1;i+k<=n;i++){
        mp[nums[i-1]]--;
        if(mp[nums[i-1]]==0)mp.erase(nums[i-1]);
        mp[nums[i+k-1]]++;
         v.push_back(mp.rbegin()->first);
      }
      return v;

    }
};
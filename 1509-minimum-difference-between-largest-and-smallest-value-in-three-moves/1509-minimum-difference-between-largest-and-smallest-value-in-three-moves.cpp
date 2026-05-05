class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=3)return 0;
        sort(nums.begin(),nums.end());
        //vector<int>v={{nums[n-4]-nums[0]}}
      // for(int i=)
      int i=3;
      int j=n-1;
      int mini=nums.back()-nums[0];
      while(i>=0&&j>=i){
          mini=min(mini,nums[j]-nums[i]);
          i--;
          j--;
      }
      return mini;
    }

};
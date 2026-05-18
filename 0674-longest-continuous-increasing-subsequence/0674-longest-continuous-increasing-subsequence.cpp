class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        int cnt=1;
        for(int i=1;i<n;i++){
          if(nums[i]>nums[i-1]){
            cnt++;
          }
          else{
            maxi=max(maxi,cnt);
            cnt=1;
          }
        }
        maxi=max(maxi,cnt);
        return maxi;
    }
};
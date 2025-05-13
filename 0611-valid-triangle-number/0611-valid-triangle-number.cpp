class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int t=nums[i]+nums[j];
            int idx=lower_bound(nums.begin()+j+1,nums.end(),t)-nums.begin();
            idx--;
            cnt+=max(0,idx-j);
        }
      }
        return cnt;
    }
};
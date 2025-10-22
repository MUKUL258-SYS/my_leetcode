class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int i=0;
       int j=0;
       int n=nums.size();
       int cnt=0;
       int ans=0;
       while(j<n){
     if(nums[j]==0)cnt++;
    while(cnt>k&&i<=j){
       if(nums[i]==0)cnt--;
       i++;
    }
    
    ans=max(ans,j-i+1);
    j++;
       }
       return ans;   
    }
};
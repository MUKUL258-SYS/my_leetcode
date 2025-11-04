class Solution {
public:
int helper(vector<int>&nums,int k){
    int i=0;
    int j=0;
    int n=nums.size();
    int cnt=0;
    int res=0;
    while(j<n){
        if(nums[j]%2)cnt++;
        while(cnt>=k&&i<=j){
             res+=(n-j);
             if(nums[i]%2)cnt--;
             i++;
        }
        j++;
    }
    return res;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k+1);
    }
};
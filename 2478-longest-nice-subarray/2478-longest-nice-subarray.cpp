class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
       int  mask=0;
       int l=0,res=0;
       int n=nums.size();
       for(int r=0;r<n;r++){
        while(mask&(nums[r])){
            mask=mask^nums[l];
            l++;
        }
        res=max(res,r-l+1);
        mask=mask|nums[r];
       }
       return res;
    }
};
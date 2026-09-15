class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
       long long ans=0;
       int l=nums.back();
       int n=nums.size();
       for(int i=n-2;i>=0;i--){
        if(nums[i]<=l){
            l=nums[i];
            continue;
        }
         //int rem=nums[i]%l;
         double k=ceil(nums[i]/(l*(1.0)));
        ans+=(k-1);
        l=floor(nums[i]/k);
       } 
       return ans;
    }
};
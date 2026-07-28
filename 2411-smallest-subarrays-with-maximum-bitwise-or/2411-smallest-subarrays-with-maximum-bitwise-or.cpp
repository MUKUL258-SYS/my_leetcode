class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int prev=i-1;
            while(prev>=0  && ((nums[prev]|curr) != nums[prev])){
                 nums[prev]=nums[prev]|curr;
                 res[prev]=i-prev+1;
                 prev--;
            }
           // res[i]=i-prev+1;
        }
        return res;
    }
};
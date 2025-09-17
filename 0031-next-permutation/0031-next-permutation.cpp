class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
       int idx=-1;
       
               for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int diff=INT_MAX;
        int sidx;
        for(int i=idx+1;i<n;i++){
            if(nums[i]<=nums[idx])continue;
            if(nums[i]-nums[idx]<diff){
                diff=nums[i]-nums[idx];
                sidx=i;
            }
        }
        swap(nums[idx],nums[sidx]);
        sort(nums.begin()+idx+1,nums.end());
    }
};
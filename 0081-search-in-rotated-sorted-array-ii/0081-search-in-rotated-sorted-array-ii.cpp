class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            while(s<e&&nums[s]==nums[s+1])s++;
            while(s<e&&nums[e]==nums[e-1])e--;
            int mid=(s+e)/2;
            if(nums[mid]==target)return true;
            if(nums[s]<=nums[mid]){
                if(target>=nums[s]&&target<=nums[mid]){
                    e=mid-1;
                }
                else s=mid+1;
            }
            else{
                if(target>=nums[mid]&&target<=nums[e]){
                    s=mid+1;
                }
                else e=mid-1;
            }
        }
        return false;
    }
};
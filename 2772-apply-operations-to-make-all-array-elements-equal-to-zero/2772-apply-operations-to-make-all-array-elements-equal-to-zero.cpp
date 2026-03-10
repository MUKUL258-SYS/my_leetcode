class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int val=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(val>nums[i])return false;
            nums[i]-=val;
            val+=nums[i];
            if(i+1>=k){
                val-=nums[i+1-k];
            }
        }
        return val==0;
    }
};
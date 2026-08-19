class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=(n+1)/2;
        int cnt=0;
        while(i<=(n/2) && j<n){
            if(nums[i]<nums[j]){
                cnt+=2;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return n-cnt;
    }
};
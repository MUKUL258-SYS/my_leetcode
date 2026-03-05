class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int mini=*min_element(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
         int rem=nums[i]%mini;
        if(rem!=0&&rem<mini){
            mini=rem;
            cnt=0;
        }
        if(rem==mini||nums[i]==mini){
            cnt++;
        }
        }
        return (cnt+1)/2;
    }
};
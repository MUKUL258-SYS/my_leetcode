class Solution {
public:
    int countWays(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
       
        if(0<nums[0])ans++;
        for(int i=0;i<n;i++){
           if(i+1>nums[i]){
               if(i+1<n && i+1<nums[i+1])ans++;
               else if(i+1 == n)ans++;

           }
        }
       

        return ans;
    }
};
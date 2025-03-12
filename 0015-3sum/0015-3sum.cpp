class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
           int j=i+1;
           int k=n-1;
           while(j<k){
             int target=nums[i]+nums[j]+nums[k];
             if(target>0){
                k--;
             }
             else if(target<0){
                j++;
             }
             else{
               ans.push_back({nums[i],nums[j],nums[k]});
               j++;
               while(nums[j]==nums[j-1]&&j<k)j++;
             }
           }
        }
        return ans;
    }
};

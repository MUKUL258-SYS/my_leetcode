class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n && nums[i]==1)i++;
        if(i==n)return 0;
        int last=0;
        int ans=1;
        for(;i<n;i++){
            if(nums[i]==last)continue;
            last=nums[i];
            ans++;
        }
        return ans;
    }
};
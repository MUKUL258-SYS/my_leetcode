class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long cnt=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
               // ans+=cnt;
                cnt=0;
                continue;
            }
            cnt++;
            ans+=cnt;
        }
        return ans;
    }
};
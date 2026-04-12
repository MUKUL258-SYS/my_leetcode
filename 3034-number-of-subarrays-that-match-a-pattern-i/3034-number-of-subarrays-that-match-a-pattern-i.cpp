class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size();
        int k=pattern.size()+1;
        int cnt=0;
        for(int i=0;i+k<=n;i++){
            vector<int>p;
            for(int j=i+1;j<i+k;j++){
               if(nums[j]>nums[j-1])p.push_back(1);
               else if(nums[j]<nums[j-1])p.push_back(-1);
               else p.push_back(0);
            }
            if(p==pattern)cnt++;
        }
        return cnt;
    }
};
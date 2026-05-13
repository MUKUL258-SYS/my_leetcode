class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>diff(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            diff[2]+=2;
            diff[2*limit+1]-=2;
            int sum=nums[i]+nums[n-i-1];
            int mini=1+min(nums[i],nums[n-i-1]);
            int maxi=limit+max(nums[i],nums[n-i-1]);
           diff[mini]-=1;
           diff[maxi+1]+=1;
            diff[sum]-=1;
            diff[sum+1]+=1;
        }
        int ans=n;
        for(int i=2;i<=2*limit;i++){
            diff[i]+=diff[i-1];
            ans=min(ans,diff[i]);
        }
        return ans;
    }
};
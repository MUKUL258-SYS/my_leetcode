class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        priority_queue<double>pq;
        int n=nums.size();
        int m=n/2;
        sort(nums.begin(),nums.end());
        double mini=INT_MAX;
        int i=0;
        int j=n-1;
        while(m--){
         mini=min(mini,(nums[i]+nums[j])/2.0);
         i++;
         j--;
        }
        return mini;
    }
};
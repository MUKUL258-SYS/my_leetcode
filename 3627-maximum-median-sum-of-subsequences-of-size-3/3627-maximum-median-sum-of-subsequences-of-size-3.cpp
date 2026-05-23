class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=n-2;i>=0;i-=2){
            if(cnt==(n/3))break;
            sum+=nums[i];
            cnt++;

        }
        return sum;
    }
};
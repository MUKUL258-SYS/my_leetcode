class Solution {
public:
int helper(int n){
    int sum=0;
    while(n){
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
    int minElement(vector<int>& nums) {
        int mini=helper(nums[0]);
        int n=nums.size();

        for(int i=1;i<n;i++){
            mini=min(mini,helper(nums[i]));
        }
        return mini;
    }
};
class Solution {
public:
vector<int>nums;
int helper(int mid){
    int sum=0;
    for(auto i:nums){
        if(i>=mid)sum+=(i-mid);
        else sum+=(mid-i);
    }
    return sum;

}
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        this->nums=nums;
      //  sort(nums.begin(),nums.end());
        if(n%2 ==0){
            int mid=n/2;
            return min(helper(nums[mid]),helper(nums[mid-1]));
        }
        else return helper(nums[n/2]);
    }
};
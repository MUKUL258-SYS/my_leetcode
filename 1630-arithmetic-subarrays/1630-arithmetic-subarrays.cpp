class Solution {
public:
bool helper(vector<int>&nums){
    if(nums.size()==1)return true;
    sort(nums.begin(),nums.end());
    int diff=nums[1]-nums[0];
    int n=nums.size();
    for(int i=2;i<n;i++){
        if((nums[i]-nums[i-1])!=diff)return false;
    }
    return true;
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0;i<l.size();i++){
            vector<int>subarray(nums.begin()+l[i],nums.begin()+r[i]+1);
            ans.push_back(helper(subarray));
        }
        return ans;
    }
};
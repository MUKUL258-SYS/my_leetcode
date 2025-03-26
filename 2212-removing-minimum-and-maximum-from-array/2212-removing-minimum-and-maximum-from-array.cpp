class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int i=min_element(nums.begin(),nums.end())-nums.begin();
        int j=max_element(nums.begin(),nums.end())-nums.begin();
        if(i>j)swap(i,j);
        return min(j+1,min(n-i,i+1+n-j));
    }
};
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
        v[0]=nums[0];
        for(int i=1;i<n;i++){
            v[i]=max(v[i-1],nums[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==v[i])cnt++;
        }
        return cnt;

    }
};
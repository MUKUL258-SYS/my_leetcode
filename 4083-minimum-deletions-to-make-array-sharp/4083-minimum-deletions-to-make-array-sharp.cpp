class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i+1<n;i++){
            while(i+1<n && (nums[i]^nums[i+1]) == 0){
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};
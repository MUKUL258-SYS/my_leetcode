class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int n=nums.size();
        vector<int>right_min(n+1,INT_MAX);
        for(int i=n-1;i>=0;i--){
            right_min[i]=min(right_min[i+1],nums[i]);
        }
        int left_max=INT_MIN;
        int cnt=0;
        for(int i=0;i<n;i++){
           left_max=max(left_max,nums[i]);
           if(left_max<=right_min[i+1]){
            cnt++;
           }
        }
        return cnt;
    }
};
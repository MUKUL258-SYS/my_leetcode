class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            nums[i]-=cnt;
            cnt+=nums[i];
            if(i+1>=k){
                cnt-=nums[i+1-k];
            }
        }
        return cnt==0;
    }
};
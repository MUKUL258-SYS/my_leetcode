class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(2,0);
        for(int parity=0;parity<2;parity++){
            int ans=0;
            for(int i=parity;i<n;i+=2){
                int v1=i-1>=0?nums[i-1]:1005;
                int v2=i+1<n?nums[i+1]:1005;
                int target=min(v1,v2)-1;
                if(nums[i]>target){
                    ans+=(nums[i]-target);
                }
            }
            res[parity]+=ans;
        }
        return min(res[0],res[1]);
    }
};
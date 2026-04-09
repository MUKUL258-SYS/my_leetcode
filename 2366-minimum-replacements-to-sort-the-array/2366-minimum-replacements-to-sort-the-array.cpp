class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        vector<int>t=nums;
        sort(t.begin(),t.end());
        if(t==nums)return 0;
        int n=nums.size();
        long long res=0;
        for(int i=n-2;i>=0;i--){
           if(nums[i]<=nums[i+1])continue;
           int parts=ceil(nums[i]/((1.0)*(nums[i+1])));
           //cout<<parts<<endl;
           res+=(parts-1);
           nums[i]=(nums[i]/parts);
        }
        return res;
    }
};
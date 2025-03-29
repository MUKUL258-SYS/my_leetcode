class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0),post(n,0);
        pre[0]=nums[0];
        post[n-1]=nums[n-1];
        for(int i=1;i<n;i++)pre[i]=max(pre[i-1],nums[i]);
        for(int i=n-2;i>=0;i--)post[i]=min(post[i+1],nums[i]);
        int s=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>pre[i-1]&&nums[i]<post[i+1])s+=2;
            else if(nums[i]>nums[i-1]&&nums[i]<nums[i+1])s++;
        }
        return s;

    }
};
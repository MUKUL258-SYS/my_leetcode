class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre1(n);
        vector<int>pre2(n);
        pre1[0]=nums[0];
        pre2[n-1]=nums[n-1];
        int cnt=0;
        for(int i=1;i<n;i++)pre1[i]=nums[i]+pre1[i-1];
        for(int i=n-2;i>=0;i--)pre2[i]=nums[i]+pre2[i+1];
        for(int i=0;i<n-1;i++){
            int diff=abs(pre1[i]-pre2[i+1]);
            if(diff%2==0)cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        unordered_map<int,int>mp;
        mp[0]++;
        mp[((nums[0]%k)+k)%k]++;
        int cnt=0;
        if(nums[0]%k==0)cnt++;
        for(int i=1;i<n;i++){
         pre[i]=pre[i-1]+nums[i];
         int rem=pre[i]%k;
         if(rem<0)rem+=k;
         cnt+=mp[rem];
         mp[rem]++;
        }
        return cnt;
    }
};
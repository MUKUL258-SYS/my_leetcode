class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int cnt=0;
        if(mp.size()==n)return cnt;
        for(int i=0;i<n;i++){
            int j;
            cnt++;
            for(j=i;j<min(i+3,n);j++){
                 mp[nums[j]]--;
                 if(mp[nums[j]]==0)mp.erase(nums[j]);
            }
            i=j-1;
            if(mp.size()==(n-i-1))return cnt;

        }
        return cnt;
    }
};
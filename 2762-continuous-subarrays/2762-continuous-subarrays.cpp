class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        map<int,int>mp;
        //mp[nums[0]]++;
        long long cnt=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
             while(j<=i&&(mp.size()>0)&&((mp.rbegin()->first - mp.begin()->first)>2)){
                mp[nums[j]]--;
                if(mp[nums[j]]==0)mp.erase(nums[j]);
                j++;

             }
            // cout<<i<<" "<<j<<endl;
             cnt+=(i-j+1);
            // mp[nums[i]]++;
        }

        return cnt;
    }
};
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();
        set<int>s;
        int mini=INT_MAX;
        for(int i=n-1;i>=0;i--){
           s.insert(nums[i]);
           if(i-x>=0){
            int ans=nums[i-x];
           auto it=s.lower_bound(ans);
            if(it!=s.end())mini=min(mini,abs(ans-*it));
            if(it!=s.begin()) mini=min(mini,abs(ans-*prev(it)));
           }
        }
        return mini;
    }
};
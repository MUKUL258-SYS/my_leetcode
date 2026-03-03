class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>>s;
        int n=nums.size();
        s.push({nums[n-1],0});
        int ans=0;
        for(int i=n-2;i>=0;i--){
            int cnt=0;
            while(s.size()&&s.top().first<nums[i]){
                cnt=max(cnt+1,s.top().second);
                s.pop();
            }
            ans=max(ans,cnt);
            s.push({nums[i],cnt});

        }
        return ans;
    }
};
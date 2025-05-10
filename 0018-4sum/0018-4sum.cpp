class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>s;
        
        int i=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        while(i<n){
            int j=i+1;
            while(j<n){
                long long t=1LL*target-nums[i]-nums[j];
                int l=j+1;
                int r=n-1;
                while(l<r){
                    long long sum=nums[l]+nums[r];
                    if(sum<t){
                        l++;
                    }
                    else if(sum>t){
                        r--;
                    }
                    else{
                        s.insert({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                      while(l<r&&nums[l]==nums[l-1])l++;
                      while(l<r&&nums[r]==nums[r+1])r--;
                    }
                }
                j++;
            }
            i++;
        }
        vector<vector<int>>v(s.begin(),s.end());
        return v;
    }
};
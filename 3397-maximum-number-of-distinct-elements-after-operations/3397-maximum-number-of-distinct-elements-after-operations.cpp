class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int ans=0;
       int prev=-1e9;
       for(auto i:nums){
        int maxi=max(i-k,prev+1);
        if(maxi<=(i+k)){
            prev=maxi;
            ans++;
        }

       }
       return ans;
    }
};
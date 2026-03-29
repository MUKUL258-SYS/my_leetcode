class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        long long maxi=0;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
              mp[nums[i]]++;
        }
        if(mp.size()>=m)maxi=sum;
        for(int i=1;i+k<=n;i++){
            sum-=nums[i-1];
            sum+=nums[i+k-1];
           if(mp[nums[i-1]]==1){
            mp.erase(nums[i-1]);

           }
           else mp[nums[i-1]]--;
           mp[nums[i+k-1]]++;
         if(mp.size()>=m)maxi=max(maxi,sum);
        }
        return maxi;
    }
};
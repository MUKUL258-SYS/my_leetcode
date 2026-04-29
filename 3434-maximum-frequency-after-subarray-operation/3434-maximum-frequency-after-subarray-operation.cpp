class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=count(nums.begin(),nums.end(),k);
        int maxi=0;
       for(int i=1;i<=50;i++){
        if(i==k)continue;
        int cnt=0;
           for(auto n:nums){
         cnt+=(n==i?1:n==k?-1:0);
         if(cnt<0)cnt=0;
         maxi=max(maxi,cnt);
           }
       }
       return maxi+ans;
    }
};
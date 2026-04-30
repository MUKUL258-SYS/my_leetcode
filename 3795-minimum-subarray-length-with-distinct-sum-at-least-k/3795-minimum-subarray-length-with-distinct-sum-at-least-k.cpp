class Solution {
public:
    int minLength(vector<int>& nums, int k) {
       int n=nums.size();
       int j=0;
       unordered_map<int,int>mp;
       long long sum=0;
       long long mini=n+1;
    for(auto i:nums){
        if(i>=k)return 1;
    }
    int i;
       for(i=0;i<n;i++){
        mp[nums[i]]++;
        if(mp[nums[i]]==1)sum+=nums[i];
       // while(j<i&&s.size())
      /* while(j<=i&&mp[nums[i]]>1){
        sum-=nums[j];
        mp[nums[j]]--;
        j++;
       }
       */


       while(j<=i&&sum>=k){
       // cout<<i<<" "<<j<<endl;
         mini=min(mini,(1ll)*(i-j+1));

         //sum-=nums[j];
         mp[nums[j]]--;
         if(mp[nums[j]]==0){
            sum-=nums[j];
         }
         j++;
       }
    }
       if(sum>=k){
        mini=min(mini,(1ll)*(i-j+1));
       }
       
       return mini==(n+1)?-1:mini; 
    }
};